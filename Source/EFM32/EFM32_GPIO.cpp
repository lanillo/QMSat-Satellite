/*
 * GPIO.cpp
 *
 *  Created on: Feb 13, 2018
 *      Author: lfani
 */

#include <EFM32_GPIO.hpp>

/****************************************************/
EFM32_GPIO::EFM32_GPIO(unsigned short pinNumber, unsigned short bankLetter)
{
	m_BankNumber = bankLetter;
    m_PinNumber = pinNumber;
}

/****************************************************/
void EFM32_GPIO::turnOFF()
{
	GPIO->P[this->m_BankNumber].MODEL = (5 << 12) | (4 << 8);
	GPIO->P[this->m_BankNumber].DOUTCLR = 1 << this->m_PinNumber;
}

/****************************************************/
void EFM32_GPIO::turnON()
{
	GPIO->P[this->m_BankNumber].MODEL = (5 << 12) | (4 << 8);
	GPIO->P[this->m_BankNumber].DOUTSET = 1 << this->m_PinNumber;
}

/****************************************************/
void EFM32_GPIO::toggle()
{

}
