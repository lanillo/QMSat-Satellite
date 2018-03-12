
#include <cxxtest/TestSuite.h>
#include "C:\SourceTree\QMSat_embeded\Tests\Steps\Mocks\GPIO-mock.hpp"
#include "C:\SourceTree\QMSat_embeded\Tests\Steps\Peripherals\LED-evaluator.hpp"
#include "C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Tests\Steps\Peripherals\GPIO-evaluator.hpp"

class FEATURE_GPIO_can_be_initialized : public CxxTest::TestSuite
{
	public:
		void test_GPIO_intialised_as_INPUT_with_OUTPUT_type_0()
		{
			// Create test object
			GPIOEvaluator GPIOEvaluator_;

			// Create GPIO
			GPIOEvaluator_.EFM32_GPIO(pinNumber, bankLetter, isInput, typeIO); // a changer les valeurs

			// Check GPIO state. It must be 0
			TS_ASSERT((GPIOEvaluator_.getGPIOState() == 0));
		};

		void test_GPIO_intialised_as_OUTPUT_with_OUTPUT_type_0()
		{
			// Create test object
			GPIOEvaluator GPIOEvaluator_;

			// Create GPIO
			GPIOEvaluator_.EFM32_GPIO(pinNumber, bankLetter, isInput, typeIO); // a changer les valeurs

			// Check GPIO state. It must be 2
			TS_ASSERT((GPIOEvaluator_.getGPIOState() == 2));
		};

		void test_GPIO_intialised_as_INPUT_with_INPUT_type_0()
		{
			// Create test object
			GPIOEvaluator GPIOEvaluator_;

			// Create GPIO
			GPIOEvaluator_.EFM32_GPIO(pinNumber, bankLetter, isInput, typeIO); // a changer les valeurs

			// Check GPIO state. It must be 1
			TS_ASSERT((GPIOEvaluator_.getGPIOState() == 1));
		};

		void test_GPIO_intialised_as_OUTPUT_with_INPUT_type_0()
		{
			// Create test object
			GPIOEvaluator GPIOEvaluator_;

			// Create GPIO
			GPIOEvaluator_.EFM32_GPIO(pinNumber, bankLetter, isInput, typeIO); // a changer les valeurs

			// Check GPIO state. It must be 0
			TS_ASSERT((GPIOEvaluator_.getGPIOState() == 0));
		};

};

class Feature_GPIO_can_be_turned_off : public CxxTest
{
	public:

		void test_A_GPIO_initially_instantiated_as_an_INPUT
		{
			// Create test object
			GPIOEvaluator GPIOEvaluator_;

			// Create GPIO
			GPIOEvaluator_.EFM32_GPIO(pinNumber, bankLetter, isInput, typeIO); // a changer les valeurs

			// Set GPIO to LOW
			GPIOEvaluator_.readInput();


		}

};


class Feature_LED_can_be_toggle : public CxxTest::TestSuite {
public:
    void test_A_LED_initially_closed_0() {

        LEDEvaluator LEDEvaluator_;

        /* a LED initialize to OFF state */
        LEDEvaluator_.LEDInitialiseOFF();

        /* toggling the LED state */
        LEDEvaluator_.LEDToggle();

        /* the state of the LED is 1 */
        TS_ASSERT(LEDEvaluator_.verifyLEDState(
        1  /* int p_ExpectedState */));

        /* toggling the LED state */
        LEDEvaluator_.LEDToggle();

        /* the state of the LED is 0 */
        TS_ASSERT(LEDEvaluator_.verifyLEDState(
        0  /* int p_ExpectedState */));
    }
    void test_A_LED_initially_opened_0() {

        LEDEvaluator LEDEvaluator_;

        /* a LED initialize to ON state */
        LEDEvaluator_.LEDInitialiseON();

        /* toggling the LED state */
        LEDEvaluator_.LEDToggle();

        /* the state of the LED is 0 */
        TS_ASSERT(LEDEvaluator_.verifyLEDState(
        0  /* int p_ExpectedState */));

        /* toggling the LED state */
        LEDEvaluator_.LEDToggle();

        /* the state of the LED is 1 */
        TS_ASSERT(LEDEvaluator_.verifyLEDState(
        1  /* int p_ExpectedState */));
    }
};

class Feature_LED_can_turn_OFF : public CxxTest::TestSuite {
public:
    void test_A_LED_initially_opened_0() {

        LEDEvaluator LEDEvaluator_;

        /* a LED initialize to ON state */
        LEDEvaluator_.LEDInitialiseON();

        /* turning the LED OFF */
        LEDEvaluator_.LEDTurnOFF();

        /* the state of the LED is 0 */
        TS_ASSERT(LEDEvaluator_.verifyLEDState(
        0  /* int p_ExpectedState */));
    }
};

class Feature_LED_can_turn_ON : public CxxTest::TestSuite {
public:
    void test_A_LED_initially_closed_0() {

        LEDEvaluator LEDEvaluator_;

        /* a LED initialize to OFF state */
        LEDEvaluator_.LEDInitialiseOFF();

        /* turning the LED ON */
        LEDEvaluator_.LEDTurnON();

        /* the state of the LED is 1 */
        TS_ASSERT(LEDEvaluator_.verifyLEDState(
        1  /* int p_ExpectedState */));
    }
};
