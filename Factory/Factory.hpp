/*
 * Factory.hpp
 *
 *  Created on: 2018-01-24
 *      Author: Guillaume Beaupré
 */

#ifndef FACTORY_FACTORY_HPP_
#define FACTORY_FACTORY_HPP_

#include "StateManager.hpp"
#include "InitState.hpp"
#include "RunState.hpp"
#include "EconoState.hpp"

#include "EFM32_Timer0.hpp"
#include "EFM32_GPIO.hpp"
#include "EFM32_USART1.hpp"
#include "EFM32_SPI.hpp"
#include "EFM32_I2C.hpp"
#include "EFM32_PWM.hpp"
#include "LED.hpp"

#include "em_cmu.h"

#include "Constants.hpp"

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
	EconoState m_EconoState;
	void createStates();

	/**** Timer0 ****/
	EFM32_Timer0 m_Timer0;
	bool m_Timer0Created;

	/**** LED0 ****/
	LED m_LED0;
	bool m_LED0Created;
	void createLED();

	/**** USART0 ****/
	EFM32_USART1 m_EFM32_USART1;
	bool m_USART1Created;
	void createUSART1();

	/**** SPI ****/
	EFM32_SPI m_EFM32_SPI;
	bool m_SPICreated;
	void createSPI();

	/**** GPIO ****/
	EFM32_GPIO m_GPIO;
	EFM32_GPIO m_PB0;
	EFM32_GPIO m_PB1;
	bool m_GPIOCreated;
	void createGPIO();

	/**** I2C ****/
	EFM32_I2C m_I2C;
	bool m_I2CCreated;
	void createI2C();

	/**** PWM ****/
	EFM32_PWM m_PWM;
	bool m_PWMCreated;
	void createPWM();

public:
	Factory();
	StateManager* createStateManager();
	EFM32_Timer0* createTimer0();

	void initEFM32Functionnality();
	void clockInit();
};

#endif /* FACTORY_FACTORY_HPP_ */
