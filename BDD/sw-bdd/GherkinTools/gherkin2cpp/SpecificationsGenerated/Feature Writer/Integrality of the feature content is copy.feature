Feature: Integrality of the feature content is copy

  The content of the feature must be copy without modification including the title, the description,
  the attribute, the traceability and the scenario.

  Scenario: A feature with everything in it
    Given an empty folder
    And   a feature file named "MLR0666 Full.feature" with content
    When  invoking Gherkin2Cpp with option "--add-traceability"
    Then  expect the feature to contain


