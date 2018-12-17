Feature: LED can turn ON

  Scenario: A LED initially closed
    Given a LED initialize to OFF state
    When  turning the LED ON
    Then  the state of the LED is 1


