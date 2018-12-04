/*
 * MCP9808.cpp
 *
 *  Created on: 2018-10-31
 *      Author: Luis Anillo
 */

#include "MCP9808TempSensor.hpp"

/****************************************************/
MCP9808TempSensor::MCP9808TempSensor(EFM32_I2C* p_I2C, uint8_t address)
{
	m_Temp = 0;
	m_Address = address;
	m_I2C = p_I2C;
}

/****************************************************/
float MCP9808TempSensor::getTemp()
{
	m_I2C->sendI2CCommand(m_Address, MCP9808_REG_AMBIENT_TEMP, 1, 2, I2C_FLAG_WRITE_READ);

	uint16_t t = ((uint16_t) m_I2C->getDATA(0) << 8) | 	m_I2C->getDATA(1);

	float temp = t & 0x0FFF;
	temp /=  16.0;
	if (t & 0x1000)
		temp -= 256;

	m_Temp = temp;

	return m_Temp;
}

/****************************************************/
char* MCP9808TempSensor::tempToString()
{

	char fstr[7];
	fstr[0] = 'T';
	float num = m_Temp;
	int digit;
	int ind = 1;
	if (num < 0)
	{
		fstr[ind] = '-';
		ind++;
		num*=-1;
	}
	int m = log10(num);

	// Change temp
	for(int i = 0 + ind; i < 6; i++)
	{
	    float weight = pow(10.0f, m);
	    digit = floor(num / weight);
	    num -= (digit*weight);
	    fstr[ind] = '0' + digit;
	    ind++;
	    if (m == 0)
	    {
	    	fstr[ind] = '.';
	    	ind++;
	    }

	    m--;
	}
	//fstr[ind] = '\0';
	fstr[6] = '\n';

	return fstr;
}
