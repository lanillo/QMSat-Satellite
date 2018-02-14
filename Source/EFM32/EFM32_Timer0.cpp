/*
 * EFM32_Timer0.cpp
 *
 *  Created on: 2018-01-25
 *      Author: Guillaume
 */

#include "EFM32_Timer0.hpp"

callback* callbackTimer0Increment;
void* timer0Instance;

/****************************************************/
EFM32_Timer0::EFM32_Timer0(unsigned int p_Period_microsecond)
{
	m_Period_microsecond = p_Period_microsecond;
	TIMER0->TOP = 0;
	m_ReferenceTime_microsecond = 0;
	m_ElapsedTime_microsecond = 0;
}

void EFM32_Timer0::start() {
	TIMER0->CMD = 0x1;
}

void EFM32_Timer0::stop() {
	TIMER0->CMD = 0x0;
}

/****************************************************/
unsigned int EFM32_Timer0::getReferenceTime_microsecond()
{
	m_ReferenceTime_microsecond = 0;
	return m_ReferenceTime_microsecond;
}

/****************************************************/
unsigned int EFM32_Timer0::getElapsedTime_microsecond()
{
	m_ElapsedTime_microsecond = 0;
	return m_ReferenceTime_microsecond;
}

/****************************************************/
static void EFM32_Timer0::callbackForTimer0Increment(void* p_TimerInstance)
{
	if (p_TimerInstance != NULL) {
		EFM32_Timer0* timer = reinterpret_cast<EFM32_Timer0*>(p_TimerInstance);
		timer->m_ElapsedTime_microsecond += timer->m_Period_microsecond;
	}
}

/****************************************************/
/*interrupt d'incrémentation*/
void Interrupt_TIMER0()
{
    TIMER0->IFC = 1;                              // Clear overflow flag
    callbackTimer0Increment(timer0Instance);      // Increment counter
}

/****************************************************/
/*initilisation*/
void initTimer0()
{
	TIMER0->IEN = 1;             // Enable Timer0 overflow interrupt
	NVIC_EnableIRQ(TIMER0_IRQn); // Enable TIMER0 interrupt vector in NVIC
}

/****************************************************/
void callbackTimer0Init(callback* p_CallbackFunction, void* p_Instance)
{
	callbackTimer0Increment = p_CallbackFunction;
	timer0Instance = p_Instance;
}
