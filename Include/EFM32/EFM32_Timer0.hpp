/*
 * EFM32_Timer0.hpp
 *
 *  Created on: 2018-01-25
 *      Author: Guillaume
 */

#ifndef INCLUDE_EFM32_EFM32_TIMER0_HPP_
#define INCLUDE_EFM32_EFM32_TIMER0_HPP_

#include "ITimer.hpp"

class EFM32_Timer0: public ITimer
{
public:
	EFM32_Timer0() {};
	EFM32_Timer0(unsigned int p_Period_microsecond);
	~EFM32_Timer0() {};

	unsigned int getReferenceTime_microsecond();
	unsigned int getElapsedTime_microsecond();

private:
	unsigned int m_ElapsedTime_microsecond;
	unsigned int m_ReferenceTime_microsecond;
};

#endif /* INCLUDE_EFM32_EFM32_TIMER0_HPP_ */
