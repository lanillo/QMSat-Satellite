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
bool suite_Feature_MLR9488_Just_a_test_init = false;
#include "C:\SourceTree\QMSat_embeded\Tests\Test.h"

static Feature_MLR9488_Just_a_test suite_Feature_MLR9488_Just_a_test;

static CxxTest::List Tests_Feature_MLR9488_Just_a_test = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_Feature_MLR9488_Just_a_test(suite_Feature_MLR9488_Just_a_test, Tests_Feature_MLR9488_Just_a_test, "MLR9488");

static class TestDescription_suite_Feature_MLR9488_Just_a_test_test_MVCP4902_First_one_0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Feature_MLR9488_Just_a_test_test_MVCP4902_First_one_0() : CxxTest::RealTestDescription(Tests_Feature_MLR9488_Just_a_test, suiteDescription_Feature_MLR9488_Just_a_test, "MVCP4902", 1) {}
 void runTest() { suite_Feature_MLR9488_Just_a_test.test_MVCP4902_First_one_0(); }
} testDescription_suite_Feature_MLR9488_Just_a_test_test_MVCP4902_First_one_0;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
