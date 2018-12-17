Feature: Remove traceability to features

  Line argument --remove-traceability-tag will remove the traceability tags in the description if there was some.

  Scenario: A feature with traceability is output without traceability tag
    Given an empty folder
    And   the folder named "Traceability Test"
    And   a file named "A feature with traceability tags.feature" with content
    When  invoking Gherkin2Cpp with option "--remove-traceability-tag"
    Then  expect the feature to contain


  Scenario: A feature with HLR traceability is output without traceability tag
    Given an empty folder
    And   the folder named "Traceability Test"
    And   a file named "A feature with traceability tags.feature" with content
    When  invoking Gherkin2Cpp with option "--remove-traceability-tag"
    Then  expect the feature to contain


  Scenario: A feature with Trace to code traceability is output without traceability tag
    Given an empty folder
    And   the folder named "Traceability Test"
    And   a file named "A feature with traceability tags.feature" with content
    When  invoking Gherkin2Cpp with option "--remove-traceability-tag"
    Then  expect the feature to contain


  Scenario: A feature without traceability keeps it without any
    Given an empty folder
    And   the folder named "Traceability Test"
    And   a file named "A feature without traceability tag.feature" with content
    When  invoking Gherkin2Cpp with option "--remove-traceability-tag"
    Then  expect the feature to contain


