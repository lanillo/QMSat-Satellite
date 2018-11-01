/*
 * EFM32_I2C.hpp
 *
 *  Created on: Oct 10, 2018
 *      Author: lfani
 */

#include "em_i2c.h"

#include "Constants.hpp"
#include "ISerialComm.hpp"

/* Flags for I2C commands */
enum I2C_FLAGS
{
	I2C_READ = I2C_FLAG_READ,
	I2C_WRITE = I2C_FLAG_WRITE,
	I2C_WRITE_READ = I2C_FLAG_WRITE_READ,
	I2C_WRITE_WRITE = I2C_FLAG_WRITE_WRITE
};

class EFM32_I2C: public ISerialComm
{
public:
	EFM32_I2C();
	~EFM32_I2C();

	void transfer(uint16_t p_deviceAddr, uint8_t p_cmdArray[], uint8_t p_dataArray[], uint16_t p_cmdLenght, uint16_t p_dataLenght, uint8_t p_flag);
	uint8_t writeCommand(uint8_t address, uint8_t reg_offset, I2C_FLAGS flag);
	uint8_t readCommand(uint8_t address, uint8_t reg_offset, I2C_FLAGS flag);

	void sendSerial(char* p_TxBuffer, unsigned short p_TxBufferSize);
	char receiveSerial();
	bool isSending();
	void setSending(bool p_Sending);

private:
	// Globals for persistent storage
	uint8_t m_cmdArray[I2C_CMD_ARRAY_SIZE];
	uint8_t m_dataArray[I2C_DATA_ARRAY_SIZE];
};

void initI2C();

