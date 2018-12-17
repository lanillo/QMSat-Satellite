Feature: Verification of trace to code command

  Line argument --check-trace-to-code allows the checkup of the feature metadata trace to code.

  Scenario: A feature that contain a trace to code
    Given an empty folder
    And   a file named "A normal feature.feature" with content
    When  invoking Gherkin2Cpp with option "--traceability"
    Then  trace to code is "MyTraceToCode"


  Scenario: A feature that miss a trace to code
    Given an empty folder
    And   a file named "A normal feature.feature" with content
    When  invoking Gherkin2Cpp with option "--traceability"
    Then  a "No trace to code for feature: A normal feature" error is raised


