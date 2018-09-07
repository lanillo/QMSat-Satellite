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

	// Set attributes
	void setGPIOMode(GPIO_Mode_TypeDef mode, unsigned int dout);

	// Get attributes
	GPIO_OutputModes getOutputMode();
	GPIO_Mode_TypeDef getGPIOMode();

	bool getError();

private:
	bool m_error;
	GPIO_Port_TypeDef m_port;
	unsigned int m_pin;
	GPIO_Mode_TypeDef m_mode;
	GPIO_OutputModes m_outputMode;
};


#endif /* INCLUDE_EFM32_EFM32_GPIO_HPP_ */
