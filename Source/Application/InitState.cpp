#include "InitState.hpp"

/****************************************************/
InitState::InitState()
{
	m_StateId = Init;
}

/****************************************************/
InitState::InitState(ILED* p_LED,ISerialComm* p_EFM32_USART1)
{
	m_LED = p_LED;
	m_EFM32_USART1 = p_EFM32_USART1;
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
	m_EFM32_USART1->sendSerial("Hello Fucking world!\r\n");
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
