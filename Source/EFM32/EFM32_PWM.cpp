/*
 * EFM32_PWM.cpp
 *
 *  Created on: Oct 7, 2018
 *      Author: lfani
 */

#include "EFM32_PWM.hpp"


/****************************************************/
EFM32_PWM::EFM32_PWM(int DUTY_CYCLE)
:
	m_dutyCycle(DUTY_CYCLE)
{
	// Create the timer count control object initializer
	TIMER_InitCC_TypeDef timerCCInit = TIMER_INITCC_DEFAULT;
	timerCCInit.mode = timerCCModePWM;
	timerCCInit.cmoa = timerOutputActionToggle;

	// Configure CC channel 2
	TIMER_InitCC(TIMER3, TIMER_CHANNEL, &timerCCInit);

	// Route CC2 to location 1 (PE3) and enable pin for cc2
	TIMER3->ROUTE |= (TIMER_ROUTE_CC2PEN | TIMER_ROUTE_LOCATION_LOC1);

	// Set Top Value
	TIMER_TopSet(TIMER3, TIMER_TOP);

	// Set the PWM duty cycle here!
	TIMER_CompareBufSet(TIMER3, TIMER_CHANNEL, DUTY_CYCLE);

	// Create a timerInit object, based on the API default
	TIMER_Init_TypeDef timerInit = TIMER_INIT_DEFAULT;
	timerInit.prescale = timerPrescale512;

	TIMER_Init(TIMER3, &timerInit);
}

/****************************************************/
bool EFM32_PWM::setDutyCycle(int dutyCycle)
{
	if (m_dutyCycle > TIMER_TOP || m_dutyCycle < 0)
	{
		return false;
	}

	m_dutyCycle = dutyCycle;
	TIMER_CompareBufSet(TIMER3, TIMER_CHANNEL, m_dutyCycle);

	return true;
}

/****************************************************/
bool EFM32_PWM::reduceDutyCycleBy(int factor)
{
	if (m_dutyCycle - factor < 0)
	{
		return false;
	}

	m_dutyCycle = m_dutyCycle - factor;
	TIMER_CompareBufSet(TIMER3, TIMER_CHANNEL, m_dutyCycle);

	return true;
}

/****************************************************/
bool EFM32_PWM::augmentDutyCycleBy(int factor)
{
	if (m_dutyCycle + factor > TIMER_TOP)
	{
		return false;
	}

	m_dutyCycle = m_dutyCycle + factor;
	TIMER_CompareBufSet(TIMER3, TIMER_CHANNEL, m_dutyCycle);

	return true;
}

/****************************************************/
int EFM32_PWM::getDutyCycle()
{
	return m_dutyCycle;
}

/****************************************************/
void EFM32_PWM::onAndOffLED()
{

	static bool m_goingUp = true;

	if (m_goingUp)
	{
	if(augmentDutyCycleBy(TIMER_STEP))
		m_goingUp = true;
	else
		m_goingUp = false;
	}
	else
	{
	if(reduceDutyCycleBy(TIMER_STEP))
		m_goingUp = false;
	else
		m_goingUp = true;
	}
}

