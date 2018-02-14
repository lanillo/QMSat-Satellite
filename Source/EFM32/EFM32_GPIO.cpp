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

    m_PinNumber = pinNumber;
	m_State = false;

	int test_PinNumber = (int) pinNumber;
	int test_bankLetter = (int) bankLetter;

	GPIO->P[bankLetter].MODEL = (5 << 12) | (4 << 8);
	GPIO->P[bankLetter].DOUTSET = 1 << pinNumber;

}

/****************************************************/
void EFM32_GPIO::turnOFF()
{
    m_State = false;
}

/****************************************************/
void EFM32_GPIO::turnON()
{
    m_State = true;
}

/****************************************************/
void EFM32_GPIO::toggle()
{

}
