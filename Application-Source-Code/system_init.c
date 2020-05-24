/*
 * system_init.c
 *
 *  Created on: Apr 13, 2019
 *      Author: Rafed
 */
#include "system_init.h"

int init_modules(void){

		int status;

		//initialize GPIO_PASS
		status = XGpio_Initialize(&Gpio_Password, GPIO_PASS_DEVICE_ID);
		if (status != XST_SUCCESS) return status;

		//initialize SSEGMENT
		status = XGpio_Initialize(&Gpio_SSEG, SSEG_GPIO_DEVICE_ID);
		if (status != XST_SUCCESS) return status;

		//initialize Mutex GPIO
		status = XGpio_Initialize(&Gpio_DisplayMutex, MUTEX_GPIO_DEVICE_ID);
		if (status != XST_SUCCESS) return status;

		//initialize UART
		status = XUartLite_Initialize(&uart, UART_DEVICE_ID);
		if (status != XST_SUCCESS) return status;

		//GPIO Pass Data Direction Setup
		XGpio_SetDataDirection(&Gpio_Password, PASS_CONFIRM_CHANNEL, 1);
		XGpio_SetDataDirection(&Gpio_Password, PASS_INPUT_CHANNEL, 0xFF);

		//GPIO SSEGMENT Data Direction Setup
		XGpio_SetDataDirection(&Gpio_SSEG, SSEG_CHANNEL, 0x00);
		XGpio_SetDataDirection(&Gpio_SSEG, ANODE_CHANNEL, 0x00);

		//GPIO MUTEX Data Direction Setup
		XGpio_SetDataDirection(&Gpio_DisplayMutex, MUTEX_OUTPUT_CHANNEL, 0);
		XGpio_SetDataDirection(&Gpio_DisplayMutex, MUTEX_INPUT_CHANNEL, 1);


		return XST_SUCCESS;

}//end init_modules

