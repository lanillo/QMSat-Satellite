<%!
    from gherkin2cpp.PythonScripts.cpp_header_parser import Method
%>\

<%def name="value(value, type)">\
    %if type in ['int', 'long', 'u8', 's8', 'u16', 's16', 'u32', 's32', 'u64', 's64']:
${int(value, 0)}\
    %elif type in ['float', 'f32', 'f64']:
${float(value)}\
    %elif type in ['char *', 'const char *', 'char const *']:
"${value.replace('"', '\\"')}"\
    %endif
</%def>\
<%def name="arguments(function, step)">\
    %if function.parameters and function.parameters[0].type != 'void':

        %for i, parameter in enumerate(function.parameters):
        ${value(function.regex.match(step.text).group(parameter.name), parameter.type)}\
${',' if i < len(function.parameters)-1 else ''}\
  /* ${parameter.type} ${parameter.name} */\
        %endfor
    %endif
</%def>\
<%def name="c_identifier(text)">\
${text.replace(' ', '_').replace('.', '_').replace(':', '_').replace(',', '_').replace('\'', '_').replace('(', '').replace(')', '').replace('+/-', 'more_or_less').replace('-', 'negative_').replace('/', '_per_')}\
</%def>\
<%def name="call(function)">\
%if isinstance(function, Method):
${function.class_name}_.\
%endif
${function.name}\
</%def>\
#include <cxxtest/TestSuite.h>
%for header in headers:
#include "${header}"
%endfor

%for feature in features:

class Feature_${c_identifier(feature.name_with_mlr)} : public CxxTest::TestSuite {
public:
<% feature_implemented = 0 %>\
%for scenario in feature.scenarios:
<% feature_implemented = 1 %>\
    void test_${c_identifier(scenario.name_with_mvcp)}_${scenario.outline_count}() {
<% instanciated_objects = set() %>\
<% scenario_implemented = 0 %>\
    %for step in scenario.steps:
<% scenario_implemented = 1 %>\
<% function = step_functions[step] %>\
        %if isinstance(function, Method) and function.class_name not in instanciated_objects:
<% instanciated_objects.add(function.class_name) %>
        ${function.class_name} ${function.class_name}_;
        %endif

        /* ${step.text} */
        %if function is None:
        TS_FAIL("no function");
        %else:
            %if function.return_type == 'void':
        ${call(function)}(${arguments(function, step)});
            %elif function.return_type == 'bool':
        TS_ASSERT(${call(function)}(${arguments(function, step)}));
            %else:
        TS_FAIL("${step.text}");
            %endif
        %endif
    %endfor
    %if scenario_implemented == 0:
        TS_WARN("scenario _${scenario.rawName}_ not implemented");
%endif
    }
%endfor
%if feature_implemented == 0:
    void test_${feature.name_mako}_not_implemented() {
        TS_WARN("feature _${feature.name_with_mlr}_ not implemented");
    }
%endif
};
%endfor
