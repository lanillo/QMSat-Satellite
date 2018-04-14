/*
 * GPIO.hpp
 *
 *  Created on: Feb 13, 2018
 *      Author: lfani
 */

#ifndef INCLUDE_EFM32_EFM32GPIO_HPP_
#define INCLUDE_EFM32_EFM32GPIO_HPP_

#include "IGPIO.hpp"
#include "Constants.hpp"

#ifndef TEST_MODE
    #include "../Tests/Steps/Mocks/GPIO-struct-mock.hpp"
#endif // TEST_MODE

#ifdef TEST_MORE
    #include "efm32gg990f1024.h"
#endif // TEST_MORE

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


#endif /* INCLUDE_EFM32_EFM32GPIO_HPP_ */
