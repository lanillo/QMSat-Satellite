Feature: Accepting a least 10 levels of hierarchy folder length

  The feature parser shall support a folder hierarchy with minimal 10 levels of deep length

Scenario: Accept at least 10 level of folders
    Given an empty folder
    And a file named "we\need\to\test\with\at least\ten\level of\folders\This should be the feature.feature" with content
    """
    Feature: This should be the feature
      Scenario: ten folders deep
        Given something
        Then nothing
    """
    When  invoking Gherkin2Cpp with option "--list-scenarios"
    Then  result is
          """
          This should be the feature: ten folders deep
          """

