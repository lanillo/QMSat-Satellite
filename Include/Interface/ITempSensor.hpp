/*
 * ITempSensor.hpp
 *
 *  Created on: 2018-10-31
 *      Author: guill
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
