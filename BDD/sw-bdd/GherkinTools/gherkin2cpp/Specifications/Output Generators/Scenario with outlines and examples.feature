Feature: Scenario with outlines and examples

    The scenarios with outline groups similar scenarios in one scenario to keep feature file readable.
    The generator will split the scenarios with outline in multiple scenarios in output file.

    Scenario: Bogus scenario with an outline
        Given an empty folder
          And a file named "a feature.feature" with content
              """
              Feature: a feature
               Scenario Outline: a scenario with an outline
                 Given an outline with variables <animal> and <drink>
                 Then nothing
               Examples:
               | animal  | drink  |
               | dog     | coffee |
               | cat     | tea    |
               | bear    | beer   |
              """
          And a file named "steps.h" with content
              """
              /** @bdd an outline with variables (?P<animal>.+) and (?P<drink>.+) */
              void aFunction(const char* animal, const char* drink);
              """
        When invoking Gherkin2Cpp with option "--cpp"
        Then result is
        """

        #include <cxxtest/TestSuite.h>
        #include "types.h"
        #include "steps.h"


        class Feature_a_feature : public CxxTest::TestSuite {
        public:
            void test_a_scenario_with_an_outline_0() {

                /* an outline with variables dog and coffee */
                aFunction(
                "dog",  /* const char * animal */        "coffee"  /* const char * drink */);

                /* nothing */
                TS_FAIL("no function");
            }
            void test_a_scenario_with_an_outline_1() {

                /* an outline with variables cat and tea */
                aFunction(
                "cat",  /* const char * animal */        "tea"  /* const char * drink */);

                /* nothing */
                TS_FAIL("no function");
            }
            void test_a_scenario_with_an_outline_2() {

                /* an outline with variables bear and beer */
                aFunction(
                "bear",  /* const char * animal */        "beer"  /* const char * drink */);

                /* nothing */
                TS_FAIL("no function");
            }
        };

        """

    Scenario: Another bogus scenario with an outline
        Given an empty folder
          And a file named "a feature.feature" with content
              """
              Feature: a feature
               Scenario Outline: a scenario with an outline
                 Given an outline with variables <car> and <colour> and <randomFloat>
                 Then nothing
               Examples:
              | car     | colour    | randomFloat |
              | Toyota  | red       | 23.655      |
              | Hyundai | black     | 0.0000      |
              | Ford    | grey      | 1337.123    |
              """
          And a file named "steps.h" with content
              """
              /** @bdd an outline with variables (?P<car>.+) and (?P<colour>.+) and (?P<randomFloat>[-+]?\d+(\.\d+)?) */
              void aFunction(const char* car, const char* colour, f32 randomFloat);
              """
        When invoking Gherkin2Cpp with option "--cpp"
        Then result is
        """

        #include <cxxtest/TestSuite.h>
        #include "types.h"
        #include "steps.h"


        class Feature_a_feature : public CxxTest::TestSuite {
        public:
            void test_a_scenario_with_an_outline_0() {

                /* an outline with variables Toyota and red and 23.655 */
                aFunction(
                "Toyota",  /* const char * car */        "red",  /* const char * colour */        23.655  /* f32 randomFloat */);

                /* nothing */
                TS_FAIL("no function");
            }
            void test_a_scenario_with_an_outline_1() {

                /* an outline with variables Hyundai and black and 0.0000 */
                aFunction(
                "Hyundai",  /* const char * car */        "black",  /* const char * colour */        0.0  /* f32 randomFloat */);

                /* nothing */
                TS_FAIL("no function");
            }
            void test_a_scenario_with_an_outline_2() {

                /* an outline with variables Ford and grey and 1337.123 */
                aFunction(
                "Ford",  /* const char * car */        "grey",  /* const char * colour */        1337.123  /* f32 randomFloat */);

                /* nothing */
                TS_FAIL("no function");
            }
        };

        """

    Scenario: Scenario with longest value exceeding longest header
        Given an empty folder
          And a file named "a feature.feature" with content
              """
              Feature: a feature
               Scenario Outline: a scenario with an outline
                 Given an outline with variables <car> and <colour> and <randomFloat>
                 Then nothing
              Examples:
              | car     | colour    | randomFloat   |
              | Toyota  | red       | 23.65523      |
              | Hyundai | black     | 0.00001231233 |
              | Ford    | grey      | 1337.12333213 |
              """
          And a file named "steps.h" with content
              """
              /** @bdd an outline with variables (?P<car>.+) and (?P<colour>.+) and (?P<randomFloat>[-+]?\d+(\.\d+)?) */
              void aFunction(const char* car, const char* colour, f32 randomFloat);
              """
        When invoking Gherkin2Cpp with option "--cpp"
        Then result is
        """

        #include <cxxtest/TestSuite.h>
        #include "types.h"
        #include "steps.h"


        class Feature_a_feature : public CxxTest::TestSuite {
        public:
            void test_a_scenario_with_an_outline_0() {

                /* an outline with variables Toyota and red and 23.65523 */
                aFunction(
                "Toyota",  /* const char * car */        "red",  /* const char * colour */        23.65523  /* f32 randomFloat */);

                /* nothing */
                TS_FAIL("no function");
            }
            void test_a_scenario_with_an_outline_1() {

                /* an outline with variables Hyundai and black and 0.00001231233 */
                aFunction(
                "Hyundai",  /* const char * car */        "black",  /* const char * colour */        1.231233e-05  /* f32 randomFloat */);

                /* nothing */
                TS_FAIL("no function");
            }
            void test_a_scenario_with_an_outline_2() {

                /* an outline with variables Ford and grey and 1337.12333213 */
                aFunction(
                "Ford",  /* const char * car */        "grey",  /* const char * colour */        1337.12333213  /* f32 randomFloat */);

                /* nothing */
                TS_FAIL("no function");
            }
        };

        """




