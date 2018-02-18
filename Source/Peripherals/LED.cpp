/*
 * LED.cpp
 *
 *  Created on: 2018-01-25
 *      Author: guillaume
 */

#include "LED.hpp"

/****************************************************/
LED::LED(IGPIO* p_GPIO)
{
	m_GPIO = p_GPIO;
	turnOFF();
}

/****************************************************/
void LED::turnOFF()
{
	m_GPIO->turnOFF();
    m_State = false;
}

/****************************************************/
void LED::turnON()
{
	m_GPIO->turnON();
    m_State = true;
}

/****************************************************/
void LED::toggle()
{
	if(m_State)
	{
		turnOFF();
	}
	else
	{
		turnON();
	}

}

/****************************************************/
bool LED::getStatus()
{
	return m_State;
}
