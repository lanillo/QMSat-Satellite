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
	bool m_PinState;    // IsPinHigh ?
	bool m_IsInput;     // Is the pin an Input
	bool m_Error;       // Initialisation error



public:
	GPIOMock() {m_PinState = false;};
	GPIOMock(int p_pinNumber, int p_bankLetter, bool isInput, int p_typeIO);

	~GPIOMock() {};

	void turnON() {m_PinState = true;};
	void turnOFF() {m_PinState = false;};

	bool readInput();
	bool setOutputHigh();
	bool setOutputLow();
	bool toggleOutput();

	bool getPinState() {return m_PinState;};
	bool getIsInput() {return m_IsInput;};
	bool getError() {return m_Error;};
};

#endif /* GPIO_MOCK_HPP_ */
