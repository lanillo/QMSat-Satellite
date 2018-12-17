Feature: Add id numbers to features and scenarios

  Line argument --add-id-numbers will associate MLR and HLR number to features and MCVP numbers to scenarios.

  Scenario: A feature without a MLR get rename with a MLR in file name
    Given an empty folder
    And   the folder named "MLR naming Test"
      And a file named "A normal feature.feature" with content
      """
      Feature: A normal feature
        Scenario: A super Scenario
        Given a step
        And another step
        When nothing happens
        Then a result
      """
      And a header file named "steps.h" with content
      """
      /** @bdd a step */
      void afuncion();

      /** @bdd another step */
      void bfunction();

      /** @bdd a result */
      void cfunction();
      """
      When invoking Gherkin2Cpp with option "--add-id-numbers"
      Then feature file name contain MLR


  Scenario: When rerunning the MLR stay
    Given the folder named "MLR naming Test"
    When invoking Gherkin2Cpp with option "--add-id-numbers"
    Then feature file name contain MLR


  Scenario: A scenario without MVCP get rename with a MLR in file name
    Given an empty folder
    And   the folder named "MVCP naming Test"
      And a file named "A normal feature.feature" with content
      """
      Feature: A normal feature
        Scenario: A super Scenario
        Given a step
        And another step
        When nothing happens
        Then a result
      """
      And a header file named "steps.h" with content
      """
      /** @bdd a step */
      void afuncion();

      /** @bdd another step */
      void bfunction();

      /** @bdd a result */
      void cfunction();
      """
      When invoking Gherkin2Cpp with option "--add-id-numbers"
      Then Scenario name contain MVCP


  Scenario: When rerunning the MVCP stay
    Given the folder named "MVCP naming Test"
    When invoking Gherkin2Cpp with option "--add-id-numbers"
    Then Scenario name contain MVCP


  Scenario: A feature with HLR number stay
    Given an empty folder
    And   the folder named "HLR naming Test"
      And a file named "HLR555 A normal feature.feature" with content
      """
      Feature: HLR555 A normal feature
        Scenario: A super Scenario
        Given a step
        And another step
        When nothing happens
        Then a result
      """
      And a header file named "steps.h" with content
      """
      /** @bdd a step */
      void afuncion();

      /** @bdd another step */
      void bfunction();

      /** @bdd a result */
      void cfunction();
      """
      When invoking Gherkin2Cpp with option "--add-id-numbers"
      Then feature name contain HLR


  Scenario: All features are uniquely numbered
    Given an empty folder
      And a file named "Feature 1.feature" with content
      """
      Feature: Feature 1
        Scenario: a scenario
          Given something
          Then something
      """
      And a file named "Feature 2.feature" with content
      """
      Feature: Feature 2
        Scenario: a scenario
          Given something
          Then something
      """
      And a file named "Feature 3.feature" with content
      """
      Feature: Feature 3
        Scenario: a scenario
          Given something
          Then something
      """
      When invoking Gherkin2Cpp with option "--add-id-numbers"
    Then no feature have the same MLR


  Scenario: Within a feature, one scenario isn't numbered
    Given an empty folder
      And a feature file
      """
      Feature: a scenario dont have a mvcp number
        Scenario: MVCP1234 has a mvcp number
          Given a step
          Then a step

        Scenario: the scenario without mvcp number
          Given a step
          Then a step
      """
      When invoking Gherkin2Cpp with option "--cpp"
      Then all scenarios have mvcp number