/*
 * EFM32_USART1.hpp
 *
 *  Created on: 2018-02-18
 *      Author: Guillaume
 */

#ifndef INCLUDE_EFM32_EFM32_USART1_HPP_
#define INCLUDE_EFM32_EFM32_USART1_HPP_

#include "ISerialComm.hpp"
#include "efm32gg990f1024.h"
#include "Callback.hpp"
#include "Constants.hpp"

class EFM32_USART1: public ISerialComm
{
public:
	EFM32_USART1() {};
	EFM32_USART1(int p_Baudrate, bool p_StopBit, bool p_Parity);
	~EFM32_USART1() {};

	void sendSerial(char* p_TxBuffer, unsigned short p_TxBufferSize);
	char receiveSerial();
	bool isSending();
	void setSending(bool p_Sending);

	static void callbackForSerialTransmit(void* p_USART1Instance);
	static void callbackForSerialReceive(void* p_USART1Instance);

private:
	int m_Baudrate;
	bool m_StopBit;
	bool m_Parity;
	bool m_IsSending;

	unsigned short m_TxBufferSize;
	unsigned short m_TxBufferIndex;
	char m_TxBuffer[TX_BUFFER_SIZE_USART1];
	char m_RxBuffer[RX_BUFFER_SIZE_USART1];
};

void initUSART1();
void callbackUSART1Init(callback p_callbackTx, callback p_callbackRx, void* p_USART1Instance);

void USART1_RX_IRQHandler(void);
void USART1_TX_IRQHandler(void);

#endif /* INCLUDE_EFM32_EFM32_USART1_HPP_ */
