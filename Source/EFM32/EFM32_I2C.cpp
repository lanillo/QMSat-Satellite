/*
 * EFM32_I2C.cpp
 *
 *  Created on: Oct 10, 2018
 *      Author: lfani
 */

#include "EFM32_I2C.hpp"

/****************************************************/
EFM32_I2C::EFM32_I2C()
{
    /* Module I2C0 is configured to location 2 */
	I2C0->ROUTE = (I2C0->ROUTE & ~_I2C_ROUTE_LOCATION_MASK) | I2C_ROUTE_LOCATION_LOC2;

	/* Enable signals SCL, SDA */
	I2C0->ROUTE |= I2C_ROUTE_SCLPEN | I2C_ROUTE_SDAPEN;
}

/****************************************************/
EFM32_I2C::~EFM32_I2C()
{

}

/****************************************************/
void EFM32_I2C::transfer(uint16_t p_deviceAddr, uint8_t p_cmdArray[], uint8_t p_dataArray[], uint16_t p_cmdLenght, uint16_t p_dataLenght, uint8_t p_flag)
{

	// Transfer structure
	I2C_TransferSeq_TypeDef i2cTransfer;

	// Initialize I2C transfer
	I2C_TransferReturn_TypeDef result;

	i2cTransfer.addr          = p_deviceAddr;
	i2cTransfer.flags         = p_flag;
	i2cTransfer.buf[0].data   = p_cmdArray;
	i2cTransfer.buf[0].len    = p_cmdLenght;

	// Note that WRITE_WRITE this is tx2 data
	i2cTransfer.buf[1].data   = p_dataArray;
	i2cTransfer.buf[1].len    = p_dataLenght;

	// Set up the transfer
	result = I2C_TransferInit(I2C0, &i2cTransfer);

	// Do it until the transfer is done
	while (result != i2cTransferDone)
	{

		result = I2C_Transfer(I2C0);
	}
}

/****************************************************/
uint8_t EFM32_I2C::writeCommand(uint8_t p_address, uint8_t p_registerOffset, I2C_FLAGS p_flag)
{
	m_cmdArray[0] = p_registerOffset;
	transfer(p_address, m_cmdArray, m_dataArray, 1, 1, p_flag);
	return m_dataArray[0];
}

/****************************************************/
uint8_t EFM32_I2C::readCommand(uint8_t p_address, uint8_t p_registerOffset, I2C_FLAGS p_flag)
{
	m_cmdArray[0] = 0x00;
	transfer(p_address, m_cmdArray, m_dataArray, 1, 2, p_flag);
	return m_dataArray[0];
}

/****************************************************/
void EFM32_I2C::sendSerial(char* p_TxBuffer, unsigned short p_TxBufferSize)
{

}

/****************************************************/
char EFM32_I2C::receiveSerial()
{
	return 0;
}

/****************************************************/
bool EFM32_I2C::isSending()
{
	return 0;
}

/****************************************************/
void EFM32_I2C::setSending(bool p_Sending)
{

}

/****************************************************/
void initI2C()
{
    I2C_Init_TypeDef i2cInit = I2C_INIT_DEFAULT;
    I2C_Init(I2C0, &i2cInit);
}
