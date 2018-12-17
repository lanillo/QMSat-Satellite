import os

from CommunPackage.feature import Feature
from CommunPackage.feature_unicity_manager import NumberUnicityManager

from gherkinParser.gherkin.parser import Parser
from gherkinParser.gherkin.pickles.compiler import compile
from CommunPackage.scenario import Step, Scenario

_parser = Parser()

def _get_feature(feature_file_content: str, feature_file_name: str, idManager: NumberUnicityManager, traceabilityEnabled):
    def make_steps(steps):
        return [Step(step['keyword'], step['text'], step['originalText']) for step in steps]

    def make_scenarios(pickles, feature_file_name):
        scenarios = []
        for pickle in pickles:
            outline_count = 0;
            for scenario in scenarios:
                if scenario.rawName == pickle['name']:
                    outline_count += 1
            scenarios.append(Scenario(pickle['name'], make_steps(pickle['steps']), outline_count, feature_file_name, pickle['examples'], idManager))

        #Verifications of minimal Then and When
        for scenario in scenarios:
            required_then_step = 0
            required_given_step = 0
            for step in scenario.steps:
                if 'Given ' == step.keyWord:
                    required_given_step += 1
                if 'Then ' == step.keyWord:
                    required_then_step += 1
            if (required_then_step != 0 and required_given_step == 0):
                raise Exception('Missing minimal Given step in FEATURE: ' + os.path.basename(feature_file_name))
            if (required_then_step == 0 and required_given_step != 0):
                raise Exception('Missing minimal Then step in FEATURE: ' + os.path.basename(feature_file_name))
        return scenarios


    feature = _parser.parse(feature_file_content)
    pickles = compile(feature, '')
    scenarios = make_scenarios(pickles, feature_file_name)
    """if feature.get('description') != None:
        return Feature(feature['name'], feature['description'], scenarios, strictModeEnabled, feature_file_name, idManager)
    else:
        return Feature(feature['name'], None, scenarios, strictModeEnabled, feature_file_name, idManager)"""
    return Feature(feature['name'], feature.get('description'), scenarios, traceabilityEnabled, feature_file_name, idManager)

def get_feature_from_file(file_name, idManager: NumberUnicityManager, traceabilityEnabled):
    return _get_feature(open(file_name).read(), file_name, idManager, traceabilityEnabled)


def get_feature_from_content(content, idManager: NumberUnicityManager, traceabilityEnabled):
    return _get_feature(content, '', idManager, traceabilityEnabled)

def apply_missing_ids_to_features(idManager: NumberUnicityManager, features):
    if type(features) is not list:
        features = [features]

    for aFeature in features:
        if aFeature.mlr == 0 and aFeature.hlr == 0:
            aFeature.mlr = str(idManager.generateNewUniqueNumber())
            if len(aFeature.mlr) < 4:
                zero_to_add = 4 - len(aFeature.mlr)
                for index in range(0,zero_to_add):
                    aFeature.mlr = '0' + aFeature.mlr
            aFeature.name_with_mlr = 'MLR{} {}'.format(aFeature.mlr, aFeature.name)
        for aScenario in aFeature.scenarios:
            if aScenario.mvcp == 0 and aScenario.outline_count == 0:
                aScenario.mvcp = str(idManager.generateNewUniqueNumber())
                if len(aScenario.mvcp) < 4:
                    zero_to_add = 4 - len(aScenario.mvcp)
                    for index in range(0, zero_to_add):
                        aScenario.mvcp = '0' + aScenario.mvcp

