from re import findall

from .feature_unicity_manager import NumberUnicityManager


class Step:
    def __init__(self, keyWord: str, text: str, originalText: str):
        self.keyWord = keyWord
        self.text = text
        self.originalText = originalText
        self.function = None


class Scenario:
    def __init__(self, name: str, steps: [Step], outline_count: int, feature_file_name: str, examples = None, idManager: NumberUnicityManager = None):
        self.name = name
        self.rawName = name
        self.name_with_mvcp = name
        self.steps = steps
        self.outline_count = outline_count
        self.mvcp  = 0
        self.robustness = 0
        self.examples = examples
        self.idManager = idManager
        self.featureFileName = feature_file_name
        self.parseName()

    def parseName(self):
        tempName = self.name.lstrip()
        splitName = tempName.split(' ')

        if len(splitName)>0:
            firstElementInName = splitName[0].lower()
            if firstElementInName.find('mvcp') != -1 and self.outline_count == 0:
                mvcpNumber = findall("\d+", firstElementInName)
                if len(mvcpNumber) > 0:
                    self.mvcp = mvcpNumber[0]
                    if self.idManager != None:
                        if self.idManager.addUniqueNumberUsedInFile(int(self.mvcp)) == 0:
                            raise Exception('Unique number already in use in scenario: ' + self.name)
                    splitName.remove(splitName[0])

        for word in splitName:
            if word.lower().find('robustness') != -1:
                self.robustness = 1
                splitName.remove(word)

        self.name = ' '.join(splitName).lstrip()



