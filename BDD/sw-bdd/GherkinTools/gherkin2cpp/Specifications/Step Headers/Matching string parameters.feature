Feature: Matching string parameters

  The pattern matching sentences can accept regular expressions (regexes) parameters to
  match with function parameters declaration. The regular expression allows to reuse sentence

  Scenario: Parameterless match sentences
    Given a header file
          """
          /** @bdd a step */
          void aFunction();
          """
    When  parsing the header file
    Then  there is 1 function


  Scenario: Single parameter match string
    Given a header file
          """
          /** @bdd a step with (?P<count>\d+) items? */
          void aFunction(int count);
          """
    When  parsing the header file
    Then  there is 1 function
      And there is a function with a parameter of type int named count


  Scenario: Single parameter mismatching regex name
    Given a header file
          """
          /** @bdd a step with (?P<count>\d+) items? */
          void aFunction(int anotherName);
          """
    When  parsing the header file
    Then  a "Parameters name mismatch with step: a step with (?P<count>\d+) items?" error is raised


  Scenario: Multiple parameters match string
    Given a header file
          """
          /** @bdd a step with (?P<count>\d+) items? at temperature (?P<temperature_degK>\d+) degree Kelvin */
          void aFunction(uint temperature_degK, int count);
          """
    When  parsing the header file
    Then  there is 1 function
      And there is a function with a parameter of type uint named temperature_degK
      And there is a function with a parameter of type int named count


  Scenario: Multiple parameters, a single one not matching
    Given a header file
          """
          /** @bdd a step with (?P<count>\d+) items? at temperature (?P<temperature_degK>\d+) degree Kelvin */
          void aFunction(int count);
          """
    When  parsing the header file
    Then  a "Parameters name mismatch with step: a step with (?P<count>\d+) items? at temperature (?P<temperature_degK>\d+) degree Kelvin" error is raised


  Scenario: Too many parameters
    Given a header file
          """
          /** @bdd a step with (?P<count>\d+) items? */
          void aFunction();
          """
    When  parsing the header file
    Then  a "Parameters name mismatch with step: a step with (?P<count>\d+) items?" error is raised


