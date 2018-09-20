/*
 * EFM32_SPI.hpp
 *
 *  Created on: 2018-09-10
 *      Author: Guillaume
 */

#ifndef INCLUDE_EFM32_EFM32_SPI_HPP_
#define INCLUDE_EFM32_EFM32_SPI_HPP_

#include "Constants.hpp"
#include "efm32gg990f1024.h"

class EFM32_SPI
{
public:
	EFM32_SPI() {};
	~EFM32_SPI() {};
};

void initSPI();

#endif /* INCLUDE_EFM32_EFM32_SPI_HPP_ */
