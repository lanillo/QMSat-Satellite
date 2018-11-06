/*
 * EFM32_I2C.hpp
 *
 *  Created on: Oct 10, 2018
 *      Author: lfani
 */

#include "em_i2c.h"

#include "Constants.hpp"
#include "ISerialComm.hpp"

class EFM32_I2C: public ISerialComm
{
public:
	EFM32_I2C();
	~EFM32_I2C();

	bool transfer(uint16_t p_deviceAddr, uint8_t p_cmdArray[], uint8_t p_dataArray[], uint16_t p_cmdLenght, uint16_t p_dataLenght, uint8_t p_flag);
	bool sendI2CCommand(uint8_t p_address, uint8_t p_registerOffset, uint16_t cmd_len, uint16_t data_len, uint8_t p_flag);

	uint8_t getCMD(int index);
	uint8_t getDATA(int index);

	void sendSerial(char* p_TxBuffer, unsigned short p_TxBufferSize);
	char receiveSerial();
	bool isSending();
	void setSending(bool p_Sending);

private:
	// Globals for persistent storage
	uint8_t m_CMDArray[I2C_CMD_ARRAY_SIZE];
	uint8_t m_DATAArray[I2C_DATA_ARRAY_SIZE];
};

void initI2C(int p_frequency);

