/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#ifdef __TMS320C28X__
#include "F2806x_SysCtrl.h"
#endif

#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorFormatter.h>

int main( int argc, char *argv[] ) {
    int status;

    #ifdef __TMS320C28X__
    SysCtrl_runInRam();
    SysCtrl_InitFlash();
    #endif

    CxxTest::ErrorFormatter tmp;
    CxxTest::RealWorldDescription::_worldName = "Tests/Test.h";
    status = CxxTest::Main< CxxTest::ErrorFormatter >( tmp, argc, argv );
    return status;
}
bool suite_Feature_MLR7059_LED_can_turn_ON_init = false;
#include "C:\SourceTree\QMSat_embeded\Tests\Test.h"

static Feature_MLR7059_LED_can_turn_ON suite_Feature_MLR7059_LED_can_turn_ON;

static CxxTest::List Tests_Feature_MLR7059_LED_can_turn_ON = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_Feature_MLR7059_LED_can_turn_ON(suite_Feature_MLR7059_LED_can_turn_ON, Tests_Feature_MLR7059_LED_can_turn_ON, "MLR7059");

static class TestDescription_suite_Feature_MLR7059_LED_can_turn_ON_test_MVCP2656_A_LED_initially_closed_0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Feature_MLR7059_LED_can_turn_ON_test_MVCP2656_A_LED_initially_closed_0() : CxxTest::RealTestDescription(Tests_Feature_MLR7059_LED_can_turn_ON, suiteDescription_Feature_MLR7059_LED_can_turn_ON, "MVCP2656", 1) {}
 void runTest() { suite_Feature_MLR7059_LED_can_turn_ON.test_MVCP2656_A_LED_initially_closed_0(); }
} testDescription_suite_Feature_MLR7059_LED_can_turn_ON_test_MVCP2656_A_LED_initially_closed_0;

static Feature_MLR8739_LED_can_turn_OFF suite_Feature_MLR8739_LED_can_turn_OFF;

static CxxTest::List Tests_Feature_MLR8739_LED_can_turn_OFF = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_Feature_MLR8739_LED_can_turn_OFF(suite_Feature_MLR8739_LED_can_turn_OFF, Tests_Feature_MLR8739_LED_can_turn_OFF, "MLR8739");

static class TestDescription_suite_Feature_MLR8739_LED_can_turn_OFF_test_MVCP1607_A_LED_initially_opened_0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Feature_MLR8739_LED_can_turn_OFF_test_MVCP1607_A_LED_initially_opened_0() : CxxTest::RealTestDescription(Tests_Feature_MLR8739_LED_can_turn_OFF, suiteDescription_Feature_MLR8739_LED_can_turn_OFF, "MVCP1607", 1) {}
 void runTest() { suite_Feature_MLR8739_LED_can_turn_OFF.test_MVCP1607_A_LED_initially_opened_0(); }
} testDescription_suite_Feature_MLR8739_LED_can_turn_OFF_test_MVCP1607_A_LED_initially_opened_0;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
