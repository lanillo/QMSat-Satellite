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
	m_Baudrate = 4*((24000000/(16*p_Baudrate)) - 1);
	USART1->CLKDIV = (m_Baudrate << 6); // 155 will give 9600 baud rate (using 16-bit oversampling with 24MHz peripheral clock)

	m_StopBit = p_StopBit;
	m_Parity = p_Parity;

	m_TxBufferSize = 0;
	m_TxBufferIndex = 0;
	m_IsSending = false;
	m_NewSwitchState = false;

	for(unsigned short index = 0; index < TX_BUFFER_SIZE_USART1; index++)
	{
		m_TxBuffer[index] = (char)0;
	}

	for(unsigned short index = 0; index < RX_BUFFER_SIZE_USART1; index++)
	{
		m_RxBuffer[index] = (char)0;
	}

	USART1->FRAME = (m_StopBit << 12) | (m_Parity << 8) | USART_FRAME_DATABITS_EIGHT; //1 STOP, no parity, 8bits data
}

/****************************************************/
char EFM32_USART1::receiveSerial()
{
	if(USART1->STATUS & (1 << 7))  // if RX buffer contains valid data
	{
		return (char)USART1->RXDATA;
	}
	return '/0';
}

/****************************************************/
bool EFM32_USART1::isSending()
{
	return m_IsSending;
}

/****************************************************/
void EFM32_USART1::setSending(bool p_Sending)
{
	m_IsSending = p_Sending;
}

/****************************************************/
void EFM32_USART1::callbackForSerialReceive(void* p_USART1Instance)
{
	if (p_USART1Instance != null)
	{
		EFM32_USART1* usart = reinterpret_cast<EFM32_USART1*>(p_USART1Instance);
		char RxData = usart->receiveSerial();
		if(RxData == '%')
		{
			usart->m_IsReceiving = true;
			usart->m_RxBufferIndex = 0;
		}
		else if(usart->m_IsReceiving)
		{
			if(RxData != '&')
			{
				usart->m_RxBuffer[usart->m_RxBufferIndex] = RxData;
				usart->m_RxBufferIndex++;
			}
			else
			{
				usart->m_IsReceiving = false;
				if(usart->m_RxBuffer[0] == 'O')
				{
					usart->setSwitchForAlim(usart->m_RxBuffer[1]);
					usart->setSwitchState(true);
				}
			}
		}
	}
}

/****************************************************/
void EFM32_USART1::setSwitchForAlim(unsigned short p_SwitchState)
{
	m_SwitchState = p_SwitchState;
}

/****************************************************/
unsigned short EFM32_USART1::getSwitchForAlim()
{
	return m_SwitchState;
}

/****************************************************/
bool EFM32_USART1::getSwitchState()
{
	return m_NewSwitchState;
}

/****************************************************/
void EFM32_USART1::setSwitchState(bool p_NewSwitchState)
{
	m_NewSwitchState = p_NewSwitchState;
}

/****************************************************/
void USART1_RX_IRQHandler(void)
{
	callbackUSART1Rx(USART1Instance);
	USART1->IFC |= USART_IFC_RXFULL;
}

/****************************************************/
void EFM32_USART1::sendSerial(char* p_TxBuffer, unsigned short p_TxBufferSize)
{
	m_TxBufferSize = p_TxBufferSize;
	setSending(true);
	for(unsigned short index = 0; index < p_TxBufferSize; index++)
	{
		m_TxBuffer[index] = (char)*p_TxBuffer;
		p_TxBuffer++;
	}
	m_TxBufferIndex = 1;
	if(USART1->STATUS & (1 << 6)) // check if TX buffer is empty
	{
		USART1->TXDATA = m_TxBuffer[0];
	}
	//while(isSending());
}

/****************************************************/
void EFM32_USART1::callbackForSerialTransmit(void* p_USART1Instance)
{
	if (p_USART1Instance != null)
	{
		EFM32_USART1* usart = reinterpret_cast<EFM32_USART1*>(p_USART1Instance);
		if(usart->m_TxBufferSize > usart->m_TxBufferIndex)
		{
			if(USART1->STATUS & (1 << 6)) // check if TX buffer is empty
			{
				USART1->TXDATA = usart->m_TxBuffer[usart->m_TxBufferIndex];
				usart->m_TxBufferIndex++;
			}
		}

		//Resets the Tx Buffer
		else
		{
			for(unsigned short index = 0; index < TX_BUFFER_SIZE_USART1; index++)
			{
				usart->m_TxBuffer[index] = (char)0;
			}
			usart->setSending(false);
		}
	}
}

/****************************************************/
void USART1_TX_IRQHandler(void)
{
	callbackUSART1Tx(USART1Instance);
	USART1->IFC |= USART_IFC_TXC;
}

/****************************************************/
void initUSART1()
{
	GPIO->P[3].MODEL = GPIO_P_MODEL_MODE1_INPUT | GPIO_P_MODEL_MODE0_PUSHPULL;  // Configure PD0 as digital output and PD1 as input
	GPIO->P[3].DOUTSET = (0 << 0); // Initialize PD0 high since UART TX idles high (otherwise glitches can occur)
	NVIC_EnableIRQ(USART1_RX_IRQn);  //Interupt USART1 Receive vector
	NVIC_EnableIRQ(USART1_TX_IRQn);  //Interupt USART1 Transmit vector

	USART1->CMD |= USART_CMD_CLEARRX | USART_CMD_CLEARTX | USART_CMD_TXEN | USART_CMD_RXEN; // Enable Transmitter and Receiver, Clear RX/TX buffers and shif regs
	USART1->CTRL |= (1 << 13) | (1 << 14) | (0 << 10) | USART_CTRL_OVS_X16 | USART_CTRL_SYNC_DEFAULT | USART_CTRL_CLKPOL_IDLELOW; //MSB first, 8-bits oversampling, Async
	USART1->IFC |= 0x1FF9;//_USART_IFC_MASK; // clear all USART interrupt flags
	USART1->ROUTE |= 0x103;//USART_ROUTE_LOCATION_LOC1; // Enable TX and RX pins, use location #1 (UART TX and RX located at PD0 and PD1)
	USART1->IEN |= USART_IEN_RXDATAV | USART_IEN_TXC;
}

/****************************************************/
void callbackUSART1Init(callback p_callbackTx, callback p_callbackRx, void* p_USART1Instance)
{
	callbackUSART1Tx = p_callbackTx;
	callbackUSART1Rx = p_callbackRx;
	USART1Instance = p_USART1Instance;
}


