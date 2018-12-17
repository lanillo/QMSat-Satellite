/*
 * IState.hpp
 *
 *  Created on: January 23, 2018
 *   Authors: Luis Anillo
 * 			  Guillaume Beaupré.
 *
 *   \brief IState Abstract Class Prototype
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
