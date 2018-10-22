/*
 * GPIO.hpp
 *
 *  Created on: Feb 13, 2018
 *      Author: Luis Anillo
 */

#ifndef INCLUDE_EFM32_EFM32_GPIO_HPP_
#define INCLUDE_EFM32_EFM32_GPIO_HPP_

#include "IGPIO.hpp"
#include "Constants.hpp"

//#define NOT_IN_TEST

#include "efm32gg990f1024.h"
#include "em_gpio.h"

enum GPIO_OutputModes
{
	OM_Disabled = 0,
	OM_PushPull = 1,
	OM_OpenSource_WiredOR = 2,
	OM_OpenDrain_WiredAND = 3
};

enum GPIO_INTERRUPTS_FLAGS
{
	ALL_GPIO_ODDS = 0xAAAA,
	ALL_GPIO_EVEN = 0x5555
};

class EFM32_GPIO: public IGPIO
{
public:
	EFM32_GPIO();
	EFM32_GPIO(GPIO_Port_TypeDef port, unsigned int pin, GPIO_Mode_TypeDef mode, unsigned int dout); // Page 750, datasheet
	~EFM32_GPIO() {};

	// For inputs
	bool readInput();

	// For outputs
	bool setOutputHigh();
	bool setOutputLow();
	bool toggleOutput();

	// For interrupts
	void clearInterruptsToTest(uint32_t flags);
	void disableInterruptsToTest(uint32_t flags);
	void enableInterruptsToTest(uint32_t flags);
	uint32_t getInterruptsToTest();
	uint32_t getEnabledInterruptsToTest();

	// Set attributes
	void setGPIOMode(GPIO_Mode_TypeDef mode, unsigned int dout);
	void setGPIOPortDriveMode(GPIO_DriveMode_TypeDef driveMode);
	void setInterruptToTest(bool risingEdge, bool fallingEdge, bool enable);

	// Get attributes
	bool getError();
	bool getGPIOCreated();
	bool getIsInterrupt();

	unsigned int getPin();

	GPIO_OutputModes getOutputMode();

	GPIO_Port_TypeDef getPort();
	GPIO_Mode_TypeDef getGPIOMode();
	//GPIO_DriveMode_TypeDef getGPIODriveMode(); 	// Commented because DriveMode is for the whole port, not the pin.

private:

	bool m_error;
	bool m_GPIOCreated;
	bool m_isInterrupt;

	unsigned int m_pin;

	GPIO_OutputModes m_outputMode;

	GPIO_Port_TypeDef m_port;
	GPIO_Mode_TypeDef m_mode;
	//GPIO_DriveMode_TypeDef m_driveMode; 			// Commented because DriveMode is for the whole port, not the pin.
};


#endif /* INCLUDE_EFM32_EFM32_GPIO_HPP_ */
