/*
 * ILED.hpp
 *
 *  Created on: January 25, 2018
 *   Authors: Luis Anillo
 * 			  Guillaume Beaupré.
 *
 *   \brief ILED Abstract Class Prototype
 */

#ifndef INCLUDE_INTERFACE_ILED_HPP_
#define INCLUDE_INTERFACE_ILED_HPP_

class ILED
{
public:
	ILED() {};
	virtual ~ILED() {};

	virtual void turnOFF() = 0;
	virtual void turnON() = 0;
	virtual void toggle() = 0;
};



#endif /* INCLUDE_INTERFACE_ILED_HPP_ */
