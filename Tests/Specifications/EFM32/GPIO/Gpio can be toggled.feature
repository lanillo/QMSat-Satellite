Feature: GPIO can be toggled

  Scenario: A GPIO initially OFF initialized as an INPUT
    Given a GPIO set to OFF state
    When  toggling the GPIO state
    Then  the state of the GPIO is <the_same>
    When  toggling the GPIO state
    Then  the state of the GPIO is <the_same>


  Scenario: A GPIO initially OFF initialized as an OUTPUT
    Given a GPIO set to OFF state
    When  toggling the GPIO state
    Then  the state of the GPIO is 1
    When  toggling the GPIO state
    Then  the state of the GPIO is 0


