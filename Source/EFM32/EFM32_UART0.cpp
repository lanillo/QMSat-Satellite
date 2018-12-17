/*
 * EFM32_UART0.cpp
 *
 *  Created on: November 13, 2018
 *   Authors: Luis Anillo
 * 			  Guillaume Beaupr�.
 *
 *   \brief UART0 Class Definition
 */

#include <EFM32_UART0.hpp>
#include <string.h>

callback callbackUART0Tx;
callback2 callbackUART0Rx;
void* UART0Instance;
void* AlimManagerInstance;

/****************************************************/
/**
* \brief Object constructor for the UART communication with the Alim uC
* \param[in] p_Baudrate :  Baud rate of the signal
* \param[in] p_StopBit  :  Select the number of stop bit
* \param[in] p_Parity   :  Add or not the parity bit
* \return None
*/
EFM32_UART0::EFM32_UART0(int p_Baudrate, bool p_StopBit, bool p_Parity)
{

	m_Baudrate = 4*((24000000/(16*p_Baudrate)) - 1);
	UART0->CLKDIV = (m_Baudrate << 6); // 155 will give 9600 baud rate (using 16-bit oversampling with 24MHz peripheral clock)

	m_StopBit = p_StopBit;
	m_Parity = p_Parity;

	m_TxBufferSize = 0;
	m_TxBufferIndex = 0;
	m_IsSending = false;

	for(unsigned short index = 0; index < TX_BUFFER_SIZE_UART0; index++)
	{
		m_TxBuffer[index] = (char)0;
	}

	for(unsigned short index = 0; index < RX_BUFFER_SIZE_UART0; index++)
	{
		m_RxBuffer[index] = (char)0;
	}

	UART0->FRAME = (m_StopBit << 12) | (m_Parity << 8) | USART_FRAME_DATABITS_EIGHT; //1 STOP, no parity, 8bits data
}

/****************************************************/
/**
* \brief Receive the next character from UART0
* \return The next character or '\0' if RX is empty or not ready
*/
char EFM32_UART0::receiveSerial()
{
	if(UART0->STATUS & (1 << 7))  // if RX buffer contains valid data
	{
		return (char)UART0->RXDATA;
	}
	return '/0';
}

/****************************************************/
/**
* \brief Get the value of the sending state
* \return Sending state
*/
bool EFM32_UART0::isSending()
{
	return m_IsSending;
}

/****************************************************/
/**
* \brief Set the value of the sending state
* \param[in] p_Sending :  Set this value to sending state
* \return None
*/
void EFM32_UART0::setSending(bool p_Sending)
{
	m_IsSending = p_Sending;
}

/****************************************************/
/**
* \brief Interrupt Service Routine of the UART0 RX
* \return None
*/
void UART0_RX_IRQHandler(void)
{
	callbackUART0Rx(UART0Instance, AlimManagerInstance);
	UART0->IFC |= USART_IFC_RXFULL;
}

/****************************************************/
/**
* \brief Interrupt Service Routine of the UART0 TX
* \param[in] p_TxBuffer 	:  Buffer pointing to the data buffer
* \param[in] p_TxBufferSize :  Size of the data buffer to send
* \return None
*/
void EFM32_UART0::sendSerial(char* p_TxBuffer, unsigned short p_TxBufferSize)
{
	m_TxBufferSize = p_TxBufferSize;
	setSending(true);
	for(unsigned short index = 0; index < p_TxBufferSize; index++)
	{
		m_TxBuffer[index] = (char)*p_TxBuffer;
		p_TxBuffer++;
	}
	m_TxBufferIndex = 1;
	if(UART0->STATUS & (1 << 6)) // check if TX buffer is empty
	{
		UART0->TXDATA = m_TxBuffer[0];
	}
	while(isSending());
}

/****************************************************/
/**
* \brief function used in the TX Interrupt
* \param[in] p_UART0Instance :  The instance of the UART0 Object
* \return None
*/
void EFM32_UART0::callbackForSerialTransmit(void* p_UART0Instance)
{
	if (p_UART0Instance != null)
	{
		EFM32_UART0* uart = reinterpret_cast<EFM32_UART0*>(p_UART0Instance);
		if(uart->m_TxBufferSize > uart->m_TxBufferIndex)
		{
			if(UART0->STATUS & (1 << 6)) // check if TX buffer is empty
			{
				UART0->TXDATA = uart->m_TxBuffer[uart->m_TxBufferIndex];
				uart->m_TxBufferIndex++;
			}
		}

		//Resets the Tx Buffer
		else
		{
			for(unsigned short index = 0; index < TX_BUFFER_SIZE_UART0; index++)
			{
				uart->m_TxBuffer[index] = (char)0;
			}
			uart->setSending(false);
		}
	}
}

/****************************************************/
/**
* \brief Interrupt Service Routine of the UART0 TX
* \return None
*/
void UART0_TX_IRQHandler(void)
{
	callbackUART0Tx(UART0Instance);
	UART0->IFC |= USART_IFC_TXC;
}

/****************************************************/
/**
* \brief Initiation of the UART0 registers
* \return None
*/
void initUART0()
{
	GPIO->P[4].MODEL = GPIO_P_MODEL_MODE1_INPUT | GPIO_P_MODEL_MODE0_PUSHPULL;  // Configure PE0 as digital output and PE1 as input
	NVIC_EnableIRQ(UART0_RX_IRQn);  //Interupt USART0 Receive vector
	NVIC_EnableIRQ(UART0_TX_IRQn);  //Interupt USART0 Transmit vector

	UART0->CMD |= USART_CMD_CLEARRX | USART_CMD_CLEARTX | USART_CMD_TXEN | USART_CMD_RXEN; // Enable Transmitter and Receiver, Clear RX/TX buffers and shif regs
	UART0->CTRL |= USART_CTRL_OVS_X16; // 8-bits oversampling, Async
	UART0->IFC |= 0x1FF9;//_USART_IFC_MASK; // clear all USART interrupt flags
	UART0->ROUTE |= 0x103;//USART_ROUTE_LOCATION_LOC1; // Enable TX and RX pins, use location #5 (UART TX and RX located at PE0 and PE1)
	UART0->IEN |= USART_IEN_RXDATAV | USART_IEN_TXC;
	GPIO->P[4].DOUTSET = (1 << 0); // Initialize PC0 high since UART TX idles high (otherwise glitches can occur)
}

/****************************************************/
/**
* \brief Initialize the function and instance pointer used in the interrupt
* \return None
*/
void callbackUART0Init(callback p_callbackTx, callback2 p_callbackRx, void* p_USAT0Instance, void* p_AlimManagerInstance)
{
	callbackUART0Tx = p_callbackTx;
	UART0Instance = p_USAT0Instance;

	callbackUART0Rx = p_callbackRx;
	AlimManagerInstance = p_AlimManagerInstance;
}


