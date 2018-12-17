Feature: Standardization of Feature file does not affect initial file capitalization

  Feature file with capitals in feature name and in the DESCRIPTION maintains said capitals when being rewritten

  Scenario: Scenario with CAPITALS in name maintains said capitals
    Given an empty folder
    And   a feature file named "Feature With Caps.feature" with content
    When  invoking Gherkin2Cpp with option " "
    Then  expect the feature to contain


