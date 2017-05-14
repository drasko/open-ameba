/*
 *  Routines to access hardware
 *
 *  Copyright (c) 2013 Realtek Semiconductor Corp.
 *
 *  This module is a confidential and proprietary property of RealTek and
 *  possession or use of this module requires written permission of RealTek.
 */

#include "device.h"
#include "gpio_api.h"   // mbed
#include "main.h"

#define GPIO_LED_PIN       PC_5

/* ---------------------------------------------------
 *  Customized Signature (Image Name)
 * ---------------------------------------------------*/
#include "section_config.h"
SECTION(".custom.validate.rodata")
const unsigned char cus_sig[32] = "Blinky";

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
//int main_app(IN u16 argc, IN u8 *argv[])
void main(void)
{
    gpio_t gpio_led;
    gpio_t gpio_btn;

    // Init LED control pin
    gpio_init(&gpio_led, GPIO_LED_PIN);
    gpio_dir(&gpio_led, PIN_OUTPUT);    // Direction: Output
    gpio_mode(&gpio_led, PullNone);     // No pull

    while(1){
		// turn on LED
        gpio_write(&gpio_led, 1);

		printf("Hello World\n");
		HalDelayUs(100000);

		// turn off LED
        gpio_write(&gpio_led, 0);
    }
}

