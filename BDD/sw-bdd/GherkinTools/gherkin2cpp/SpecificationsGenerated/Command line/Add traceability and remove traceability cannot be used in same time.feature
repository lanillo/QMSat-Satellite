Feature: Add traceability and remove traceability cannot be used in same time

  Line arguments --add-traceability-tag and --remove-traceability-tag raise a error during execution. The error is
  "Cant call Gherkin2Cpp with argument --add-traceability-tag and --remove-traceability-tag"

  Scenario: execute Gherkin2Cpp with add and remove id number
    Given an empty folder
    And   a file named "A normal feature.feature" with content
    When  invoking Gherkin2Cpp with option "--add-traceability-tag --remove-traceability-tag"
    Then  a "Cant call Gherkin2Cpp with argument --add-traceability-tag and --remove-traceability-tag" error is raised


