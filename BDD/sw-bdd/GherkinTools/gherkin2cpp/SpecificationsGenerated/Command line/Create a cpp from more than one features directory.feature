Feature: Create a cpp from more than one features directory

  Scenario: give two feature folders in the command line argument
    Given an empty folder
    And   the folder named "..\\AnotherSpecFolder"
    And   a feature file named "Feature1.feature" with content
    And   the folder named "Folder2"
    And   a feature file named "Feature2.feature" with content
    And   a file named "steps.h" with content
    When  invoking Gherkin2Cpp with option "--features-dir=gherkin2cpp\\AnotherSpecFolder --cpp"
    Then  result is


