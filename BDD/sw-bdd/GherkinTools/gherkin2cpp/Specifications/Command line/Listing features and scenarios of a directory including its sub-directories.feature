Feature: Listing features and scenarios of a directory including its sub-directories

    Line argument "--list-features" is used to list all parsed features.
    Line argument "--list-scenarios" is used to list all parsed scenarios.

  Scenario: Scans sub folders for feature files
    Given an empty folder
      And a file named "string.feature" with content
          """
          Feature: 001 - Some string
            Scenario: 01
              Given nothing
              Then nothing
          """
      And a file named "sub/002.feature" with content
          """
          Feature: 002
            Scenario: 01 - Some scenario
              Given nothing
              Then nothing
          """
      And a file named "sub/004.feature" with content
          """
          Feature: 004
            Scenario: 01
              Given nothing
              Then nothing
          """
      And a file named "003.feature" with content
          """
          Feature: 003
            Scenario: 01
              Given nothing
              Then nothing
          """
    When  invoking Gherkin2Cpp with option "--list-features"
    Then  result is
          """
          001 - Some string
          002
          003
          004
          """

  Scenario: Scans sub folders for scenarios
    Given an empty folder
      And a file named "Feature string 1.feature" with content
          """
          Feature: Feature string 1

            Scenario: 001
              Given a step
              When nothing
              Then a step
            Scenario Outline: 002
              Given a <beer>
              When brewing it
              Then the alcool pourcent is <pourcent>
            Examples:
            |   beer    | pourcent  |
            |  boreal   |   5.1     |
            |  corona   |   4.6     |

            Scenario Outline: 003
              Given a <beer>
              When brewing it
              Then the alcool pourcent is <pourcent>
            Examples:
            |   beer    | pourcent  |
            |  rickards |   5.3     |
            |  bud      |   5       |

            Scenario: 004
              Given a <beer>
              When brewing it
              Then you drink it
          """
      And a file named "sub/002.feature" with content
          """
          Feature: 002
            Scenario: Scenario string
              Given a step
              When nothing
              Then a step
          """
    When  invoking Gherkin2Cpp with option "--list-scenarios"
    Then  result is
          """
          002: Scenario string
          Feature string 1: 001
          Feature string 1: 002
          """

