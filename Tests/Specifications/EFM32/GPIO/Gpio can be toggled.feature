Feature: GPIO can be toggled

  Scenario: A GPIO initially OFF initialized as an INPUT
    Given the pin number is 2, a bank letter is 0, is an input and the type is 0
    When  toggling the GPIO state
    Then  the state of GPIO is 3 (0_low or 1_high or 3_dont_care) since GPIO is set as a 0 (0_INPUT or 1_OUTPUT)


  Scenario: A GPIO initially OFF initialized as an OUTPUT
    Given the pin number is 2, a bank letter is 0, is an output and the type is 6
    When  toggling the GPIO state
    Then  the state of the GPIO is 1
    When  toggling the GPIO state
    Then  the state of the GPIO is 0


