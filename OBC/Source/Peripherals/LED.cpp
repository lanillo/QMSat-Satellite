/*
 * LED.cpp
 *
 *  Created on: January 25, 2018
 *   Authors: Luis Anillo
 * 			  Guillaume Beaupré.
 *
 *   \brief LED Class Definition
 */

#include "LED.hpp"

/****************************************************/
/**
* \brief Create a LED object with a GPIO
*  \param[in] p_GPIO : GPIO pin pointer
* \return None
*/
LED::LED(IGPIO* p_GPIO)
{
	m_GPIO = p_GPIO;
	turnOFF();
}

/****************************************************/
/**
* \brief Turn off LED
* \return None
*/
void LED::turnOFF()
{
	m_GPIO->setOutputLow();
    m_State = false;
}

/****************************************************/
/**
* \brief Turn on LED
* \return None
*/
void LED::turnON()
{
	m_GPIO->setOutputHigh();
    m_State = true;
}

/****************************************************/
/**
* \brief Toggle LED
* \return None
*/
void LED::toggle()
{
    m_GPIO->toggleOutput();
    m_State = !m_State;
}

/****************************************************/
/**
* \brief Get LED Status
* \return None
*/
bool LED::getState()
{
    return m_State;
}
