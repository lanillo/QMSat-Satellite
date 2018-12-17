Feature: Cpp generation

  The output of the generator is a Cpp file sequencing execution to properly test the entire implemented feature

  Scenario: Simple one feature, two scenarios project
    Given an empty folder
    And   a file named "Feature.feature" with content
    And   a file named "steps.h" with content
    When  invoking Gherkin2Cpp with option "--cpp"
    Then  result is


