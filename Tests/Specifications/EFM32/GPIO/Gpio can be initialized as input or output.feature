Feature: GPIO can be initialized as INPUT or OUTPUT

  Scenario: Initialize GPIO as INPUT with OUTPUT type
    Given the pin number is 2, a bank letter is A (0), is an input and the type is output (6)
    Then  an initialization error flag is set


  Scenario: Initialize GPIO as OUTPUT with OUTPUT type
    Given a pin number, a bank letter, isInput and a type
    When  isInput is FALSE and the type is OUTPUT
    Then  a GPIO is instantiated as an OUTPUT


  Scenario: Initialize GPIO as INPUT with INPUT type
    Given a pin number, a bank letter, isInput and a type
    When  isInput is TRUE and the type is INPUT
    Then  a GPIO is instantiated as an INPUT


  Scenario: Initialize GPIO as OUTPUT with INPUT type
    Given a pin number, a bank letter, isInput and a type
    When  isInput is FALSE and the type is INPUT
    Then  no GPIO is instantiated


