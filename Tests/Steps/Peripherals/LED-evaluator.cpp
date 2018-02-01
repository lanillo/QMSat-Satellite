#include "LED-evaluator.hpp"

LEDEvaluator::LEDEvaluator() 
{
	
}
	
void LEDEvaluator::LEDTurnOFF()
{
	m_LED = LED(13);
	m_LED.turnOff();
}
	
