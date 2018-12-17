Feature: Listing features and scenarios of a directory including its sub-directories

  Line argument "--list-features" is used to list all parsed features.
  Line argument "--list-scenarios" is used to list all parsed scenarios.

  Scenario: Scans sub folders for feature files
    Given an empty folder
    And   a file named "string.feature" with content
    And   a file named "sub/002.feature" with content
    And   a file named "sub/004.feature" with content
    And   a file named "003.feature" with content
    When  invoking Gherkin2Cpp with option "--list-features"
    Then  result is


  Scenario: Scans sub folders for scenarios
    Given an empty folder
    And   a file named "Feature string 1.feature" with content
    And   a file named "sub/002.feature" with content
    When  invoking Gherkin2Cpp with option "--list-scenarios"
    Then  result is


