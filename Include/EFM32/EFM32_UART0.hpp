/*
 * EFM32_USART0.hpp
 *
 *  Created on: 2018-11-13
 *      Author: Guillaume Beaupré
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

	unsigned short m_RxBufferIndex;			//Index of received characters
	char m_RxBuffer[RX_BUFFER_SIZE_UART0];	//Buffer of the received character
	bool m_IsReceiving;						//State of sending communication

private:
	int m_Baudrate;							//Baud Rate
	bool m_StopBit;							//number of stop bit (0-2)
	bool m_Parity;							//As parity bit or not

	unsigned short m_TxBufferSize;			//Index
	unsigned short m_TxBufferIndex;
	char m_TxBuffer[TX_BUFFER_SIZE_UART0];
	bool m_IsSending;

	char m_RxData;
};

void initUART0();
void callbackUART0Init(callback p_callbackTx, callback2 p_callbackRx, void* p_USAT0Instance, void* p_AlimManagerInstance);

#endif /* INCLUDE_EFM32_EFM32_UART0_HPP_ */
