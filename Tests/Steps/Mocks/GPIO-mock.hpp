/*
 * GPIO-mock.hpp
 *
 *  Created on: 2018-02-18
 *      Author: Guillaume
 */

#ifndef GPIO_MOCK_HPP_
#define GPIO_MOCK_HPP_

#include "IGPIO.hpp"

class GPIOMock: public IGPIO
{
private:
	bool m_PinState;
	int m_GPIOState; // 0 -> error; 1 -> INPUT; 2 -> OUTPUT
	bool m_readState;
public:
	GPIOMock() {m_PinState = false;};
	~GPIOMock() {};

	void EFM32_GPIO(unsigned short pinNumber, unsigned short bankLetter, bool isInput, int typeIO) 
	{
		if (pinNumber >= 0 && pinNumber < 16)
		{
			if (bankLetter >= 0 && bankLetter < 5)
			{
				if (isInput) 
				{
					if (typeIO < 4 && typeIO >= 0)
						m_GPIOState = 1;
					else
						m_GPIOState = 0;
				} else 
				{
					if (typeIO >= 4 && typeIO <= 13)
						m_GPIOState = 2;
					else
						m_GPIOState = 0;
				}				
			} 
			else
				m_GPIOState = 0;					
		}
		else
			m_GPIOState = 0;			
	};
	
	bool readInput() 
	{
		if (m_GPIOState = 1)
		{
			m_readState = true;
			return true;
		}
		else
			m_readState = false;
			return false;
	}
	
	int getGPIOState() {return m_GPIOState;};
	
	
	void turnON() {m_PinState = true;};
	void turnOFF() {m_PinState = false;};
	
	bool getPinState() {return m_PinState;};
	bool getReadState() {return m_readState;};
	int getGPIOState() {return m_GPIOState;};
};

#endif /* GPIO_MOCK_HPP_ */
