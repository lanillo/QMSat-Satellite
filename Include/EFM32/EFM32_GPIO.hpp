/*
 * GPIO.hpp
 *
 *  Created on: Feb 13, 2018
 *      Author: lfani
 */

#ifndef INCLUDE_PERIPHERALS_EFM32GPIO_HPP_
#define INCLUDE_PERIPHERALS_EFM32GPIO_HPP_

#include "IGPIO.hpp"
#include "Constants.hpp"
#include "em_device.h"

class EFM32_GPIO: public IGPIO
{
public:
	EFM32_GPIO();
	EFM32_GPIO(unsigned short pinNumber, unsigned short bankLetter, bool isInput, int typeIO);
	~EFM32_GPIO() {};

	// For inputs
	bool readInput();

	// For outputs
	bool setOutputHigh();
	bool setOutputLow();
	bool toggleOutput();

	// For attributes
	bool getError();
	bool getIsInput();

private:
	unsigned short m_PinNumber;
	unsigned short m_BankNumber;
	unsigned short m_IOType;

	bool m_isInput;
	bool m_error;

};


#endif /* INCLUDE_PERIPHERALS_EFM32GPIO_HPP_ */
