/*
 * ITimer.hpp
 *
 *  Created on: January 25, 2018
 *   Authors: Luis Anillo
 * 			  Guillaume Beaupré.
 *
 *   \brief ITimer Abstract Class Prototype
 */

#ifndef INCLUDE_INTERFACE_ITIMER_HPP_
#define INCLUDE_INTERFACE_ITIMER_HPP_

class ITimer
{
public:
	ITimer() {};
	virtual ~ITimer() {};

	virtual unsigned int getReferenceTime_microsecond() = 0;
	virtual unsigned int getElapsedTime_microsecond(unsigned int p_ReferenceTime_microsecond) = 0;
};

#endif /* INCLUDE_INTERFACE_ITIMER_HPP_ */
