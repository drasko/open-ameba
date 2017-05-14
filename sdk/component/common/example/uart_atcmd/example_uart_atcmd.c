/******************************************************************************
 *
 * Copyright(c) 2007 - 2015 Realtek Corporation. All rights reserved.
 *
 *
 ******************************************************************************/
#include "platform_opts.h"
#include "FreeRTOS.h"
#include "task.h"
#include "platform/platform_stdlib.h"
#include "semphr.h"
#include "device.h"
#include "serial_api.h"
#include "at_cmd/log_service.h"
#include "uart_atcmd/example_uart_atcmd.h"
#include "flash_api.h"
#include "device_lock.h"
#if defined(configUSE_WAKELOCK_PMU) && (configUSE_WAKELOCK_PMU == 1)
#include "freertos_pmu.h"
#endif
#include "osdep_api.h"
#include "osdep_service.h"
#include "serial_ex_api.h"
#include "at_cmd/atcmd_wifi.h"
#include "at_cmd/atcmd_lwip.h"
#include "pinmap.h"

#ifdef USE_FLASH_EEP
#include "flash_eep.h"
#endif

#if CONFIG_EXAMPLE_UART_ATCMD

typedef int (*init_done_ptr)(void);
extern init_done_ptr p_wlan_init_done_callback;
extern char log_buf[LOG_SERVICE_BUFLEN];
extern xSemaphoreHandle log_rx_interrupt_sema;
extern void serial_rx_fifo_level(serial_t *obj, SerialFifoLevel FifoLv);
extern int atcmd_wifi_restore_from_flash(void);
extern int atcmd_lwip_restore_from_flash(void);

serial_t at_cmd_sobj;
char at_string[ATSTRING_LEN];
//xSemaphoreHandle at_printf_sema;
_Sema uart_at_dma_tx_sema;
unsigned char gAT_Echo = 1; // default echo on

#define UART_AT_MAX_DELAY_TIME_MS   20

#define UART_AT_DATA		UART_SETTING_SECTOR
#define BACKUP_SECTOR		FLASH_SYSTEM_DATA_ADDR-0x1000

#define UART_AT_USE_DMA_TX 0

void atcmd_update_partition_info(AT_PARTITION id, AT_PARTITION_OP ops, u8 *data, u16 len){
#ifdef USE_FLASH_EEP
	if(id == AT_PARTITION_UART || id == AT_PARTITION_LWIP || id == AT_PARTITION_WIFI) {
		if(ops == AT_PARTITION_READ) flash_read_cfg(data, id, len);
		else if (ops == AT_PARTITION_WRITE) flash_write_cfg(data, id, len);
		else if (ops == AT_PARTITION_ERASE) flash_write_cfg(data, id, 0);
	}
#else
	flash_t flash;
	int size, offset, i;
	u32 read_data;

	switch(id){
		case AT_PARTITION_UART:
			size = UART_CONF_DATA_SIZE;
			offset = UART_CONF_DATA_OFFSET;
			break;
		case AT_PARTITION_WIFI:
			size = WIFI_CONF_DATA_SIZE;
			offset = WIFI_CONF_DATA_OFFSET;
			break;
		case AT_PARTITION_LWIP:
			size = LWIP_CONF_DATA_SIZE;
			offset = LWIP_CONF_DATA_OFFSET;
			break;
		case AT_PARTITION_ALL:
			size = 0x1000;
			offset = 0;
			break;
		default:
			printf("partition id is invalid!\r\n");
			return;
	}

	device_mutex_lock(RT_DEV_LOCK_FLASH);
	if(id == AT_PARTITION_ALL && ops == AT_PARTITION_ERASE){
		flash_erase_sector(&flash, UART_SETTING_SECTOR);
		goto exit;
	}
	
	if(ops == AT_PARTITION_READ){
		flash_stream_read(&flash, UART_SETTING_SECTOR+offset, len, data);
		goto exit;
	}

	//erase BACKUP_SECTOR
	flash_erase_sector(&flash, UART_SETTING_BACKUP_SECTOR);

	if(ops == AT_PARTITION_WRITE){
		// backup new data
		flash_stream_write(&flash, UART_SETTING_BACKUP_SECTOR+offset, len, data);
	}
	
	//backup front data to backup sector
	for(i = 0; i < offset; i += sizeof(read_data)){
		flash_read_word(&flash, UART_SETTING_SECTOR + i, &read_data);
		flash_write_word(&flash, UART_SETTING_BACKUP_SECTOR + i,read_data);
	}
	
	//backup rear data
	for(i = (offset + size); i < 0x1000; i += sizeof(read_data)){
		flash_read_word(&flash, UART_SETTING_SECTOR + i, &read_data);
		flash_write_word(&flash, UART_SETTING_BACKUP_SECTOR + i,read_data);
	}
	
	//erase UART_SETTING_SECTOR
	flash_erase_sector(&flash, UART_SETTING_SECTOR);
	
	//retore data to UART_SETTING_SECTOR from UART_SETTING_BACKUP_SECTOR
	for(i = 0; i < 0x1000; i+= sizeof(read_data)){
		flash_read_word(&flash, UART_SETTING_BACKUP_SECTOR + i, &read_data);
		flash_write_word(&flash, UART_SETTING_SECTOR + i,read_data);
	}
	
	//erase BACKUP_SECTOR
	flash_erase_sector(&flash, UART_SETTING_BACKUP_SECTOR);

exit:
	device_mutex_unlock(RT_DEV_LOCK_FLASH);
	return;
#endif
}

