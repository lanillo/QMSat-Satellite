/*
 * GPIO.hpp
 *
 *  Created on: Feb 13, 2018
 *      Author: lfani
 */

#ifndef INCLUDE_EFM32_EFM32_GPIO_HPP_
#define INCLUDE_EFM32_EFM32_GPIO_HPP_

#include "IGPIO.hpp"
#include "Constants.hpp"

//#define NOT_IN_TEST

#include "efm32gg990f1024.h"
#include "em_gpio.h"

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
	void clearInterrupts(uint32_t flags);
	void disableInterrupts(uint32_t flags);
	void enableInterrupts(uint32_t flags);
	uint32_t getInterrupts();
	uint32_t getEnabledInterrupts();

	// Set attributes
	void setGPIOMode(GPIO_Mode_TypeDef mode, unsigned int dout);
	void setGPIOPortDriveMode(GPIO_DriveMode_TypeDef driveMode);
	void setInterrupt(bool risingEdge, bool fallingEdge, bool enable);

	// Get attributes
	bool getError();
	bool getGPIOCreated();
	bool getIsInterrupt();

	unsigned int getPin();

	GPIO_OutputModes getOutputMode();

	GPIO_Port_TypeDef getPort();
	GPIO_Mode_TypeDef getGPIOMode();
	GPIO_DriveMode_TypeDef getGPIODriveMode();

private:

	bool m_error;
	bool m_GPIOCreated;
	bool m_isInterrupt;

	unsigned int m_pin;

	GPIO_OutputModes m_outputMode;

	GPIO_Port_TypeDef m_port;
	GPIO_Mode_TypeDef m_mode;
	GPIO_DriveMode_TypeDef m_driveMode;
};


#endif /* INCLUDE_EFM32_EFM32_GPIO_HPP_ */
