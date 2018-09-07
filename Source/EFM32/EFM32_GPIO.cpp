/*
 * GPIO.cpp
 *
 *  Created on: Feb 13, 2018
 *      Author: lfani
 */

#include <EFM32_GPIO.hpp>

#include <cstdio>

/****************************************************/
EFM32_GPIO::EFM32_GPIO()
:
		m_error(true),
		m_port(gpioPortA),
		m_pin(null),
		m_mode(gpioModeDisabled),
		m_outputMode(OM_Disabled)
{
}

/****************************************************/
// Look page 750 from the datasheet to see all the mode configuration
EFM32_GPIO::EFM32_GPIO(GPIO_Port_TypeDef port, unsigned int pin, GPIO_Mode_TypeDef mode, unsigned int dout)
:
		m_error(false),
		m_port(port),
		m_pin(pin),
		m_mode(mode)
{
	if (mode == gpioModeDisabled || mode == gpioModeInput || mode == gpioModeInputPull || mode == gpioModeInputPullFilter)
	{
		m_outputMode = OM_Disabled;
	}
	else if (mode == gpioModePushPull || mode == gpioModePushPullDrive)
	{
		m_outputMode = OM_PushPull;
	}
	else if (mode == gpioModeWiredOr || mode == gpioModeWiredOrPullDown)
	{
		m_outputMode = OM_OpenDrain_WiredAND;
	}
	else
	{
		m_outputMode = OM_OpenSource_WiredOR;
	}

	GPIO_PinModeSet(port, pin, mode, dout);
}

/****************************************************/
bool EFM32_GPIO::readInput()
{
	return GPIO_PinInGet(m_port, m_pin) == 1;
}

/****************************************************/
bool EFM32_GPIO::setOutputHigh()
{
	GPIO_PinOutSet(m_port, m_pin);

	return readInput() == 1;
}

/****************************************************/
bool EFM32_GPIO::setOutputLow()
{
	GPIO_PinOutClear(m_port, m_pin);

	return readInput() == 0;
}

/****************************************************/
bool EFM32_GPIO::toggleOutput()
{
	unsigned int tmp;
	tmp = readInput();

	GPIO_PinOutToggle(m_port, m_pin);

	return readInput() != tmp;
}

/****************************************************/
void EFM32_GPIO::setGPIOMode(GPIO_Mode_TypeDef mode, unsigned int dout)
{
	if (mode == gpioModeDisabled || mode == gpioModeInput || mode == gpioModeInputPull || mode == gpioModeInputPullFilter)
	{
		m_outputMode = OM_Disabled;
	}
	else if (mode == gpioModePushPull || mode == gpioModePushPullDrive)
	{
		m_outputMode = OM_PushPull;
	}
	else if (mode == gpioModeWiredOr || mode == gpioModeWiredOrPullDown)
	{
		m_outputMode = OM_OpenDrain_WiredAND;
	}
	else
	{
		m_outputMode = OM_OpenSource_WiredOR;
	}

		GPIO_PinModeSet(m_port, m_pin, mode, dout);
}

/****************************************************/
GPIO_Mode_TypeDef EFM32_GPIO::getGPIOMode()
{
    return m_mode; //GPIO_PinModeGet(m_port, m_pin);
}

/****************************************************/
GPIO_OutputModes EFM32_GPIO::getOutputMode()
{
    return m_outputMode;
}

/****************************************************/
bool EFM32_GPIO::getError()
{
    return m_error;
}
