
#include <cxxtest/TestSuite.h>
#include "C:\SourceTree\QMSat_embeded\Tests\Steps\Mocks\GPIO-mock.hpp"
#include "C:\SourceTree\QMSat_embeded\Tests\Steps\Peripherals\LED-evaluator.hpp"


class Feature_MLR7059_LED_can_turn_ON : public CxxTest::TestSuite {
public:
    void test_MVCP2656_A_LED_initially_closed_0() {

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

class Feature_MLR8739_LED_can_turn_OFF : public CxxTest::TestSuite {
public:
    void test_MVCP1607_A_LED_initially_opened_0() {

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
