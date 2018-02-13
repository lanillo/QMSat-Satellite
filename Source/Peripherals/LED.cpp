/*
 * LED.cpp
 *
 *  Created on: 2018-01-25
 *      Author: guillaume
 */

#include "LED.hpp"

/****************************************************/
LED::LED()
{
    m_State = false;
}

/****************************************************/
LED::LED(unsigned short p_PinNumber)
{
    m_PinNumber = p_PinNumber;
	m_State = false;
}

/****************************************************/
void LED::turnOFF()
{
    m_State = false;
}

/****************************************************/
void LED::turnON()
{
    m_State = true;
}

/****************************************************/
void LED::toggle()
{

}
