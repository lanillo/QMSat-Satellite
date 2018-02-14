/*
 * EFM32_Timer0.hpp
 *
 *  Created on: 2018-01-25
 *      Author: Guillaume
 */

#ifndef LED_EVALUATOR_HPP_
#define LED_EVALUATOR_HPP_

#include "LED.hpp"

class LEDEvaluator
{
private:
	LED m_LED;

public:
	LEDEvaluator();
	~LEDEvaluator() {};

	/** @bdd a LED initialize to off state */
	void LEDTurnOFF();

	/** @bdd the LED works */
	bool verifyLED();



};

#endif /* LED_EVALUATOR_HPP_ */