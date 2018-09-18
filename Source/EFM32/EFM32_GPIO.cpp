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
		m_GPIOCreated(false),
		m_error(false),
		m_port(gpioPortA),
		m_pin(null),
		m_mode(gpioModeDisabled),
		m_outputMode(OM_Disabled),
		//m_driveMode(gpioDriveModeLow),
		m_isInterrupt(false)
{
}

/****************************************************/
// Look page 750 from the datasheet to see all the mode configuration
EFM32_GPIO::EFM32_GPIO(GPIO_Port_TypeDef port, unsigned int pin, GPIO_Mode_TypeDef mode, unsigned int dout)
:
		m_GPIOCreated(true),
		m_error(false),
		m_port(port),
		m_pin(pin),
		m_mode(mode),
		m_isInterrupt(false)
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
/*void EFM32_GPIO::setGPIOPortDriveMode(GPIO_DriveMode_TypeDef driveMode)
{
	m_driveMode = driveMode;
	GPIO_DriveModeSet(m_port, driveMode);
}*/

/****************************************************/
void EFM32_GPIO::setInterruptToTest(bool risingEdge, bool fallingEdge, bool enable)
{
	/*
	if (m_isInterrupt)
		GPIO_Disable ? // Fonction doesn't exist
	*/

	int intNo; // The interrupt number to trigger.

	if (m_pin <= 3)
		intNo = 0;
	else if (m_pin > 3 && m_pin <= 7)
		intNo = 1;
	else if (m_pin > 7 && m_pin <= 11)
		intNo = 2;
	else if (m_pin > 11 && m_pin <= 15)
		intNo = 3;

	GPIO_ExtIntConfig(m_port, m_pin, intNo, risingEdge, fallingEdge, enable);
}

/****************************************************/
void EFM32_GPIO::clearInterruptsToTest(uint32_t flags)
{
	GPIO_IntClear(flags);
}

/****************************************************/
void EFM32_GPIO::disableInterruptsToTest(uint32_t flags)
{
	GPIO_IntDisable(flags);
}

/****************************************************/
void EFM32_GPIO::enableInterruptsToTest(uint32_t flags)
{
	GPIO_IntEnable(flags);
}

/****************************************************/
uint32_t EFM32_GPIO::getInterruptsToTest()
{
	return GPIO_IntGet();
}

/****************************************************/
uint32_t EFM32_GPIO::getEnabledInterruptsToTest()
{
	return GPIO_IntGetEnabled();
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
bool EFM32_GPIO::getError()
{
    return m_error;
}

/****************************************************/
bool EFM32_GPIO::getGPIOCreated()
{
    return m_GPIOCreated; //GPIO_PinModeGet(m_port, m_pin);
}

/****************************************************/
bool EFM32_GPIO::getIsInterrupt()
{
    return m_isInterrupt; //GPIO_PinModeGet(m_port, m_pin);
}

/****************************************************/
unsigned int EFM32_GPIO::getPin()
{
    return m_pin; //GPIO_PinModeGet(m_port, m_pin);
}

/****************************************************/
GPIO_OutputModes EFM32_GPIO::getOutputMode()
{
    return m_outputMode;
}

/****************************************************/
GPIO_Port_TypeDef EFM32_GPIO::getPort()
{
    return m_port; //GPIO_PinModeGet(m_port, m_pin);
}

/****************************************************/
GPIO_Mode_TypeDef EFM32_GPIO::getGPIOMode()
{
    return m_mode; //GPIO_PinModeGet(m_port, m_pin);
}

/****************************************************/
/*GPIO_DriveMode_TypeDef EFM32_GPIO::getGPIODriveMode()
{
    return m_driveMode; //GPIO_PinModeGet(m_port, m_pin);
}*/
