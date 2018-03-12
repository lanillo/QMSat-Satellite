/*
 * GPIO-evaluator.hpp
 *
 *  Created on: 2018-03-10
 *      Author: Luis Anillo
 */

#ifndef GPIO_EVALUATOR_HPP_
#define GPIO_EVALUATOR_HPP_

#include "GPIO.hpp"
#include "GPIO-mock.hpp"

class GPIOEvaluator
{
private:
	GPIO m_UUT;

public:
	GPIOEvaluator();
	~GPIOEvaluator() {};

	// Initialise GPIO
	/** @bdd the pin number is (?P<p_pinNumber>[-+]?\d+(\.\d+)?),
        a bank letter is A ((?P<p_bankLetter>[-+]?\d+(\.\d+)?)),
        is an input and the type is output ((?P<p_typeIO>[-+]?\d+(\.\d+)?)) */
	void GPIOInitialiseINPUT(int p_pinNumber, int p_bankLetter, int p_typeIO);

    /** @bdd an initialization error flag is set */
	bool verifyInitializeError();

	// Read GPIO state
	/** @bdd read GPIO initialized as INPUT */
	void GPIOReadINPUT();

	/** @bdd read GPIO initialized as OUTPUT */
	void GPIOReadOUTPUT(); // Must return error


	// Set GPIO state
	/** @bdd set GPIO initialized as OUTPUT to HIGH */
	void GPIOSetOUTPUTtoHIGH();

	/** @bdd set GPIO initialized as INPUT to HIGH */
	void GPIOSetINPUTtoHIGH(); // Must return error

	/** @bdd set GPIO initialized as OUTPUT to LOW */
	void GPIOSetOUTPUTtoLOW();

	/** @bdd set GPIO initialized as INPUT to LOW */
	void GPIOSetINPUTtoLOW(); // Must return error


	// Toggle GPIO
	/** @bdd toggle GPIO initialized as OUTPUT from LOW to HIGH */
	void GPIOToggleOUTPUTtoHIGH();

	/** @bdd toggle GPIO initialized as OUTPUT from HIGH to LOW */
	void GPIOToggleOUTPUTtoLOW();

	/** @bdd toggle GPIO initialized as INPUT from LOW to HIGH */
	void GPIOToggleINPUTtoHIGH();

	/** @bdd toggle GPIO initialized as INPUT from HIGH to LOW */
	void GPIOToggleINPUTtoLOW();

};

#endif /* GPIO_EVALUATOR_HPP_ */
