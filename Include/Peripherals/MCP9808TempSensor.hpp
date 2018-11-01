/*
 * MCP9808TempSensor.hpp
 *
 *  Created on: 2018-10-31
 *      Author: Guillaume Beaupré
 */

#ifndef INCLUDE_PERIPHERALS_MCP9808TEMPSENSOR_HPP_
#define INCLUDE_PERIPHERALS_MCP9808TEMPSENSOR_HPP_

#include "ISerialComm.hpp"
#include "ITempSensor.hpp"

class MCP9808TempSensor: public ITempSensor
{
private:
	int m_Temp;
	ISerialComm* m_I2C;

public:
	MCP9808TempSensor();
	MCP9808TempSensor(ISerialComm* p_I2C);
	~MCP9808TempSensor() {};

	int getTemp();
};



#endif /* INCLUDE_PERIPHERALS_MCP9808TEMPSENSOR_HPP_ */
