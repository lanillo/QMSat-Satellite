Feature: Add traceability to features

  Line argument --add-traceability-tag will add the traceability tags in the description for the tester to
  complete. Otherwise it will keep the current attributes

  Scenario: A feature without traceability is output with traceability tags
    Given an empty folder
    And   the folder named "Traceability Test"
    And   a file named "A normal feature.feature" with content
    When  invoking Gherkin2Cpp with option "--add-traceability-tag"
    Then  expect the feature to contain


  Scenario: A feature with traceability keeps it
    Given an empty folder
    And   the folder named "Traceability Test"
    And   a file named "A normal feature.feature" with content
    When  invoking Gherkin2Cpp with option "--add-traceability-tag"
    Then  expect the feature to contain


  Scenario: A feature with only a TCC
    Given an empty folder
    And   the folder named "Traceability Test"
    And   a file named "A feature with only a tcc.feature" with content
    When  invoking Gherkin2Cpp with option "--add-traceability-tag"
    Then  expect the feature to contain


  Scenario: A feature with only a parent HLR
    Given an empty folder
    And   the folder named "Traceability Test"
    And   a file named "A feature with only a parent hlr.feature" with content
    When  invoking Gherkin2Cpp with option "--add-traceability-tag"
    Then  expect the feature to contain


