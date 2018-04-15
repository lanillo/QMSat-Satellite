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
    m_State = !m_State;
}

/****************************************************/
bool LED::getState()
{
    return m_State;
}
