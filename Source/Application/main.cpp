
//For CHIP_Init which must be called in main
#include "em_chip.h"

#include "Factory.hpp"
#include "Constants.hpp"

void auditBatterySimulator(Factory* factory);

// Globals for persistent storage
uint8_t cmd_array[I2C_CMD_ARRAY_SIZE];
uint8_t data_array[I2C_DATA_ARRAY_SIZE];

int main(void)
{
    /* Initialize chip and check for chip errata */
	CHIP_Init();

	// Setup Clock Tree
	CMU_ClockDivSet(cmuClock_HF, cmuClkDiv_2);			// Set HF clock divider to /2 to keep core frequency < 32MHz
	CMU_OscillatorEnable(cmuOsc_HFXO, true, true);   	// Enable XTAL OSC and wait to stabilize
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO); 	// Select HF XTAL osc as system clock source. 48MHz XTAL, but we divided the system clock by 2, therefore our HF clock will be 24MHz

    CMU_ClockEnable(cmuClock_GPIO, true);       		// Enable GPIO peripheral clock
    CMU_ClockEnable(cmuClock_USART0, true);				// Enable USART0 peripheral clock
    CMU_ClockEnable(cmuClock_USART1, true);				// Enable USART1 peripheral clock
    CMU_ClockEnable(cmuClock_TIMER0, true);				// Enable Timer_0 peripheral clock
    //CMU_ClockEnable(cmuClock_I2C1, true);				// Enable I2C1 peripheral clock

    Factory factory = Factory();
    StateManager* stateManager = factory.createStateManager();
    EFM32_Timer0* timer0 = factory.createTimer0();
    EFM32_I2C* I2C = factory.createI2C();
    EFM32_PWM* PWM0 = factory.createPWM();
    factory.createGPIO();

    /* Initializations */
    initTimer0();
    initSPI();
    initUSART1();
    initI2C();

    timer0->start();

    static unsigned int referenceTime_microsecond;
    bool sendI2CCommandDelay = false;
    referenceTime_microsecond = timer0->getReferenceTime_microsecond();

    /*cmd_array[0] = 0x05;
	I2C->transfer(TEMP_SENSOR_ADDRESS, cmd_array, data_array, 1, 1, I2C_FLAG_WRITE);

	while(timer0 ->getElapsedTime_microsecond(referenceTime_microsecond) <= TIME_1_SECOND/1000){};

	cmd_array[0] = 0x05;
	I2C->transfer(TEMP_SENSOR_ADDRESS, cmd_array, data_array, 1, 2, I2C_FLAG_READ);*/

    /* Infinite loop */
	referenceTime_microsecond = timer0->getReferenceTime_microsecond();
    while (true)
    {
    	if (timer0->getElapsedTime_microsecond(referenceTime_microsecond) >= TIME_1_SECOND)
    	{
    		if (factory.m_PB0.readInput())
    		{
    			PWM0->onAndOffLED();
    		}

    		stateManager->execute();
    		referenceTime_microsecond = timer0->getReferenceTime_microsecond();

    		auditBatterySimulator(&factory);

    		sendI2CCommandDelay = false;
    	}

		if (!factory.m_PB1.readInput())
		{
			if (!sendI2CCommandDelay)
			{
				I2C->writeCommand(ACCELEROMETER_ADDRESS, 0x00, I2C_WRITE_READ);
				sendI2CCommandDelay = true;
			}
		}
    }
}

