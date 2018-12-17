import argparse
import os
import sys
from glob import iglob
from os.path import realpath

from gherkinParser.PythonScripts.cmdline_parser import parsing
from CommunPackage.feature_unicity_manager import NumberUnicityManager
from CommunPackage.context import Context
from gherkinParser.PythonScripts.feature_parser import apply_missing_ids_to_features

from .cpp_header_parser import get_functions_from_file
from .feature_writer import writeFeature
from .generator import generate_tests

out_file = sys.stdout


def print_cpp(context):
    context.current_evaluator = ''
    return generate_tests(context, context.features_for_cpp,
                          context.functions_for_cpp,
                          headers=[realpath(path) for path in context.function_files])


def print_features(context):
    return '\n'.join(sorted(feature.name for feature in context.features))


def print_scenarios(context):
    return '\n'.join(sorted("%s: %s" %(feature.name, scenario.name, scenario.outline_count) for feature in context.features for scenario in feature.scenarios))


def invoke(argv: [str]):
    global out_file

    parser = argparse.ArgumentParser(description='Converts Gherkin feature files to executable CPP unit tests.')
    parser.add_argument('--features-dir', type=str, dest='features_root_directory', default='.', metavar='DIR',
                        help='Root folder of feature files.')
    parser.add_argument('--steps-dir', type=str, dest='steps_root_directory', metavar='DIR',
                        help='Root folder of steps header files to use to generate steps.'
                        'Defaults to the feature directory.')
    parser.add_argument('-o', '--output', dest='output_file', metavar='FILE',
                        help='Outputs to FILE.')
    parser.add_argument('--cpp', dest='outputs', action='append_const', const=print_cpp,
                        help='Outputs c++ test content file.')
    parser.add_argument('--list-features', dest='outputs', action='append_const', const=print_features,
                        help='Output list of feature names, ordered alphabetically.')
    parser.add_argument('--list-scenarios', dest='outputs', action='append_const', const=print_scenarios,
                        help='Output list of scenario names, ordered alphabetically.')
    parser.add_argument('--check-traceability', action='store_true',
                        help='Parse feature files and make sure DO178 elements are present')
    parser.add_argument('--output-feature-dir', type=str, dest='output_feature_dir', metavar='DIR',
                        help='Optional Dir to which output formatted features. If empty, features are written over existing ones')
    parser.add_argument('--add-id-numbers', dest='add_id_numbers', action='store_true',
                        help='Adds the identification numbers in feature files and feature files names')
    parser.add_argument('--remove-id-numbers', dest='remove_id_numbers', action='store_true',
                        help='Removes the identification numbers in feature files and feature files names')
    parser.add_argument('--add-traceability-tag', dest='add_traceability_tag', action='store_true',
                        help='Adds the traceability attributes in feature files')
    parser.add_argument('--remove-traceability-tag', dest='remove_traceability_tag', action='store_true',
                        help='Removes the traceability attributes in feature files')

    args = parser.parse_args(argv)

    context = Context()

    get_feature_dir = False
    get_step_dir = False
    for arg in argv:
        if get_feature_dir == True:
            context.features_root_directories.append(arg)
            get_feature_dir = False
        if get_step_dir == True:
            context.function_root_directories.append(arg)
            get_step_dir = False
        if arg == '--features-dir':
            get_feature_dir = True
        elif arg == '--steps-dir':
            get_step_dir = True
        elif '--features-dir=' in arg:
            context.features_root_directories.append(arg.replace('--features-dir=',''))
        elif '--steps-dir=' in arg:
            context.function_root_directories.append(arg.replace('--steps-dir=',''))

    if(args.add_id_numbers and args.remove_id_numbers):
        raise Exception("Cant call Gherkin2Cpp with argument --add-id-numbers and --remove-id-numbers")
    if (args.add_traceability_tag and args.remove_traceability_tag):
        raise Exception("Cant call Gherkin2Cpp with argument --add-traceability-tag and --remove-traceability-tag")

    if args.output_file is not None:
        if not os.path.exists(os.path.dirname(args.output_file)):
            os.makedirs(os.path.dirname(args.output_file))
        out_file = open(args.output_file, 'w', newline='\n')

    # Detect if we want ID numbers in feature file name and/or traceability
    if args.add_id_numbers:
        context.add_id_numbers = args.add_id_numbers

    if args.remove_id_numbers:
        context.remove_id_numbers = args.remove_id_numbers

    if args.add_traceability_tag:
        context.add_traceability_tag = args.add_traceability_tag

    if args.remove_traceability_tag:
        context.remove_traceability_tag = args.remove_traceability_tag

    #Creat Unique number manager, which will manage number unicity throughout feature files
    idManager = NumberUnicityManager()

    # Collect and parse all the step in the steps root directory (header files)
    if context.function_root_directories == []:
        context.function_root_directories = context.features_root_directories

    for function_root_directory in context.function_root_directories:
        context.function_root_directory = function_root_directory
        function_files = []
        context.functions = []
        function_files.extend(
            iglob(os.path.join(context.function_root_directory, '**', '*.h*'), recursive=True))
        for function_file in function_files:
            context.function_files.append(function_file)
        context.functions.extend(function for function_file in function_files
                                 for function in get_functions_from_file(function_file))

        for function in context.functions:
            context.functions_for_cpp.append(function)


    #Collect and parse all Features in the features root directory (feature files)
    for features_root_directory in context.features_root_directories:
        context.features_root_directory = features_root_directory

        #Detect and activate strict mode and call the Parser
        if args.check_traceability:
            context.traceability = args.check_traceability
            context.features, idManager, context.module_descriptions  = parsing(['--features-dir=' + context.features_root_directory, '--check-traceability'], idManager)
        else:
            context.features, idManager, context.module_descriptions = parsing(['--features-dir=' + context.features_root_directory], idManager)
        for feature in context.features:
            context.features_for_cpp.append(feature)
        if len(context.features) == 0:
            raise Exception("The specified feature folder: " + context.features_root_directory + " doesn't contain any feature")

        # Apply IDs to features and scenarios who don't have any. Do this after parsing features so all existing IDs are known
        if context.add_id_numbers == True:
            apply_missing_ids_to_features(idManager, context.features)

        #If there is a specified output dir, dump parsed files there instead of overwriting them
        if args.output_feature_dir is not None:
            for feature in context.features:
                writeFeature(feature, args.output_feature_dir, context.add_id_numbers, context.remove_id_numbers, context.features_root_directory, context.add_traceability_tag, context.remove_traceability_tag)

        #If there is no output feature dir, overwrite original files
        else:
            for feature in context.features:
                os.remove(feature.file_name)
                writeFeature(feature, '',context.add_id_numbers, context.remove_id_numbers, '', context.add_traceability_tag, context.remove_traceability_tag)


    final_output = ''
    if args.outputs != None:
        final_output = '\n'.join(output(context) for output in args.outputs)

    if args.output_file is not None:
        return out_file.write(final_output)

    return final_output
