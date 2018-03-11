/*
 * EFM32_USART1.cpp
 *
 *  Created on: 2018-02-18
 *      Author: Guillaume
 */

#include "EFM32_USART1.hpp"
#include <string.h>

callback callbackUSART1Tx;
callback callbackUSART1Rx;
void* USART1Instance;

/****************************************************/
EFM32_USART1::EFM32_USART1(int p_Baudrate, bool p_StopBit, bool p_Parity)
{
	m_Baudrate = 4*((24000000/(8*p_Baudrate)) - 1);
	USART1->CLKDIV = (152 << 6); // 204 will give 38400 baud rate (using 8-bit oversampling with 24MHz peripheral clock)

	m_StopBit = p_StopBit;
	m_Parity = p_Parity;

	*m_TxBuffer = null;
	m_TxBufferSize = null;

	USART1->FRAME = (m_StopBit << 12) | (m_Parity << 8) | USART_FRAME_DATABITS_EIGHT; //1 STOP, no parity, 8bits data

}

/****************************************************/
void EFM32_USART1::sendSerial(char* p_TxBuffer)
{
	m_TxBufferSize = strlen(p_TxBuffer);
	m_TxBuffer = p_TxBuffer;
	USART1->TXDATA = *m_TxBuffer++;
}

/****************************************************/
void EFM32_USART1::receiveSerial()
{

}

/****************************************************/
void EFM32_USART1::callbackForSerialTransmit(void* p_USART1Instance)
{
	if (p_USART1Instance != null)
	{
		EFM32_USART1* usart = reinterpret_cast<EFM32_USART1*>(p_USART1Instance);
		unsigned short bufferSize = strlen(usart->m_TxBuffer);
		if (bufferSize != null)
		{
			USART1->TXDATA = *(usart->m_TxBuffer);
			usart->incrementTxBuffer();
		}
	}
}

void EFM32_USART1::incrementTxBuffer()
{
	m_TxBuffer++;
}

/****************************************************/
void EFM32_USART1::callbackForSerialReceive(void* p_USART1Instance)
{
	if (p_USART1Instance != null)
	{
		EFM32_USART1* usart = reinterpret_cast<EFM32_USART1*>(p_USART1Instance);
	}
}

/****************************************************/
void initUSART1()
{
	GPIO->P[3].MODEL = GPIO_P_MODEL_MODE1_INPUT | GPIO_P_MODEL_MODE0_PUSHPULL;  // Configure PD0 as digital output and PD1 as input
	GPIO->P[3].DOUTSET = (1 << 0); // Initialize PD0 high since UART TX idles high (otherwise glitches can occur)

	NVIC_EnableIRQ(USART1_RX_IRQn);  //Interupt USART1 Receive vector
	NVIC_EnableIRQ(USART1_TX_IRQn);  //Interupt USART1 Transmit vector

	USART1->CMD = USART_CMD_CLEARRX | USART_CMD_CLEARTX | USART_CMD_TXEN | USART_CMD_RXEN; // Enable Transmitter and Receiver, Clear RX/TX buffers and shif regs
	USART1->CTRL |= USART_CTRL_LOOPBK;
	//USART1->CTRL = USART_CTRL_MSBF | USART_CTRL_OVS_X16 | USART_CTRL_LOOPBK | USART_CTRL_SYNC_DEFAULT | USART_CTRL_CLKPOL_IDLEHIGH; //MSB first, 8-bits oversampling, Async
	USART1->ROUTE = 0x103;//USART_ROUTE_LOCATION_LOC1; // Enable TX and RX pins, use location #1 (UART TX and RX located at PD0 and PD1)
	USART1->IEN = USART_IEN_RXDATAV | USART_IEN_TXC;
	USART1->IFC = 0x1FF9;//_USART_IFC_MASK; // clear all USART interrupt flags
}

/****************************************************/
void USART1_RX_IRQHandler(void)
{
	callbackUSART1Rx(USART1Instance);
	char a = (char)USART1->RXDATA;
	//USART1->TXDATA = a;
	int b = 0;
}

/****************************************************/
void USART1_TX_IRQHandler(void)
{
	callbackUSART1Tx(USART1Instance);
	USART1->IFC |= USART_IFC_TXC;
	int b = 0;
}

/****************************************************/
void callbackUSART1Init(callback p_callbackTx, callback p_callbackRx, void* p_USART1Instance)
{
	callbackUSART1Tx = p_callbackTx;
	callbackUSART1Rx = p_callbackRx;
	USART1Instance = p_USART1Instance;
}


