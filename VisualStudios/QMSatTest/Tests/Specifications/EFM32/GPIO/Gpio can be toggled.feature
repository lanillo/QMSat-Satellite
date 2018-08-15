Feature: GPIO can be toggled

  Pin Number represents the number of the pin of the GPIO (from 0 to 15)
  Bank Letter represents the bank of the pin of the GPIO (from A to E)
  GPIO can be set as an input (0) or output (1)
  Type is the type of the GPIO (pullup or pulldown, etc)
  The state of the GPIO can be low (0), high (1) or it does not matter (3) since it is an input

  Scenario: A GPIO initially OFF initialized as an INPUT
    Given the pin number is 2, a bank letter is 0, is an input and the type is 0
    When  toggling the GPIO state
    Then  the state of GPIO is 3 since GPIO is set as a 0


  Scenario: A GPIO initially OFF initialized as an OUTPUT
    Given the pin number is 2, a bank letter is 0, is an output and the type is 6
    When  toggling the GPIO state
    Then  the state of GPIO is 1 since GPIO is set as a 1
    When  toggling the GPIO state
    Then  the state of GPIO is 0 since GPIO is set as a 1


