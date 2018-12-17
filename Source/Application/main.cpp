/*
 * main.cpp
 *
 *  Created on: January 24, 2018
 *   Authors: Luis Anillo
 * 			      Guillaume Beaupré
 *
 *   \brief main function
 */

//For CHIP_Init which must be called in main
#include "em_chip.h"

#include "Factory.hpp"
#include "Constants.hpp"

int main(void)
{
	/* Initialize chip and check for chip errata */
	CHIP_Init();

	//Creation of the object
	Factory factory = Factory();
	StateManager* stateManager = factory.createStateManager();
	EFM32_Timer0* timer0 = factory.createTimer0();

	// Setup Clock Tree
	factory.clockInit();

	/* Initializations */
	factory.initEFM32Functionnality();

	/* Start the timer and take the first reference time */
	static unsigned int referenceTime_microsecond;
	timer0->start();
	referenceTime_microsecond = timer0->getReferenceTime_microsecond();

	/* Main program loop */
	while (true)
	{
		if (timer0->getElapsedTime_microsecond(referenceTime_microsecond) >= TIME_1_SECOND)
		{
			stateManager->execute(); //Principal execution of the code
			referenceTime_microsecond = timer0->getReferenceTime_microsecond(); // restart the time counter for the execution loop
		}
	}

}

