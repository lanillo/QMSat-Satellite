/*
 * Factory.cpp
 *
 *  Created on: January 24, 2018
 *   Authors: Luis Anillo
 * 			  Guillaume Beaupré.
 *
 *   \brief Creates all objects necessary for the execution of the code
 */

#include "Factory.hpp"

/****************************************************/
/**
* \brief Initialise the created state of each object and start-up the different clocks
* \return None
*/
Factory::Factory()
{
	m_StateManagerCreated = false;
	m_StatesCreated = false;

	m_AlimManagerCreated = false;

	m_Timer0Created = false;
	m_LED0Created = false;
	m_USART1Created = false;
	m_UART0Created = false;
	m_SPICreated = false;
	m_GPIOCreated = false;
	m_I2CCreated = false;
	m_PWMCreated = false;

	// Setup Clock Tree
	this->clockInit();
}

/****************************************************/
/**
* \brief Creates the StateManager object and add the states to it
* \return StateManager Object pointer
*/
StateManager* Factory::createStateManager()
{
	createStates();

	if(m_StateManagerCreated == false)
	{
		m_StateManager = StateManager(&m_InitState);

		m_StateManager.addState(&m_RunState);
		m_StateManager.addState(&m_EconoState);
	}
	return &m_StateManager;
}

/****************************************************/
/**
* \brief Creates the different state to be use in the StateManager
* \return None
*/
void Factory::createStates()
{
	createUSART1();
	createUART0();
	createLED();
	createAlimManager();
	createMCPTempSense();
	if(m_StatesCreated == false)
	{
		m_InitState = InitState(&m_UartUI,&m_AlimManager);
		m_RunState = RunState(&m_UartUI, &m_UartAlim, &m_AlimManager, &m_MCPTempSense);
		m_EconoState = EconoState(&m_UartUI, &m_AlimManager);

		m_StatesCreated = true;
	}
}

/****************************************************/
/**
* \brief Creates the AlimManager object
* \return None
*/
void Factory::createAlimManager()
{
	if(m_AlimManagerCreated == false)
	{
		m_AlimManager = AlimManager();

		m_AlimManagerCreated = true;
	}
}

/****************************************************/
/**
* \brief This function is useless at the moment
* \return None
*/
void Factory::createLED()
{
  if(m_LED0Created == false)
  {

  }
}

/****************************************************/
/**
* \brief Creates the different GPIO objects
* \return None
*/
void Factory::createGPIO()
{
	if(m_GPIOCreated == false)
	{
		/***** PWM *****/
		EFM32_GPIO LED0(BSP_GPIO_LED0_PORT, BSP_GPIO_LED0_PIN, gpioModePushPull, 0); // set LED0 (PE2) pin as push-pull output

	    /***** GPIO *****/
		m_PB0 = EFM32_GPIO(BSP_GPIO_PB0_PORT, BSP_GPIO_PB0_PIN, gpioModeInput, 1); // set PBO button (B9) as input
		m_PB1 = EFM32_GPIO(BSP_GPIO_PB1_PORT, BSP_GPIO_PB1_PIN, gpioModeInput, 1); // set PB1 button (B10) as input

		m_GPIOCreated = true;
	}
}

/****************************************************/
/**
* \brief Creates USART object used for the communication with the UI
* \return None
*/
void Factory::createUSART1()
{
	if(m_USART1Created == false)
	{
		m_UartUI = EFM32_USART1(9600, _USART_FRAME_STOPBITS_ONE, _USART_FRAME_PARITY_NONE);
		callbackUSART1Init(&EFM32_USART1::callbackForSerialTransmit, &EFM32_USART1::callbackForSerialReceive, (void*)&m_UartUI);

		m_USART1Created = true;
	}
}

/****************************************************/
/**
* \brief Creates UART object used for the communication with the Alim uC
* \return None
*/
void Factory::createUART0()
{
	createAlimManager();
	if(m_UART0Created == false)
	{
		m_UartAlim = EFM32_UART0(9600, _USART_FRAME_STOPBITS_ONE, _USART_FRAME_PARITY_NONE);
		callbackUART0Init(&EFM32_UART0::callbackForSerialTransmit, &AlimManager::callbackForSerialReceive, (void*)&m_UartAlim, (void*)&m_AlimManager);

		m_UART0Created = true;
	}
}

