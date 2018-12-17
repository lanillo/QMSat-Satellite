Feature: Unicity identifier of MLR & SVCP

  Parser ensure unicity of each ID number to keep tracking easier

  Scenario: Duplicate feature numbers
    Given the folder named "duplicate MLR test"
      And a file named "Feature 1.feature" with content
      """
      Feature: MLR1556 Feature 1
        Scenario: a scenario
          Given something
          Then something
      """
      And a file named "Feature 2.feature" with content
      """
      Feature: MLR1556 Feature 2
        Scenario: a scenario
          Given something
          Then something
      """
      And a file named "Feature 3.feature" with content
      """
      Feature: MLR1557 Feature 3
        Scenario: a scenario
          Given something
          Then something
      """
      When invoking Gherkin2Cpp with option "--cpp"
    Then a "Unique number already in use in: Feature 2.feature" error is raised


   Scenario: Within a feature, two scenarios have the same number
    Given an empty folder
      And a feature file
      """
      Feature: a scenario have a mvcp number
        Scenario: MVCP1234 has a mvcp number
          Given a step
          Then a step

        Scenario: MVCP1234 scenario with same mvcp number
          Given a step
          Then a step
      """
      When invoking Gherkin2Cpp with option "--cpp"
      Then a "Unique number already in use in scenario: MVCP1234 scenario with same mvcp number" error is raised


  Scenario: Two Scenario with same number in two different feature root directory
    Given an empty folder
      And the folder named "..\\AnotherSpecFolder"
      And a feature file named "Feature1.feature" with content
      """
      Feature: Feature1
        Scenario: MVCP4312 has a mvcp number
          Given a step
          Then a step

        Scenario: MVCP1234 scenario with same mvcp number
          Given a step
          Then a step
      """
      And the folder named "Folder2"
      And a feature file named "Feature2.feature" with content
      """
      Feature:Feature2

        Scenario: MVCP1234 scenario with same mvcp number
          Given a step
          Then a step
      """
      When invoking Gherkin2Cpp with option "--features-dir=gherkinParser\\AnotherSpecFolder --cpp"
      Then a "Unique number already in use in scenario: MVCP1234 scenario with same mvcp number" error is raised


  Scenario: Within 2 feature, two scenarios have the same number
    Given an empty folder
      And a feature file named "feature 1.feature" with content
      """
      Feature: feature 1

        Scenario: MVCP1234 a scenario have a mvcp number
          Given a step
          Then a step
      """
      And a feature file named "feature 2.feature" with content
      """
      Feature: feature 2

        Scenario: MVCP1234 scenario with same mvcp number
          Given a step
          Then a step
      """
      When invoking Gherkin2Cpp with option "--cpp"
      Then a "Unique number already in use in scenario: MVCP1234 scenario with same mvcp number" error is raised


  Scenario: feature and scenario have the same number
    Given an empty folder
      And a feature file named "feature 1.feature" with content
      """
      Feature: MLR1234 feature 1

        Scenario: MVCP1234 a scenario have a mvcp number
          Given a step
          Then a step
      """
      When invoking Gherkin2Cpp with option "--cpp"
      Then a "Unique number already in use in: feature 1.feature" error is raised