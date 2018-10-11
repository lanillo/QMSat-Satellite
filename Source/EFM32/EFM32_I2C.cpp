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
void EFM32_I2C::i2c_transfer(uint16_t device_addr, uint8_t cmd_array[], uint8_t data_array[], uint16_t cmd_len, uint16_t data_len, uint8_t flag)
{

	// Transfer structure
	I2C_TransferSeq_TypeDef i2cTransfer;

	// Initialize I2C transfer
	I2C_TransferReturn_TypeDef result;

	i2cTransfer.addr          = device_addr;
	i2cTransfer.flags         = flag;
	i2cTransfer.buf[0].data   = cmd_array;
	i2cTransfer.buf[0].len    = cmd_len;

	// Note that WRITE_WRITE this is tx2 data
	i2cTransfer.buf[1].data   = data_array;
	i2cTransfer.buf[1].len    = data_len;

	// Set up the transfer
	result = I2C_TransferInit(I2C0, &i2cTransfer);

	// Do it until the transfer is done
	while (result != i2cTransferDone)
	{

		result = I2C_Transfer(I2C0);
	}
}

/****************************************************/
uint8_t EFM32_I2C::i2c_write_command(uint8_t address, uint8_t reg_offset, I2C_FLAGS flag)
{
	m_cmd_array[0] = reg_offset;
	i2c_transfer(address, m_cmd_array, m_data_array, 1, 1, flag);
	return m_data_array[0];
}

/****************************************************/
uint8_t EFM32_I2C::i2c_read_command(uint8_t address, uint8_t reg_offset, I2C_FLAGS flag)
{
	m_cmd_array[0] = 0x00;
	i2c_transfer(address, m_cmd_array, m_data_array, 1, 2, flag);
	return m_data_array[0];
}

/****************************************************/
void initI2C()
{
    I2C_Init_TypeDef i2cInit = I2C_INIT_DEFAULT;
    I2C_Init(I2C0, &i2cInit);
}
