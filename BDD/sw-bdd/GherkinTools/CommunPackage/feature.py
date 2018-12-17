import os
import re
from re import findall

from .feature_unicity_manager import NumberUnicityManager
from .scenario import Scenario


class Feature:
    def __init__(self, name: str, description: str, scenarios: [Scenario], traceabilityEnabled: bool, file_name: str=None, idManager: NumberUnicityManager = None):

        self.name = name
        self.name_mako = name
        self.folder_lvl = 0
        self.father_folder = ''
        self.folder = ''
        self.folder_path = ''
        self.name_with_mlr = ''
        self.name_with_hlr = ''
        self.scenarios = scenarios
        self.file_name = file_name
        self.mlr = 0
        self.hlr = 0
        self.attributes = []
        self.parentHLR = []
        self.ttc = ''
        self.idManager = idManager
        self.traceability = traceabilityEnabled

        self.parsedDescription = []
        if description != None or self.traceability == True:
            self.parseDescription(description)
        if self.parsedDescription != []:
            self.html_parsedDescription = self.html_parsedDescription()
        else:
            self.html_parsedDescription = ''
        self.parseName()
        self.complete_name()


    def parseName(self):
        tempName = self.name.lstrip()
        splitName = tempName.split(' ')

        # Vérifier si le nom contient des caractères invalides
        re1 = re.compile(r"[@+,:<>/{}[\]~`éèêçôòûùîì]");
        if re1.search(tempName):
            raise Exception('Invalid character in Feature name: ' + self.name)

        if len(splitName)>0:
            firstElementInName = splitName[0].lower()
            if firstElementInName.find('mlr') != -1 or firstElementInName.find('hlr') != -1:
                number = findall("\d+", firstElementInName)[0]
                if len(number) > 0:
                    # Register unique number
                    if firstElementInName.find('mlr') != -1:
                        self.mlr = number
                    elif firstElementInName.find('hlr') != -1:
                        self.hlr = number

                    if self.idManager != None:
                        if self.idManager.addUniqueNumberUsedInFile(int(number)) == 0:
                            raise Exception('Unique number already in use in: ' + os.path.basename(self.file_name))
                    splitName.remove(splitName[0])

        self.name = ' '.join(splitName).lstrip()


    def parseDescription(self, description):

        traceToCodeFound = False
        hlrFound = False
        #Iterate over lines of the decription. For each line, if keyword is found, parse it. If no keywords are found,
        #add line to parsedDescription
        if description != None:
            for line in description.split('\n'):
                if ':' in line:
                    metadata, data = line.lstrip().replace(' ', '').split(':')
                    if metadata.lower().find('attributes') != -1:
                        self.attributes = data.split(',')
                    elif metadata.lower().find('hlr') != -1:
                        self.parentHLR = data.split(',')
                        hlrFound = True
                    elif metadata.lower().find('trace to code') != -1:
                        self.ttc = data.split(',')
                        traceToCodeFound = True
                    elif metadata.lower().find('tracetocode') != -1:
                        self.ttc = data.split(',')
                        traceToCodeFound = True
                    else:
                        self.parsedDescription.append(line.lstrip())
                else:
                    self.parsedDescription.append(line.lstrip())

        if traceToCodeFound == False and self.traceability == True:
            raise Exception('No trace to code for feature: ' + self.name)

        if hlrFound == False and self.traceability == True and self.hlr == 0:
            raise Exception('No parent hlr for feature: ' + self.name)


    def complete_name(self):
        if self.mlr != 0:
            self.name_with_mlr = 'MLR{} {}'.format(str(self.mlr), self.name)
            self.name_mako = self.name_with_mlr.replace(' ','_')
        elif self.hlr != 0:
            self.name_with_hlr = 'HLR{} {}'.format(str(self.hlr), self.name)
            self.name_mako = self.name_with_hlr.replace(' ', '_')
        else:
            self.name_with_mlr = self.name
            self.name_mako = self.name_with_mlr.replace(' ', '_')

    def html_parsedDescription(self):
        html_parsedDescription = ''
        for line in self.parsedDescription:
            html_parsedDescription += '  ' + line + '\n'
        return html_parsedDescription
