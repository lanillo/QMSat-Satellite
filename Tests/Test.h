
#include <cxxtest/TestSuite.h>
#include "C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Tests\Steps\Mocks\GPIO-mock.hpp"
#include "C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Tests\Steps\Peripherals\GPIO-evaluator.hpp"
#include "C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Tests\Steps\Peripherals\LED-evaluator.hpp"


class Feature_GPIO_can_be_initialized_as_INPUT_or_OUTPUT : public CxxTest::TestSuite {
public:
    void test_Initialize_GPIO_as_INPUT_with_OUTPUT_type_0() {

        GPIOEvaluator GPIOEvaluator_;

        /* the pin number is 2, a bank letter is 0, is an input and the type is 6 */
        GPIOEvaluator_.GPIOInitialiseInput(
        2,  /* int p_pinNumber */        0,  /* int p_bankLetter */        6  /* int p_typeIO */);

        /* an initialization error flag is set */
        TS_ASSERT(GPIOEvaluator_.verifyInitializeError());
    }
    void test_Initialize_GPIO_as_OUTPUT_with_OUTPUT_type_0() {

        GPIOEvaluator GPIOEvaluator_;

        /* the pin number is 2, a bank letter is 0, is an output and the type is 6 */
        GPIOEvaluator_.GPIOInitialiseOutput(
        2,  /* int p_pinNumber */        0,  /* int p_bankLetter */        6  /* int p_typeIO */);

        /* a GPIO is instantiated as 0 */
        TS_ASSERT(GPIOEvaluator_.verifyIOType(
        0  /* int p_expectedInput */));
    }
    void test_Initialize_GPIO_as_INPUT_with_INPUT_type_0() {

        GPIOEvaluator GPIOEvaluator_;

        /* the pin number is 2, a bank letter is 0, is an input and the type is 0 */
        GPIOEvaluator_.GPIOInitialiseInput(
        2,  /* int p_pinNumber */        0,  /* int p_bankLetter */        0  /* int p_typeIO */);

        /* a GPIO is instantiated as 1 */
        TS_ASSERT(GPIOEvaluator_.verifyIOType(
        1  /* int p_expectedInput */));
    }
    void test_Initialize_GPIO_as_OUTPUT_with_INPUT_type_0() {

        GPIOEvaluator GPIOEvaluator_;

        /* the pin number is 2, a bank letter is 0, is an output and the type is 0 */
        GPIOEvaluator_.GPIOInitialiseOutput(
        2,  /* int p_pinNumber */        0,  /* int p_bankLetter */        0  /* int p_typeIO */);

        /* an initialization error flag is set */
        TS_ASSERT(GPIOEvaluator_.verifyInitializeError());
    }
};

class Feature_GPIO_can_be_toggled : public CxxTest::TestSuite {
public:
    void test_A_GPIO_initially_OFF_initialized_as_an_INPUT_0() {

        GPIOEvaluator GPIOEvaluator_;

        /* the pin number is 2, a bank letter is 0, is an input and the type is 0 */
        GPIOEvaluator_.GPIOInitialiseInput(
        2,  /* int p_pinNumber */        0,  /* int p_bankLetter */        0  /* int p_typeIO */);

        /* toggling the GPIO state */
        TS_FAIL("no function");

        /* the state of GPIO is 3 (0_low or 1_high or 3_dont_care) since GPIO is set as a 0 (0_INPUT or 1_OUTPUT) */
        TS_FAIL("no function");
    }
    void test_A_GPIO_initially_OFF_initialized_as_an_OUTPUT_0() {

        GPIOEvaluator GPIOEvaluator_;

        /* the pin number is 2, a bank letter is 0, is an output and the type is 6 */
        GPIOEvaluator_.GPIOInitialiseOutput(
        2,  /* int p_pinNumber */        0,  /* int p_bankLetter */        6  /* int p_typeIO */);

        /* toggling the GPIO state */
        TS_FAIL("no function");

        /* the state of the GPIO is 1 */
        TS_FAIL("no function");

        /* toggling the GPIO state */
        TS_FAIL("no function");

        /* the state of the GPIO is 0 */
        TS_FAIL("no function");
    }
};

class Feature_GPIO_can_be_turned_OFF : public CxxTest::TestSuite {
public:
    void test_A_GPIO_initially_instantiated_as_an_INPUT_0() {

        GPIOEvaluator GPIOEvaluator_;

        /* the pin number is 2, a bank letter is 0, is an input and the type is 0 */
        GPIOEvaluator_.GPIOInitialiseInput(
        2,  /* int p_pinNumber */        0,  /* int p_bankLetter */        0  /* int p_typeIO */);

        /* the state of GPIO is 3 (0_low or 1_high or 3_dont_care) since GPIO is set as a 0 (0_INPUT or 1_OUTPUT) */
        TS_FAIL("no function");
    }
    void test_A_GPIO_initially_instantiated_as_an_OUTPUT_0() {

        GPIOEvaluator GPIOEvaluator_;

        /* the pin number is 2, a bank letter is 0, is an output and the type is 6 */
        GPIOEvaluator_.GPIOInitialiseOutput(
        2,  /* int p_pinNumber */        0,  /* int p_bankLetter */        6  /* int p_typeIO */);

        /* the state of GPIO is 0 (0_low or 1_high or 3_dont_care) since GPIO is set as a 1 (0_INPUT or 1_OUTPUT) */
        TS_FAIL("no function");
    }
};

class Feature_GPIO_can_be_turned_ON : public CxxTest::TestSuite {
public:
    void test_A_GPIO_initially_instantiated_as_an_INPUT_0() {

        GPIOEvaluator GPIOEvaluator_;

        /* the pin number is 2, a bank letter is 0, is an input and the type is 0 */
        GPIOEvaluator_.GPIOInitialiseInput(
        2,  /* int p_pinNumber */        0,  /* int p_bankLetter */        0  /* int p_typeIO */);

        /* the state of GPIO is 3 (0_low or 1_high or 3_dont_care) since GPIO is set as a 0 (0_INPUT or 1_OUTPUT) */
        TS_FAIL("no function");
    }
    void test_A_GPIO_initially_instantiated_as_an_OUTPUT_0() {

        GPIOEvaluator GPIOEvaluator_;

        /* the pin number is 2, a bank letter is 0, is an output and the type is 6 */
        GPIOEvaluator_.GPIOInitialiseOutput(
        2,  /* int p_pinNumber */        0,  /* int p_bankLetter */        6  /* int p_typeIO */);

        /* the state of GPIO is 1 (0_low or 1_high or 3_dont_care) since GPIO is set as a 1 (0_INPUT or 1_OUTPUT) */
        TS_FAIL("no function");
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
