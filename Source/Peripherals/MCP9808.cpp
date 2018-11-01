/*
 * MCP9808.cpp
 *
 *  Created on: 2018-10-31
 *      Author: Guillaume Beaupré
 */

#include "MCP9808TempSensor.hpp"

/****************************************************/
MCP9808TempSensor::MCP9808TempSensor(ISerialComm* p_I2C)
{
	m_Temp = 0;
	m_I2C = p_I2C;
}

/****************************************************/
int MCP9808TempSensor::getTemp()
{
	return m_Temp;
}
