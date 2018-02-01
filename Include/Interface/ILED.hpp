/*
 * ILED.hpp
 *
 *  Created on: 2018-01-25
 *      Author: guillaume
 */

#ifndef INCLUDE_INTERFACE_ILED_HPP_
#define INCLUDE_INTERFACE_ILED_HPP_

class ILED
{
public:
	ILED() {};
	virtual ~ILED();

	virtual void turnOFF() = 0;
	virtual void turnON() = 0;
	virtual void toggle() = 0;
};



#endif /* INCLUDE_INTERFACE_ILED_HPP_ */
