#include "LED-evaluator.hpp"

/**************************************************/
LEDEvaluator::LEDEvaluator()
{
    m_GPIOMock = GPIOMock();
    m_LED = LED(&m_GPIOMock);
}

/**************************************************/
void LEDEvaluator::LEDInitialiseOFF()
{
    m_LED.turnOFF();
}

/**************************************************/
void LEDEvaluator::LEDInitialiseON()
{
    m_LED.turnON();
}

/**************************************************/
void LEDEvaluator::LEDTurnON()
{
	m_LED.turnON();
}

/**************************************************/
void LEDEvaluator::LEDTurnOFF()
{
	m_LED.turnOFF();
}

/**************************************************/
void LEDEvaluator::LEDToggle()
{
    m_LED.toggle();
}

/**************************************************/
bool LEDEvaluator::verifyLEDState(int p_ExpectedState)
{
	return p_ExpectedState == m_LED.getStatus();
}
