Feature: GPIO can be turned OFF

  Scenario: A GPIO initially instantiated as an INPUT
    Given a GPIO set to ON state
    When  turning the GPIO OFF
    Then  the state of the GPIO is <the_same>


  Scenario: A GPIO initially instantiated as an OUTPUT
    Given a GPIO set to ON state
    When  turning the GPIO OFF
    Then  the state of the GPIO is 0


