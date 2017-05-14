#include "FreeRTOS.h"
#include "task.h"
#include "main.h"

#include <lwip/sockets.h>
#if LWIP_SOCKET
#include <lwip/raw.h>
#include <lwip/icmp.h>
#include <lwip/inet_chksum.h>
#include <platform/platform_stdlib.h>

//#define PING_IP		"192.168.0.1"
#define PING_IP		"192.168.159.1"
#define PING_TO		1000
#define PING_ID		0xABCD
#define BUF_SIZE	10000
#define STACKSIZE	1024

static unsigned short ping_seq = 0;
static int infinite_loop, ping_count, data_size, ping_interval, ping_call;
static char ping_ip[16];

static void generate_ping_echo(unsigned char *buf, int size)
{
	int i;
	struct icmp_echo_hdr *pecho;

	for(i = 0; i < size; i ++) {
		buf[sizeof(struct icmp_echo_hdr) + i] = (unsigned char) i;
	}

	pecho = (struct icmp_echo_hdr *) buf;
	ICMPH_TYPE_SET(pecho, ICMP_ECHO);
	ICMPH_CODE_SET(pecho, 0);
	pecho->chksum = 0;
	pecho->id = PING_ID;
	pecho->seqno = htons(++ ping_seq);

	//Checksum includes icmp header and data. Need to calculate after fill up icmp header
	pecho->chksum = inet_chksum(pecho, sizeof(struct icmp_echo_hdr) + size);
}

