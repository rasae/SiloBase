/*
 * system_init.h
 *
 *  Created on: Apr 13, 2019
 *      Author: Rafed
 */

#ifndef SRC_SYSTEM_INIT_H_
#define SRC_SYSTEM_INIT_H_


#include "xparameters.h"
#include "xgpio.h"
#include "xil_printf.h"
#include "stdio.h"
#include "xstatus.h"
#include "xuartlite.h"
#include "xuartlite_l.h"
#include "sleep.h"

//defining drivers for Gpio devices
XGpio Gpio_Password;
XGpio Gpio_DisplayMutex;
XGpio Gpio_SSEG;

//defining Uart Driver
XUartLite uart;

//GPIO defines for Gpio_Password  - 2 channels
#define GPIO_PASS_BASE_ADDR XPAR_GPIO_0_BASEADDR
#define GPIO_PASS_DEVICE_ID XPAR_CORE1PASS_CONFIRM_INPUT_DEVICE_ID
#define PASS_CONFIRM_CHANNEL 1
#define PASS_INPUT_CHANNEL 2

//GPIO defines for SSEGMENTGPIO  - 2 channels
#define SSEG_GPIO_BASEADDR XPAR_CORE1_SSEG_ANODE_BASEADDR
#define SSEG_GPIO_DEVICE_ID XPAR_CORE1_SSEG_ANODE_DEVICE_ID
#define SSEG_CHANNEL 1
#define ANODE_CHANNEL 2

//GPIO defines for MutexGPIO  - 2 channels
#define MUTEX_GPIO_BASEADDR XPAR_CORE1_MUTEXO_MUTEXI_BASEADDR
#define MUTEX_GPIO_DEVICE_ID XPAR_CORE1_MUTEXO_MUTEXI_DEVICE_ID
#define MUTEX_OUTPUT_CHANNEL 1
#define MUTEX_INPUT_CHANNEL 2


//UART defines - DeviceID and BaseAddress
#define UART_BASEADDR XPAR_CORE1_UARTLITE_0_BASEADDR
#define UART_DEVICE_ID      XPAR_CORE1_UARTLITE_0_DEVICE_ID



/*-------------------FUNCTION PROTOTYPES-------------------------------*/

int init_modules(void);



#endif /* SRC_SYSTEM_INIT_H_ */
