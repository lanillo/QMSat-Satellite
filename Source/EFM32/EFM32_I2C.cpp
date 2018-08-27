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
	currentSDA = null;
	currentSCL = null;
	slaveAddress = null;
}

/****************************************************/
EFM32_I2C::EFM32_I2C(EFM32_GPIO SDA, EFM32_GPIO SCL, int address)
{
	currentSDA = SDA;
	currentSCL = SCL;
	slaveAddress = null;
	addressInteger = address;

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
	for (int i = 26; i < 33; i++) // we take the seven bits representing the address of the slave
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
	unsigned int mask = 1 << (sizeof(int) * 8 - 1);

	for(int i = 0; i < sizeof(int) * 8; i++)
	{
		if((slaveAddress & mask) == 0 )
			slaveAddress[i] = 0; // cout << '0' ; // MSB to LSB [31,30,29,28,27,...,2,1,0] for 32 bits
	    else
	    	slaveAddress[i] = 1; // cout << '1' ; // MSB to LSB [31,30,29,28,27,...,2,1,0] for 32 bits

		mask  >>= 1;
	}
}
