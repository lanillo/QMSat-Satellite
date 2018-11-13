/*
 * EFM32_I2C.hpp
 *
 *  Created on: Oct 10, 2018
 *      Author: lfani
 */

#ifndef INCLUDE_EFM32_EFM32_I2C_HPP_
#define INCLUDE_EFM32_EFM32_I2C_HPP_

#include "em_i2c.h"
#include "Constants.hpp"

class EFM32_I2C
{
public:
	EFM32_I2C();
	~EFM32_I2C();

	bool transfer(uint16_t p_deviceAddr, uint8_t p_cmdArray[], uint8_t p_dataArray[], uint16_t p_cmdLenght, uint16_t p_dataLenght, uint8_t p_flag);
	bool sendI2CCommand(uint8_t p_address, uint8_t p_registerOffset, uint16_t cmd_len, uint16_t data_len, uint8_t p_flag);

	uint8_t getCMD(int index);
	uint8_t getDATA(int index);
	I2C_TransferReturn_TypeDef getError();

private:
	// For storage of values received and sent on I2C channel
	uint8_t m_CMDArray[I2C_CMD_ARRAY_SIZE];
	uint8_t m_DATAArray[I2C_DATA_ARRAY_SIZE];

	I2C_TransferReturn_TypeDef m_Error;
};

void initI2C(int p_frequency);

#endif /* INCLUDE_EFM32_EFM32_I2C_HPP_ */

