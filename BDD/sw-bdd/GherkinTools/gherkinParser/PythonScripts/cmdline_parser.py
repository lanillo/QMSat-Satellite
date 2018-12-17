import argparse
import os
from glob import iglob

from CommunPackage.module_description import get_description_from_file
from .feature_parser import get_feature_from_file


def parsing(argv: [str], idManager):

    parser = argparse.ArgumentParser(description='Parse the Gherkin feature files and header files.')
    parser.add_argument('--features-dir', type=str, dest='features_root_directory', default='.', metavar='DIR',
                        help='Root folder of feature files.')
    parser.add_argument('--check-traceability', action='store_true',
                        help='Parse feature files and make sure DO178 elements are present')

    args = parser.parse_args(argv)

    # Detect and activate strict mode
    check_traceability = args.check_traceability

    #Collect and parse all the feature in the feature root directory
    feature_files = []
    description_files = []
    features = []
    module_descriptions = []


    feature_files.extend(iglob(os.path.join(args.features_root_directory, '**', '*.feature'),
                                       recursive=True))
    features.extend(get_feature_from_file(feature_file, idManager, check_traceability)
                    for feature_file in feature_files)

    description_files.extend(iglob(os.path.join(args.features_root_directory, '**', '*.txt'),
                               recursive=True))
    module_descriptions.extend(get_description_from_file(description_file) for description_file in description_files)

    return features, idManager, module_descriptions