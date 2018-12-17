Feature: Gherkin file format specifications

  The Gherkins format is used to describe requirement and test scenario associated
  in a non-programmer understandable.

  Scenario: Simple scenario
    Given a feature file
          """
          Feature: Feature
            Scenario: Scenario
              Given there are 5 cucumbers
              When we slice it
              Then it squirts
          """
    When  parsing the feature file
    Then  there are 3 steps
      And there is 1 scenario


  Scenario: Usage of Scenario Outline
    Given a feature file
          """
          Feature: Feature
            Scenario Outline: Scenario outline
              Given an automated <thing> thing
              Then is it in <state> state
            Examples:
            | thing | state  |
            | bot   | moving |
            | cat   | cute   |
          """
    When  parsing the feature file
    Then  there are 4 steps
      And there are 2 scenarios


  Scenario: Multiple scenarios
    Given a feature file
          """
          Feature: Feature
            Scenario Outline: Scenario outline
              Given an automated <thing> thing
              Then is it in <state> state
            Examples:
            | thing | state  |
            | bot   | moving |
            | cat   | cute   |


            Scenario: Scenario
              Given there are 5 cucumbers
              When we slice it
              Then it squirts


            Scenario Outline: Scenario outline
              Given an automated <thing> thing
              Then is it in <state> state
            Examples:
            | thing | state  |
            | bot   | moving |
            | cat   | cute   |


            Scenario: Scenario
              Given there are 5 cucumbers
              When we slice it
              Then it squirts
          """
    When  parsing the feature file
    Then  there are 14 steps
      And there are 6 scenarios


  Scenario: missing the examples sections
      Given an empty folder
        And a file named "a feature.feature" with content
            """
            Feature: a feature
              Scenario Outline: a scenario with an outline but no examples
                Given an outline with variables <car> and <colour>
                When nothing
                Then nothing
            """
        And a file named "steps.h" with content
            """
            /** @bdd an outline with variables (?P<car>.+) and (?P<colour>.+) and (?P<randomFloat>[-+]?\d+(\.\d+)?) */
            void aFunction(const char* car, const char* colour);
            """
        When invoking Gherkin2Cpp with option "--cpp"
      Then a "MissingExampleError" error is raised


    Scenario: examples without the outline keyword
      Given an empty folder
        And a file named "a feature.feature" with content
            """
            Feature: a feature
              Scenario: a scenario with an outline but no examples
                Given an outline with variables <car> and <colour>
                When nothing
                Then nothing
              Examples:
              |    car    | colour |
              |   tesla   |  blue  |
              | batmobile |  dark  |
            """
        And a file named "steps.h" with content
            """
            /** @bdd an outline with variables (?P<car>.+) and (?P<colour>.+) */
            void aFunction(const char* car, const char* colour);
            """
            When invoking Gherkin2Cpp with option "--cpp"
      Then a "MissingOutlineError" error is raised