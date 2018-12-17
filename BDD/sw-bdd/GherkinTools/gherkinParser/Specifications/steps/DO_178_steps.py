from behave import Then


@Then("the MLR code is {code}")
def step_impl(context, code):
    assert context.parsed_feature.mlr == code


@Then("the Attributes are {attr1} {attr2}")
def step_impl(context, attr1, attr2):
    if not (attr1 or attr2 in context.parsed_feature.attributes):
        assert(False)
    else:
        assert(True)


@Then("TraceToCode is {ttc}")
def step_impl(context, ttc):
    if not ttc in context.parsed_feature.ttc:
        assert(False)
    else:
        assert(True)


@Then("TraceToCode are {ttc1} {ttc2}")
def step_impl(context, ttc1, ttc2):
    if not (ttc1 or ttc2 in context.parsed_feature.ttc):
        assert(False)
    else:
        assert(True)


@Then("HLR are {hlr1} {hlr2}")
def step_impl(context, hlr1, hlr2):
    if not (hlr1 or hlr2 in context.parsed_feature.parentHLR):
        assert(False)
    else:
        assert(True)


@Then("feature file has a MLR")
def step_impl(context):
    assert('MLR' in context.result_text)


@Then('the scenario MVCP number is {number}')
def step_impl(context, number):
    assert(context.parsed_feature.scenarios[0].mvcp == number)