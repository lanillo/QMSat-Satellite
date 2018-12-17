Feature: Pattern Match Uniqueness

  The generator notifies user if there is not one and only one function matching
  a step sentence to simplify utilisation of test integration.

  Scenario: Two identical regexes
    Given an empty folder
    Given a file named "features.feature" with content
          """
          Feature: Feature
            Scenario: Scenario
              Given a sentence to match
              When a step
              Then a step
          """
    And   a file named "steps.h" with content
          """
          class AClass {
          public:
          /** @bdd a sentence to match */
          void abFunction();
          /** @bdd a sentence to match */
          void anotherFunction();
          };
          """
    When  invoking Gherkin2Cpp with option "--cpp"
    Then  a "TooManyFunctionMatchError" error is raised


  Scenario: Different regexes matching the same sentence
    Given an empty folder
    Given a file named "features.feature" with content
          """
          Feature: Feature
            Scenario: Scenario
              Given 1 item
              When a step
              Then a step
          """
    And   a file named "steps.h" with content
          """
          class AClass {
          public:
          /** @bdd 1 item */
          void aFunction();
          /** @bdd (?P<count>\d+) items? */
          void anotherFunction(int count);
          };
          """
    When  invoking Gherkin2Cpp with option "--cpp"
    Then  a "TooManyFunctionMatchError" error is raised
