Feature: GPIO can be initialized as INPUT or OUTPUT

  Scenario: Initialize GPIO as INPUT with OUTPUT type
    Given the pin number is 2, a bank letter is 0, is an input and the type is 6
    Then  an initialization error flag is set


  Scenario: Initialize GPIO as OUTPUT with OUTPUT type
    Given the pin number is 2, a bank letter is 0, is an output and the type is 4
    Then  a GPIO is instantiated as 0


  Scenario: Initialize GPIO as INPUT with INPUT type
    Given the pin number is 2, a bank letter is 0, is an input and the type is 2
    Then  a GPIO is instantiated as 1


  Scenario: Initialize GPIO as OUTPUT with INPUT type
    Given the pin number is 2, a bank letter is 0, is an output and the type is 2
    Then  an initialization error flag is set


