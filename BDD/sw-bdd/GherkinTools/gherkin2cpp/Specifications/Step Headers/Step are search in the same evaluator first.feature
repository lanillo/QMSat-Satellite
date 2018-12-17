Feature: Step are search in the same evaluator first

  The generator will first search for a step in the same evaluator as the one in which it found
  the last one. That will accept that two evaluator use the same regex except for the first one.

  Scenario: Two evaluator with the same regex but not its first one
    Given an empty folder
    And   a file named "features.feature" with content
          """
          Feature: Feature
            Scenario: Scenario
              Given a first sentence
              When a same sentence as other header file
              Then a step
          """
    And   a file named "evaluator1.h" with content
          """
          class evaluator1 {
          public:
          /** @bdd a first sentence */
          void abFunction();
          /** @bdd a same sentence as other header file */
          void anotherFunction();
          };
          """
    And   a file named "evaluator2.h" with content
          """
          class evaluator2 {
          public:
          /** @bdd a second sentence */
          void abFunction();
          /** @bdd a same sentence as other header file */
          void anotherFunction();
          };
          """
    When  invoking Gherkin2Cpp with option "--cpp"
    Then  execution ends without exception


  Scenario: Two evaluator with its first regex identical
    Given an empty folder
    And   a file named "features.feature" with content
          """
          Feature: Feature
            Scenario: Scenario
              Given a same sentence as other header file
              When another sentence
              Then a step
          """
    And   a file named "evaluator1.h" with content
          """
          class evaluator1 {
          public:
          /** @bdd a same sentence as other header file */
          void abFunction();
          /** @bdd another sentence */
          void anotherFunction();
          };
          """
    And   a file named "evaluator2.h" with content
          """
          class evaluator2 {
          public:
          /** @bdd a same sentence as other header file */
          void abFunction();
          /** @bdd a regex */
          void anotherFunction();
          };
          """
    When  invoking Gherkin2Cpp with option "--cpp"
    Then  a "TooManyFunctionMatchError" error is raised