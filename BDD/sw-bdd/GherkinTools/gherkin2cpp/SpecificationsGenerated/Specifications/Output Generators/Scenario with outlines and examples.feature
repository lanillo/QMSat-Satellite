Feature: Scenario with outlines and examples

  The scenarios with outline groups similar scenarios in one scenario to keep feature file readable.
  The generator will split the scenarios with outline in multiple scenarios in output file.

  Scenario: Bogus scenario with an outline
    Given an empty folder
    And   a file named "a feature.feature" with content
    And   a file named "steps.h" with content
    When  invoking Gherkin2Cpp with option "--cpp"
    Then  result is


  Scenario: Another bogus scenario with an outline
    Given an empty folder
    And   a file named "a feature.feature" with content
    And   a file named "steps.h" with content
    When  invoking Gherkin2Cpp with option "--cpp"
    Then  result is


  Scenario: Scenario with longest value exceeding longest header
    Given an empty folder
    And   a file named "a feature.feature" with content
    And   a file named "steps.h" with content
    When  invoking Gherkin2Cpp with option "--cpp"
    Then  result is


