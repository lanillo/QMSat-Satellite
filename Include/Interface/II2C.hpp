/*
 * II2C.hpp
 *
 *  Created on: Aug 15, 2018
 *      Author: lfani
 */

#ifndef INCLUDE_INTERFACE_II2C_HPP_
#define INCLUDE_INTERFACE_II2C_HPP_

class II2C
{
public:
	II2C() {};
	virtual ~II2C() {};

	virtual void Write() = 0;
	virtual void Read() = 0;
};

#endif /* INCLUDE_INTERFACE_II2C_HPP_ */
