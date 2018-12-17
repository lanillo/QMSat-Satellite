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


@Then("a step")
def step_impl(context):
    pass