/****************************************************/
/**
* \brief Creates SPI object used for the communication with the Magnetometer
* \return None
*/
void Factory::createSPI()
{
	if(m_SPICreated == false)
	{
		m_EFM32_SPI = EFM32_SPI(9600, true);
	}
}

/****************************************************/
/**
* \brief Creates Timer object used for the loop of the 	StateManager execution
* \return None
*/
EFM32_Timer0* Factory::createTimer0()
{
	if(m_Timer0Created == false)
	{
		m_Timer0 = EFM32_Timer0(TIME_100_MICROSECONDS);
		m_Timer0Created = true;
	}
	return &m_Timer0;
}

/****************************************************/
/**
* \brief Creates I2C object used for several peripherals
* \return None
*/
void Factory::createI2C()
{
	if(m_I2CCreated == false)
	{
		//Route PC6 abd PC7 to I2C0
		m_I2C = EFM32_I2C();

		/***** I2C *****/
		/* MUST BE initialized after ROUTE of I2C to avoid glitches */
	    /* Output value must be set to 1 to not drive lines low. Set SCL first, to ensure it is high before changing SDA. */
	    EFM32_GPIO SCL(gpioPortC, 7, gpioModeWiredAndPullUpFilter, 1);	// PD7(I2C0) #1 - PC5(I2C1) #0 - PC7(I2C0) #1 - SCL
	    EFM32_GPIO SDA(gpioPortC, 6, gpioModeWiredAndPullUpFilter, 1);	// PD6(I2C0) #1 - PC4(I2C1) #0 - PC6(I2C0) #1 - SDA

		m_I2CCreated = true;
	}
}

/****************************************************/
/**
* \brief Creates PWM object
* \return None
*/
void Factory::createPWM()
{
	if(m_PWMCreated == false)
	{
		m_PWM = EFM32_PWM(PWM_DUTY_CYCLE);
		m_PWMCreated = true;
	}
}

/****************************************************/
/**
* \brief Creates the different Temperature Sensors objects
* \return None
*/
void Factory::createMCPTempSense()
{
	createI2C();

	if(m_MCPTempSenseCreated == false)
	{
		m_MCPTempSense = MCP9808TempSensor(&m_I2C ,TEMP_SENSOR_ADDRESS);
		m_MCPTempSenseCreated = true;
	}
}

/****************************************************/
/**
* \brief start all the initialization of the EFM32 functionalities
* \return None
*/
void Factory::initEFM32Functionnality()
{
	initTimer0();
	initSPI();
	initUSART1();
	initUART0();
	initI2C(I2C_BUS_FREQUENCY);
}

/****************************************************/
/**
* \brief Initialize the clocks of the uC functionalities
* \return None
*/
void Factory::clockInit()
{
	// Setup Clock Tree
	CMU_ClockDivSet(cmuClock_HF, cmuClkDiv_2);			// Set HF clock divider to /2 to keep core frequency < 32MHz
	CMU_OscillatorEnable(cmuOsc_HFXO, true, true);   	// Enable XTAL OSC and wait to stabilize
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO); 	// Select HF XTAL osc as system clock source. 48MHz XTAL, but we divided the system clock by 2, therefore our HF clock will be 24MHz

    CMU_ClockEnable(cmuClock_GPIO, true);       // Enable GPIO peripheral clock
    CMU_ClockEnable(cmuClock_ADC0, true);		// Enable ADC peripheral clock
    CMU_ClockEnable(cmuClock_USART1, true);		// Enable USART1 peripheral clock
    CMU_ClockEnable(cmuClock_UART0, true);		// Enable UART0 peripheral clock
    CMU_ClockEnable(cmuClock_TIMER0, true);		// Enable Timer_0 peripheral clock
    CMU_ClockEnable(cmuClock_TIMER3, true);		// Enable Timer_3 peripheral clock, PWM
    CMU_ClockEnable(cmuClock_I2C0, true);		// Enable I2C0 peripheral clock
}