int read_uart_atcmd_setting_from_system_data(UART_LOG_CONF* uartconf)
{
//	flash_t flash;
	UART_LOG_CONF conf;
	bool load_default = _TRUE;

//	device_mutex_lock(RT_DEV_LOCK_FLASH);
//	flash_stream_read(&flash, UART_AT_DATA,sizeof(UART_LOG_CONF), (u8 *)&conf);
	atcmd_update_partition_info(AT_PARTITION_UART, AT_PARTITION_READ, (u8 *)&conf, sizeof(UART_LOG_CONF));	
	do{
		if(conf.FlowControl != AUTOFLOW_DISABLE && conf.FlowControl != AUTOFLOW_ENABLE)
			break;
		
		if(conf.DataBits != 5 
			&&  conf.DataBits != 6 
			&&  conf.DataBits != 7 
			&&  conf.DataBits != 8) //5, 6, 7, 8
			break;

		if(conf.Parity != ParityNone && conf.Parity != ParityOdd && conf.Parity != ParityEven)
			break;

		if(conf.StopBits != 1 && conf.StopBits != 2)
			break;

		load_default = _FALSE;
	}while(0);

	if(load_default == _TRUE){
		// load default setting
		uartconf->BaudRate = DEFAULT_BAUDRATE;
		uartconf->DataBits = 8;
		uartconf->Parity = ParityNone;
		uartconf->StopBits = 1;
		uartconf->FlowControl = AUTOFLOW_DISABLE;
	}
	else{
		uartconf->BaudRate = conf.BaudRate;
		uartconf->DataBits = conf.DataBits;
		uartconf->Parity = conf.Parity;
		uartconf->StopBits = conf.StopBits;
		uartconf->FlowControl = conf.FlowControl;		
	}
//	device_mutex_unlock(RT_DEV_LOCK_FLASH);
	printf("\r\nAT_UART_CONF: %d,%d,%d,%d,%d\r\n", 
		uartconf->BaudRate, 
		uartconf->DataBits,
		uartconf->StopBits,
		uartconf->Parity,
		uartconf->FlowControl);

	return 0;
}

