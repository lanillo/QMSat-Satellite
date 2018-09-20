/*
 * ITimer.hpp
 *
 *  Created on: 2018-01-25
 *      Author: guillaume
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
