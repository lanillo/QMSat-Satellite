import os
import shutil
from glob import iglob

from CommunPackage.feature import Feature, Scenario

MAX_FILEPATH_LENGTH = 260

def generateNewFileName(feature: Feature, destinationDir: str, features_root_directory):

    if destinationDir == '':
        return os.path.dirname(feature.file_name) + '\\' + feature.name.capitalize() + '.feature'
    else:
        splitPath = feature.file_name.split('\\')
        temp = features_root_directory.split('\\')[len(features_root_directory.split('\\')) - 1]
        if temp == '':
            temp = features_root_directory.split('\\')[len(features_root_directory.split('\\')) - 2]
        index_father_folder = splitPath.index(temp)
        index_file_name = splitPath.index(os.path.basename(feature.file_name))
        newSplitPath = splitPath[index_father_folder+1:index_file_name]
        return destinationDir + '\\' + ('\\').join(newSplitPath) + '\\' + feature.name.capitalize() + '.feature'


def move_other_files(parent_path, destinationDir):
    other_files = []
    other_files.extend(iglob(os.path.join(parent_path, '**', '*.*'), recursive=True))
    for file_path in other_files:
        if '.feature' not in file_path:
            splitPath = file_path.split('\\')
            temp = parent_path.split('\\')[len(parent_path.split('\\')) - 1]
            index_father_folder = splitPath.index(temp)
            index_file_name = splitPath.index(os.path.basename(file_path))
            newSplitPath = splitPath[index_father_folder + 1:index_file_name]
            new_path = destinationDir  + '\\' +  ('\\').join(newSplitPath) + '\\' + os.path.basename(file_path)
            if not os.path.exists(os.path.dirname(new_path)):
                os.makedirs(os.path.dirname(new_path))
            shutil.copyfile(file_path,new_path)


def examplesToString(examples):

    """ 
    A similar string must be returned:
        | animal  | drink  |
        | dog     | coffee |
        | cat     | tea    |
        | bear    | beer   |
    """

    columnWidthTable = []
    for column in range(len(examples['tableHeader']['cells'])):
        columnWidthTable.append(len(examples['tableHeader']['cells'][column]['value']))
        for row in examples['tableBody']:
            if len(row['cells'][column]['value']) > columnWidthTable[column]:
                columnWidthTable[column] = len(row['cells'][column]['value'])

        #Add one for padding
        columnWidthTable[column] = columnWidthTable[column] + 1


    exampleString = '    |'
    for headerElement in examples['tableHeader']['cells']:
        index = examples['tableHeader']['cells'].index(headerElement)
        exampleString += ' ' + headerElement['value'].ljust(columnWidthTable[index], ' ') + '|'

    for bodyLine in examples['tableBody']:
        exampleString += '\n'
        exampleString += '    |'
        for cell in bodyLine['cells']:
            index = bodyLine['cells'].index(cell)
            exampleString += ' ' + cell['value'].ljust(columnWidthTable[index], ' ') + '|'


    return exampleString

def formatScenarioToString(scenario: Scenario, add_id_numbers, remove_id_numbers):
    scenarioString = ''

    if scenario.outline_count == 0 :
        if scenario.examples != None:
            scenarioString = '  Scenario Outline: '
        else:
            scenarioString = '  Scenario: '

        if remove_id_numbers == False:
            """Write MVCP"""
            if scenario.mvcp != 0:
                scenarioString += "MVCP{} ".format(str(scenario.mvcp))
                scenario.name_with_mvcp = "MVCP{}".format(str(scenario.mvcp) + ' ' + scenario.name)

        """Write ROBUSTNESS"""
        if scenario.robustness != 0:
            scenarioString += "ROBUSTNESS "

        scenarioString += scenario.name
        scenarioString += '\n'

        for step in scenario.steps:
            scenarioString += '    '
            scenarioString += '{} {}\n'.format(step.keyWord.strip(" ").ljust(5), step.originalText)

        if scenario.examples != None:
            scenarioString += '\n  Examples:\n'
            scenarioString += examplesToString(scenario.examples)
            scenarioString += '\n'

        scenarioString += '\n\n'


    return scenarioString

