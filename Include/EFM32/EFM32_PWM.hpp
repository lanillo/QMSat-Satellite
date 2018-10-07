/*
 * EFM32_PWM.hpp
 *
 *  Created on: Oct 7, 2018
 *      Author: lfani
 */

#ifndef INCLUDE_EFM32_EFM32_PWM_HPP_
#define INCLUDE_EFM32_EFM32_PWM_HPP_

#include "em_gpio.h"
#include "em_timer.h"

#include "Constants.hpp"

#define TIMER_TOP				100
#define TIMER_CHANNEL 			2

class EFM32_PWM
{
public:
	EFM32_PWM();
	EFM32_PWM(int dutyCycle);
	~EFM32_PWM() {};

	bool setDutyCycle(int dutyCycle);
	bool reduceDutyCycleBy(int factor);
	bool augmentDutyCycleBy(int factor);
	int getDutyCycle();

private:
	int m_dutyCycle;
};

#endif /* INCLUDE_EFM32_EFM32_PWM_HPP_ */
