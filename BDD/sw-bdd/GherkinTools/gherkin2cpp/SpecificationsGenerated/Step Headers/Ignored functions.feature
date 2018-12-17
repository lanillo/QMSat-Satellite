Feature: Ignored functions

  The step header can declare functions without pattern matching to use independently from the Gherkin2Cpp script.

  Scenario: No Doxygen comment
    Given a header file
    When  parsing the header file
    Then  there are 0 functions


  Scenario: No @bdd in Doxygen comment
    Given a header file
    When  parsing the header file
    Then  there are 0 functions


