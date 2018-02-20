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

class EFM32_USART1: public ISerialComm
{
public:
	EFM32_USART1() {};
	EFM32_USART1(int p_Baudrate, bool p_StopBit, bool p_Parity);
	~EFM32_USART1() {};

	void sendSerial(char* p_TxBuffer);
	void receiveSerial();

private:
	int m_Baudrate;
	bool m_StopBit;
	bool m_Parity;

};

void initUSART1();

#endif /* INCLUDE_EFM32_EFM32_USART1_HPP_ */
