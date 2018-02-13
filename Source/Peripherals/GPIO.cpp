/*
 * GPIO.cpp
 *
 *  Created on: Feb 13, 2018
 *      Author: lfani
 */

#include "GPIO.hpp"

/****************************************************/
GPIO::GPIO()
{
    m_State = false;
}

/****************************************************/
GPIO::GPIO(unsigned short p_PinNumber)
{
    m_PinNumber = p_PinNumber;
	m_State = false;
}

/****************************************************/
void GPIO::turnOFF()
{
    m_State = false;
}

/****************************************************/
void GPIO::turnON()
{
    m_State = true;
}

/****************************************************/
void GPIO::toggle()
{

}
