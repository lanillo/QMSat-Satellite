#include "GPIO-evaluator.hpp"

/**************************************************/
GPIOEvaluator::GPIOEvaluator()
{
    m_PinState = false;
}

/**************************************************/
void GPIOEvaluator::GPIOInitialiseInput(int p_pinNumber, int p_bankLetter, int p_typeIO)
{
    m_UUT = EFM32_GPIO(p_pinNumber, p_bankLetter, true, p_typeIO);
}

/**************************************************/
void GPIOEvaluator::GPIOInitialiseOutput(int p_pinNumber, int p_bankLetter, int p_typeIO)
{
    m_UUT = EFM32_GPIO(p_pinNumber, p_bankLetter, false, p_typeIO);
}

/**************************************************/
bool GPIOEvaluator::verifyInitializeError()
{
    return m_UUT.getError();
}

/**************************************************/
bool GPIOEvaluator::verifyIOType(int p_expectedInput)
{
    if (p_expectedInput == 1)
    {
        return m_UUT.getIsInput();
    }
    else
    {
        return !(m_UUT.getIsInput());
    }
}

/**************************************************/
bool GPIOEvaluator::GPIOSetState(int p_expectedState, int p_GPIOType)
{
    if (p_GPIOType == 0) //If it is an input
    {
        if (p_expectedState == 0) //If it is expected to be low
        {
            return !(m_UUT.setOutputLow()); //Should return false since INPUT
        }

        if (p_expectedState == 1) //If it is expected to be high
        {
            return !(m_UUT.setOutputHigh()); //Should return false since INPUT
        }


        if (p_expectedState == 3) //If it does not matter
        {
            return !(m_UUT.setOutputHigh()); //Should return false since INPUT
        }
    }
    else //if (p_GPIOType == 1) //If it is an output
    {
        if (p_expectedState == 0) //If it is expected to be low
        {
            if (m_UUT.setOutputLow()) //Should return true if successful
            {
                UpdateRegisters(); //Update registers as if it was in the microcontroller
                this->m_PinState = m_UUT.readInput();
                return !(m_UUT.readInput()); // Should return false since it's low
            }
        }

        if (p_expectedState == 1) //If it is expected to be high
        {
            if (m_UUT.setOutputHigh()) //Should return true if successful
            {
                UpdateRegisters(); //Update registers as if it was in the microcontroller
                this->m_PinState = m_UUT.readInput();
                return m_UUT.readInput(); // Should return true since it's high
            }
        }



        // p_expectedState == 3 should never happen since we do care when it is an output
    }
    return false;

}

/**************************************************/
bool GPIOEvaluator::GPIOtoggle()
{

    if (m_UUT.getIsInput()) //If it is an input
    {
        return true; // No change is expected
    }
    else //If it is an output
    {
        return m_UUT.toggleOutput(); // Should be toggled
    }

    return false;

}


/**************************************************/
void GPIOEvaluator::UpdateRegisters()
{

    for(int i = 0; i < NUMBER_OF_BANKS; i++)
    {
        //printf("/****************/\n");

        //printf("Voici le registre avant SET: %d\n",  GPIO->P[i].DOUT);
        GPIO->P[i].DOUT = GPIO->P[i].DOUTSET | GPIO->P[i].DOUT;
        GPIO->P[i].DOUTSET = 0;
        //printf("Voici le registre apres SET: %d\n",  GPIO->P[i].DOUT);

        //printf("Voici le registre avant SET: %d\n",  GPIO->P[i].DOUT);
        GPIO->P[i].DOUT = (GPIO->P[i].DOUTCLR ^ MASK) & GPIO->P[i].DOUT;
        GPIO->P[i].DOUTCLR = 0;
        //printf("Voici le registre apres SET: %d\n",  GPIO->P[i].DOUT);

        //printf("Voici le registre avant SET: %d\n",  GPIO->P[i].DOUT);
        GPIO->P[i].DOUT = GPIO->P[i].DOUT ^ GPIO->P[i].DOUTTGL;
        GPIO->P[i].DOUTTGL = 0;
        //printf("Voici le registre apres SET: %d\n",  GPIO->P[i].DOUT);

        //printf("/****************/\n");
    }
}