int write_uart_atcmd_setting_to_system_data(UART_LOG_CONF* uartconf)
{
#if 0
	flash_t flash;
	
	u8 data1[sizeof(UART_LOG_CONF)];
	u8 data2[sizeof(UART_LOG_CONF)];

	u32 data,i;

	memset(data2, 0xFF, sizeof(UART_LOG_CONF));
	
	//Get upgraded image 2 addr from offset
	device_mutex_lock(RT_DEV_LOCK_FLASH);
	flash_stream_read(&flash, UART_AT_DATA,sizeof(UART_LOG_CONF), data1);

	if(memcmp(data1,data2,sizeof(UART_LOG_CONF)) == 0){
		flash_stream_write(&flash, UART_AT_DATA, sizeof(UART_LOG_CONF),(u8*)uartconf);
	}else{
		//erase backup sector
		flash_erase_sector(&flash, BACKUP_SECTOR);

		// backup log uart configuration
		flash_stream_write(&flash, BACKUP_SECTOR, sizeof(UART_LOG_CONF),(u8*)uartconf);
		
		//backup system data to backup sector
		for(i = sizeof(UART_LOG_CONF); i < 0x1000; i+= 4){
			flash_read_word(&flash, UART_AT_DATA + i, &data);
			flash_write_word(&flash, BACKUP_SECTOR + i,data);
		}
		//erase system data
		flash_erase_sector(&flash, UART_AT_DATA);
		//write data back to system data
		for(i = 0; i < 0x1000; i+= 4){
			flash_read_word(&flash, BACKUP_SECTOR + i, &data);
			flash_write_word(&flash, UART_AT_DATA + i,data);
		}
		//erase backup sector
		flash_erase_sector(&flash, BACKUP_SECTOR);
	}
	device_mutex_unlock(RT_DEV_LOCK_FLASH);
#else
	atcmd_update_partition_info(AT_PARTITION_UART, AT_PARTITION_WRITE, (u8 *)uartconf, sizeof(UART_LOG_CONF));	
#endif
	return 0;
}

int reset_uart_atcmd_setting(){
#if 0
	flash_t flash;
	
	u8 data1[sizeof(UART_LOG_CONF)];
	u8 data2[sizeof(UART_LOG_CONF)];

	u32 data,i;

	memset(data2, 0xFF, sizeof(UART_LOG_CONF));
	
	//Get upgraded image 2 addr from offset
	device_mutex_lock(RT_DEV_LOCK_FLASH);
	flash_stream_read(&flash, UART_AT_DATA,sizeof(UART_LOG_CONF), data1);

	if(memcmp(data1,data2,sizeof(UART_LOG_CONF)) == 0){
		;
	}else{
		//erase backup sector
		flash_erase_sector(&flash, BACKUP_SECTOR);

		// erase uart configuration
		flash_stream_write(&flash, BACKUP_SECTOR, sizeof(UART_LOG_CONF),(u8*)data2);
		//backup system data to backup sector
		for(i = sizeof(UART_LOG_CONF); i < 0x1000; i+= 4){
			flash_read_word(&flash, UART_AT_DATA + i, &data);
			flash_write_word(&flash, BACKUP_SECTOR + i,data);
		}
		//erase system data
		flash_erase_sector(&flash, UART_AT_DATA);
		//write data back to system data
		for(i = 0; i < 0x1000; i+= 4){
			flash_read_word(&flash, BACKUP_SECTOR + i, &data);
			flash_write_word(&flash, UART_AT_DATA + i,data);
		}
		//erase backup sector
		flash_erase_sector(&flash, BACKUP_SECTOR);
	}
	device_mutex_unlock(RT_DEV_LOCK_FLASH);
#else
#ifdef USE_FLASH_EEP
	flash_write_cfg(NULL, AT_PARTITION_UART, 0);
	flash_write_cfg(NULL, AT_PARTITION_WIFI, 0);
	flash_write_cfg(NULL, AT_PARTITION_LWIP, 0);
#else
	atcmd_update_partition_info(AT_PARTITION_ALL, AT_PARTITION_ERASE, NULL, 0);
#endif
#endif
	return 0;
}

#if defined(configUSE_WAKELOCK_PMU) && (configUSE_WAKELOCK_PMU == 1)
#include "gpio_irq_api.h"
#define UART_AT_RX_WAKE 	UART_RX
void gpio_uart_at_rx_irq_callback (uint32_t id, gpio_irq_event event)
{
	/*  WAKELOCK_LOGUART is also handled in log service.
	 *  It is release after a complete command is sent.
	 **/
	//acquire_wakelock(WAKELOCK_LOGUART);
}

