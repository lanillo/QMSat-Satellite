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
	m_GPIO->setOutputLow();
    m_State = false;
}

/****************************************************/
void LED::turnON()
{
	m_GPIO->setOutputHigh();
    m_State = true;
}

/****************************************************/
void LED::toggle()
{
    m_GPIO->toggleOutput();
    m_State = !m_State;
}

/****************************************************/
bool LED::getState()
{
    return m_State;
}

/****************************************************/
bool LED::getStatus()
{
	return m_State;
}
