Feature: Feature file created with empty scenario generated warning function call

  To avoid possibility to miss some empty feature (not implemented yet), generator will add warning function call

  Scenario: Empty feature
    Given an empty folder
    And   a file named "Feature with empty scenario.feature" with content
          """
          Feature: Feature with empty scenario
            Scenario: Im empty
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


          class Feature_Feature_with_empty_scenario : public CxxTest::TestSuite {
          public:
              void test_Im_empty_0() {
                  TS_WARN("scenario _Im empty_ not implemented");
              }
          };

          """