void uart_at_rx_wakeup()
{
	gpio_irq_t gpio_rx_wake;
#ifdef RTL8711AM
#if  (UART_AT_RX_WAKE!=PA_0)||(UART_AT_RX_WAKE!=PE_3)
#error "Set pin rx_wakeup!"
#endif
#endif
	gpio_irq_init(&gpio_rx_wake, UART_AT_RX_WAKE, gpio_uart_at_rx_irq_callback, 0);
	gpio_irq_set(&gpio_rx_wake, IRQ_FALL, 1);   // Falling Edge Trigger
	gpio_irq_enable(&gpio_rx_wake);
}
#endif

void uart_atcmd_reinit(UART_LOG_CONF* uartconf){
	serial_baud(&at_cmd_sobj,uartconf->BaudRate);
	serial_format(&at_cmd_sobj, uartconf->DataBits, (SerialParity)uartconf->Parity, uartconf->StopBits);

	// set flow control, only support RTS and CTS concurrent mode
	// rxflow and tx flow is fixed by hardware
#define rxflow	UART_RTS
#define txflow	UART_CTS
	if(uartconf->FlowControl){
		pin_mode(txflow, PullDown); //init CTS in low
		serial_set_flow_control(&at_cmd_sobj, FlowControlRTSCTS, rxflow, txflow);
	}
	else
		serial_set_flow_control(&at_cmd_sobj, FlowControlNone, rxflow, txflow);
}

void uart_at_send_string(char *str)
{
	unsigned int i=0;
	while (str[i] != '\0') {
		serial_putc(&at_cmd_sobj, str[i]);
		i++;
	}
}

#if UART_AT_USE_DMA_TX
static void uart_at_send_buf_done(uint32_t id)
{
	//serial_t *sobj = (serial_t *)id;

	RtlUpSemaFromISR(&uart_at_dma_tx_sema);
}
#endif

