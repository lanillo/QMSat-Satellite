/*
 * EFM32_SPI.cpp
 *
 *  Created on: September 10, 2018
 *   Authors: Luis Anillo
 * 			  Guillaume Beaupré.
 *
 *   \brief SPI Class Definition
 */

#include "EFM32_SPI.hpp"

/****************************************************/
EFM32_SPI::EFM32_SPI(int p_Baudrate, bool p_MSBFirst)
{
	m_Baudrate = 256*((24000000/(2*p_Baudrate))-1);
	m_MSBFirst = p_MSBFirst;
	USART0->CLKDIV = (m_Baudrate << 6); // 319744 will give 9600 baud rate (24MHz peripheral clock)
}

/****************************************************/
/*initialization*/
void initSPI()
{
	GPIO->P[4].MODEL = GPIO_P_MODEL_MODE6_INPUT | GPIO_P_MODEL_MODE7_PUSHPULL | GPIO_P_MODEL_MODE4_PUSHPULL | GPIO_P_MODEL_MODE5_PUSHPULL;
	GPIO->P[4].DOUTSET = (0 << 0) | (0 << 4); // Initialize PE7 & PE4 high since UART TX idles high (otherwise glitches can occur)

	USART0->CMD |= USART_CMD_CLEARRX | USART_CMD_CLEARTX | USART_CMD_TXEN | USART_CMD_RXEN; // Enable Transmitter and Receiver, Clear RX/TX buffers and shif regs
	USART0->CMD |= USART_CMD_MASTEREN;
	USART0->CTRL |= (1 << _USART_CTRL_SYNC_SHIFT) || (0 << _USART_CTRL_CLKPOL_SHIFT) || (0 << _USART_CTRL_CLKPOL_SHIFT) ||
					(0 << _USART_CTRL_CLKPHA_SHIFT) || USART_CTRL_AUTOCS || USART_CTRL_BIT8DV;
	USART0->IFC |= 0x1FF9;//_USART_IFC_MASK; // clear all USART interrupt flags
	USART0->ROUTE = _USART_ROUTE_LOCATION_LOC1;//USART_ROUTE_LOCATION_LOC1; // Enable TX and RX pins, use location #1 ( TX->PE7, RX->PE6, CLK->PE5, CS->PE4)
}

