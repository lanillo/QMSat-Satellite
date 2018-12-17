Feature: Feature minimal steps in test case verification

  Each scenario shall implement at least Given and Then step.
  Each Then step is associated with bool return function to certify Scenario result

  Scenario: Scenario minimal requirement [Given and Then mandatory]
    Given the folder named "has minimum requirements"
     And a feature file named "Feature with minimal steps.feature" with content
     """
     Feature: Feature with minimal steps
       Scenario: has requirement
         Given something
         Then Something
     """
     When invoking Gherkin2Cpp with option "--cpp"
     Then execution ends without exception

  Scenario: Scenario missing a given step
    Given the folder named "dont has minimum given requirements"
     And a feature file named "Feature without minimal steps.feature" with content
     """
     Feature: Feature without minimal steps
       Scenario: has not requirement
         When something
         Then Something
     """
     When invoking Gherkin2Cpp with option "--cpp"
     Then a "Missing minimal Given step in FEATURE: Feature without minimal steps.feature" error is raised

  Scenario: Scenario missing a then step
    Given the folder named "dont has minimum then requirements"
     And a feature file named "Feature without minimal steps.feature" with content
     """
     Feature: Feature without minimal steps
       Scenario: has not requirement
         Given something
         When  Something
     """
     When invoking Gherkin2Cpp with option "--cpp"
     Then a "Missing minimal Then step in FEATURE: Feature without minimal steps.feature" error is raised