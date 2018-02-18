#include "InitState.hpp"

/****************************************************/
InitState::InitState()
{
	m_StateId = Init;
}

/****************************************************/
InitState::InitState(ILED* p_LED)
{
	m_LED = p_LED;
	m_StateId = Init;
}

/****************************************************/
short InitState::getStateId()
{
	return m_StateId;
}

/****************************************************/
void InitState::onEntry()
{
	m_LED->turnON();
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
