/*
 * GPIO.cpp
 *
 *  Created on: Feb 13, 2018
 *      Author: lfani
 */

#include <EFM32_GPIO.hpp>
#include "Constants.hpp"
#include <cstdio>

/****************************************************/
EFM32_GPIO::EFM32_GPIO()
{
	m_BankNumber = null;
    m_PinNumber = null;
    m_isInput = false;
    m_IOType = 0;
    m_error = false;
}

/****************************************************/
EFM32_GPIO::EFM32_GPIO(unsigned short pinNumber, unsigned short bankLetter, bool isInput, int type)
{
	this->m_BankNumber = bankLetter;
    this->m_PinNumber = pinNumber;
    this->m_isInput = isInput;
    this->m_IOType = type;
    this->m_error = false;

    //printf("\n\n Voici l'objet GPIO: %p\n\n", GPIO); //004110E0

    if (isInput)
    {
    	if (pinNumber >= 0 && pinNumber <= 7)
    	{
    		switch (type)
    		{
				case PULLDOWN:
					GPIO->P[bankLetter].MODEL = _GPIO_P_MODEL_MODE0_INPUTPULL << 4*pinNumber;
					GPIO->P[bankLetter].DOUT = 0 << pinNumber;
					break;
				case PULLUP:
					GPIO->P[bankLetter].MODEL = _GPIO_P_MODEL_MODE0_INPUTPULL << 4*pinNumber;
					GPIO->P[bankLetter].DOUT = 1 << pinNumber;
					break;
				case PULLDOWN_FILTERED:
					GPIO->P[bankLetter].MODEL = _GPIO_P_MODEL_MODE0_INPUTPULLFILTER << 4*pinNumber;
					GPIO->P[bankLetter].DOUT = 0 << pinNumber;
					break;
				case PULLUP_FILTERED:
					GPIO->P[bankLetter].MODEL = _GPIO_P_MODEL_MODE0_INPUTPULLFILTER << 4*pinNumber;
					GPIO->P[bankLetter].DOUT = 1 << pinNumber;
					break;
				default:
					m_error = true;
					break;
			}

    	}
    	else if (pinNumber >= 8 && pinNumber <= 15)
		{
    		switch (type)
			{
				case PULLDOWN:
					GPIO->P[bankLetter].MODEH = _GPIO_P_MODEH_MODE8_INPUTPULL << 4*(pinNumber-7);
					GPIO->P[bankLetter].DOUT = 0 << pinNumber;
					break;
				case PULLUP:
					GPIO->P[bankLetter].MODEH = _GPIO_P_MODEH_MODE8_INPUTPULL << 4*(pinNumber-7);
					GPIO->P[bankLetter].DOUT = 1 << pinNumber;
					break;
				case PULLDOWN_FILTERED:
					GPIO->P[bankLetter].MODEH = _GPIO_P_MODEH_MODE8_INPUTPULLFILTER << 4*(pinNumber-7);
					GPIO->P[bankLetter].DOUT = 0 << pinNumber;
					break;
				case PULLUP_FILTERED:
					GPIO->P[bankLetter].MODEH = _GPIO_P_MODEH_MODE8_INPUTPULLFILTER << 4*(pinNumber-7);
					GPIO->P[bankLetter].DOUT = 1 << pinNumber;
					break;
				default:
					m_error = true;
					break;
			}
		}
    	else
		{
			m_error = true;
		}
    }
	else
    {
		if (pinNumber >= 0 && pinNumber <= 7)
		{
			switch (type)
			{
				case OPENSOURCE:
					GPIO->P[bankLetter].MODEL = _GPIO_P_MODEL_MODE0_WIREDOR << 4*pinNumber;
					GPIO->P[bankLetter].DOUT = 0 << pinNumber;
					break;
				case OPENSOURCE_PULLDOWN:
					GPIO->P[bankLetter].MODEL = _GPIO_P_MODEL_MODE0_WIREDORPULLDOWN << 4*pinNumber;
					GPIO->P[bankLetter].DOUT = 1 << pinNumber;
					break;
				case OPENDRAIN_PULLUP:
					GPIO->P[bankLetter].MODEL = _GPIO_P_MODEL_MODE0_WIREDANDPULLUP << 4*pinNumber;
					GPIO->P[bankLetter].DOUT = 0 << pinNumber;
					break;
				case OPENDRAIN_PULLUP_FILTER:
					GPIO->P[bankLetter].MODEL = _GPIO_P_MODEL_MODE0_WIREDANDPULLUPFILTER << 4*pinNumber;
					GPIO->P[bankLetter].DOUT = 0 << pinNumber;
					break;
				case OPENDRAIN_ATLDRIVE:
					GPIO->P[bankLetter].MODEL = _GPIO_P_MODEL_MODE0_WIREDANDDRIVE << 4*pinNumber;
					GPIO->P[bankLetter].DOUT = 0 << pinNumber;
					break;
				case OPENDRAIN_ATLDRIVE_FILTER:
					GPIO->P[bankLetter].MODEL = _GPIO_P_MODEL_MODE0_WIREDANDDRIVEFILTER << 4*pinNumber;
					GPIO->P[bankLetter].DOUT = 0 << pinNumber;
					break;
				case OPENDRAIN_ATLDRIVE_PULLUP:
					GPIO->P[bankLetter].MODEL = _GPIO_P_MODEL_MODE0_WIREDANDDRIVEPULLUP << 4*pinNumber;
					GPIO->P[bankLetter].DOUT = 0 << pinNumber;
					break;
				case OPENDRAIN_ATLDRIVE_PULLUP_FILTER:
					GPIO->P[bankLetter].MODEL = _GPIO_P_MODEL_MODE0_WIREDANDDRIVEPULLUPFILTER << 4*pinNumber;
					GPIO->P[bankLetter].DOUT = 0 << pinNumber;
					break;
				case PUSHPULL:
					GPIO->P[bankLetter].MODEL = _GPIO_P_MODEL_MODE0_PUSHPULL << 4*pinNumber;
					GPIO->P[bankLetter].DOUT = 0 << pinNumber;
					break;
				case PUSHPULL_ALTDRIVE:
					GPIO->P[bankLetter].MODEL = _GPIO_P_MODEL_MODE0_PUSHPULLDRIVE << 4*pinNumber;
					GPIO->P[bankLetter].DOUT = 0 << pinNumber;
					break;
				default:
					m_error = true;
					break;
			}
		}
		else if (pinNumber >= 8 && pinNumber <= 15)
		{
			switch (type)
			{
				case OPENSOURCE:
					GPIO->P[bankLetter].MODEH = _GPIO_P_MODEH_MODE8_WIREDOR << 4*(pinNumber-7);
					GPIO->P[bankLetter].DOUT = 0 << pinNumber;
					break;
				case OPENSOURCE_PULLDOWN:
					GPIO->P[bankLetter].MODEH = _GPIO_P_MODEH_MODE8_WIREDORPULLDOWN << 4*(pinNumber-7);
					GPIO->P[bankLetter].DOUT = 1 << pinNumber;
					break;
				case OPENDRAIN_PULLUP:
					GPIO->P[bankLetter].MODEH = _GPIO_P_MODEH_MODE8_WIREDANDPULLUP << 4*(pinNumber-7);
					GPIO->P[bankLetter].DOUT = 0 << pinNumber;
					break;
				case OPENDRAIN_PULLUP_FILTER:
					GPIO->P[bankLetter].MODEH = _GPIO_P_MODEH_MODE8_WIREDANDPULLUPFILTER << 4*(pinNumber-7);
					GPIO->P[bankLetter].DOUT = 0 << pinNumber;
					break;
				case OPENDRAIN_ATLDRIVE:
					GPIO->P[bankLetter].MODEH = _GPIO_P_MODEH_MODE9_WIREDANDDRIVE << 4*(pinNumber-7);
					GPIO->P[bankLetter].DOUT = 0 << pinNumber;
					break;
				case OPENDRAIN_ATLDRIVE_FILTER:
					GPIO->P[bankLetter].MODEH = _GPIO_P_MODEH_MODE8_WIREDANDDRIVEFILTER << 4*(pinNumber-7);
					GPIO->P[bankLetter].DOUT = 0 << pinNumber;
					break;
				case OPENDRAIN_ATLDRIVE_PULLUP:
					GPIO->P[bankLetter].MODEH = _GPIO_P_MODEH_MODE8_WIREDANDDRIVEPULLUP << 4*(pinNumber-7);
					GPIO->P[bankLetter].DOUT = 0 << pinNumber;
					break;
				case OPENDRAIN_ATLDRIVE_PULLUP_FILTER:
					GPIO->P[bankLetter].MODEH = _GPIO_P_MODEH_MODE8_WIREDANDDRIVEPULLUPFILTER << 4*(pinNumber-7);
					GPIO->P[bankLetter].DOUT = 0 << pinNumber;
					break;
				case PUSHPULL:
					GPIO->P[bankLetter].MODEL = _GPIO_P_MODEH_MODE8_PUSHPULL << 4*pinNumber;
					GPIO->P[bankLetter].DOUT = 0 << pinNumber;
					break;
				case PUSHPULL_ALTDRIVE:
					GPIO->P[bankLetter].MODEL = _GPIO_P_MODEH_MODE8_PUSHPULLDRIVE << 4*pinNumber;
					GPIO->P[bankLetter].DOUT = 0 << pinNumber;
					break;
				default:
					m_error = true;
					break;
			}
		}
		else
		{
			m_error = true;
		}
    }
}

/****************************************************/
bool EFM32_GPIO::readInput()
{
	return GPIO->P[this->m_BankNumber].DOUT;
}

/****************************************************/
bool EFM32_GPIO::setOutputHigh()
{
	if (m_isInput)
	{
		return false;
	} else
	{
		GPIO->P[this->m_BankNumber].DOUTSET = 1 << this->m_PinNumber;
		return true;
	}
}

/****************************************************/
bool EFM32_GPIO::setOutputLow()
{
	if (m_isInput)
	{
		return false;
	} else
	{
		GPIO->P[this->m_BankNumber].DOUTCLR = 1 << this->m_PinNumber;
		return true;
	}
}

/****************************************************/
bool EFM32_GPIO::toggleOutput()
{
	if (m_isInput)
	{
		return false;
	}
	else
	{
		GPIO->P[this->m_BankNumber].DOUTTGL = 1 << this->m_PinNumber;
		return true;
	}
}

/****************************************************/
bool EFM32_GPIO::getError()
{
    return m_error;
}

/****************************************************/
bool EFM32_GPIO::getIsInput()
{
    return m_isInput;
}
