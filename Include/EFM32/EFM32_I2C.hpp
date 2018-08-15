/*
 * EFM32_I2C.hpp
 *
 *  Created on: Aug 15, 2018
 *      Author: lfani
 */

#ifndef INCLUDE_EFM32_EFM32_I2C_HPP_
#define INCLUDE_EFM32_EFM32_I2C_HPP_

class EFM32_I2C: public II2C
{
public:
	EFM32_I2C();
	EFM32_I2C(EFM32_GPIO SDA, EFM32_GPIO SCL, int address);
	~EFM32_I2C() {};

	void Write(int command);
	void Read();

private:

	int addressInteger
	int slaveAddress[32];

	void Delay();
	void StartCom();
	void StopCom();
	void DecodeAddress();
	void SendAddress();

	EFM32_GPIO currentSDA; // GPIO used for SDA (serial data line)
	EFM32_GPIO currentSCL;	// GPIO used for SCL (serial clock line)

};


#endif /* INCLUDE_EFM32_EFM32_I2C_HPP_ */
