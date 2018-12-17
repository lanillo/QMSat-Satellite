Feature: Standardization of Feature file does not affect initial file capitalization

    Feature file with capitals in feature name and in the DESCRIPTION maintains said capitals when being rewritten

    Scenario: Scenario with CAPITALS in name maintains said capitals
         Given an empty folder
         And a feature file named "Feature With Caps.feature" with content
              """
              Feature: Feature With Caps
                Description with Caps
                Scenario: Scenario name with CAps
                    Given step With Caps
                    And More Caps
                    Then There are Caps
              """
          When invoking Gherkin2Cpp with option " "
          Then expect the feature to contain
              """
              Feature: Feature With Caps

                Description with Caps

                Scenario: Scenario name with CAps
                  Given step With Caps
                  And   More Caps
                  Then  There are Caps



              """
