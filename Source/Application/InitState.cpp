#include "InitState.hpp"

/****************************************************/
InitState::InitState()
{
	stateId = Init;
}

/****************************************************/
short InitState::getStateId()
{
	return stateId;
}

/****************************************************/
void InitState::onEntry()
{

}

/****************************************************/
short InitState::execute()
{
	return Init;
}

/****************************************************/
void InitState::onExit()
{

}
