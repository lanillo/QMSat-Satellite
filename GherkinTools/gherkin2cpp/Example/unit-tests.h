
#include <cxxtest/TestSuite.h>
#include "C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Tests\Steps\Mocks\GPIO-mock.hpp"
#include "C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Tests\Steps\Peripherals\GPIO-evaluator.hpp"
#include "C:\Universite\ProjetFinBac\Git\QMSat-Satellite\Tests\Steps\Peripherals\LED-evaluator.hpp"


class Feature_GPIO_can_be_initialized_as_INPUT_or_OUTPUT : public CxxTest::TestSuite {
public:
    void test_Initialize_GPIO_as_INPUT_with_OUTPUT_type_0() {

        /* the pin number is 2, a bank letter is A (0), is an input and the type is output (6) */
        TS_FAIL("no function");

        GPIOEvaluator GPIOEvaluator_;

        /* an initialization error flag is set */
        TS_ASSERT(GPIOEvaluator_.verifyInitializeError());
    }
    void test_Initialize_GPIO_as_OUTPUT_with_OUTPUT_type_0() {

        /* a pin number, a bank letter, isInput and a type */
        TS_FAIL("no function");

        /* isInput is FALSE and the type is OUTPUT */
        TS_FAIL("no function");

        /* a GPIO is instantiated as an OUTPUT */
        TS_FAIL("no function");
    }
    void test_Initialize_GPIO_as_INPUT_with_INPUT_type_0() {

        /* a pin number, a bank letter, isInput and a type */
        TS_FAIL("no function");

        /* isInput is TRUE and the type is INPUT */
        TS_FAIL("no function");

        /* a GPIO is instantiated as an INPUT */
        TS_FAIL("no function");
    }
    void test_Initialize_GPIO_as_OUTPUT_with_INPUT_type_0() {

        /* a pin number, a bank letter, isInput and a type */
        TS_FAIL("no function");

        /* isInput is FALSE and the type is INPUT */
        TS_FAIL("no function");

        /* no GPIO is instantiated */
        TS_FAIL("no function");
    }
};

class Feature_GPIO_can_be_toggled : public CxxTest::TestSuite {
public:
    void test_A_GPIO_initially_OFF_initialized_as_an_INPUT_0() {

        /* a GPIO set to OFF state */
        TS_FAIL("no function");

        /* toggling the GPIO state */
        TS_FAIL("no function");

        /* the state of the GPIO is <the_same> */
        TS_FAIL("no function");

        /* toggling the GPIO state */
        TS_FAIL("no function");

        /* the state of the GPIO is <the_same> */
        TS_FAIL("no function");
    }
    void test_A_GPIO_initially_OFF_initialized_as_an_OUTPUT_0() {

        /* a GPIO set to OFF state */
        TS_FAIL("no function");

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

        /* a GPIO set to ON state */
        TS_FAIL("no function");

        /* turning the GPIO OFF */
        TS_FAIL("no function");

        /* the state of the GPIO is <the_same> */
        TS_FAIL("no function");
    }
    void test_A_GPIO_initially_instantiated_as_an_OUTPUT_0() {

        /* a GPIO set to ON state */
        TS_FAIL("no function");

        /* turning the GPIO OFF */
        TS_FAIL("no function");

        /* the state of the GPIO is 0 */
        TS_FAIL("no function");
    }
};

class Feature_GPIO_can_be_turned_ON : public CxxTest::TestSuite {
public:
    void test_A_GPIO_initially_instantiated_as_an_INPUT_0() {

        /* a GPIO set to OFF state */
        TS_FAIL("no function");

        /* turning the GPIO ON */
        TS_FAIL("no function");

        /* the state of the GPIO is <the_same> */
        TS_FAIL("no function");
    }
    void test_A_GPIO_initially_instantiated_as_an_OUTPUT_0() {

        /* a GPIO set to OFF state */
        TS_FAIL("no function");

        /* turning the GPIO ON */
        TS_FAIL("no function");

        /* the state of the GPIO is 1 */
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

class Feature_MLR9488_Just_a_test : public CxxTest::TestSuite {
public:
    void test_MVCP4902_First_one_0() {

        /* a LED initialize to off state */
        TS_FAIL("no function");

        /* the LED works */
        TS_FAIL("no function");
    }
};
