/*
 * IState.hpp
 *
 *  Created on: 2018-01-23
 *      Author: Guillaume
 */

#ifndef INCLUDE_INTERFACE_ISTATE_HPP_
#define INCLUDE_INTERFACE_ISTATE_HPP_

enum States
{
	Init,
	Run,
	Econo
};

class IState
{
public:
	IState() {};
	virtual ~IState() {};

	virtual short getStateId() = 0;

	virtual void onEntry() = 0;
	virtual void onExit() = 0;
	virtual short execute() = 0;
};

#endif /* INCLUDE_INTERFACE_ISTATE_HPP_ */
