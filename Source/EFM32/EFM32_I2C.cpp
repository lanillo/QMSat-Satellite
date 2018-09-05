/*
 * EFM32_I2C.cpp
 *
 *  Created on: Aug 15, 2018
 *      Author: lfani
 */

#include <EFM32_I2C.hpp>
#include "Constants.hpp"

// for testing, we take GPIO PD14 and PD15 (I2C_#3)

/****************************************************/
EFM32_I2C::EFM32_I2C()
{

	for (int i = 0; i < 32; i++)
	{
		this->slaveAddress[i] = null;
		this->dataOut[i] = null;
	}

	this->addressInteger = null;
}

/****************************************************/
EFM32_I2C::EFM32_I2C(EFM32_GPIO SDA, EFM32_GPIO SCL, int address)
{
	this->currentSDA = SDA;
	this->currentSCL = SCL;

	for (int i = 0; i < 32; i++)
	{
		this->slaveAddress[i] = null;
	}

	this->addressInteger = address;

	SDA.setOutputHigh();
	SCL.setOutputHigh();

	DecodeAddress();

}

/****************************************************/
void EFM32_I2C::Delay()
{
	// for delay purposes
}

/****************************************************/
void EFM32_I2C::StartCom()
{
	currentSDA.setOutputHigh();            // I2C start bit sequence
	Delay();
	currentSCL.setOutputHigh();
	Delay();
	currentSDA.setOutputLow();
	Delay();
	currentSCL.setOutputLow();
	Delay();

	SendAddress();
}

/****************************************************/
void EFM32_I2C::StopCom()
{
	currentSDA.setOutputLow();           // I2C stop bit sequence
	Delay();
	currentSCL.setOutputHigh();
	Delay();
	currentSDA.setOutputHigh();
	Delay();
}

/****************************************************/
void EFM32_I2C::SendAddress()
{
	slaveAddress[25] = 1;
	slaveAddress[26] = 0;
	slaveAddress[27] = 1;
	slaveAddress[28] = 0;
	slaveAddress[29] = 1;
	slaveAddress[30] = 0;
	slaveAddress[31] = 1;

	for (int i = 25; i < 32; i++) // we take the seven bits representing the address of the slave
	{
		if (slaveAddress[i] == 0)
		{
			currentSDA.setOutputLow();
			Delay();
			currentSCL.toggleOutput();
			Delay();
		}
		else if (slaveAddress[i] == 1)
		{
			currentSDA.setOutputHigh();
			Delay();
			currentSCL.toggleOutput();
			Delay();
		}

	}


}

/****************************************************/
void EFM32_I2C::DecodeAddress()
{
	for (int i = 0; i < 25; i++)
	{
		slaveAddress[i] = 0;
	}

	slaveAddress[31] = 1;
	slaveAddress[30] = 0;
	slaveAddress[29] = 1;
	slaveAddress[28] = 0;
	slaveAddress[27] = 1;
	slaveAddress[26] = 0;
	slaveAddress[25] = 1;

}

/****************************************************/
void EFM32_I2C::ReadData()
{
	StartCom();
	SendAddress();

}

