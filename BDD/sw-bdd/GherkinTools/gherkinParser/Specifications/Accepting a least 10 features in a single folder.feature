Feature: Accepting a least 10 features in a single folder

    The feature parser shall support least 10 features in the same folder

  Scenario: a folder with 10 features in it
    Given an empty folder
      And a feature file named "feature 1.feature" with content
          """
          Feature: feature 1
            Scenario: dummy
              Given anything
              Then a miracle
          """
      And a feature file named "feature 2.feature" with content
          """
          Feature: feature 2
            Scenario: dummy
              Given anything
              Then a miracle
          """
      And a feature file named "feature 3.feature" with content
          """
          Feature: feature 3
            Scenario: dummy
              Given anything
              Then a miracle
          """
      And a feature file named "feature 4.feature" with content
          """
          Feature: feature 4
            Scenario: dummy
              Given anything
              Then a miracle
          """
      And a feature file named "feature 5.feature" with content
          """
          Feature: feature 5
            Scenario: dummy
              Given anything
              Then a miracle
          """
      And a feature file named "feature 6.feature" with content
          """
          Feature: feature 6
            Scenario: dummy
              Given anything
              Then a miracle
          """
      And a feature file named "feature 7.feature" with content
          """
          Feature: feature 7
            Scenario: dummy
              Given anything
              Then a miracle
          """
      And a feature file named "feature 8.feature" with content
          """
          Feature: feature 8
            Scenario: dummy
              Given anything
              Then a miracle
          """
      And a feature file named "feature 9.feature" with content
          """
          Feature: feature 9
            Scenario: dummy
              Given anything
              Then a miracle
          """
      And a feature file named "feature 10.feature" with content
          """
          Feature: feature 10
            Scenario: dummy
              Given anything
              Then a miracle
          """
      When invoking Gherkin2Cpp with option "--list-features"
      Then result is
        """
        feature 1
        feature 10
        feature 2
        feature 3
        feature 4
        feature 5
        feature 6
        feature 7
        feature 8
        feature 9
        """