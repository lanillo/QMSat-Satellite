Feature: GPIO can be initialized as INPUT or OUTPUT

  Pin Number represents the number of the pin of the GPIO (from 0 to 15)
  Bank Letter represents the bank of the pin of the GPIO (from A to E)
  GPIO can be set as an input (0) or output (1)
  Type is the type of the GPIO (pullup or pulldown, etc)

  Scenario: Initialize GPIO as INPUT with OUTPUT type
    Given the pin number is 2, a bank letter is 0, is an input and the type is 6
    Then  an initialization error flag is set


  Scenario: Initialize GPIO as OUTPUT with OUTPUT type
    Given the pin number is 2, a bank letter is 0, is an output and the type is 6
    Then  a GPIO is instantiated as 0


  Scenario: Initialize GPIO as INPUT with INPUT type
    Given the pin number is 2, a bank letter is 0, is an input and the type is 0
    Then  a GPIO is instantiated as 1


  Scenario: Initialize GPIO as OUTPUT with INPUT type
    Given the pin number is 2, a bank letter is 0, is an output and the type is 0
    Then  an initialization error flag is set


