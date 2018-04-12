/*
 * GPIO-evaluator.hpp
 *
 *  Created on: 2018-03-10
 *      Author: Luis Anillo
 */

#ifndef GPIO_EVALUATOR_HPP_
#define GPIO_EVALUATOR_HPP_

#include "EFM32_GPIO.hpp"
#include "GPIO-mock.hpp"

class GPIOEvaluator
{
private:
	//EFM32_GPIO m_UUT;
    GPIOMock m_UUT;

public:
	GPIOEvaluator();
	~GPIOEvaluator() {};

	// Initialise GPIO
	/** @bdd the pin number is (?P<p_pinNumber>[-+]?\d+(\.\d+)?), a bank letter is (?P<p_bankLetter>[-+]?\d+(\.\d+)?), is an input and the type is (?P<p_typeIO>[-+]?\d+(\.\d+)?) */
	void GPIOInitialiseInput(int p_pinNumber, int p_bankLetter, int p_typeIO);

	/** @bdd the pin number is (?P<p_pinNumber>[-+]?\d+(\.\d+)?), a bank letter is (?P<p_bankLetter>[-+]?\d+(\.\d+)?), is an output and the type is (?P<p_typeIO>[-+]?\d+(\.\d+)?) */
	void GPIOInitialiseOutput(int p_pinNumber, int p_bankLetter, int p_typeIO);

    /** @bdd an initialization error flag is set */
	bool verifyInitializeError();

	/** @bdd a GPIO is instantiated as (?P<p_expectedInput>[-+]?\d+(\.\d+)?) */
	bool verifyIOType(int p_expectedInput);

	// Set GPIO State
	/** @bdd the state of GPIO is (?P<p_expectedState>[-+]?\d+(\.\d+)?) ,0_low or 1_high or 3_dont_care, since GPIO is set as a (?P<p_GPIOType>[-+]?\d+(\.\d+)?) ,0_INPUT or 1_OUTPUT*/
	bool GPIOSetState(int p_expectedState, int p_GPIOType);

	// Toggle GPIO
    /** @bdd toggling the GPIO state */
    bool GPIOtoggle();
};

#endif /* GPIO_EVALUATOR_HPP_ */
