Feature: LED can be toggle

  Scenario: A LED initially closed
    Given a LED initialize to OFF state
    When  toggling the LED state
    Then  the state of the LED is 1
    When  toggling the LED state
    Then  the state of the LED is 0


  Scenario: A LED initially opened
    Given a LED initialize to ON state
    When  toggling the LED state
    Then  the state of the LED is 0
    When  toggling the LED state
    Then  the state of the LED is 1


