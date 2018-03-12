Feature: GPIO can be turned ON

  Scenario: A GPIO initially instantiated as an INPUT
    Given a GPIO set to OFF state
    When  turning the GPIO ON
    Then  the state of the GPIO is <the_same>


  Scenario: A GPIO initially instantiated as an OUTPUT
    Given a GPIO set to OFF state
    When  turning the GPIO ON
    Then  the state of the GPIO is 1


