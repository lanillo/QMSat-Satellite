/*
 * EFM32_Timer0.cpp
 *
 *  Created on: 2018-01-25
 *      Author: Guillaume
 */

#include "EFM32_Timer0.hpp"

/****************************************************/
EFM32_Timer0::EFM32_Timer0(unsigned int p_Period_microsecond)
{
	m_ReferenceTime_microsecond = 0;
	m_ElapsedTime_microsecond = 0;
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
/*interrupt d'incrémentation*/

