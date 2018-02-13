
#include <cxxtest/TestSuite.h>
#include "C:\SourceTree\QMSat_embeded\Tests\Steps\Peripherals\LED-evaluator.hpp"


class Feature_MLR9488_Just_a_test : public CxxTest::TestSuite {
public:
    void test_MVCP4902_First_one_0() {

        LEDEvaluator LEDEvaluator_;

        /* a LED initialize to off state */
        LEDEvaluator_.LEDTurnOFF();

        /* the LED works */
        TS_ASSERT(LEDEvaluator_.verifyLED());
    }
};
