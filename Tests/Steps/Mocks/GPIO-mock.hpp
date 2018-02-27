/*
 * GPIO-mock.hpp
 *
 *  Created on: 2018-02-18
 *      Author: Guillaume
 */

#ifndef GPIO_MOCK_HPP_
#define GPIO_MOCK_HPP_

#include "IGPIO.hpp"

class GPIOMock: public IGPIO
{
private:
	bool m_PinState;
public:
	GPIOMock() {m_PinState = false;};
	~GPIOMock() {};

	void turnON() {m_PinState = true;};
	void turnOFF() {m_PinState = false;}
	bool getPinState() {return m_PinState;};
};

#endif /* GPIO_MOCK_HPP_ */
