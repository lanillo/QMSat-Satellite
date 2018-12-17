/*
 * EFM32_USART0.hpp
 *
 *  Created on: November 13, 2018
 *   Authors: Luis Anillo
 * 			  Guillaume Beaupré.
 *
 *   \brief UART0 Class Prototype
 */

#ifndef INCLUDE_EFM32_EFM32_UART0_HPP_
#define INCLUDE_EFM32_EFM32_UART0_HPP_

#include <AlimManager.hpp>
#include "ISerialComm.hpp"
#include "efm32gg990f1024.h"
#include "Callback.hpp"
#include "Constants.hpp"

class EFM32_UART0: public ISerialComm
{
public:
	EFM32_UART0() {};
	EFM32_UART0(int p_Baudrate, bool p_StopBit, bool p_Parity);
	~EFM32_UART0() {};

	void sendSerial(char* p_TxBuffer, unsigned short p_TxBufferSize);
	char receiveSerial();
	bool isSending();
	void setSending(bool p_Sending);

	static void callbackForSerialTransmit(void* p_UART0Instance);

	unsigned short m_RxBufferIndex;
	char m_RxBuffer[RX_BUFFER_SIZE_UART0];
	bool m_IsReceiving;

private:
	int m_Baudrate;
	bool m_StopBit;
	bool m_Parity;

	unsigned short m_TxBufferSize;
	unsigned short m_TxBufferIndex;
	char m_TxBuffer[TX_BUFFER_SIZE_UART0];
	bool m_IsSending;

	char m_RxData;
};

void initUART0();
void callbackUART0Init(callback p_callbackTx, callback2 p_callbackRx, void* p_USAT0Instance, void* p_AlimManagerInstance);

#endif /* INCLUDE_EFM32_EFM32_UART0_HPP_ */
