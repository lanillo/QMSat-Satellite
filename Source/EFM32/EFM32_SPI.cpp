/*
 * EFM32_SPI.cpp
 *
 *  Created on: 2018-09-10
 *      Author: guill
 */

#include "EFM32_SPI.hpp"

/****************************************************/
/*initialization*/
void initSPI()
{
	GPIO->P[4].MODEL = GPIO_P_MODEL_MODE6_INPUT | GPIO_P_MODEL_MODE7_PUSHPULL;  // Configure PD0 as digital output and PD1 as input
	GPIO->P[4].DOUTSET = (0 << 0); // Initialize PD0 high since UART TX idles high (otherwise glitches can occur)

	USART0->CMD |= USART_CMD_CLEARRX | USART_CMD_CLEARTX | USART_CMD_TXEN | USART_CMD_RXEN; // Enable Transmitter and Receiver, Clear RX/TX buffers and shif regs
	USART0->CMD |= USART_CMD_MASTEREN;
	USART0->CTRL |= (1 << _USART_CTRL_SYNC_SHIFT);
	USART0->IFC |= 0x1FF9;//_USART_IFC_MASK; // clear all USART interrupt flags
	USART0->ROUTE = _USART_ROUTE_LOCATION_LOC1;//USART_ROUTE_LOCATION_LOC1; // Enable TX and RX pins, use location #1 ( TX->PE7, RX->PE6, CLK->PE5, CS->PE4)
}

