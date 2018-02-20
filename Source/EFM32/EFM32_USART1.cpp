/*
 * EFM32_USART1.cpp
 *
 *  Created on: 2018-02-18
 *      Author: Guillaume
 */

#include "EFM32_USART1.hpp"
#include <string.h>

/****************************************************/
EFM32_USART1::EFM32_USART1(int p_Baudrate, bool p_StopBit, bool p_Parity)
{
	m_Baudrate = p_Baudrate;
	m_StopBit = p_StopBit;
	m_Parity = p_Parity;
}

/****************************************************/
void EFM32_USART1::sendSerial(char* p_TxBuffer)
{
	// Print test string
	for(unsigned short index = 0; index < strlen(p_TxBuffer); index++)
	{
		while( !(USART1->STATUS & (1 << 6)) ); // wait for TX buffer to empty
		USART1->TXDATA = *p_TxBuffer++;       // print each character of the test string
	}
}

/****************************************************/
void EFM32_USART1::receiveSerial()
{

}

/****************************************************/
void initUSART1()
{
	GPIO->P[3].MODEL = (1 << 4) | (4 << 0);  // Configure PD0 as digital output and PD1 as input
	GPIO->P[3].DOUTSET = (1 << 0); // Initialize PD0 high since UART TX idles high (otherwise glitches can occur)
	// Use default value for USART1->CTRL: asynch mode, x16 OVS, lsb first, CLK idle low
	// Default frame options: 8-none-1-none
	USART1->CLKDIV = (152 << 6);                               // 152 will give 38400 baud rate (using 16-bit oversampling with 24MHz peripheral clock)
	USART1->CMD = (1 << 11) | (1 << 10) | (1 << 2) | (1 << 0); // Clear RX/TX buffers and shif regs, Enable Transmitter and Receiver
	USART1->IFC = 0x1FF9;                                      // clear all USART interrupt flags
	USART1->ROUTE = 0x103;                                     // Enable TX and RX pins, use location #1 (UART TX and RX located at PD0 and PD1, see EFM32GG990 datasheet for details)
}
