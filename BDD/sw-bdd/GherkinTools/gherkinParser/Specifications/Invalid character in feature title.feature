Feature: Invalid character in feature title

  Certain character cant be accepted in the feature name as @ , [ ]

  Scenario: invalid character in feature title
    Given an empty folder
    And a file named "Fe@ture.feature" with content
    """
    Feature: Fe@ture

      Scenario: a scenario
        Given a evil mastermind plan succeeding
        Then  evil laugh muhahahaha
    """
    When invoking Gherkin2Cpp with option " "
    Then a "Invalid character in Feature name: Fe@ture" error is raised


  Scenario: another invalid character in feature title
    Given an empty folder
    And a file named "Fea[tôré.feature" with content
    """
    Feature: Fea[tôré

      Scenario: a scenario
        Given a evil mastermind plan succeeding
        Then  evil laugh muhahahaha
    """
    When invoking Gherkin2Cpp with option " "
    Then a "Invalid character in Feature name: Fea[tôré" error is raised