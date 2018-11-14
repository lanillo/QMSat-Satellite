/*
 * EFM32_ADC.hpp
 *
 *  Created on: Nov 13, 2018
 *      Author: lfani
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
