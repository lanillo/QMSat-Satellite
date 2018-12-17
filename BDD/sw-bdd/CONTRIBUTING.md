# Multi-Level Requirement review checklist
The "feature" section of a Feature file contains the definition of a multi-level requirements (MLR).
This MLR must conform to all items below. 

## MLR complies with HLR
The multi-level requirement satisfies related high-level requirements.

In case MLR is a derived requirement, the reason of its existence is
available and correctly defined.

## MLR is unambiguous, accurate and does not conflict with other requirements

## MLR does not conflict with hardware feature of the target microprocessor.

## MLR definition and attributes conforms to Software Standards Document D3335
Ensure that the software requirements standards and feature file standards were followed and derived
requirements are justified during implementation of the multi-level requirement 

## MLR is traceable to HLR
The traceability information of a multi-level requirement is directly
available in the Feature file by any of the following ways:

  1. By a direct reference to a HLR
  1. By the identification of MLR as a derived requirement

## MLR has a unique identifier

# Multi-level requirement Verification Cases and Procedures review checklist
The "scenario" section of a Feature file contains the Multi-level requirement Verification Cases
and Procedures (MVCP). MVCP must conform to all items below.

## MVCP are developed and executed successfully without any warnings or errors
Warning or error deviation must be justify and approve in the Pull request

## MVCP are complete, unambiguous and accurate

## MVCP conforms to Software Standards Document D3335
Ensure that the feature file standards were followed during implementation of the MVCP

## MVCP test code is correct
Test code is used to implement the test procedure definitions (Gherkin statements).
Test code must be consistent and fully described by the associated Gherkin statement.

## MVCP normal test cases are developed

## MVCP robustness test cases are developed

## MVCP achieve full coverage of data and control coupling

## MVCP were developed with independence to source code development
The Pull Request approval guarantees the developer/modifier of a "scenario" section is different than
the author of the code being reviewed (Table A-6 [3] independence objective).

# Source code review checklist
Source code review verifies if code conforms to items below.

## Working branch under review is created from master branch
Ensure that sources code under review are the modifications between working branch and master branch 

## Source code complies with MLR
Ensure that the source code is complete with respect to multi-level requirements

## Source code complies with software architecture
Ensure that the source code matches the data flow and control flow

## Source code does not implement any undocumented function

## MLR has traceability to source code
Ensure that the multi-level requirement were developed into source code

## Source code is verifiable
Ensure there are no statements or structures that cannot be verified and that code does not
have to be altered to test it.

## Source code conforms to Software Standards Document D3335
Ensure that the software code standards were followed during implementation of the source code

# Pull request approval
Once all software data is conformed to this guidelines the Pull Request itself is annotated with the following:

Pull Request Annotation                                       | Author of the Annotation
------------------------------------------------------------- | ---
Review and analysis of MLR completed                          | A reviewer different than the MLR developer
Review and analysis of source code completed                  | A reviewer different than the source code developer
Review and analysis of test code completed                    | A reviewer different than the test code developer
MLR coverage is achieved by test cases                        | A reviewer different than the test cases developer
Data and control coupling coverage us achieved by test cases  | A reviewer different than the test cases and test code developers
Test cases were developed by **<Name>**                       | A developer different than the source code developer
Structural coverage is achieved by test cases                 | A reviewer different than test cases and test developers

