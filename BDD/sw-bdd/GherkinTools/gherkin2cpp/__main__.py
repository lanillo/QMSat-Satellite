import sys, os
sys.path.insert(0, os.path.dirname(sys.argv[0])) #sys.args[0] = script name
from gherkin2cpp.PythonScripts.cmdline_gherkin2cpp import invoke

if __name__ == '__main__':
    invoke(sys.argv[1:])
