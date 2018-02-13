/*
 * GPIO.hpp
 *
 *  Created on: Feb 13, 2018
 *      Author: lfani
 */

#ifndef INCLUDE_PERIPHERALS_GPIO_HPP_
#define INCLUDE_PERIPHERALS_GPIO_HPP_

#include "IGPIO.hpp"

class GPIO: public IGPIO
{
public:
	GPIO();
	GPIO(unsigned short p_PinNumber);
	~GPIO() {};

	void turnOFF();
	void turnON();
	void toggle();

private:
	bool m_State;
	unsigned short m_PinNumber;
};


#endif /* INCLUDE_PERIPHERALS_GPIO_HPP_ */
