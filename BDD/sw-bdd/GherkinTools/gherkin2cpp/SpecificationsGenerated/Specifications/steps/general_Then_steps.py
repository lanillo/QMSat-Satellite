import os
from glob import iglob

from behave import Then

from CommunPackage.feature_unicity_manager import NumberUnicityManager
from gherkinParser.PythonScripts.feature_parser import get_feature_from_file


@Then("result is")
def step_impl(context):
    if hasattr(context, 'result_text'):
        print(str(context.result_text))
        context.result_text = str(context.result_text).replace(context.temporary_folder, '')
        assert context.result_text.replace('\r', '') == str(context.text).replace('\r', '')
    else:
        context.result_exception = 'context has no attribute result_text'


@Then('a "{error_name}" error is raised')
@Then('an "{error_name}" error is raised')
def step_impl(context, error_name):
    assert error_name == context.result_exception


@Then("expect")
def step_impl(context):
    try:
        context.feature_content == context.text or context.header_content == context.text
    except Exception as e:
        context.result_exception = e.args[0]


@Then("expect the feature to contain")
def step_impl(context):
    fileWriter = open(context.features_root_directory, 'r')
    context.file_content = fileWriter.read()
    fileWriter.close()
    a = context.file_content
    b = str(context.text.replace('\r',''))
    assert(context.file_content == context.text.replace('\r',''))


@Then('execution ends without exception')
def step_impl(context):
    if not (hasattr(context, 'result_exception')):
        assert(True)
    else:
        assert(False)


@Then('the robustness scenario is detected')
def step_impl(context):
    assert(context.parsed_feature.scenarios[0].robustness == True)

@Then('no robutness information')
def step_impl(context):
    assert(context.parsed_feature.scenarios[0].robustness == False)


@Then("there is {count} function")
@Then("there are {count} functions")
def step_impl(context, count):
    assert len(context.parsed_functions) == int(count)


@Then("there is {count} step")
@Then("there are {count} steps")
def step_impl(context, count):
    assert len([step for scenario in context.parsed_feature.scenarios for step in scenario.steps]) == int(count)


@Then("there is {count} scenario")
@Then("there are {count} scenarios")
def step_impl(context, count):
    assert len([scenario for scenario in context.parsed_feature.scenarios]) == int(count)


@Then("there is a function with a parameter of type {type_name} named {name}")
def step_impl(context, type_name, name):
    parameterFound = False
    for functions in context.parsed_functions:
        for parameter in functions.parameters:
            parameter.type = str(parameter.type).replace('unsigned ','u')
            if parameter.name == name and parameter.type == type_name:
                parameterFound = True
    assert (parameterFound)


@Then("file {file_name} is in {folder_name} folder instead")
def step_impl(context, file_name, folder_name):
    files = []
    files.extend(iglob(os.path.join(folder_name, '**', '*.*'),
                               recursive=True))
    file_found = False
    for file in files:
        name = os.path.basename(file)
        if name == file_name:
            file_found = True
    assert(file_found)


@Then("file is named {file_name}")
def step_impl(context, file_name):
    assert context.feature_files == file_name


@Then("feature file name contain MLR")
def step_impl(context):
    feature_files = []
    feature_files.extend(iglob(os.path.join(context.temporary_folder, '**', '*.feature'),
                                       recursive=True))
    for feature_file in feature_files:
        assert('MLR' in feature_file)

@Then("feature file name do not contain MLR")
def step_impl(context):
    feature_files = []
    feature_files.extend(iglob(os.path.join(context.temporary_folder, '**', '*.feature'),
                                       recursive=True))
    for feature_file in feature_files:
        assert('MLR' not in os.path.basename(feature_file))


@Then("no feature have the same MLR")
def step_impl(context):
    feature_files = []
    MLR_list = []
    feature_files.extend(iglob(os.path.join(context.temporary_folder, '**', '*.feature'),
                                       recursive=True))
    for feature_file in feature_files:
        feature_file = (feature_file.replace('\\','\\ ')).split()
        indices = 0
        for index, elem in enumerate(feature_file):
            if 'MLR' in elem:
                indices = index
        MLR_list.append(feature_file[indices].replace('MLR',''))
    for MLR in MLR_list:
        assert(MLR_list.count(MLR) <= 1)

@Then("all scenarios have mvcp number")
def step_impl(context):
    for scenario in context.feature.scenarios:
        assert(scenario.mvcp != 0)

@Then ('trace to code is "{code}"')
def step_impl(context,code):
    feature_files = []
    feature_files.extend(iglob(os.path.join(context.temporary_folder, '**', '*.feature'),
                               recursive=True))
    idManager = NumberUnicityManager()
    context.feature = get_feature_from_file(feature_files[0], idManager, True)
    assert (code == context.feature.ttc.replace('\n',''))

@Then("Scenario name contain MVCP")
def step_impl(context):
    feature_files = []
    feature_files.extend(iglob(os.path.join(context.temporary_folder, '**', '*.feature'),
                               recursive=True))
    idManager = NumberUnicityManager()
    context.feature = get_feature_from_file(feature_files[0], idManager, False)
    for scenario in context.feature.scenarios:
        assert (scenario.mvcp != 0)


@Then("feature name contain HLR")
def step_impl(context):
    feature_files = []
    feature_files.extend(iglob(os.path.join(context.temporary_folder, '**', '*.feature'),
                               recursive=True))
    idManager = NumberUnicityManager()
    context.feature = get_feature_from_file(feature_files[0], idManager, False)
    assert (context.feature.hlr != 0)


@Then("no id number are left in feature file")
def step_impl(context):
    feature_files = []
    feature_files.extend(iglob(os.path.join(context.temporary_folder, '**', '*.feature'),
                               recursive=True))
    idManager = NumberUnicityManager()
    context.feature = get_feature_from_file(feature_files[0], idManager, False)
    assert (context.feature.hlr == 0)
    assert (context.feature.mlr == 0)
    for scenario in context.feature.scenarios:
        assert (scenario.mvcp == 0)


@Then("feature title and feature file name matches")
def step_impl(context):
    feature_files = []
    feature_files.extend(iglob(os.path.join(context.temporary_folder, '**', '*.feature'),
                               recursive=True))
    idManager = NumberUnicityManager()
    context.feature = get_feature_from_file(feature_files[0], idManager, False)
    file_name = os.path.basename(feature_files[0]).replace('.feature','')
    feature_title = context.feature.name
    assert (feature_title == file_name)


@Then("a step")
def step_impl(context):
    pass

