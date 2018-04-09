Feature: GPIO can be turned OFF

  Scenario: A GPIO initially instantiated as an INPUT
    Given the pin number is 2, a bank letter is 0, is an input and the type is 0
    Then  the state of GPIO is 3 (0_low or 1_high or 3_dont_care) since GPIO is set as a 0 (0_INPUT or 1_OUTPUT)


  Scenario: A GPIO initially instantiated as an OUTPUT
    Given the pin number is 2, a bank letter is 0, is an output and the type is 6
    Then  the state of GPIO is 0 (0_low or 1_high or 3_dont_care) since GPIO is set as a 1 (0_INPUT or 1_OUTPUT)