void uart_at_send_buf(u8 *buf, u32 len)
{
	unsigned char *st_p=buf;
	if(!len || (!buf)){
		return;
	}
#if UART_AT_USE_DMA_TX
	int ret;
	while(RtlDownSema(&uart_at_dma_tx_sema) == pdTRUE){
		ret = serial_send_stream_dma(&at_cmd_sobj, st_p, len);
		if(ret != HAL_OK){
			RtlUpSema(&uart_at_dma_tx_sema);
			return;
		}else{
			return;
		}
	}
#else
	while(len){
		serial_putc(&at_cmd_sobj, *st_p);
		st_p++;
		len--;
	}
#endif
}
/*
void uart_at_lock(void)
{
	RtlDownSema(&at_printf_sema);
}

void uart_at_unlock(void)
{
	RtlUpSema(&at_printf_sema);
}

void uart_at_lock_init(){
	RtlInitSema(&at_printf_sema, 1);
}
*/
void uart_irq(uint32_t id, SerialIrq event)
{
	serial_t    *sobj = (serial_t *)id;
	unsigned char rc=0;
	static unsigned char temp_buf[LOG_SERVICE_BUFLEN] = "\0";
	static unsigned int buf_count = 0;
	static unsigned char combo_key = 0;
	static u32 last_tickcnt = 0; //to check if any data lost
	static bool is_data_cmd = _FALSE; // to mark if it's a data command
	static u32 data_sz = 0, data_cmd_sz =0; // command will send to log handler until "data_cmd_sz" characters are received
	
	if(event == RxIrq) {
		rc = serial_getc(sobj);
		
		if(atcmd_lwip_is_tt_mode()){
			log_buf[atcmd_lwip_tt_datasize++] = rc;
			atcmd_lwip_tt_lasttickcnt = xTaskGetTickCountFromISR();
			if(atcmd_lwip_tt_datasize == 1)
				RtlUpSemaFromISR((_Sema *)&atcmd_lwip_tt_sema);
			return;
		}
		
		if(buf_count == 4){
			// if this is a data command with hex data, then '\n' should not be treated
			// as the end of command
			if(strncmp(temp_buf, "ATPT", C_NUM_AT_CMD)==0){
				is_data_cmd = _TRUE;
			}
		}
		if(buf_count > C_NUM_AT_CMD && is_data_cmd == _TRUE){
			if(data_cmd_sz == 0){
				if(data_sz == 0){
					if(rc == ','){
						//first delimeter, ATxx=[sz],....
						char str[10]={0};
						char size_pos = C_NUM_AT_CMD + C_NUM_AT_CMD_DLT;
						memcpy(str, &temp_buf[size_pos], buf_count-size_pos);
						data_sz = atoi(str); //get data size
					}
				}else{
					if(rc == ':'){ //data will start after this delimeter ':'
						strncpy(log_buf, (char *)temp_buf, buf_count);
						memset(temp_buf,'\0',buf_count);
						last_tickcnt =  xTaskGetTickCountFromISR();
						data_cmd_sz = buf_count + 1 + data_sz;
					}
				}
			}
			
			if(data_cmd_sz){
				if((!gAT_Echo) && (rtw_systime_to_ms(xTaskGetTickCountFromISR() - last_tickcnt) > UART_AT_MAX_DELAY_TIME_MS)){
					uart_at_send_string("\r\nERROR:data timeout\r\n\n# ");
					memset(log_buf, 0, buf_count);
					is_data_cmd = _FALSE;
					data_sz = 0;
					data_cmd_sz = 0;
					buf_count=0;
					last_tickcnt = 0;
					return;
				}	
				last_tickcnt =  xTaskGetTickCountFromISR();
				log_buf[buf_count++]=rc;
				if(gAT_Echo == 1){
					serial_putc(sobj, rc);
				}
				if(buf_count >= data_cmd_sz){
					log_buf[data_cmd_sz - data_sz - 1] = '\0'; //for log service handler parse to get command parameter, replace ":" with "\0"
					is_data_cmd = _FALSE;
					data_sz = 0;
					data_cmd_sz = 0;
					buf_count=0;
					last_tickcnt = 0;
					RtlUpSemaFromISR((_Sema *)&log_rx_interrupt_sema);
				}
				return;			
			}
		}

		if (rc == KEY_ESC) {
			combo_key = 1;
		}
		else if (combo_key == 1){
			if (rc == KEY_LBRKT) {
				combo_key = 2;
			}
			else{
				combo_key = 0;
			}
		}
		else if (combo_key == 2){
			//if ((rc=='A')|| rc=='B'){//up and down
			//}
			combo_key=0;
		}
		else if(rc == KEY_ENTER){
			if(buf_count>0){
				memset(log_buf,'\0',LOG_SERVICE_BUFLEN);
				strncpy(log_buf,(char *)&temp_buf[0],buf_count);
				RtlUpSemaFromISR((_Sema *)&log_rx_interrupt_sema);
				memset(temp_buf,'\0',buf_count);
				is_data_cmd = _FALSE;
				data_sz = 0;
				data_cmd_sz = 0;
				buf_count=0;
				last_tickcnt = 0;
			}else{
				uart_at_send_string(STR_END_OF_ATCMD_RET);
			}
		}
		else if(rc == KEY_BS){
			if(buf_count>0){
				buf_count--;
				temp_buf[buf_count] = '\0';
				if(gAT_Echo == 1){
					serial_putc(sobj, rc);
					serial_putc(sobj, ' ');
					serial_putc(sobj, rc);
				}
			}
		}
		else{
			// skip characters until "A"
			if((buf_count == 0) && (rc != 'A')){
				if(gAT_Echo == 1){
					uart_at_send_string("\r\nERROR:command should start with 'A'"STR_END_OF_ATCMD_RET);
				}
				return;
			}
			if(buf_count < (LOG_SERVICE_BUFLEN - 1)){
				temp_buf[buf_count] = rc;
				buf_count++;
				if(gAT_Echo == 1){
					serial_putc(sobj, rc);
				}
			}
			else if(buf_count == (LOG_SERVICE_BUFLEN - 1)){
				temp_buf[buf_count] = '\0';
				if(gAT_Echo == 1){
					uart_at_send_string("\r\nERROR:exceed size limit"STR_END_OF_ATCMD_RET);
				}
			}
		}
	}
}

