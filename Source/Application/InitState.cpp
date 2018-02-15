#include "InitState.hpp"

/****************************************************/
InitState::InitState()
{
	stateId = Init;
}

/****************************************************/
InitState::InitState(ILED* p_LED)
{
	m_LED = p_LED;
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
	m_LED->turnON();
	return Init;
}

/****************************************************/
void InitState::onExit()
{

}
