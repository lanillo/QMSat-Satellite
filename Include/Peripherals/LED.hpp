/*
 * LED.hpp
 *
 *  Created on: 2018-01-25
 *      Author: guillaume
 */

#ifndef INCLUDE_EF32GG_LED_HPP_
#define INCLUDE_EF32GG_LED_HPP_

#include "ILED.hpp"

class LED: public ILED
{
public:
	LED(unsigned short p_PinNumber);
	~LED();

	void turnOFF() = 0;
	void turnON() = 0;
	void toggle() = 0;

private:
	bool m_State;
};

#endif /* INCLUDE_EF32GG_LED_HPP_ */
