/*
 * EFM32_ADC.hpp
 *
 *  Created on: November 13, 2018
 *   Authors: Luis Anillo
 * 			  Guillaume Beaupré.
 *
 *   \brief ADC Class Prototype
 */

#ifndef INCLUDE_EFM32_EFM32_ADC_HPP_
#define INCLUDE_EFM32_EFM32_ADC_HPP_

#include "em_adc.h"

class EFM32_ADC {
public:

	EFM32_ADC();
	~EFM32_ADC() {};

	float readADC();

private:
};

void initADC();


#endif /* INCLUDE_EFM32_EFM32_ADC_HPP_ */
