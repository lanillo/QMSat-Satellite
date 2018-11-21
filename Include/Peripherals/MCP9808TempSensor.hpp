/*
 * MCP9808TempSensor.hpp
 *
 *  Created on: 2018-10-31
 *      Author: Luis Anillo
 */

#ifndef INCLUDE_PERIPHERALS_MCP9808TEMPSENSOR_HPP_
#define INCLUDE_PERIPHERALS_MCP9808TEMPSENSOR_HPP_

#include "EFM32_I2C.hpp"
#include "ITempSensor.hpp"
#include <math.h>

#define MCP9808_REG_UPPER_TEMP         0x02
#define MCP9808_REG_LOWER_TEMP         0x03
#define MCP9808_REG_CRIT_TEMP          0x04
#define MCP9808_REG_AMBIENT_TEMP       0x05
#define MCP9808_REG_MANUF_ID           0x06
#define MCP9808_REG_DEVICE_ID          0x07

class MCP9808TempSensor: public ITempSensor
{
private:
	float m_Temp;
	uint8_t m_Address;
	EFM32_I2C* m_I2C;

	enum units
	{
		HUNDREDS,
		TENS,
		WHOLE,
		TENTHS
	};

	char itoa(float temperature);
	int findNumber(int temperature);


public:
	MCP9808TempSensor() {};
	MCP9808TempSensor(EFM32_I2C* p_I2C, uint8_t address);
	~MCP9808TempSensor() {};

	float getTemp();
	char* tempToString();
};



#endif /* INCLUDE_PERIPHERALS_MCP9808TEMPSENSOR_HPP_ */
