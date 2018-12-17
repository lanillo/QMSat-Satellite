Feature: Pattern Match Uniqueness

  The generator notifies user if there is not one and only one function matching
  a step sentence to simplify utilisation of test integration.

  Scenario: Two identical regexes
    Given an empty folder
    Given a feature file
    And   a header file
    When  invoking Gherkin2Cpp with option "--cpp"
    Then  a "TooManyFunctionMatchError" error is raised


  Scenario: Different regexes matching the same sentence
    Given an empty folder
    Given a feature file
    And   a header file
    When  invoking Gherkin2Cpp with option "--cpp"
    Then  a "TooManyFunctionMatchError" error is raised


