Feature: Feature file created without scenario generated warning function call

  To avoid possibility to miss some empty test scenario (not implemented yet), generator will add warning function call

  Scenario: Empty feature
    Given an empty folder
    And   a file named "Feature with no scenario.feature" with content
          """
          Feature: Feature with no scenario
          """
    And   a file named "steps.h" with content
          """
          /** @bdd a step */
          void aFunction();
          """
    When  invoking Gherkin2Cpp with option "--cpp"
    Then  result is
          """

          #include <cxxtest/TestSuite.h>
          #include "types.h"
          #include "steps.h"


          class Feature_Feature_with_no_scenario : public CxxTest::TestSuite {
          public:
              void test_Feature_with_no_scenario_not_implemented() {
                  TS_WARN("feature _Feature with no scenario_ not implemented");
              }
          };

          """