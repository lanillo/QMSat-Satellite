Feature: Create new feature folder

  Line argument --output-feature-dir provides the option to choose where you want the feature write the put the feature
  files, if the command is empty or not present, the feature write overwrite the feature in the specification folder

  The output feature directory is relative to the working directory where the script was launch.

  Scenario: Changing the feature output folder
    Given an empty folder
    And   a file named "That feature should be moved.feature" with content
    And   a file named "That txt should be moved.txt" with content
    And   a file named "That image should be moved.png" with content
    When  invoking Gherkin2Cpp with option "--output-feature-dir=gherkin2cpp\\CreateNewFeatureFolder"
    Then  file That feature should be moved.feature is in gherkin2cpp\\CreateNewFeatureFolder folder instead
    Then  file That txt should be moved.txt is in gherkin2cpp\\CreateNewFeatureFolder folder instead
    Then  file That image should be moved.png is in gherkin2cpp\\CreateNewFeatureFolder folder instead


  Scenario: non feature files keep their level folder
    Given an empty folder
    And   the folder named "Subfolder"
    And   a file named "That feature should be moved.feature" with content
    And   a file named "That txt should be moved.txt" with content
    When  invoking Gherkin2Cpp with option "--output-feature-dir=gherkin2cpp\\CreateNewFeatureFolder"
    Then  file That feature should be moved.feature is in gherkin2cpp\\CreateNewFeatureFolder folder instead
    Then  file That txt should be moved.txt is in gherkin2cpp\\CreateNewFeatureFolder folder instead

