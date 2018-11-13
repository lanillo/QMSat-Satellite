/*
 * EFM32_UART0.cpp
 *
 *  Created on: 2018-11-13
 *      Author: Guillaume Beaupré
 */

#include <EFM32_USART0.hpp>
#include <string.h>

callback callbackUSART0Tx;
callback callbackUSART0Rx;
void* USART0Instance;

/****************************************************/
EFM32_USART0::EFM32_USART0(int p_Baudrate, bool p_StopBit, bool p_Parity)
{
	m_Baudrate = 4*((24000000/(16*p_Baudrate)) - 1);
	USART0->CLKDIV = (m_Baudrate << 6); // 155 will give 9600 baud rate (using 16-bit oversampling with 24MHz peripheral clock)

	m_StopBit = p_StopBit;
	m_Parity = p_Parity;

	m_TxBufferSize = 0;
	m_TxBufferIndex = 0;
	m_IsSending = false;

	for(unsigned short index = 0; index < TX_BUFFER_SIZE_USART0; index++)
	{
		m_TxBuffer[index] = (char)0;
	}

	for(unsigned short index = 0; index < RX_BUFFER_SIZE_USART0; index++)
	{
		m_RxBuffer[index] = (char)0;
	}

	USART0->FRAME = (m_StopBit << 12) | (m_Parity << 8) | USART_FRAME_DATABITS_EIGHT; //1 STOP, no parity, 8bits data
}

/****************************************************/
char EFM32_USART0::receiveSerial()
{
	if(USART0->STATUS & (1 << 7))  // if RX buffer contains valid data
	{
		return (char)USART0->RXDATA;
	}
	return '/0';
}

/****************************************************/
bool EFM32_USART0::isSending()
{
	return m_IsSending;
}

/****************************************************/
void EFM32_USART0::setSending(bool p_Sending)
{
	m_IsSending = p_Sending;
}

/****************************************************/
void EFM32_USART0::callbackForSerialReceive(void* p_USART0Instance)
{
	if (p_USART0Instance != null)
	{
		EFM32_USART0* usart = reinterpret_cast<EFM32_USART0*>(p_USART0Instance);
		//uart->m_RxBuffer[0] = uart->receiveSerial();
		char a = (char)USART0->RXDATA;
		usart->sendSerial(&a, 1);
	}
}

/****************************************************/
void USART0_RX_IRQHandler(void)
{
	callbackUSART0Rx(USART0Instance);
	USART0->IFC |= USART_IFC_RXFULL;
}

/****************************************************/
void EFM32_USART0::sendSerial(char* p_TxBuffer, unsigned short p_TxBufferSize)
{
	m_TxBufferSize = p_TxBufferSize;
	setSending(true);
	for(unsigned short index = 0; index < p_TxBufferSize; index++)
	{
		m_TxBuffer[index] = (char)*p_TxBuffer;
		p_TxBuffer++;
	}
	m_TxBufferIndex = 1;
	if(USART0->STATUS & (1 << 6)) // check if TX buffer is empty
	{
		USART0->TXDATA = m_TxBuffer[0];
	}
	while(isSending());
}

/****************************************************/
void EFM32_USART0::callbackForSerialTransmit(void* p_USART0Instance)
{
	if (p_USART0Instance != null)
	{
		EFM32_USART0* usart = reinterpret_cast<EFM32_USART0*>(p_USART0Instance);
		if(usart->m_TxBufferSize > usart->m_TxBufferIndex)
		{
			if(USART0->STATUS & (1 << 6)) // check if TX buffer is empty
			{
				USART0->TXDATA = usart->m_TxBuffer[usart->m_TxBufferIndex];
				usart->m_TxBufferIndex++;
			}
		}

		//Resets the Tx Buffer
		else
		{
			for(unsigned short index = 0; index < TX_BUFFER_SIZE_USART0; index++)
			{
				usart->m_TxBuffer[index] = (char)0;
			}
			usart->setSending(false);
		}
	}
}

/****************************************************/
void USART0_TX_IRQHandler(void)
{
	callbackUSART0Tx(USART0Instance);
	USART0->IFC |= USART_IFC_TXC;
}

/****************************************************/
void initUSART0()
{
	GPIO->P[2].MODEL = GPIO_P_MODEL_MODE1_INPUT | GPIO_P_MODEL_MODE0_PUSHPULL;  // Configure PC0 as digital output and PC1 as input
	GPIO->P[2].DOUTSET = (0 << 0); // Initialize PD0 high since UART TX idles high (otherwise glitches can occur)
	NVIC_EnableIRQ(USART0_RX_IRQn);  //Interupt USART0 Receive vector
	NVIC_EnableIRQ(USART0_TX_IRQn);  //Interupt USART0 Transmit vector

	USART0->CMD |= USART_CMD_CLEARRX | USART_CMD_CLEARTX | USART_CMD_TXEN | USART_CMD_RXEN; // Enable Transmitter and Receiver, Clear RX/TX buffers and shif regs
	USART0->CTRL |= (1 << 13) | (1 << 14) | (0 << 10) | USART_CTRL_OVS_X16 | USART_CTRL_SYNC_DEFAULT | USART_CTRL_CLKPOL_IDLELOW; //MSB first, 8-bits oversampling, Async
	USART0->IFC |= 0x1FF9;//_USART_IFC_MASK; // clear all USART interrupt flags
	USART0->ROUTE |= 0x503;//USART_ROUTE_LOCATION_LOC1; // Enable TX and RX pins, use location #1 (UART TX and RX located at PD0 and PD1)
	USART0->IEN |= USART_IEN_RXDATAV | USART_IEN_TXC;
}

/****************************************************/
void callbackUSART0Init(callback p_callbackTx, callback p_callbackRx, void* p_USARTInstance)
{
	callbackUSART0Tx = p_callbackTx;
	callbackUSART0Rx = p_callbackRx;
	USART0Instance = p_USARTInstance;
}


