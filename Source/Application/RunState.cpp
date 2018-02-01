/*
 * RunState.cpp
 *
 *  Created on: 2018-01-25
 *      Author: Guillaume
 */

#include "RunState.hpp"

/****************************************************/
RunState::RunState()
{
	stateId = Run;
}

/****************************************************/
short RunState::getStateId()
{
	return stateId;
}

/****************************************************/
void RunState::onEntry()
{

}

/****************************************************/
short RunState::execute()
{
	return Run;
}

/****************************************************/
void RunState::onExit()
{

}


