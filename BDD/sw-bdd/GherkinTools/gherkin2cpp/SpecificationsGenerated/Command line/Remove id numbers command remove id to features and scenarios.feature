Feature: Remove id numbers command Remove id to features and scenarios

  Line argument --remove-id-numbers will remove the associate MLR, HLR and MCVP numbers to each features or scenarios.

  Scenario: A feature with a MLR gets it MLR remove in file name
    Given an empty folder
    And   the folder named "ID naming Test"
    And   a file named "MLR0666 A normal feature.feature" with content
    And   a header file named "steps.h" with content
    When  invoking Gherkin2Cpp with option "--remove-id-numbers"
    Then  feature file name do not contain MLR


  Scenario: A feature with a HLR and SVCP gets it id numbers remove
    Given an empty folder
    And   the folder named "ID Test"
    And   a file named "HLR0777 A normal feature.feature" with content
    And   a header file named "steps.h" with content
    When  invoking Gherkin2Cpp with option "--remove-id-numbers"
    Then  no id number are left in feature file


