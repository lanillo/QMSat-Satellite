/*
 * EFM32_ADC.cpp
 *
 *  Created on: Nov 13, 2018
 *      Author: lfani
 */

#include "EFM32_ADC.hpp"

/****************************************************/
EFM32_ADC::EFM32_ADC()
{

}

/****************************************************/
void initADC()
{
	ADC_Reset(ADC0);
	ADC_Init_TypeDef ADCInit = ADC_INITSINGLE_DEFAULT;
	ADC_Init(ADC0, &ADCInit);
}
