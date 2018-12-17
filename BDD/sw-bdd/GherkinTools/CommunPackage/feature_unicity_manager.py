from random import randint



class NumberUnicityManager:
    maxUniqueNumber = 9999

    def __init__(self):
        self._uniqueNumberList = []
        self._uniqueNumbersUsedInFiles = []

    def _addUniqueNumber(self, newUniqueNumber: int):
        if newUniqueNumber >= 1 and newUniqueNumber <= self.maxUniqueNumber and self._uniqueNumberList.count(newUniqueNumber) == 0 :
            self._uniqueNumberList.append(newUniqueNumber)
            return 1
        else :
            return 0

    def addUniqueNumberUsedInFile(self, newUniqueNumber: int):
        if newUniqueNumber >= 1 and newUniqueNumber <= self.maxUniqueNumber and self._uniqueNumbersUsedInFiles.count(newUniqueNumber) == 0 :
            if self._uniqueNumberList.count(newUniqueNumber) == 0:
                self._uniqueNumberList.append(newUniqueNumber)

            self._uniqueNumbersUsedInFiles.append(newUniqueNumber)
            return 1
        else :
            return 0

    def generateNewUniqueNumber(self):
        numberFound = 0
        newUniqueNumber = 0
        while numberFound != 1:
            newUniqueNumber = randint(1, self.maxUniqueNumber)
            if self._uniqueNumberList.count(newUniqueNumber) == 0:
                numberFound = 1

        self._addUniqueNumber(newUniqueNumber)
        return newUniqueNumber