def writeFeature(featureFile: Feature, dir: str = '' , add_id_numbers =  False, remove_id_numbers = False, features_root_directory: str = '', add_traceability = False, remove_traceability = False):
    #Copie the non .feature files
    if dir != '':
        move_other_files(features_root_directory, dir)

    # The feature file name will take the title of the feature name
    if add_id_numbers == True or (featureFile.mlr != 0 and remove_id_numbers == False and add_id_numbers == False):
        if dir != '':
            newFileName = generateNewFileName(featureFile, dir, features_root_directory)
            if not os.path.exists(os.path.dirname(newFileName)):
                os.makedirs(os.path.dirname(newFileName))

        elif featureFile.mlr != 0 and featureFile.hlr == 0:
            newFileName = featureFile.file_name.replace(os.path.basename(featureFile.file_name),
                                                        featureFile.name_with_mlr + '.feature')
        elif featureFile.mlr == 0 and featureFile.hlr != 0:
            newFileName = featureFile.file_name.replace(os.path.basename(featureFile.file_name),
                                                        featureFile.name_with_hlr + '.feature')

    elif remove_id_numbers == True:
        newFileName = featureFile.file_name.replace(os.path.basename(featureFile.file_name),
                                                    featureFile.name + '.feature')

    else:
        newFileName = generateNewFileName(featureFile, dir, features_root_directory)
        """Create Dir if inexistant"""
        if not os.path.exists(os.path.dirname(newFileName)):
            os.makedirs(os.path.dirname(newFileName))

    """Create file and open writer"""
    if len(newFileName) > MAX_FILEPATH_LENGTH:
        raise Exception('Feature path exceeds character limit: ' + featureFile.name)

    fileWriter = open(newFileName, 'w')


    """Write unique number and feature name"""
    if featureFile.hlr != 0 and add_id_numbers == True:
        fileWriter.write('Feature: {}\n\n'.format(featureFile.name_with_hlr))
    #Nowhere a hlr is given to a feature
    elif featureFile.mlr != 0 and add_id_numbers == True:
        fileWriter.write('Feature: {}\n\n'.format(featureFile.name_with_mlr))

    elif (featureFile.mlr != 0 or featureFile.hlr != 0) and remove_id_numbers == False and add_id_numbers == False:
        fileWriter.write('Feature: {}\n\n'.format(featureFile.name_with_mlr))

    else:
        fileWriter.write('Feature: {}\n\n'.format(featureFile.name))

    """Write description"""
    empty_line = False
    if featureFile.parsedDescription != [''] or (len(featureFile.parentHLR) == 0 and len(featureFile.ttc) == 0):
        for line in featureFile.parsedDescription:
            if empty_line == True:
                if line != '':
                    empty_line = False
            if empty_line == False:
                if line == '':
                    empty_line = True
                    fileWriter.write('\n')
                else:
                    fileWriter.write('  {}\n'.format(line))
    if len(featureFile.parsedDescription) != 0 and featureFile.parsedDescription[len(featureFile.parsedDescription) - 1] != '':
        fileWriter.write('\n')

    if remove_traceability == False or add_traceability == True:

        """Write attributes"""
        if(len(featureFile.attributes) > 0):
            fileWriter.write('  Attributes:')
            isFirstElement = 1
            for attribute in featureFile.attributes:
                if(isFirstElement == 1):
                    fileWriter.write(' ')
                    isFirstElement = 0
                else:
                    fileWriter.write(', ')

                fileWriter.write('{}'.format(str(attribute)))

            fileWriter.write('\n')

        """Write parent HLR"""
        if(len(featureFile.parentHLR) > 0):
            fileWriter.write('  HLR:')
            isFirstElement = 1
            for aHLR in featureFile.parentHLR:
                if isFirstElement == 1:
                    fileWriter.write(' ')
                    isFirstElement = 0
                else:
                    fileWriter.write(', ')

                fileWriter.write('{}'.format(str(aHLR)))

            fileWriter.write('\n')
        elif add_traceability == True:
            fileWriter.write('  HLR:')
            fileWriter.write('\n')

        """Write Trace to code"""
        if(len(featureFile.ttc) > 0):
            fileWriter.write('  Trace to code:')
            isFirstElement = 1
            for aTTC in featureFile.ttc:
                if isFirstElement == 1:
                    fileWriter.write(' ')
                    isFirstElement = 0
                else:
                    fileWriter.write(', ')

                fileWriter.write('{}'.format(str(aTTC)))
            fileWriter.write('\n\n')
        elif add_traceability == True:
            fileWriter.write('  Trace to code:')
            fileWriter.write('\n\n')

    """Write scenarios"""
    for scenario in featureFile.scenarios:
        fileWriter.write(formatScenarioToString(scenario, add_id_numbers, remove_id_numbers))

    fileWriter.close()
