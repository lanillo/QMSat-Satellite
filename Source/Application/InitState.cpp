#include "InitState.hpp"
#include "efm32gg990f1024.h"

/****************************************************/
InitState::InitState()
{
	m_StateId = Init;
}

/****************************************************/
InitState::InitState(ILED* p_LED, ISerialComm* p_USART)
{
	m_LED = p_LED;
	m_USART = p_USART;
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
	m_USART->sendSerial("Entering Init State\n",20);
	m_USART->sendSerial("T024\n",5);
}

/****************************************************/
short InitState::execute()
{
	m_USART->sendSerial("Executing Init State\n",21);

	return Run;
}

/****************************************************/
void InitState::onExit()
{

}