void uart_atcmd_main(void)
{
	UART_LOG_CONF uartconf;

	read_uart_atcmd_setting_from_system_data(&uartconf);
	serial_init(&at_cmd_sobj, UART_TX, UART_RX);
	serial_baud(&at_cmd_sobj,uartconf.BaudRate);
	serial_format(&at_cmd_sobj, uartconf.DataBits, (SerialParity)uartconf.Parity, uartconf.StopBits);
	serial_rx_fifo_level(&at_cmd_sobj, FifoLvHalf);
	// set flow control, only support RTS and CTS concurrent mode
	// rxflow and tx flow is fixed by hardware
	#define rxflow	UART_RTS
	#define txflow	UART_CTS
	if(uartconf.FlowControl){
		pin_mode(txflow, PullDown); //init CTS in low
		serial_set_flow_control(&at_cmd_sobj, FlowControlRTSCTS, rxflow, txflow);
	}
	else
		serial_set_flow_control(&at_cmd_sobj, FlowControlNone, rxflow, txflow);

	/*uart_at_lock_init();*/

#if UART_AT_USE_DMA_TX
	RtlInitSema(&uart_at_dma_tx_sema, 1);
#endif

#if UART_AT_USE_DMA_TX
	serial_send_comp_handler(&at_cmd_sobj, (void*)uart_at_send_buf_done, (uint32_t)&at_cmd_sobj);
#endif
	
	serial_irq_handler(&at_cmd_sobj, uart_irq, (uint32_t)&at_cmd_sobj);
	serial_irq_set(&at_cmd_sobj, RxIrq, 1);

#if defined(configUSE_WAKELOCK_PMU) && (configUSE_WAKELOCK_PMU == 1)
	uart_at_rx_wakeup();
#endif
}

static void uart_atcmd_thread(void *param)
{
	p_wlan_init_done_callback = NULL;
#if CONFIG_DEBUG_LOG > 3
	 ConfigDebugErr  = -1;
	 ConfigDebugInfo = ~_DBG_SPI_FLASH_;
	 ConfigDebugWarn = -1;
	 CfgSysDebugErr = -1;
	 CfgSysDebugInfo = -1;
	 CfgSysDebugWarn = -1;
#endif
	atcmd_wifi_restore_from_flash();
	atcmd_lwip_restore_from_flash();
	vTaskDelay(20); //rtw_msleep_os(20);
	uart_atcmd_main();
	at_printf("\r\nAT COMMAND READY");
	if(atcmd_lwip_is_tt_mode())
		at_printf(STR_END_OF_ATDATA_RET);
	else
		at_printf(STR_END_OF_ATCMD_RET);
	_AT_DBG_MSG(AT_FLAG_COMMON, AT_DBG_ALWAYS, STR_END_OF_ATCMD_RET); 
	vTaskDelete(NULL);
}

int uart_atcmd_module_init(void){
#if CONFIG_DEBUG_LOG > 3
	printf("Time at start %d ms.\n", xTaskGetTickCount());
#endif
	if(xTaskCreate(uart_atcmd_thread, ((const char*)"uart_atcmd_thread"), 1024, NULL, tskIDLE_PRIORITY + 1 , NULL) != pdPASS) // tskIDLE_PRIORITY + 1
		printf("\n\r%s xTaskCreate(uart_atcmd_thread) failed", __FUNCTION__);
	return 0;
}

void example_uart_atcmd(void)
{
	//if(xTaskCreate(uart_atcmd_thread, ((const char*)"uart_atcmd_thread"), 1024, NULL, tskIDLE_PRIORITY + 1 , NULL) != pdPASS)
	//	printf("\n\r%s xTaskCreate(uart_atcmd_thread) failed", __FUNCTION__);
	p_wlan_init_done_callback = uart_atcmd_module_init;
	return;
}
#endif
