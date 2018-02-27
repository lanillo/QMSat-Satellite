/*
 * IGPIO.hpp
 *
 *  Created on: 2018-02-14
 *      Author: Guillaume
 *  Created on: Feb 13, 2018
 *      Author: lfani
 */

#ifndef INCLUDE_INTERFACE_IGPIO_HPP_
#define INCLUDE_INTERFACE_IGPIO_HPP_

class IGPIO
{
public:
	IGPIO() {};
	virtual ~IGPIO() {};

	virtual bool readInput() = 0;
	virtual bool setOutputHigh() = 0;
	virtual bool setOutputLow() = 0;
	virtual bool toggleOutput() = 0;
};

#endif /* INCLUDE_INTERFACE_IGPIO_HPP_ */
