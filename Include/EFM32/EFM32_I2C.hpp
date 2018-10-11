/*
 * EFM32_I2C.hpp
 *
 *  Created on: Oct 10, 2018
 *      Author: lfani
 */

#include "em_i2c.h"

#include "Constants.hpp"

/* Flags for I2C commands */
enum I2C_FLAGS
{
	I2C_READ = I2C_FLAG_READ,
	I2C_WRITE = I2C_FLAG_WRITE,
	I2C_WRITE_READ = I2C_FLAG_WRITE_READ,
	I2C_WRITE_WRITE = I2C_FLAG_WRITE_WRITE
};

class EFM32_I2C
{
public:
	EFM32_I2C();
	~EFM32_I2C() {};

	void i2c_transfer(uint16_t device_addr, uint8_t cmd_array[], uint8_t data_array[], uint16_t cmd_len, uint16_t data_len, uint8_t flag);
	uint8_t i2c_write_command(uint8_t address, uint8_t reg_offset, I2C_FLAGS flag);
	uint8_t i2c_read_command(uint8_t address, uint8_t reg_offset, I2C_FLAGS flag);

private:
	// Globals for persistent storage
	uint8_t m_cmd_array[I2C_CMD_ARRAY_SIZE];
	uint8_t m_data_array[I2C_DATA_ARRAY_SIZE];
};

void initI2C();



