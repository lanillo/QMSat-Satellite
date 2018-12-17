import os
import shlex
from glob import iglob
from os.path import realpath

from gherkin2cpp.PythonScripts.cpp_header_parser import get_functions_from_content
from gherkin2cpp.PythonScripts.generator import generate_tests
from behave import When

from CommunPackage.feature_unicity_manager import NumberUnicityManager
from gherkin2cpp.PythonScripts.cmdline_gherkin2cpp import invoke
from gherkinParser.PythonScripts.feature_parser import apply_missing_ids_to_features, get_feature_from_content


@When("parsing the feature file")
def step_impl(context):
    idManager = NumberUnicityManager()
    context.parsed_feature = get_feature_from_content(context.feature_content, idManager, 0)


@When('invoking Gherkin2Cpp with option "{options}"')
def step_impl(context, options):
    if context.from_content == False:
        try:
            if hasattr(context,'output'):
                print(invoke(['--features-dir='+context.temporary_folder] + shlex.split(options)), file=options[options.index('-o')+3:])
            else:
                context.result_text = invoke(['--features-dir='+context.temporary_folder] + shlex.split(options))
        except Exception as e:
            context.result_exception = e.args[0]
    else:
        idManager = NumberUnicityManager()
        try:
            context.feature = get_feature_from_content(context.feature_content, idManager, 0)
            apply_missing_ids_to_features(idManager, context.feature)

            context.function_files = []
            context.function_files.extend(iglob(os.path.join(context.temporary_folder, '**', '*.h*'),
                                        recursive=True))
            context.functions = get_functions_from_content(context.header_content)
            context.result_text = generate_tests([context.feature], context.functions,
                                                              headers=[realpath(path) for path in context.function_files])
        except Exception as e:
            context.result_exception = e.args[0]


@When("a step")
def step_impl(context):
    pass
