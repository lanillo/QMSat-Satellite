Feature: Add id number and remove id number cannot be used in same time

  Line arguments --add-id-numbers and --remove-id-numbers raise a error during execution. The error is
  "Cant call Gherkin2Cpp with argument --add-id-numbers and --remove-id-numbers"

  Scenario: execute Gherkin2Cpp with add and remove id number
    Given an empty folder
    And   a file named "A normal feature.feature" with content
    When  invoking Gherkin2Cpp with option "--add-id-numbers --remove-id-numbers"
    Then  a "Cant call Gherkin2Cpp with argument --add-id-numbers and --remove-id-numbers" error is raised


