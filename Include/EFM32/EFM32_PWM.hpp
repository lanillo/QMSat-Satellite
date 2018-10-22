/*
 * EFM32_PWM.hpp
 *
 *  Created on: Oct 7, 2018
 *      Author: lfani
 */

#ifndef INCLUDE_EFM32_EFM32_PWM_HPP_
#define INCLUDE_EFM32_EFM32_PWM_HPP_

#include "em_timer.h"

#include "Constants.hpp"

#define TIMER_TOP				10
#define TIMER_STEP				5
#define TIMER_CHANNEL 			2

class EFM32_PWM
{
public:
	EFM32_PWM() :m_dutyCycle(0) {};
	EFM32_PWM(int p_dutyCycle);
	~EFM32_PWM() {};

	bool setDutyCycle(int p_dutyCycle);
	bool reduceDutyCycleBy(int p_factor);
	bool augmentDutyCycleBy(int p_factor);
	void onAndOffLED();
	int getDutyCycle();

private:
	int m_dutyCycle;
};

#endif /* INCLUDE_EFM32_EFM32_PWM_HPP_ */
