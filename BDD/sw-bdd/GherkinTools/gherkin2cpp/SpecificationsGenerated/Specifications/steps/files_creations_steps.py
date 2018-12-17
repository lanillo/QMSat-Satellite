import os
import shutil
from behave import Given


@Given('a Scenario with an outline')
@Given('a scenario with an robustness tag')
@Given('a scenario with an MVCP number')
@Given('a Scenario with an outline')
@Given('a feature file')
def step_impl(context):
    context.from_content = True
    try:
        context.feature_content = context.text
    except Exception as e:
        context.result_exception = e.args[0]


@Given('a header file')
def step_impl(context):
    context.from_content = True
    try:
        context.header_content = context.text
    except Exception as e:
        context.result_exception = e.args[0]


@Given('an empty folder')
def step_impl(context):
    context.temporary_folder = os.path.dirname(os.path.dirname(os.path.dirname(__file__))) + '\\Python Test\\'
    if (os.path.exists(context.temporary_folder)):
        shutil.rmtree(context.temporary_folder)
    os.makedirs(context.temporary_folder)


@Given('the folder named "{file_name}"')
def step_impl(context,file_name):
    context.from_content = False
    context.temporary_folder = os.path.dirname(os.path.dirname(os.path.dirname(__file__))) + '\\Python Test\\' + file_name
    if not os.path.exists(context.temporary_folder):
        os.makedirs(context.temporary_folder)


@Given('a file named "{file_name}" with content')
def step_impl(context, file_name):
    context.from_content = False
    directory, file_name = os.path.split(file_name)
    os.makedirs(os.path.join(context.temporary_folder, directory), exist_ok=True)
    open(os.path.join(context.temporary_folder, directory, file_name), 'w').write(context.text)
    context.features_root_directory = os.path.join(context.temporary_folder, directory, file_name)


@Given('a feature file named "{file_name}" with content')
def step_impl(context, file_name):
    context.from_content = False
    directory, file_name = os.path.split(file_name)
    os.makedirs(os.path.join(context.temporary_folder, directory), exist_ok=True)
    open(os.path.join(context.temporary_folder, directory, file_name), 'w').write(context.text)
    context.features_root_directory = os.path.join(context.temporary_folder, directory, file_name)


@Given('a header file named "{file_name}" with content')
def step_impl(context, file_name):
    context.from_content = False
    directory, file_name = os.path.split(file_name)
    os.makedirs(os.path.join(context.temporary_folder, directory), exist_ok=True)
    open(os.path.join(context.temporary_folder, directory, file_name), 'w').write(context.text)
    context.functions_root_directory = os.path.join(context.temporary_folder, directory, file_name)


@Given('a step')
def step_impl(context):
    pass