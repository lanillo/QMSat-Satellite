Feature: LED can turn OFF

  Scenario: A LED initially opened
    Given a LED initialize to ON state
    When  turning the LED OFF
    Then  the state of the LED is 0


