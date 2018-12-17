Feature: Create a cpp from more than one features directory

  Scenario: give two feature folders in the command line argument
  Given an empty folder
  And the folder named "..\\AnotherSpecFolder"
  And a feature file named "Feature1.feature" with content
  """
  Feature: Feature1
    Scenario: a step
      Given a step
      Then a step
  """
  And the folder named "Folder2"
  And a feature file named "Feature2.feature" with content
  """
  Feature: Feature2
    Scenario: a step
      Given a step
      Then a step
  """
  And   a file named "steps.h" with content
  """
  /** @bdd a step */
  void aFunction();
  """
  When invoking Gherkin2Cpp with option "--features-dir=gherkin2cpp\\AnotherSpecFolder --cpp"
  Then result is
    """

    #include <cxxtest/TestSuite.h>
    #include "types.h"
    #include "\steps.h"


    class Feature_Feature2 : public CxxTest::TestSuite {
    public:
        void test_a_step_0() {

            /* a step */
            aFunction();

            /* a step */
            aFunction();
        }
    };

    class Feature_Feature1 : public CxxTest::TestSuite {
    public:
        void test_a_step_0() {

            /* a step */
            aFunction();

            /* a step */
            aFunction();
        }
    };

    """