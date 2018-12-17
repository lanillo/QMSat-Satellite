Feature: Cpp generation

  The output of the generator is a Cpp file sequencing execution to properly test the entire implemented feature

  Scenario: Simple one feature, two scenarios project
    Given an empty folder
    And   a file named "Feature.feature" with content
          """
          Feature: Feature
            Scenario: Scenario
              Given a step
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


          class Feature_Feature : public CxxTest::TestSuite {
          public:
              void test_Scenario_0() {

                  /* a step */
                  aFunction();
              }
          };

          """