void ping_test(void *param)
//void ping_test()
{
	int i, ping_socket;
	int pint_timeout = PING_TO;
	struct sockaddr_in to_addr, from_addr;
	int from_addr_len = sizeof(struct sockaddr);
	int ping_size, reply_size;
	unsigned char *ping_buf, *reply_buf;
	unsigned int ping_time, reply_time;
	struct ip_hdr *iphdr;
	struct icmp_echo_hdr *pecho;

	if(data_size > BUF_SIZE){
	    printf("[ERROR] %s: data size error, can't exceed %d\n",__func__,BUF_SIZE);
	    return;
	}

	//Ping size = icmp header(8 bytes) + data size
	ping_size = sizeof(struct icmp_echo_hdr) + data_size;

	ping_buf = pvPortMalloc(ping_size);
    if(NULL == ping_buf){
        printf("[ERROR] %s: Allocate ping_buf failed\n",__func__);
        return;
    }

    reply_buf = pvPortMalloc(ping_size);
    if(NULL == reply_buf){
        vPortFree(ping_buf);
        printf("[ERROR] %s: Allocate reply_buf failed\n",__func__);
        return;
    }

	printf("[%s] PING %s %d(%d) bytes of data\n", __FUNCTION__, ping_ip, data_size, sizeof(struct ip_hdr) + sizeof(struct icmp_echo_hdr) + data_size);

	for(i = 0; (i < ping_count) || (infinite_loop == 1); i ++) {
		ping_socket = socket(AF_INET, SOCK_RAW, IP_PROTO_ICMP);
#ifdef CONFIG_LWIP_1_5_0
		struct timeval timeout;
		timeout.tv_sec = pint_timeout / 1000;
		timeout.tv_usec = pint_timeout % 1000 * 1000;
		setsockopt(ping_socket, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
#else
		setsockopt(ping_socket, SOL_SOCKET, SO_RCVTIMEO, &pint_timeout, sizeof(pint_timeout));
#endif
		to_addr.sin_len = sizeof(to_addr);
		to_addr.sin_family = AF_INET;
		to_addr.sin_addr.s_addr = inet_addr(ping_ip);

		generate_ping_echo(ping_buf, data_size);
		sendto(ping_socket, ping_buf, ping_size, 0, (struct sockaddr *) &to_addr, sizeof(to_addr));
		
		ping_time = xTaskGetTickCount();
		if((reply_size = recvfrom(ping_socket, reply_buf, ping_size, 0, (struct sockaddr *) &from_addr, (socklen_t *) &from_addr_len))
			>= (int)(sizeof(struct ip_hdr) + sizeof(struct icmp_echo_hdr))) {

			reply_time = xTaskGetTickCount();
			iphdr = (struct ip_hdr *)reply_buf;
			pecho = (struct icmp_echo_hdr *)(reply_buf + (IPH_HL(iphdr) * 4));

			if((pecho->id == PING_ID) && (pecho->seqno == htons(ping_seq))) {
				printf("[%s] %d bytes from %s: icmp_seq=%d time=%d ms\n", __FUNCTION__, reply_size - sizeof(struct ip_hdr), inet_ntoa(from_addr.sin_addr), htons(pecho->seqno), (reply_time - ping_time) * portTICK_RATE_MS);
			}
		}
		else
			printf("[%s] Request timeout for icmp_seq %d\n", __FUNCTION__, ping_seq);

		close(ping_socket);
		vTaskDelay(ping_interval * configTICK_RATE_HZ);
	}

	vPortFree(ping_buf);
    vPortFree(reply_buf);

	if(!ping_call)
		vTaskDelete(NULL);
}

void do_ping_call(char *ip, int loop, int count)
{
	ping_call = 1;
	ping_seq = 0;
	data_size = 120;
	ping_interval = 1;
	infinite_loop = loop;
	ping_count = count;
	strcpy(ping_ip, ip);
	ping_test(NULL);
}

void cmd_ping(int argc, char **argv)
{
    int argv_count = 2;

    if(argc < 2)
        goto Exit;

    //ping cmd default value
    infinite_loop = 0;
    ping_count    = 4;
    data_size     = 32;
    ping_interval = 1;
    ping_call     = 1;
    ping_seq      = 0;

    while(argv_count<=argc){
        //first operation
        if(argv_count == 2){
            memset(ping_ip, 0, sizeof(ping_ip));
            strncpy(ping_ip, argv[argv_count-1], (strlen(argv[argv_count-1])>16)?16:strlen(argv[argv_count-1]));
            argv_count++;
        }
        else{
            if(strcmp(argv[argv_count-1], "-t") == 0){
                infinite_loop = 1;
                argv_count++;
            }
            else if(strcmp(argv[argv_count-1], "-n") == 0){
                if(argc < (argv_count+1))
                    goto Exit;
                ping_count = (int) atoi(argv[argv_count]);
                argv_count+=2;
            }
            else if(strcmp(argv[argv_count-1], "-l") == 0){
                if(argc < (argv_count+1))
                    goto Exit;
                data_size = (int) atoi(argv[argv_count]);
                argv_count+=2;
            }
            else{
                goto Exit;
            }
        }
    }

    ping_test(NULL);

    return;

Exit:
    printf("[ATWI] Usage: ATWI=[host],[options]\n");
    printf("\t-t\tPing the specified host until stopped\n");
    printf("\t-n\t#   Number of echo requests to send (default 4 times)\n");
    printf("\t-l\t#   Send buffer size (default 32 bytes)\n");
    printf("\tExample:\n");
    printf("\t\tATWI=192.168.1.2,-n,100,-l,5000\n");
    return;
}

void do_ping_test(char *ip, int size, int count, int interval)
{
	if((sizeof(struct icmp_echo_hdr) + size) > BUF_SIZE) {
		printf("%s BUF_SIZE(%d) is too small\n", __FUNCTION__, BUF_SIZE);
		return;
	}

	if(ip == NULL)
		strcpy(ping_ip, PING_IP);
	else
		strcpy(ping_ip, ip);

	ping_call = 0;
	ping_seq = 0;
	data_size = size;
	ping_interval = interval;

	if(count == 0) {
		infinite_loop = 1;
		ping_count = 0;
	}
	else {
		infinite_loop = 0;
		ping_count = count;
	}

	if(xTaskCreate(ping_test, ((const signed char*)"ping_test"), STACKSIZE, NULL, tskIDLE_PRIORITY + 1, NULL) != pdPASS)
		printf("%s xTaskCreate failed\n", __FUNCTION__);
}
#endif // LWIP_SOCKET
