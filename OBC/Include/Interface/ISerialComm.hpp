/*
 * SerialCom.hpp
 *
 *  Created on: February 18, 2018
 *   Authors: Luis Anillo
 * 			  Guillaume Beaupré.
 *
 *   \brief ISerialComm Abstract Class Prototype
 */

#ifndef INCLUDE_INTERFACE_ISERIALCOMM_HPP_
#define INCLUDE_INTERFACE_ISERIALCOMM_HPP_

class ISerialComm
{
public:
	virtual void sendSerial(char* p_TxBuffer, unsigned short p_TxBufferSize) = 0;
	virtual char receiveSerial() = 0;
	virtual bool isSending() = 0;
	virtual void setSending(bool p_Sending) = 0;
	//virtual bool sendI2CCommand(uint8_t p_address, uint8_t p_registerOffset, uint16_t cmd_len, uint16_t data_len, uint8_t p_flag) = 0;

	ISerialComm() {};
	virtual ~ISerialComm() {};
};


#endif /* INCLUDE_INTERFACE_ISERIALCOMM_HPP_ */
