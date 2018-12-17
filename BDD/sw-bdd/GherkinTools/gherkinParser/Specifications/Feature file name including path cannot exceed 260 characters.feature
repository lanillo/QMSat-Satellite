Feature: Feature file name including path cannot exceed 260 characters

  The feature path cannot exceed 260 characters long because of Windows limitation

    Scenario: feature file path too long
      Given an empty folder
      And a file named "TooLong.feature" with content
      """
      Feature: Apparently I have to write a feature with a name of at least two hundreds forty characters long so that that the exceeds character limit error raise but I dont have internet right now to get a text generator so I wrote it all by myself gg ez

        Scenario: a scenario
          Given a evil mastermind plan succeeding
          Then  evil laugh muhahahaha
      """
      When invoking Gherkin2Cpp with option " "
      Then a "Feature path exceeds character limit: Apparently I have to write a feature with a name of at least two hundreds forty characters long so that that the exceeds character limit error raise but I dont have internet right now to get a text generator so I wrote it all by myself gg ez" error is raised


    Scenario: feature with maximum characters in name
      Given an empty folder
      And a file named "LongEnough.feature" with content
      """
      Feature: Lorem cetuer adipiscing eli ligula eget dolor Aenean massa Cum sociis penatibus et magnis dis parturient montes nascetur ridiculus mus Donec quam felis ultricies nec pellentesque eu pretiu

        Scenario: a scenario
          Given a evil mastermind plan succeeding
          Then  evil laugh muhahahaha
      """
      When invoking Gherkin2Cpp with option " "
      Then execution ends without exception