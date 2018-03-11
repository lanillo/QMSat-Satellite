/*
 * EFM32_Timer0.hpp
 *
 *  Created on: 2018-01-25
 *      Author: Guillaume
 */

#ifndef INCLUDE_EFM32_EFM32_TIMER0_HPP_
#define INCLUDE_EFM32_EFM32_TIMER0_HPP_

#include "ITimer.hpp"
#include "Constants.hpp"
#include "Callback.hpp"
#include "efm32gg990f1024.h"

class EFM32_Timer0: public ITimer
{
public:
	EFM32_Timer0() {};
	EFM32_Timer0(unsigned int p_Period_microsecond);
	~EFM32_Timer0() {};

	unsigned int getReferenceTime_microsecond();
	unsigned int getElapsedTime_microsecond(unsigned int p_ReferenceTime_microsecond);
	void start();
	void stop();

	static void callbackForTimer0Increment(void* p_TimerInstance);

private:
	unsigned int m_ElapsedTime_microsecond;
	unsigned int m_ReferenceTime_microsecond;
	unsigned int m_Period_microsecond;
};

void initTimer0();
void callbackTimer0Init(callback p_callbackFunction, void* p_Instance);
void TIMER0_IRQHandler(void);

#endif /* INCLUDE_EFM32_EFM32_TIMER0_HPP_ */
