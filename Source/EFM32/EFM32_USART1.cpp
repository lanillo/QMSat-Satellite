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
	m_Baudrate = 4*((24000000/(8*p_Baudrate)) - 1);
	USART1->CLKDIV = (m_Baudrate << 6); // 204 will give 38400 baud rate (using 8-bit oversampling with 24MHz peripheral clock)

	m_StopBit = p_StopBit;
	m_Parity = p_Parity;

	USART1->FRAME = (m_StopBit << 12) | (m_Parity << 8) | USART_FRAME_DATABITS_EIGHT; //1 STOP, no parity, 8bits data

}

/****************************************************/
void EFM32_USART1::sendSerial(char* p_TxBuffer)
{
	// Print test string
	for(unsigned short index = 0; index < strlen(p_TxBuffer); index++)
	{
		while( !(USART1->STATUS & (1 << 6)) ); // wait for TX buffer to empty
		USART1->TXDATA = *p_TxBuffer++;       // print each character of the test string
		USART1->IFC = USART_IFC_TXC;
	}
}

/****************************************************/
void EFM32_USART1::receiveSerial()
{

}

/****************************************************/
void initUSART1()
{
	GPIO->P[3].MODEL = GPIO_P_MODEL_MODE1_INPUT | GPIO_P_MODEL_MODE0_PUSHPULL;  // Configure PD0 as digital output and PD1 as input
	GPIO->P[3].DOUTSET = (1 << 0); // Initialize PD0 high since UART TX idles high (otherwise glitches can occur)

	NVIC_EnableIRQ(USART1_RX_IRQn);  //Interupt USART1 Receive vector
	NVIC_EnableIRQ(USART1_TX_IRQn);  //Interupt USART1 Transmit vector

	USART1->CTRL = USART_CTRL_MSBF | USART_CTRL_OVS_X8 | USART_CTRL_LOOPBK | USART_CTRL_SYNC_DEFAULT | USART_CTRL_CLKPOL_IDLEHIGH; //MSB first, 8-bits oversampling, Async
	USART1->ROUTE = USART_ROUTE_LOCATION_LOC1; // Enable TX and RX pins, use location #1 (UART TX and RX located at PD0 and PD1)
	USART1->IEN = USART_IEN_RXDATAV;
	USART1->IFC = _USART_IFC_MASK; // clear all USART interrupt flags
	USART1->CMD = USART_CMD_RXEN | USART_CMD_TXEN | USART_CMD_CLEARRX | USART_CMD_CLEARTX; // Clear RX/TX buffers and shif regs, Enable Transmitter and Receiver
}

/****************************************************/
void USART1_RX_IRQHandler(void)
{
	//USART1->IFC = USART_IFC_RXFULL_DEFAULT;
	char a = USART1->RXDATA;
	int b = 0;
}

/****************************************************/
void USART1_TX_IRQHandler(void)
{

}

