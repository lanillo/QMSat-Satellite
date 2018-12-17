#include "InitState.hpp"
#include "efm32gg990f1024.h"

/****************************************************/
/**
* \brief By default Object constructor for the INIT State
* \return None
*/
InitState::InitState()
{
	m_stateId = Init;
}

/****************************************************/
/**
* \brief Object constructor for the INIT State
* \param[in] p_UartUI 	:  Pointer to the USART1 Object
* \param[in] p_AlimManager 	:  Pointer to the AlimManager Object
* \return None
*/
InitState::InitState(ISerialComm* p_UartUI, AlimManager* p_AlimManager)
{
	m_UartUI = p_UartUI;
	m_stateId = Init;
	m_AlimManager = p_AlimManager;

	m_SwitchValue[0] = 'S';
	m_SwitchValue[2] = '\n';
}

/****************************************************/
/**
* \brief Return the unique identifier of the state
* \return 0 for the INIT state
*/
short InitState::getStateId()
{
	return m_stateId;
}

/****************************************************/
/**
* \brief Execute the initial action when entering the state
* \return None
*/
void InitState::onEntry()
{
	m_UartUI->sendSerial("Initiation of QMSat Sattelite\n",30);
}

/****************************************************/
/**
* \brief Execute the normal set of actions for this state
* \return ID of the next state to be execute
*/
short InitState::execute()
{
	m_SwitchValue[1] = m_AlimManager->getSwitchState();
	m_UartUI->sendSerial(m_SwitchValue,3);

	return Run;
}

/****************************************************/
/**
* \brief Execute the initial action when exiting the state
* \return None
*/
void InitState::onExit()
{

}
