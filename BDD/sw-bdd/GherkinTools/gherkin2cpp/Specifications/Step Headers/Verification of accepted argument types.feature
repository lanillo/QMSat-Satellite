Feature: Verification of accepted argument types

  These are the types that should be accepted:
  Types: void, int, long, float, char *, const char * and char const *
  Exonetik type: u8, s8, u16, s16, u32, s32, u64, s64, f32 and f64

  Scenario: Accepted type u8
    Given a header file
    """
    /** @bdd a step with (?P<count>\d+) items? */
    void aFunction(u8 count);
    """
    When  parsing the header file
    Then execution ends without exception

   Scenario: Accepted type u16
    Given a header file
    """
    /** @bdd a step with (?P<count>\d+) items? */
    void aFunction(u16 count);
    """
    When  parsing the header file
    Then execution ends without exception

   Scenario: Accepted type u32
    Given a header file
    """
    /** @bdd a step with (?P<count>\d+) items? */
    void aFunction(u32 count);
    """
    When  parsing the header file
    Then execution ends without exception

   Scenario: Accepted type u64
    Given a header file
    """
    /** @bdd a step with (?P<count>\d+) items? */
    void aFunction(u64 count);
    """
    When  parsing the header file
    Then execution ends without exception

   Scenario: Accepted type s8
    Given a header file
    """
    /** @bdd a step with (?P<count>\d+) items? */
    void aFunction(s8 count);
    """
    When  parsing the header file
    Then execution ends without exception

    Scenario: Accepted type s16
    Given a header file
    """
    /** @bdd a step with (?P<count>\d+) items? */
    void aFunction(s16 count);
    """
    When  parsing the header file
    Then execution ends without exception

   Scenario: Accepted type s32
    Given a header file
    """
    /** @bdd a step with (?P<count>\d+) items? */
    void aFunction(s32 count);
    """
    When  parsing the header file
    Then execution ends without exception

   Scenario: Accepted type s64
    Given a header file
    """
    /** @bdd a step with (?P<count>\d+) items? */
    void aFunction(s64 count);
    """
    When  parsing the header file
    Then execution ends without exception

   Scenario: Accepted type f32
    Given a header file
    """
    /** @bdd a step with (?P<count>\d+) items? */
    void aFunction(f32 count);
    """
    When  parsing the header file
    Then execution ends without exception

  Scenario: Accepted type f64
    Given a header file
    """
    /** @bdd a step with (?P<count>\d+) items? */
    void aFunction(f64 count);
    """
    When  parsing the header file
    Then execution ends without exception

   Scenario: Accepted type long
    Given a header file
    """
    /** @bdd a step with (?P<count>\d+) items? */
    void aFunction(long count);
    """
    When  parsing the header file
    Then execution ends without exception

  Scenario: Accepted type float
    Given a header file
    """
    /** @bdd a step with (?P<count>\d+) items? */
    void aFunction(float count);
    """
    When  parsing the header file
    Then execution ends without exception

  Scenario: Accepted type char
    Given a header file
    """
    /** @bdd a step with (?P<count>\d+) items? */
    void aFunction(char* count);
    """
    When  parsing the header file
    Then execution ends without exception

  Scenario: A void parameter
    Given a header file
          """
          /** @bdd a step for a function with void parameter */
          void cFunction(void);
          """
    When  parsing the header file
    Then  execution ends without exception

  Scenario: A not accepted parameter
    Given a header file
          """
          /** @bdd a step with (?P<count>\d+) items? */
          void aFunction(bad count);
          """
    When  parsing the header file
    Then  a "TypeParameterError" error is raised

  Scenario: Missing type on argument
    Given a header file
          """
          /** @bdd a step with (?P<count>\d+) items? at temperature (?P<temperature_degK>\d+) degree Kelvin */
          void aFunction(int count, temperature_degK);
          """
    When  parsing the header file
    Then  a "TypeParameterError" error is raised
