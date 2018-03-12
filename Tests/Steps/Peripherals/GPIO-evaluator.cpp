#include "GPIO-evaluator.hpp"

/**************************************************/
GPIOEvaluator::GPIOEvaluator()
{

}

/**************************************************/
void GPIOEvaluator::GPIOInitialiseINPUT(int p_pinNumber, int p_bankLetter, int p_typeIO);
{
    m_UUT.EFM32_GPIO(p_pinNumber, p_bankLetter, true, p_typeIO);
}

/**************************************************/
bool GPIOEvaluator::verifyInitializeError();
{
    return m_UUT.getError();
}

/**************************************************/
void GPIOEvaluator::GPIOReadINPUT()
{
	m_UUT.readInput();
}

/**************************************************/
void GPIOEvaluator::GPIOReadOUTPUT()
{
	m_UUT.readInput();
}

/**************************************************/
void GPIOEvaluator::GPIOSetOUTPUTtoHIGH()
{
	m_UUT.setOutputHigh();
}

/**************************************************/
void GPIOEvaluator::GPIOSetINPUTtoHIGH()
{
	m_UUT.setOutputHigh();
}

/**************************************************/
void GPIOEvaluator::GPIOSetOUTPUTtoLOW()
{
	m_UUT.setOutputLow();
}

/**************************************************/
void GPIOEvaluator::GPIOSetINPUTtoLOW()
{
	m_UUT.setOutputLow();
}

/**************************************************/
void GPIOEvaluator::GPIOToggleOUTPUTtoHIGH()
{
	m_UUT.toggleOutput();
}

/**************************************************/
void GPIOEvaluator::GPIOToggleOUTPUTtoLOW()
{
	m_UUT.toggleOutput();
}

/**************************************************/
void GPIOEvaluator::GPIOToggleINPUTtoHIGH()
{
	m_UUT.toggleOutput();
}

/**************************************************/
void GPIOEvaluator::GPIOToggleINPUTtoLOW()
{
	m_UUT.toggleOutput();
}
