Feature: Accepting a least 50 scenarios in a single feature file

    The feature parser shall support at least 50 features in the same Feature

  Scenario: a folder with 50 scenarios in it
    Given an empty folder
      And a feature file named "feature with many scenarios.feature" with content
          """
          Feature: feature with many scenarios
            Scenario: scenario 1
              Given nothing
              Then you get nothing
            Scenario: scenario 2
              Given nothing
              Then you get nothing
            Scenario: scenario 3
              Given nothing
              Then you get nothing
            Scenario: scenario 4
              Given nothing
              Then you get nothing
            Scenario: scenario 5
              Given nothing
              Then you get nothing
            Scenario: scenario 6
              Given nothing
              Then you get nothing
            Scenario: scenario 7
              Given nothing
              Then you get nothing
            Scenario: scenario 8
              Given nothing
              Then you get nothing
            Scenario: scenario 9
              Given nothing
              Then you get nothing
            Scenario: scenario 10
              Given nothing
              Then you get nothing
            Scenario: scenario 11
              Given nothing
              Then you get nothing
            Scenario: scenario 12
              Given nothing
              Then you get nothing
            Scenario: scenario 13
              Given nothing
              Then you get nothing
            Scenario: scenario 14
              Given nothing
              Then you get nothing
            Scenario: scenario 15
              Given nothing
              Then you get nothing
            Scenario: scenario 16
              Given nothing
              Then you get nothing
            Scenario: scenario 17
              Given nothing
              Then you get nothing
            Scenario: scenario 18
              Given nothing
              Then you get nothing
            Scenario: scenario 19
              Given nothing
              Then you get nothing
            Scenario: scenario 20
              Given nothing
              Then you get nothing
            Scenario: scenario 21
              Given nothing
              Then you get nothing
            Scenario: scenario 22
              Given nothing
              Then you get nothing
            Scenario: scenario 23
              Given nothing
              Then you get nothing
            Scenario: scenario 24
              Given nothing
              Then you get nothing
            Scenario: scenario 25
              Given nothing
              Then you get nothing
            Scenario: scenario 26
              Given nothing
              Then you get nothing
            Scenario: scenario 27
              Given nothing
              Then you get nothing
            Scenario: scenario 28
              Given nothing
              Then you get nothing
            Scenario: scenario 29
              Given nothing
              Then you get nothing
            Scenario: scenario 30
              Given nothing
              Then you get nothing
            Scenario: scenario 31
              Given nothing
              Then you get nothing
            Scenario: scenario 32
              Given nothing
              Then you get nothing
            Scenario: scenario 33
              Given nothing
              Then you get nothing
            Scenario: scenario 34
              Given nothing
              Then you get nothing
            Scenario: scenario 35
              Given nothing
              Then you get nothing
            Scenario: scenario 36
              Given nothing
              Then you get nothing
            Scenario: scenario 37
              Given nothing
              Then you get nothing
            Scenario: scenario 38
              Given nothing
              Then you get nothing
            Scenario: scenario 39
              Given nothing
              Then you get nothing
            Scenario: scenario 40
              Given nothing
              Then you get nothing
            Scenario: scenario 41
              Given nothing
              Then you get nothing
            Scenario: scenario 42
              Given nothing
              Then you get nothing
            Scenario: scenario 43
              Given nothing
              Then you get nothing
            Scenario: scenario 44
              Given nothing
              Then you get nothing
            Scenario: scenario 45
              Given nothing
              Then you get nothing
            Scenario: scenario 46
              Given nothing
              Then you get nothing
            Scenario: scenario 47
              Given nothing
              Then you get nothing
            Scenario: scenario 48
              Given nothing
              Then you get nothing
            Scenario: scenario 49
              Given nothing
              Then you get nothing
            Scenario: scenario 50
              Given nothing
              Then you get nothing
          """
      When invoking Gherkin2Cpp with option "--list-scenarios"
    Then result is
        """
        feature with many scenarios: scenario 10_0
        feature with many scenarios: scenario 11_0
        feature with many scenarios: scenario 12_0
        feature with many scenarios: scenario 13_0
        feature with many scenarios: scenario 14_0
        feature with many scenarios: scenario 15_0
        feature with many scenarios: scenario 16_0
        feature with many scenarios: scenario 17_0
        feature with many scenarios: scenario 18_0
        feature with many scenarios: scenario 19_0
        feature with many scenarios: scenario 1_0
        feature with many scenarios: scenario 20_0
        feature with many scenarios: scenario 21_0
        feature with many scenarios: scenario 22_0
        feature with many scenarios: scenario 23_0
        feature with many scenarios: scenario 24_0
        feature with many scenarios: scenario 25_0
        feature with many scenarios: scenario 26_0
        feature with many scenarios: scenario 27_0
        feature with many scenarios: scenario 28_0
        feature with many scenarios: scenario 29_0
        feature with many scenarios: scenario 2_0
        feature with many scenarios: scenario 30_0
        feature with many scenarios: scenario 31_0
        feature with many scenarios: scenario 32_0
        feature with many scenarios: scenario 33_0
        feature with many scenarios: scenario 34_0
        feature with many scenarios: scenario 35_0
        feature with many scenarios: scenario 36_0
        feature with many scenarios: scenario 37_0
        feature with many scenarios: scenario 38_0
        feature with many scenarios: scenario 39_0
        feature with many scenarios: scenario 3_0
        feature with many scenarios: scenario 40_0
        feature with many scenarios: scenario 41_0
        feature with many scenarios: scenario 42_0
        feature with many scenarios: scenario 43_0
        feature with many scenarios: scenario 44_0
        feature with many scenarios: scenario 45_0
        feature with many scenarios: scenario 46_0
        feature with many scenarios: scenario 47_0
        feature with many scenarios: scenario 48_0
        feature with many scenarios: scenario 49_0
        feature with many scenarios: scenario 4_0
        feature with many scenarios: scenario 50_0
        feature with many scenarios: scenario 5_0
        feature with many scenarios: scenario 6_0
        feature with many scenarios: scenario 7_0
        feature with many scenarios: scenario 8_0
        feature with many scenarios: scenario 9_0
        """