import sys, os
sys.path.insert(0, os.path.dirname(sys.argv[0])) #sys.args[0] = script name
from CommunPackage.context import Context

from CommunPackage.feature_unicity_manager import NumberUnicityManager
from gherkinParser.PythonScripts.cmdline_parser import parsing

context = Context()
idManager = NumberUnicityManager()

if __name__ == '__main__':
    parsing(sys.argv[1:], context, idManager)