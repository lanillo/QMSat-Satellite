Feature: Feature file may contain parsable metadata in their description

  The feature description have the ability to contain metadata. This metadata contain information to
  generate other documents related to that feature. This is example of metadata:

  Attributes: test, mlr, ttc, hlr
  Trace To Code: attributeParser
  HLR: 1, 2, 4, 6

  The trace to code name can accept Trace to code and TraceToCode
  Name must be separated from data with ":"
  Many data associate with a name must be separate by a ","

  Scenario: Attributes are properly recognized when present
    Given a feature file
      """
        Feature: MLR123 Sub folders scan
          Attributes: asd, fdsfsdf
          TraceToCode: blu, whit
          HLR: 123, 1234
      """
    When parsing the feature file
    Then the MLR code is 123
    And the Attributes are asd fdsfdsdf
    And TraceToCode are blu whit
    And HLR are 123 1234

  Scenario: Trace to code are properly recognized with separate word
    Given a feature file
      """
        Feature: MLR123 Sub folders scan
          Attributes: asd, fdsfsdf
          Trace to code: blu
          HLR: 123, 1234
      """
    When parsing the feature file
    Then the MLR code is 123
    And the Attributes are asd fdsfdsdf
    And TraceToCode is blu
    And HLR are 123 1234

  Scenario: Scenario MVCP numbers
    Given a scenario with an MVCP number
      """
      Feature: a feature
        Scenario: MVCP1332 This is a bogus scenario
          Given Nothing
          When more nothing
          Then nothing happens
      """
    When parsing the feature file
    Then the scenario MVCP number is 1332
    And  no robutness information


  Scenario: detect robustness tag in a scenario
    Given a scenario with an robustness tag
      """
      Feature: a feature
        Scenario: ROBUSTNESS This is a bogus scenario
          Given Nothing
          When more nothing
          Then nothing happens
      """
    When parsing the feature file
    Then the robustness scenario is detected


  Scenario: detect robustness tag in a scenario outline
    Given a scenario with an robustness tag
      """
      Feature: a feature
        Scenario Outline: ROBUSTNESS This is a bogus scenario outline
          Given a <Weapons>
          When more nothing
          Then nothing happens
        Examples:
          | Weapons |
          | sword   |
          | hammer  |
      """
    When parsing the feature file
    Then the robustness scenario is detected