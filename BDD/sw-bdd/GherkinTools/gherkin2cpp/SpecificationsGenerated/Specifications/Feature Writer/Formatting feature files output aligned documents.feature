Feature: Formatting feature files output aligned documents

  The feature writer will align the feature files to obtain uniform documents.

  Scenario: Scenario with unalign steps get align
    Given an empty folder
    And   a feature file named "Steps get align when formating.feature" with content
    When  invoking Gherkin2Cpp with option " "
    Then  expect the feature to contain


  Scenario: Scenario with unalign examples get align
    Given an empty folder
    And   a feature file named "examples get align when formating.feature" with content
    When  invoking Gherkin2Cpp with option " "
    Then  expect the feature to contain


  Scenario: Scenario with longest value exceeding longest header
    Given an empty folder
    And   a file named "a feature.feature" with content
    When  invoking Gherkin2Cpp with option " "
    Then  expect the feature to contain


