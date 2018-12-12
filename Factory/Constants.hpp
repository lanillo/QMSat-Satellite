/*
 * Constants.hpp
 *
 *  Created on: Feb 13, 2018
 *      Author: lfani
 */

#ifndef FACTORY_CONSTANTS_HPP_
#define FACTORY_CONSTANTS_HPP_

#include "bspconfig.h"

#define null (0U)

//Testing Purposes
#define DEBUG_BREAK 			__asm__("BKPT #0"); //For debug
#define LED0_PORT				gpioPortE
#define LED1_PORT				gpioPortE
#define LED0_PIN				2
#define LED2_PIN				3

//Time defines
#define TIME_1_MICROSECOND 		(1U)
#define TIME_10_MICROSECONDS 	(10U)
#define TIME_100_MICROSECONDS 	(100U)
#define TIME_1_MILLISECOND 		(1000U)
#define TIME_500_MILLISECONDS 	(500000U)
#define TIME_1_SECOND 			(1000000U)
#define TIME_3_SECOND 			(3000000U)

//Buffers
#define TX_BUFFER_SIZE_USART1 	(50U)
#define RX_BUFFER_SIZE_USART1 	(50U)
#define TX_BUFFER_SIZE_UART0 	(50U)
#define RX_BUFFER_SIZE_UART0 	(50U)

//I2C
#define TEMP_SENSOR_ADDRESS		0x18 << 1
#define I2C_CMD_ARRAY_SIZE      1
#define I2C_DATA_ARRAY_SIZE     10
#define I2C_ERROR_CODE			0xFF
#define I2C_BUS_FREQUENCY		200000

//PWM
#define PWM_DUTY_CYCLE			5

#endif /* FACTORY_CONSTANTS_HPP_ */
