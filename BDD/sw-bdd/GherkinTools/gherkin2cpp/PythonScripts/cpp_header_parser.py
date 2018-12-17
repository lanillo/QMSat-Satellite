import re
from CppHeaderParser import CppHeader


class StepAndFunctionParametersMismatch(Exception):
    def __init__(self, step_parameters: [str], function_parameters: [str]):
        self.step_parameters = step_parameters
        self.function_parameters = function_parameters


class Parameter:

    def __init__(self, name: str, type: str):
        self.name = name
        self.type_error = False
        self.type = type
        self.valid_types = ['int', 'uint', 'unsigned int', 'unsigned short', 'long', 'float', 'char *' , 'const char*', 'const char *' ,'char const*','char const *' ,'u8' ,'s8' ,'u16' ,'s16' ,'u32' ,'s32' ,'u64' ,'s64' ,'f32' ,'f64','void']
        self.validate_accepted_types()

    def validate_accepted_types(self):
        if self.type not in self.valid_types:
            print('Type Parameter Error, ' + str(self.type) + ' is not accepted')
            raise Exception('TypeParameterError')


class Function:
    def __init__(self, regex, name: str, return_type: str, parameters: [Parameter]):
        self.parametersMatch = self.validate_regex_vs_parameters(regex, parameters)

        self.regex = regex
        self.name = name
        self.return_type = return_type
        self.parameters = parameters

    @staticmethod
    def validate_regex_vs_parameters(regex, parameters):
        function_parameter_names = [parameter.name for parameter in parameters]
        step_parameter_names = regex.groupindex.keys()
        if len(parameters) != 0 and parameters[0].type == 'void':
            # To be sure the void parameter dont trig a parameter match error trying to find a parameter in the regex
            return True
        if sorted(function_parameter_names) != sorted(step_parameter_names):
            StepAndFunctionParametersMismatch(step_parameters=step_parameter_names,
                                              function_parameters=function_parameter_names)
            raise Exception('Parameters name mismatch with step: ' + regex.pattern);
            return False
        return True

class Method(Function):
    def __init__(self, class_name, regex, name: str, return_type: str, parameters: [Parameter]):
        Function.__init__(self, regex, name, return_type, parameters)

        self.class_name = class_name

    @staticmethod
    def validate_regex_vs_parameters(regex, parameters):
        function_parameter_names = [parameter.name for parameter in parameters]
        step_parameter_names = regex.groupindex.keys()
        if sorted(function_parameter_names) != sorted(step_parameter_names):
            StepAndFunctionParametersMismatch(step_parameters=step_parameter_names,
                                              function_parameters=function_parameter_names)


_bdd_doc_regex = re.compile(r'@bdd (.+?)(?:\*/)?$')


def _get_functions(cpp_header: CppHeader):
    for function in cpp_header.functions:
        doxygen = function.get('doxygen')
        if doxygen is None:
            continue
        step_match = _bdd_doc_regex.search(doxygen)
        if step_match:
            yield Function(re.compile(step_match.group(1).strip().replace('\n', '')),
                           function['name'],
                           function['returns'],
                           [Parameter(parameter['name'], parameter['type']) for parameter in function['parameters']])
    for method in (method for class_ in cpp_header.classes.values() for method in class_['methods']['public']):
        doxygen = method.get('doxygen')
        if doxygen is None:
            continue
        step_match = _bdd_doc_regex.search(doxygen)
        if step_match:
            yield Method(method['parent']['name'],
                         re.compile(step_match.group(1).strip().replace('\n', '')),
                         method['name'],
                         method['returns'],
                         [Parameter(parameter['name'], parameter['type']) for parameter in method['parameters']])


def get_functions_from_file(file_name: str):
    return list(_get_functions(CppHeader(file_name)))


def get_functions_from_content(content: str):
    return list(_get_functions(CppHeader(content, 'string')))
