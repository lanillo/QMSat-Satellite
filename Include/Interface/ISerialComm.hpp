/*
 * SerialCom.hpp
 *
 *  Created on: 2018-02-18
 *      Author: Guillaume
 */

#ifndef INCLUDE_INTERFACE_ISERIALCOMM_HPP_
#define INCLUDE_INTERFACE_ISERIALCOMM_HPP_


class ISerialComm
{
public:
	virtual void sendSerial(char* p_TxBuffer, unsigned short p_TxBufferSize) = 0;
	virtual char receiveSerial() = 0;

	ISerialComm() {};
	virtual ~ISerialComm() {};
};


#endif /* INCLUDE_INTERFACE_ISERIALCOMM_HPP_ */