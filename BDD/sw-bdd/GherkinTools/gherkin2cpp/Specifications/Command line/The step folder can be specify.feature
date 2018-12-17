Feature: The step folder can be specify

   Line arguments --steps-dir can be use to specify a step folder to search in.
   It is possible to specify more than one step directory.

   Scenario: Invoking gherkin2cpp with a specified step directory
     Given an empty folder
     Given a header file named "Feature1.feature" with content
     """
     Feature: Feature1
       Scenario: Scenario
         Given a sentence to match
         Then  a step
     """
     And   a header file named "..\\AnotherStepsFolder\\Steps1\\Steps.h" with content
     """
     /** @bdd a sentence to match */
     void functionInFolderSteps1();
     /** @bdd a step */
     void anotherFunction();
     """
     And   a header file named "..\\AnotherStepsFolder\\Steps2\\Steps.h" with content
     """
     /** @bdd a sentence to match */
     void functionInFolderSteps2();
     /** @bdd a step */
     void anotherFunction();
     """
     When  invoking Gherkin2Cpp with option "--steps-dir=gherkin2cpp\\AnotherStepsFolder\\Steps1 --cpp"
     Then result is
     """

     #include <cxxtest/TestSuite.h>
     #include "types.h"
     #include "AnotherStepsFolder\Steps1\Steps.h"


     class Feature_Feature1 : public CxxTest::TestSuite {
     public:
         void test_Scenario_0() {

             /* a sentence to match */
             functionInFolderSteps1();

             /* a step */
             anotherFunction();
         }
     };

     """

   Scenario: Invoking gherkin2cpp with two specified step directories
     Given an empty folder
     Given a header file named "Feature1.feature" with content
     """
     Feature: Feature1
       Scenario: Scenario
         Given a sentence in Steps1 folder
         Then  a sentence in Steps2 folder
     """
     And   a header file named "..\\AnotherStepsFolder\\Steps1\\Steps.h" with content
     """
     /** @bdd a sentence in Steps1 folder */
     void functionInFolderSteps1();
     """
     And   a header file named "..\\AnotherStepsFolder\\Steps2\\Steps.h" with content
     """
     /** @bdd a sentence in Steps2 folder */
     void functionInFolderSteps2();
     """
     When  invoking Gherkin2Cpp with option "--steps-dir=gherkin2cpp\\AnotherStepsFolder\\Steps1 --steps-dir=gherkin2cpp\\AnotherStepsFolder\\Steps2 --cpp"
     Then result is
     """

     #include <cxxtest/TestSuite.h>
     #include "types.h"
     #include "AnotherStepsFolder\Steps1\Steps.h"
     #include "AnotherStepsFolder\Steps2\Steps.h"


     class Feature_Feature1 : public CxxTest::TestSuite {
     public:
         void test_Scenario_0() {

             /* a sentence in Steps1 folder */
             functionInFolderSteps1();

             /* a sentence in Steps2 folder */
             functionInFolderSteps2();
         }
     };

     """