Feature: Remove traceability to features

  Line argument --remove-traceability-tag will remove the traceability tags in the description if there was some.

  Scenario: A feature with traceability is output without traceability tag
    Given an empty folder
    And   the folder named "Traceability Test"
      And a file named "A feature with traceability tags.feature" with content
      """
      Feature: A feature with traceability tags

        HLR: 6
        Trace to code: Tag

        Scenario: A super Scenario
          Given a step
          Then  a result
      """
      When invoking Gherkin2Cpp with option "--remove-traceability-tag"
      Then   expect the feature to contain
      """
      Feature: A feature with traceability tags

        Scenario: A super Scenario
          Given a step
          Then  a result



      """

  Scenario: A feature with HLR traceability is output without traceability tag
    Given an empty folder
    And   the folder named "Traceability Test"
      And a file named "A feature with traceability tags.feature" with content
      """
      Feature: A feature with traceability tags

        HLR: 6

        Scenario: A super Scenario
          Given a step
          Then  a result
      """
      When invoking Gherkin2Cpp with option "--remove-traceability-tag"
      Then   expect the feature to contain
      """
      Feature: A feature with traceability tags

        Scenario: A super Scenario
          Given a step
          Then  a result



      """

  Scenario: A feature with Trace to code traceability is output without traceability tag
    Given an empty folder
    And   the folder named "Traceability Test"
      And a file named "A feature with traceability tags.feature" with content
      """
      Feature: A feature with traceability tags

        Trace to code: Tag

        Scenario: A super Scenario
          Given a step
          Then  a result
      """
      When invoking Gherkin2Cpp with option "--remove-traceability-tag"
      Then   expect the feature to contain
      """
      Feature: A feature with traceability tags

        Scenario: A super Scenario
          Given a step
          Then  a result



      """

  Scenario: A feature without traceability keeps it without any
    Given an empty folder
    And   the folder named "Traceability Test"
      And a file named "A feature without traceability tag.feature" with content
      """
      Feature: A feature without traceability tag

        Scenario: A super Scenario
          Given a step
          Then  a result
      """
      When invoking Gherkin2Cpp with option "--remove-traceability-tag"
      Then   expect the feature to contain
      """
      Feature: A feature without traceability tag

        Scenario: A super Scenario
          Given a step
          Then  a result



      """