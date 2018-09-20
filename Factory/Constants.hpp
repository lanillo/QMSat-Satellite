/*
 * Constants.hpp
 *
 *  Created on: Feb 13, 2018
 *      Author: lfani
 */

#ifndef FACTORY_CONSTANTS_HPP_
#define FACTORY_CONSTANTS_HPP_

#define ACCELEROMETER_ADDRESS 	0x55 << 1

static int null = 0;

enum GPIO_OutputModes
{
	OM_Disabled = 0,
	OM_PushPull = 1,
	OM_OpenSource_WiredOR = 2,
	OM_OpenDrain_WiredAND = 3
};

enum GPIO_INTERRUPTS_FLAGS
{
	ALL_GPIO_ODDS = 0xAAAA,
	ALL_GPIO_EVEN = 0x5555
};

#endif /* FACTORY_CONSTANTS_HPP_ */
