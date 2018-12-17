Feature: Create new feature folder

  Line argument --output-feature-dir provides the option to choose where you want the feature write the put the feature
  files, if the command is empty or not present, the feature write overwrite the feature in the specification folder

  The output feature directory is relative to the working directory where the script was launch.

  Scenario: Changing the feature output folder
    Given an empty folder
    And   a file named "That feature should be moved.feature" with content
    """
    Feature: That feature should be moved
      Scenario: a Scenario
        Given a step
        Then  a step
    """
    When  invoking Gherkin2Cpp with option "--output-feature-dir=gherkin2cpp\\CreateNewFeatureFolder"
    Then  file That feature should be moved.feature is in gherkin2cpp\\CreateNewFeatureFolder folder instead
