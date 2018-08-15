/*
 * GPIO-mock.cpp
 *
 *  Created on: 2018-04-10
 *      Author: Luis
 */

#include "GPIO-mock.hpp"

/**************************************************/
GPIOMock::GPIOMock(int p_pinNumber, int p_bankLetter, bool isInput, int p_typeIO)
{
    m_IsInput = isInput;
    m_Error = false;
    m_PinState = false;

    // If it is an Input
    if (isInput)
    {
        // Check if the pin number fits (normally, there is two banks of 8 pins,
        // low and high. For behaviour testing, just check if pinNumber is between 0 and 15
        if (p_pinNumber >= 0 && p_pinNumber <= 15)
    	{
    	    // Pulldown
            if (p_typeIO == 0 || p_typeIO == 2)
            {
               m_PinState = false;
            }
            // Pullup
            else if (p_typeIO == 1 || p_typeIO == 3)
            {
                m_PinState = true;
            }
            else
            {
                m_Error = true;
            }
    	}
    	else
        {
            m_Error = true;
        }
    }
    // If it is an Output
    else
    {
        // Check if the pin number fits (normally, there is two banks of 8 pins,
        // low and high. For behaviour testing, just check if pinNumber is between 0 and 15
        if (p_pinNumber >= 0 && p_pinNumber <= 15)
    	{
    	    // Pulldown (for output, it's inverted from input)
            if (p_typeIO == 5)
            {
               m_PinState = true;
            }
            // Pullup (for output, it's inverted from input)
            else if (p_typeIO == 4 || (p_typeIO >= 6 && p_typeIO <= 13))
            {
                m_PinState = false;
            }
            else
            {
                m_Error = true;
            }
    	}
    	else
        {
            m_Error = true;
        }
    }
}

/**************************************************/
bool GPIOMock::readInput()
{
    return m_PinState;
}

/**************************************************/
bool GPIOMock::setOutputHigh()
{
    if (m_IsInput)
	{
		return false;
	}
	else
	{
        m_PinState = true;
		return true;
	}
}

/**************************************************/
bool GPIOMock::setOutputLow()
{
    if (m_IsInput)
	{
		return false;
	}
	else
	{
        m_PinState = false;
		return true;
	}
}

/**************************************************/
bool GPIOMock::toggleOutput()
{
    if (m_IsInput)
	{
		return false;
	}
	else
	{
		m_PinState = !m_PinState;
		return true;
	}
}
