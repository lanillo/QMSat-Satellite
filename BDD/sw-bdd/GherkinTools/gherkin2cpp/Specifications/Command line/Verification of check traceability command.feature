Feature: Verification of check traceability command

  Line argument --check-traceability allows the checkup of the feature metadata Trace to code and HLR.

  Scenario: A feature that contain a trace to code
    Given an empty folder
    And a file named "A normal feature.feature" with content
    """
    Feature: A normal feature

      Trace to code: MyTraceToCode
      HLR: 1

      Scenario: A super Scenario
        Given a step
        And   another step
        When  nothing happens
        Then  a result
    """
    When invoking Gherkin2Cpp with option "--check-traceability"
    Then trace to code is "MyTraceToCode"


  Scenario: A feature that miss a trace to code
    Given an empty folder
    And a file named "A normal feature.feature" with content
    """
    Feature: A normal feature

      HLR: 1

      Scenario: A super Scenario
        Given a step
        And   another step
        When  nothing happens
        Then  a result
    """
    When invoking Gherkin2Cpp with option "--check-traceability"
    Then a "No trace to code for feature: A normal feature" error is raised


  Scenario: A feature that miss a hlr
    Given an empty folder
    And a file named "A normal feature.feature" with content
    """
    Feature: A normal feature

      Trace to code: AAA

      Scenario: A super Scenario
        Given a step
        And   another step
        When  nothing happens
        Then  a result
    """
    When invoking Gherkin2Cpp with option "--check-traceability"
    Then a "No parent hlr for feature: A normal feature" error is raised