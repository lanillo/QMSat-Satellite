Feature: Add traceability to features

  Line argument --add-traceability-tag will add the traceability tags in the description for the tester to
  complete. Otherwise it will keep the current attributes

  Scenario: A feature without traceability is output with traceability tags
    Given an empty folder
    And   the folder named "Traceability Test"
      And a file named "A normal feature.feature" with content
      """
      Feature: A normal feature
        Scenario: A super Scenario
        Given a step
        Then a result
      """
      When invoking Gherkin2Cpp with option "--add-traceability-tag"
      Then   expect the feature to contain
      """
      Feature: A normal feature

        HLR:
        Trace to code:

        Scenario: A super Scenario
          Given a step
          Then  a result



      """

  Scenario: A feature with traceability keeps it
    Given an empty folder
    And   the folder named "Traceability Test"
      And a file named "A normal feature.feature" with content
      """
      Feature: A normal feature

        HLR: 6
        Trace to code: Tag

        Scenario: A super Scenario
          Given a step
          Then  a result
      """
      When invoking Gherkin2Cpp with option "--add-traceability-tag"
      Then   expect the feature to contain
      """
      Feature: A normal feature

        HLR: 6
        Trace to code: Tag

        Scenario: A super Scenario
          Given a step
          Then  a result



      """

  Scenario: A feature with only a TCC
    Given an empty folder
    And   the folder named "Traceability Test"
      And a file named "A feature with only a tcc.feature" with content
      """
      Feature: A feature with only a tcc

        Trace to code: Tag

        Scenario: A super Scenario
          Given a step
          Then  a result
      """
      When invoking Gherkin2Cpp with option "--add-traceability-tag"
      Then   expect the feature to contain
      """
      Feature: A feature with only a tcc

        HLR:
        Trace to code: Tag

        Scenario: A super Scenario
          Given a step
          Then  a result



      """

  Scenario: A feature with only a parent HLR
    Given an empty folder
    And   the folder named "Traceability Test"
      And a file named "A feature with only a parent hlr.feature" with content
      """
      Feature: A feature with only a parent hlr

        HLR: 76

        Scenario: A super Scenario
          Given a step
          Then  a result
      """
      When invoking Gherkin2Cpp with option "--add-traceability-tag"
      Then   expect the feature to contain
      """
      Feature: A feature with only a parent hlr

        HLR: 76
        Trace to code:

        Scenario: A super Scenario
          Given a step
          Then  a result



      """