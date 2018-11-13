/*
 * EFM32_USART0.hpp
 *
 *  Created on: 2018-11-13
 *      Author: Guillaume Beaupré
 */

#ifndef INCLUDE_EFM32_EFM32_USART0_HPP_
#define INCLUDE_EFM32_EFM32_USART0_HPP_

#include "ISerialComm.hpp"
#include "efm32gg990f1024.h"
#include "Callback.hpp"
#include "Constants.hpp"

class EFM32_USART0: public ISerialComm
{
public:
	EFM32_USART0() {};
	EFM32_USART0(int p_Baudrate, bool p_StopBit, bool p_Parity);
	~EFM32_USART0() {};

	void sendSerial(char* p_TxBuffer, unsigned short p_TxBufferSize);
	char receiveSerial();
	bool isSending();
	void setSending(bool p_Sending);

	static void callbackForSerialTransmit(void* p_USART0Instance);
	static void callbackForSerialReceive(void* p_USART0Instance);

private:
	int m_Baudrate;
	bool m_StopBit;
	bool m_Parity;
	bool m_IsSending;

	unsigned short m_TxBufferSize;
	unsigned short m_TxBufferIndex;
	char m_TxBuffer[TX_BUFFER_SIZE_USART0];
	char m_RxBuffer[RX_BUFFER_SIZE_USART0];
};

void initUSART0();
void callbackUSART0Init(callback p_callbackTx, callback p_callbackRx, void* p_USARTInstance);

//void USART0_RX_IRQHandler(void);
//void USART0_TX_IRQHandler(void);

#endif /* INCLUDE_EFM32_EFM32_USART0_HPP_ */
