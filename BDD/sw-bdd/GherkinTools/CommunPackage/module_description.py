import os

class ModuleDescription:
    def __init__(self, text, path):
        self.description = text
        self.folder_path = path
        self.name = 'description.txt'


def get_description_from_file(description_file):
    file_name = os.path.basename(description_file)

    if file_name == 'description.txt':
        file = open(description_file, 'r')
        path = os.path.dirname(description_file)
        text = ''
        for line in file:
            text += line
        return ModuleDescription(text.replace('\n','\n '), path)
    else:
        return ModuleDescription('','')


