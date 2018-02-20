/*
 * LED.hpp
 *
 *  Created on: 2018-01-25
 *      Author: Guillaume
 */

#ifndef INCLUDE_EF32GG_LED_HPP_
#define INCLUDE_EF32GG_LED_HPP_

#include "ILED.hpp"
#include "IGPIO.hpp"

class LED: public ILED
{
public:
	LED() {};
	LED(IGPIO* p_GPIO);
	~LED() {};

	void turnOFF();
	void turnON();
	void toggle();

	bool getStatus();

private:
	bool m_State;
	IGPIO* m_GPIO;
};

#endif /* INCLUDE_EF32GG_LED_HPP_ */
