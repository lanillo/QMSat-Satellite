from os import path

from CommunPackage.feature import Feature
from mako.template import Template

from CommunPackage.scenario import Step
from .cpp_header_parser import Function


class NoFunctionMatchError(Exception):
    pass


class TooManyFunctionMatchError(Exception):
    pass


def _map_steps_to_function(context, features: [Feature], functions: [Function]) -> {Step: Function}:
    def find_function_for_text(context, text: str):
        matching_functions = [function for function in functions if (function.regex.fullmatch(text)
                                                                     and context.current_evaluator == function.class_name)]
        too_much_match = False
        if len(matching_functions) == 0:
            matching_functions = [function for function in functions if function.regex.fullmatch(text)]
            if len(matching_functions) == 0:
                return None
            if len(matching_functions) > 1 :
                too_much_match = True
        if len(matching_functions) > 1 or too_much_match == True:
            print('Following function are detected by the same regex:\n')
            for a in matching_functions:
                print(str(a.name))
            raise Exception('TooManyFunctionMatchError')
        if context.current_evaluator != str(matching_functions[0].class_name):
            context.current_evaluator = str(matching_functions[0].class_name)
        return matching_functions[0]

    steps = (step for feature in features for scenario in feature.scenarios for step in scenario.steps)
    return {step: find_function_for_text(context, step.text) for step in steps}


def generate_tests(context, features: [Feature], functions: [Function], headers: [str]) -> str:
    step_functions = _map_steps_to_function(context, features, functions)

    template = Template(filename=path.realpath(path.join(path.dirname(__file__), 'template.cpp.mako')))
    return template.render(features=features,
                           step_functions=step_functions,
                           headers=headers)
