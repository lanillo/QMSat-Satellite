/*
 * EFM32_I2C.hpp
 *
 *  Created on: Aug 15, 2018
 *      Author: lfani
 */

#ifndef INCLUDE_EFM32_EFM32_I2C_HPP_
#define INCLUDE_EFM32_EFM32_I2C_HPP_

#include "II2C.hpp"
#include "Constants.hpp"
#include "EFM32_GPIO.hpp"

class EFM32_I2C: public II2C
{
public:
	EFM32_I2C();
	EFM32_I2C(EFM32_GPIO SDA, EFM32_GPIO SCL, int address);

	void ReadData();

	~EFM32_I2C() {};


private:
	int addressInteger;
	int slaveAddress[32];
	int dataOut[32];

	void Delay();
	void StartCom();
	void StopCom();
	void DecodeAddress();
	void SendAddress();

	EFM32_GPIO currentSDA; // GPIO used for SDA (serial data line)
	EFM32_GPIO currentSCL;	// GPIO used for SCL (serial clock line)

};


#endif /* INCLUDE_EFM32_EFM32_I2C_HPP_ */
