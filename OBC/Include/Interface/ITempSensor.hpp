/*
 * ITempSensor.hpp
 *
 *  Created on: October 31, 2018
 *   Authors: Luis Anillo
 * 			  Guillaume Beaupré.
 *
 *   \brief ITempSensor Abstract Class Prototype
 */

#ifndef INCLUDE_INTERFACE_ITEMPSENSOR_HPP_
#define INCLUDE_INTERFACE_ITEMPSENSOR_HPP_

class ITempSensor
{
public:
	ITempSensor() {};
	virtual ~ITempSensor() {};

	virtual float getTemp() = 0;
	virtual char* tempToString() = 0;
};


#endif /* INCLUDE_INTERFACE_ITEMPSENSOR_HPP_ */
