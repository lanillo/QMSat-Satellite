/*
 * LED-evaluator.hpp
 *
 *  Created on: 2018-01-25
 *      Author: Guillaume
 */

#ifndef LED_EVALUATOR_HPP_
#define LED_EVALUATOR_HPP_

#include "LED.hpp"
#include "GPIO-mock.hpp"

class LEDEvaluator
{
private:
	LED m_LED;
	GPIOMock m_GPIOMock;

public:
	LEDEvaluator();
	~LEDEvaluator() {};

	/** @bdd a LED initialize to OFF state */
	void LEDInitialiseOFF();

	/** @bdd turning the LED OFF */
	void LEDTurnOFF();

	/** @bdd a LED initialize to ON state */
	void LEDInitialiseON();

	/** @bdd turning the LED ON */
	void LEDTurnON();

	/** @bdd toggling the LED state */
	void LEDToggle();

	/** @bdd the state of the LED is (?P<p_ExpectedState>[-+]?\d+(\.\d+)?) */
	bool verifyLEDState(int p_ExpectedState);
};

#endif /* LED_EVALUATOR_HPP_ */
