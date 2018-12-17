Feature: Feature file created without scenario generated warning function call

  To avoid possibility to miss some empty test scenario (not implemented yet), generator will add warning function call

  Scenario: Empty feature
    Given an empty folder
    And   a file named "Feature with no scenario.feature" with content
    And   a file named "steps.h" with content
    When  invoking Gherkin2Cpp with option "--cpp"
    Then  result is


