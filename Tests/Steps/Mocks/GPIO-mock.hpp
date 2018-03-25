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
	int m_GPIOState; // 0 -> error; 1 -> INPUT; 2 -> OUTPUT
	bool m_readState;
public:
	GPIOMock() {m_PinState = false;};
	~GPIOMock() {};

	void turnON() {m_PinState = true;};
	void turnOFF() {m_PinState = false;};

	bool readInput() {};
	bool setOutputHigh() {};
	bool setOutputLow() {};
	bool toggleOutput() {};

	bool getPinState() {return m_PinState;};
};

#endif /* GPIO_MOCK_HPP_ */
