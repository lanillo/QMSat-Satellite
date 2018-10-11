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
	EFM32_PWM(int dutyCycle);
	~EFM32_PWM() {};

	bool setDutyCycle(int dutyCycle);
	bool reduceDutyCycleBy(int factor);
	bool augmentDutyCycleBy(int factor);
	void onAndOffLED();
	int getDutyCycle();

private:
	int m_dutyCycle;
};

#endif /* INCLUDE_EFM32_EFM32_PWM_HPP_ */