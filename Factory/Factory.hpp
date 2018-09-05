/*
 * Factory.hpp
 *
 *  Created on: 2018-01-24
 *      Author: Guillaume
 */

#ifndef FACTORY_FACTORY_HPP_
#define FACTORY_FACTORY_HPP_

#include "StateManager.hpp"
#include "InitState.hpp"
#include "RunState.hpp"
#include "LED.hpp"

#include "EFM32_Timer0.hpp"
#include "EFM32_GPIO.hpp"
#include "EFM32_I2C.hpp"

class Factory
{
private:
	/**** StateManager ****/
	bool m_StateManagerCreated;
	StateManager m_StateManager;

	/**** States ****/
	bool m_StatesCreated;
	InitState m_InitState;
	RunState m_RunState;
	void createStates();

	/**** Timer0 ****/
	EFM32_Timer0 m_Timer0;
	bool m_Timer0Created;

	/**** LED ****/
	LED m_LED0;
	bool m_LED0Created;
	void createLED();

	/**** GPIO ****/
	EFM32_GPIO m_GPIO;
	EFM32_GPIO m_GPIO_LED0;
	bool m_GPIOCreated;

	/**** I2C ****/
	EFM32_I2C m_I2C;
	EFM32_I2C m_I2C_0;
	bool m_I2CCreated;

public:
	Factory();
	StateManager* createStateManager();
	EFM32_Timer0* createTimer0();
	EFM32_GPIO* createGPIO();
	EFM32_I2C* createI2C0();
};



#endif /* FACTORY_FACTORY_HPP_ */
