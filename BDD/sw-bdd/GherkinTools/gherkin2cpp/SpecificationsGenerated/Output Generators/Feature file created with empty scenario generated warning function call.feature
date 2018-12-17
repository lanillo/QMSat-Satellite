Feature: Feature file created with empty scenario generated warning function call

  To avoid possibility to miss some empty feature (not implemented yet), generator will add warning function call

  Scenario: Empty feature
    Given an empty folder
    And   a file named "Feature with empty scenario.feature" with content
    And   a file named "steps.h" with content
    When  invoking Gherkin2Cpp with option "--cpp"
    Then  result is


