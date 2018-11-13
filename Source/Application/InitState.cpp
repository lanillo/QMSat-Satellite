#include "InitState.hpp"
#include "efm32gg990f1024.h"

/****************************************************/
InitState::InitState()
{
	m_stateId = Init;
}

/****************************************************/
InitState::InitState(ILED* p_LED, ISerialComm* p_USART)
{
	m_LED = p_LED;
	m_USART = p_USART;
	m_stateId = Init;
}

/****************************************************/
short InitState::getStateId()
{
	return m_stateId;
}

/****************************************************/
void InitState::onEntry()
{
	//m_USART->sendSerial("Entering Init State\n",20);

}

/****************************************************/
short InitState::execute()
{
	//m_USART->sendSerial("Executing Init State\n",21);

	return Run;
}

/****************************************************/
void InitState::onExit()
{

}
