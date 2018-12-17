Feature: Formatting feature files output aligned documents

  The feature writer will align the feature files to obtain uniform documents.

  Scenario: Scenario with unalign steps get align
         Given an empty folder
         And   a feature file named "Steps get align when formating.feature" with content
         """
         Feature: Steps get align when formating



           Scenario: unalign steps
                Given step place like that
                             And another further
             Then one closer
         """
         When invoking Gherkin2Cpp with option " "
         Then expect the feature to contain
         """
         Feature: Steps get align when formating

           Scenario: unalign steps
             Given step place like that
             And   another further
             Then  one closer



         """


  Scenario: Scenario with unalign examples get align
    Given an empty folder
    And   a feature file named "examples get align when formating.feature" with content
          """
          Feature: examples get align when formating

            Scenario Outline: unalign examples
                Given a garden
                And <quantity> vegetables named <name>
                Then good job you got vegetables
                     Examples:
                     | quantity |   name |
              |                                  6             |carrots|
                                    |3|pickles|
                 |2034                    |                               peppers|
          """
      When invoking Gherkin2Cpp with option " "
      Then expect the feature to contain
          """
          Feature: examples get align when formating

            Scenario Outline: unalign examples
              Given a garden
              And   <quantity> vegetables named <name>
              Then  good job you got vegetables

            Examples:
              | quantity | name    |
              | 6        | carrots |
              | 3        | pickles |
              | 2034     | peppers |



          """


    Scenario: Scenario with longest value exceeding longest header
         Given an empty folder
         And   a file named "a feature.feature" with content
         """
         Feature: a feature
          Scenario Outline: a scenario with an outline
            Given an outline with variables <car> and <colour> and <randomFloat>
            When nothing
            Then nothing
         Examples:
         |car|colour|randomFloat|
         |Toyota|red|23.65523|
         |Hyundai|black|0.00001231233|
         |Ford|grey|1337.12333213|
         """
         When   invoking Gherkin2Cpp with option " "
         Then   expect the feature to contain
         """
         Feature: a feature

           Scenario Outline: a scenario with an outline
             Given an outline with variables <car> and <colour> and <randomFloat>
             When  nothing
             Then  nothing

           Examples:
             | car     | colour | randomFloat   |
             | Toyota  | red    | 23.65523      |
             | Hyundai | black  | 0.00001231233 |
             | Ford    | grey   | 1337.12333213 |



         """