// Temp pour laudit
void auditBatterySimulator(Factory* factory)
{
	static int count = 0;
	static bool goingUp = true;

	switch (count)
		{
			case 0:
				if (goingUp)
				{
					count++;
				}
				else
				{
					factory->m_BAT.D0D1.setOutputLow();
					count--;
				}
				break;

			case 1:
				if (goingUp)
				{
					factory->m_BAT.D0D1.setOutputHigh();
					count++;
				}
				else
				{
					count--;
				}
				break;

			case 20:
				if (goingUp)
				{
					count++;
				}
				else
				{
					factory->m_BAT.D2D3.setOutputLow();
					count--;
				}
				break;

			case 21:
				if (goingUp)
				{
					factory->m_BAT.D2D3.setOutputHigh();
					count++;
				}
				else
				{
					count--;
				}
				break;

			case 40:
				if (goingUp)
				{
					count++;
				}
				else
				{
					factory->m_BAT.D4D5.setOutputLow();
					count--;
				}

				break;

			case 41:
				if (goingUp)
				{
					factory->m_BAT.D4D5.setOutputHigh();
					count++;
				}
				else
				{
					count--;
				}

				break;

			case 60:
				if (goingUp)
				{

					count++;
				}
				else
				{
					factory->m_BAT.D6D7.setOutputLow();
					count--;
				}
				break;

			case 61:
				if (goingUp)
				{
					factory->m_BAT.D6D7.setOutputHigh();
					count++;
				}
				else
				{
					count--;
				}
				break;

			case 80:
				if (goingUp)
				{
					count++;
				}
				else
				{
					factory->m_BAT.D8D9.setOutputLow();
					count--;
				}
				break;

			case 81:
				if (goingUp)
				{
					factory->m_BAT.D8D9.setOutputHigh();
					count++;
				}
				else
				{
					count--;
				}
				break;

			default:
				if(count == -1)
					goingUp = true;
				else if (count == 101)
					goingUp = false;

				if (goingUp)
				{
					count++;
				} else
				{
					count--;
				}

		}
	if(count == 0){factory->m_EFM32_USART1.sendSerial("B000\n",5);}
		else if(count == 1){factory->m_EFM32_USART1.sendSerial("B001\n",5);}
		else if(count == 2){factory->m_EFM32_USART1.sendSerial("B002\n",5);}
		else if(count == 3){factory->m_EFM32_USART1.sendSerial("B003\n",5);}
		else if(count == 4){factory->m_EFM32_USART1.sendSerial("B004\n",5);}
		else if(count == 5){factory->m_EFM32_USART1.sendSerial("B005\n",5);}
		else if(count == 6){factory->m_EFM32_USART1.sendSerial("B006\n",5);}
		else if(count == 7){factory->m_EFM32_USART1.sendSerial("B007\n",5);}
		else if(count == 8){factory->m_EFM32_USART1.sendSerial("B008\n",5);}
		else if(count == 9){factory->m_EFM32_USART1.sendSerial("B009\n",5);}
		else if(count == 10){factory->m_EFM32_USART1.sendSerial("B010\n",5);}
		else if(count == 11){factory->m_EFM32_USART1.sendSerial("B011\n",5);}
		else if(count == 12){factory->m_EFM32_USART1.sendSerial("B012\n",5);}
		else if(count == 13){factory->m_EFM32_USART1.sendSerial("B013\n",5);}
		else if(count == 14){factory->m_EFM32_USART1.sendSerial("B014\n",5);}
		else if(count == 15){factory->m_EFM32_USART1.sendSerial("B015\n",5);}
		else if(count == 16){factory->m_EFM32_USART1.sendSerial("B016\n",5);}
		else if(count == 17){factory->m_EFM32_USART1.sendSerial("B017\n",5);}
		else if(count == 18){factory->m_EFM32_USART1.sendSerial("B018\n",5);}
		else if(count == 19){factory->m_EFM32_USART1.sendSerial("B019\n",5);}
		else if(count == 20){factory->m_EFM32_USART1.sendSerial("B020\n",5);}
		else if(count == 21){factory->m_EFM32_USART1.sendSerial("B021\n",5);}
		else if(count == 22){factory->m_EFM32_USART1.sendSerial("B022\n",5);}
		else if(count == 23){factory->m_EFM32_USART1.sendSerial("B023\n",5);}
		else if(count == 24){factory->m_EFM32_USART1.sendSerial("B024\n",5);}
		else if(count == 25){factory->m_EFM32_USART1.sendSerial("B025\n",5);}
		else if(count == 26){factory->m_EFM32_USART1.sendSerial("B026\n",5);}
		else if(count == 27){factory->m_EFM32_USART1.sendSerial("B027\n",5);}
		else if(count == 28){factory->m_EFM32_USART1.sendSerial("B028\n",5);}
		else if(count == 29){factory->m_EFM32_USART1.sendSerial("B029\n",5);}
		else if(count == 30){factory->m_EFM32_USART1.sendSerial("B030\n",5);}
		else if(count == 31){factory->m_EFM32_USART1.sendSerial("B031\n",5);}
		else if(count == 32){factory->m_EFM32_USART1.sendSerial("B032\n",5);}
		else if(count == 33){factory->m_EFM32_USART1.sendSerial("B033\n",5);}
		else if(count == 34){factory->m_EFM32_USART1.sendSerial("B034\n",5);}
		else if(count == 35){factory->m_EFM32_USART1.sendSerial("B035\n",5);}
		else if(count == 36){factory->m_EFM32_USART1.sendSerial("B036\n",5);}
		else if(count == 37){factory->m_EFM32_USART1.sendSerial("B037\n",5);}
		else if(count == 38){factory->m_EFM32_USART1.sendSerial("B038\n",5);}
		else if(count == 39){factory->m_EFM32_USART1.sendSerial("B039\n",5);}
		else if(count == 40){factory->m_EFM32_USART1.sendSerial("B040\n",5);}
		else if(count == 41){factory->m_EFM32_USART1.sendSerial("B041\n",5);}
		else if(count == 42){factory->m_EFM32_USART1.sendSerial("B042\n",5);}
		else if(count == 43){factory->m_EFM32_USART1.sendSerial("B043\n",5);}
		else if(count == 44){factory->m_EFM32_USART1.sendSerial("B044\n",5);}
		else if(count == 45){factory->m_EFM32_USART1.sendSerial("B045\n",5);}
		else if(count == 46){factory->m_EFM32_USART1.sendSerial("B046\n",5);}
		else if(count == 47){factory->m_EFM32_USART1.sendSerial("B047\n",5);}
		else if(count == 48){factory->m_EFM32_USART1.sendSerial("B048\n",5);}
		else if(count == 49){factory->m_EFM32_USART1.sendSerial("B049\n",5);}
		else if(count == 40){factory->m_EFM32_USART1.sendSerial("B050\n",5);}
		else if(count == 50){factory->m_EFM32_USART1.sendSerial("B051\n",5);}
		else if(count == 52){factory->m_EFM32_USART1.sendSerial("B052\n",5);}
		else if(count == 53){factory->m_EFM32_USART1.sendSerial("B053\n",5);}
		else if(count == 54){factory->m_EFM32_USART1.sendSerial("B054\n",5);}
		else if(count == 55){factory->m_EFM32_USART1.sendSerial("B055\n",5);}
		else if(count == 56){factory->m_EFM32_USART1.sendSerial("B056\n",5);}
		else if(count == 57){factory->m_EFM32_USART1.sendSerial("B057\n",5);}
		else if(count == 58){factory->m_EFM32_USART1.sendSerial("B058\n",5);}
		else if(count == 59){factory->m_EFM32_USART1.sendSerial("B059\n",5);}
		else if(count == 60){factory->m_EFM32_USART1.sendSerial("B060\n",5);}
		else if(count == 61){factory->m_EFM32_USART1.sendSerial("B061\n",5);}
		else if(count == 62){factory->m_EFM32_USART1.sendSerial("B062\n",5);}
		else if(count == 63){factory->m_EFM32_USART1.sendSerial("B063\n",5);}
		else if(count == 64){factory->m_EFM32_USART1.sendSerial("B064\n",5);}
		else if(count == 65){factory->m_EFM32_USART1.sendSerial("B065\n",5);}
		else if(count == 66){factory->m_EFM32_USART1.sendSerial("B066\n",5);}
		else if(count == 67){factory->m_EFM32_USART1.sendSerial("B067\n",5);}
		else if(count == 68){factory->m_EFM32_USART1.sendSerial("B068\n",5);}
		else if(count == 69){factory->m_EFM32_USART1.sendSerial("B069\n",5);}
		else if(count == 70){factory->m_EFM32_USART1.sendSerial("B070\n",5);}
		else if(count == 71){factory->m_EFM32_USART1.sendSerial("B071\n",5);}
		else if(count == 72){factory->m_EFM32_USART1.sendSerial("B072\n",5);}
		else if(count == 73){factory->m_EFM32_USART1.sendSerial("B073\n",5);}
		else if(count == 74){factory->m_EFM32_USART1.sendSerial("B074\n",5);}
		else if(count == 75){factory->m_EFM32_USART1.sendSerial("B075\n",5);}
		else if(count == 76){factory->m_EFM32_USART1.sendSerial("B076\n",5);}
		else if(count == 77){factory->m_EFM32_USART1.sendSerial("B077\n",5);}
		else if(count == 78){factory->m_EFM32_USART1.sendSerial("B078\n",5);}
		else if(count == 79){factory->m_EFM32_USART1.sendSerial("B079\n",5);}
		else if(count == 80){factory->m_EFM32_USART1.sendSerial("B080\n",5);}
		else if(count == 81){factory->m_EFM32_USART1.sendSerial("B081\n",5);}
		else if(count == 82){factory->m_EFM32_USART1.sendSerial("B082\n",5);}
		else if(count == 83){factory->m_EFM32_USART1.sendSerial("B083\n",5);}
		else if(count == 84){factory->m_EFM32_USART1.sendSerial("B084\n",5);}
		else if(count == 85){factory->m_EFM32_USART1.sendSerial("B085\n",5);}
		else if(count == 86){factory->m_EFM32_USART1.sendSerial("B086\n",5);}
		else if(count == 87){factory->m_EFM32_USART1.sendSerial("B087\n",5);}
		else if(count == 88){factory->m_EFM32_USART1.sendSerial("B088\n",5);}
		else if(count == 89){factory->m_EFM32_USART1.sendSerial("B089\n",5);}
		else if(count == 90){factory->m_EFM32_USART1.sendSerial("B090\n",5);}
		else if(count == 91){factory->m_EFM32_USART1.sendSerial("B091\n",5);}
		else if(count == 92){factory->m_EFM32_USART1.sendSerial("B092\n",5);}
		else if(count == 93){factory->m_EFM32_USART1.sendSerial("B093\n",5);}
		else if(count == 94){factory->m_EFM32_USART1.sendSerial("B094\n",5);}
		else if(count == 95){factory->m_EFM32_USART1.sendSerial("B095\n",5);}
		else if(count == 96){factory->m_EFM32_USART1.sendSerial("B096\n",5);}
		else if(count == 97){factory->m_EFM32_USART1.sendSerial("B097\n",5);}
		else if(count == 98){factory->m_EFM32_USART1.sendSerial("B098\n",5);}
		else if(count == 99){factory->m_EFM32_USART1.sendSerial("B099\n",5);}
		else if(count == 100){factory->m_EFM32_USART1.sendSerial("B100\n",5);}
}
