Feature: Integrality of the feature content is copy

  The content of the feature must be copy without modification including the title, the description,
  the attribute, the traceability and the scenario.

Scenario: A feature with everything in it
         Given an empty folder
         And   a feature file named "MLR0666 Full.feature" with content
         """
         Feature: MLR0666 Full

           This is a short description

           Attributes: Linkin, Park
           HLR: 4, 2
           Trace to code: Chester

           Scenario: MVCP8236 A scenario
             Given one step closer
             And   to the edge
             Then  I'm about the break



         """
         When invoking Gherkin2Cpp with option "--add-traceability"
         Then expect the feature to contain
         """
         Feature: MLR0666 Full

           This is a short description

           Attributes: Linkin, Park
           HLR: 4, 2
           Trace to code: Chester

           Scenario: MVCP8236 A scenario
             Given one step closer
             And   to the edge
             Then  I'm about the break



         """