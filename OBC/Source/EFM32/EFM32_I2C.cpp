/*
 * EFM32_I2C.cpp
 *
 *  Created on: October 10, 2018
 *   Authors: Luis Anillo
 * 			  Guillaume Beaupré.
 *
 *   \brief I2C Class Definition
 */

#include "EFM32_I2C.hpp"

/****************************************************/
/**
* \brief Creates I2C object and routes pins location (PC7 PC8)
* \return I2C object
*/
EFM32_I2C::EFM32_I2C()
{
    /* Module I2C0 is configured to location 2 */
	I2C0->ROUTE = (I2C0->ROUTE & ~_I2C_ROUTE_LOCATION_MASK) | I2C_ROUTE_LOCATION_LOC2;

	/* Enable signals SCL, SDA */
	I2C0->ROUTE |= I2C_ROUTE_SCLPEN | I2C_ROUTE_SDAPEN;

	for (int i = 0; i < I2C_CMD_ARRAY_SIZE; ++i)
	{
		m_CMDArray[i] = 0;
	}

	for (int i = 0; i < I2C_DATA_ARRAY_SIZE; ++i)
	{
		m_DATAArray[i] = 0;
	}

	m_Error = i2cTransferDone;

}

/****************************************************/
/**
* \brief Destroy I2C object
* \return None
*/
EFM32_I2C::~EFM32_I2C()
{}

/****************************************************/
/**
* \brief Transfer data to the I2C bus
*  \param[in] p_deviceAddr : 		I2C device address
*  \param[in] p_cmdArray[] : 		Command buffer
*  \param[in] p_dataArray[] :  		Data buffer
*  \param[in] p_cmdLenght : 		Length of the command buffer
*  \param[in] p_dataLenght : 		Length of the data buffer
*  \param[in] p_flag :  			type of communication initiated
* \return 	true if transfer end
* 			false if error
*/
bool EFM32_I2C::transfer(uint16_t p_deviceAddr, uint8_t p_cmdArray[], uint8_t p_dataArray[], uint16_t p_cmdLenght, uint16_t p_dataLenght, uint8_t p_flag)
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
		if (result != i2cTransferInProgress)
		{
			m_Error = result;
			//DEBUG_BREAK; Breakpoint
			return false;
		}

		result = I2C_Transfer(I2C0);
	}
	return true;
}

/****************************************************//**
 * \brief Send command via I2C bus
 *  \param[in] p_address : 		I2C device address
 *  \param[in] p_registerOffset : Register Offset of I2C command
 *  \param[in] cmd_len :  		Length of the command buffer
 *  \param[in] data_len : 		Length of the data buffer
 *  \param[in] p_flag :  			type of communication initiated
 * \return 	true if successful
 * 			false if unsuccessful
 *
 * exemple of use
 * if(I2C.sendCommand(TEMP_SENSOR_ADDRESS, 0x05, 1, 2, I2C_FLAG_WRITE_READ))
 * {
 * 	do code
 * }
 **/
bool EFM32_I2C::sendI2CCommand(uint8_t p_address, uint8_t p_registerOffset, uint16_t cmd_len, uint16_t data_len, uint8_t p_flag)
{
	m_CMDArray[0] = p_registerOffset;
	return transfer(p_address, m_CMDArray, m_DATAArray, cmd_len, data_len, p_flag);

}

/****************************************************/
/**
* \brief Get byte of the command buffer
*  \param[in] index : Byte index of the command buffer
* \return data contained in the command buffer at index position
*/
uint8_t EFM32_I2C::getCMD(int index)
{
	return m_CMDArray[index];
}

/****************************************************/
/**
* \brief Get byte of the data buffer
*  \param[in] index : Byte index of the data buffer
* \return data contained in the data buffer at index position
*/
uint8_t EFM32_I2C::getDATA(int index)
{
	return m_DATAArray[index];
}

/****************************************************/
/**
* \brief Get error of the bus
* \return Data error code
*/
I2C_TransferReturn_TypeDef EFM32_I2C::getError()
{
	return m_Error;
}

/****************************************************/
/**
 * \brief Initializes I2C communication
 *  \param[in] frequency : Frequency used in the bus
 * \return None
 */
void initI2C(int frequency)
{
    I2C_Init_TypeDef i2cInit = I2C_INIT_DEFAULT;
	i2cInit.freq = 200000;
    I2C_Init(I2C0, &i2cInit);
}
