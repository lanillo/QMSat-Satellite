/*
 * EFM32_Timer0.cpp
 *
 *  Created on: 2018-01-25
 *      Author: Guillaume
 */

#include "EFM32_Timer0.hpp"

callback callbackTimer0Increment;
void* timer0Instance;

/****************************************************/
EFM32_Timer0::EFM32_Timer0(unsigned int p_Period_microsecond)
{
	m_Period_microsecond = p_Period_microsecond;
	TIMER0->TOP = p_Period_microsecond;
	m_ReferenceTime_microsecond = 0;
	m_ElapsedTime_microsecond = 0;
}

void EFM32_Timer0::start() {
	TIMER0->CMD = 0x1;
}

void EFM32_Timer0::stop() {
	TIMER0->CMD = 0x2;
}

/****************************************************/
unsigned int EFM32_Timer0::getReferenceTime_microsecond()
{
	m_ReferenceTime_microsecond = m_ElapsedTime_microsecond;
	return m_ReferenceTime_microsecond;
}

/****************************************************/
unsigned int EFM32_Timer0::getElapsedTime_microsecond(unsigned int p_ReferenceTime_microsecond)
{
	if (p_ReferenceTime_microsecond > m_ElapsedTime_microsecond)
	{
		return((4294967295 - p_ReferenceTime_microsecond) + m_ElapsedTime_microsecond);
	}
	return (m_ElapsedTime_microsecond - p_ReferenceTime_microsecond);
}

/****************************************************/
void EFM32_Timer0::callbackForTimer0Increment(void* p_TimerInstance)
{
	if (p_TimerInstance != 0)
	{
		EFM32_Timer0* timer = reinterpret_cast<EFM32_Timer0*>(p_TimerInstance);
		timer->m_ElapsedTime_microsecond += timer->m_Period_microsecond;
	}
}

/****************************************************/
/*interrupt d'incrémentation*/
void TIMER0_IRQHandler(void)
{
    TIMER0->IFC = 0x1;                            // Clear overflow flag
    callbackTimer0Increment(timer0Instance);      // Increment counter
}

/****************************************************/
/*initilisation*/
void initTimer0()
{
	TIMER0->IEN = 1;             // Enable Timer0 overflow interrupt
	NVIC_EnableIRQ(TIMER0_IRQn); // Enable TIMER0 interrupt vector in NVIC
	//TIMER0->CTRL = TIMER0->CTRL | (_TIMER_CTRL_PRESC_DIV1 << 24);
}

/****************************************************/
void callbackTimer0Init(callback p_CallbackFunction, void* p_Instance)
{
	callbackTimer0Increment = p_CallbackFunction;
	timer0Instance = p_Instance;
}
