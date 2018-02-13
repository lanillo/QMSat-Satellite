#include "LED-evaluator.hpp"

LEDEvaluator::LEDEvaluator()
{
    m_LED = LED();
}

void LEDEvaluator::LEDTurnOFF()
{
	m_LED.turnOFF();
}

bool LEDEvaluator::verifyLED()
{
    return true;
}
