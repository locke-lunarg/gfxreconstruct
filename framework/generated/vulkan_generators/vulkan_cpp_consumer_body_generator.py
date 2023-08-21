#!/usr/bin/python3 -i
#
# Copyright (c) 2020 Samsung
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from base_generator import *
from collections import Counter
from reverse_alias_mapping import getReverseAliasMap


# TODO: Copied from base_generator.py.
def makeREstring(argList, defaultValue = None):
    if (len(argList) > 0) or (defaultValue is None):
        return '^(' + '|'.join(argList) + ')$'
    else:
        return defaultValue


def getExtApiStructs(featureDictionary):
    extApiStructs = []
    for extension in CPP_REQUIRED_EXTENSIONS:
        extDict = featureDictionary[extension]
        extStructs = list(extDict['struct'].values())
        extApiStructs.extend([item for subList in extStructs for item in subList if item is not None])
    extApiStructs = [item.split(',') for item in extApiStructs]
    return [item for subList in extApiStructs for item in subList]


def getExtApiFuncs(featureDictionary):
    extApiFuncs = []
    for extension in CPP_REQUIRED_EXTENSIONS:
        extDict = featureDictionary[extension]
        extCmds = list(extDict['command'].values())
        extApiFuncs.extend([item for sublist in extCmds for item in sublist])
    return extApiFuncs


CPP_REQUIRED_EXTENSIONS = [
    'VK_EXT_inline_uniform_block',
    'VK_EXT_memory_budget',
    'VK_EXT_separate_stencil_usage',
    'VK_KHR_android_surface',
    'VK_KHR_create_renderpass2',
    'VK_KHR_descriptor_update_template',
    'VK_KHR_draw_indirect_count',
    'VK_KHR_get_memory_requirements2',
    'VK_KHR_get_physical_device_properties2',
    'VK_KHR_image_format_list',
    'VK_KHR_maintenance1',
    'VK_KHR_maintenance2',
    'VK_KHR_multiview',
    'VK_KHR_surface',
    'VK_KHR_swapchain',
    'VK_KHR_swapchain_mutable_format',
    'VK_KHR_wayland_surface',
    'VK_KHR_xcb_surface',
]

# Extensions can be enabled by specifying them in this list
CPP_OPTIONAL_EXTENSIONS = []

CPP_CONSUMER_ADD_EXTENSION_PAT = makeREstring(CPP_REQUIRED_EXTENSIONS + CPP_OPTIONAL_EXTENSIONS)
CPP_CONSUMER_ADD_OPTIONAL_EXTENSION_PAT = makeREstring(CPP_OPTIONAL_EXTENSIONS)

CPP_CONSUMER_REMOVE_EXTENSION_PAT = None  # makeREstring(['.*'])
CPP_CONSUMER_VULKAN_VERSION = ['VK_VERSION_1_0']

CPP_CONSUMER_VULKAN_VERSION_PAT = makeREstring(CPP_CONSUMER_VULKAN_VERSION)

CPP_APICALL_BLACKLIST = [
    'vkCreateDescriptorUpdateTemplate',
    'vkCreateDescriptorUpdateTemplateKHR',
]

# These functions are manually generated.
CPP_APICALL_GENERATE = [
    'vkAcquireNextImageKHR',
    'vkAllocateMemory',
    'vkCreateAndroidSurfaceKHR',
    'vkCreateInstance',
    'vkCreatePipelineCache',
    'vkCreateShaderModule',
    'vkCreateWaylandSurfaceKHR',
    'vkCreateXcbSurfaceKHR',
    'vkEnumeratePhysicalDevices',
    'vkGetFenceStatus',
    'vkGetPhysicalDeviceQueueFamilyProperties',
    'vkGetPhysicalDeviceSurfaceFormatsKHR',
    'vkGetPhysicalDeviceSurfacePresentModesKHR',
    'vkGetSwapchainImagesKHR',
    'vkMapMemory',
    'vkUnmapMemory',
]

CPP_APICALL_INTERCEPT_LIST = [
    'vkCmdBeginRenderPass',
    'vkCreateDevice',
    'vkCreateFramebuffer',
    'vkCreateSwapchainKHR',
]

CPP_CONSUMER_API_POST_CALL = [
    'vkGetBufferMemoryRequirements',
    'vkGetBufferMemoryRequirements2KHR',
    'vkGetImageMemoryRequirements',
    'vkGetImageMemoryRequirements2KHR',
]

# Disabled wrapping function call into the 'VK_CALL_CHECK' macro call
CPP_APICALL_DO_NOT_CHECK = ['vkGetPhysicalDeviceImageFormatProperties']


def makeGenCall(method, args, arguments=None, indent=4, **kwargs):
    """
    Output a method call into the CPP generator.

    :param method: the name of the method to invoke in the CPP generator.
    :param args: list of arguments used for the method call.
    :param arguments: dictionary containing the key-values used for the string formatting.
    :param indent: indentation size.

    :returns: string representation of the method call which can be inserted into the CPP generator.
    """
    return makeGenVarCall(None, None, method, args, arguments=arguments, indent=indent, **kwargs)


def makeGenVarCall(typeToUse, genName, method, methodArgs, arguments=None, indent=4, **kwargs):
    """
    Output a variable initialization with a method call into the CPP generator.

    :param typeToUse type  (same type as the return value of the given method). Can be None so no type name is added.
    :param genName: the name of the std::string variable used in the CPP generator. Can be None so no assignment is generated.
    :param method: a non void method name.
    :param methodArgs: list of target method arguments.
    :param arguments: dictionary containing the key-values used for the string formatting.
    :param indent: indentation size.

    :returns: method call assigning the value to the 'genName'
    """
    if not arguments:
        arguments = {}

    assignment = ''
    if genName:
        if typeToUse:
            assignment = '{} {} = '.format(typeToUse, genName).format(**arguments, **kwargs)
        else:
            assignment = '{} = '.format(genName).format(**arguments, **kwargs)

    arg_indent = ',\n' + ' ' * (indent + len(method) + 1 + len(assignment))
    padded_args = arg_indent.join(methodArgs)

    return (' ' * indent) + ('%s%s(%s);\n' % (assignment, method, padded_args)).format(**arguments, **kwargs)


def makeGenVar(genName, cppName, arguments=None, indent=4, addType=True, useThis=True):
    """
    Output a usable variable name into the CPP generator.

    :param genName: the name of the std::string variable used in the CPP generator.
    :param cppName: the name of the variable which will be used in the resulting CPP file. If None is passed a "NULL" value will be inserted.
    :param arguments: dictionary containing the key-values used for the string formatting.
    :param indent: indentation size.
    :param addType: if True the 'std::string' type will be added into the output string, otherwise it is a simple assignment.
    :param useThis: use 'this' pointer if True, otherwise access attributes with the object of class.

    :returns: string representation of the std::string variable which can be inserted into the CPP generator.
    """
    typeToUse = ''
    object = 'consumer.'

    if not arguments:
        arguments = {}
    if addType:
        typeToUse = 'std::string ' # note the space!
    if cppName is None:
        return '{}{}{} = "NULL";\n'.format(' ' * indent, typeToUse, genName, cppName).format(**arguments)
    if useThis:
        object = 'this->'

    return '{}{}{} = "{}_" + std::to_string({}getNextId());\n'.format(' ' * indent, typeToUse, genName, cppName, object).format(**arguments)


def makeGenCastVar(cast_type, type_name, target_var_name, source_var_name, use_auto=False, indent=4):
    """
    Create a variable cast in the CPP generator.

    :param cast_type: type of the cast to perform
    :param type_name: name of the type to cast to
    :param target_var_name: name of the variable to cast to
    :param source_var_name: name of the variable to cast from
    :param use_auto: bool whether to use the auto keyword instead
    :param indent: indentation size
    :return:
    """
    if use_auto:
        return ' ' * indent + 'auto %s = %s<%s>(%s);\n' % (target_var_name, cast_type, type_name, source_var_name)
    return ' ' * indent + '%s %s = %s<%s>(%s);\n' % (
        type_name, target_var_name, cast_type, type_name, source_var_name)


def makeGen(statement, arguments=None, indent=4, **kwargs):
    """
    Output a single line into the CPP generator.

    :param genName: statement to format and write out.
    :param arguments: dictionary containing the key-values used for the string formatting.
    :param indent: indentation size.

    :returns: string representation of the statment which can be inserted into the CPP generator.
    """
    if not arguments:
        arguments = {}
    return (' ' * indent) + statement.format(**arguments, **kwargs) + '\n'


def makeCppOutputStream(streamName, indent=4):
    """
    Create a function call to write out contents of a stream into the resulting CPP file.

    :param streamName: the name of the std::stringstream to write its contents into the final CPP.
    :param indent: indentation size.

    :returns:
    """
    return (' ' * indent) + 'fprintf(file, "\\n%s", {streamName}.str().c_str());\n'.format(streamName=streamName)


def makeCppArray(type, name, values, arguments=None, indent=4):
    """
    Create an Array definition in the resulting CPP file.

    :param type: type of the array.
    :param name: name of the array.
    :param values: the array contents for the initializer.
    :param arguments: dictionary containing the key-values used for the string formatting.
    :param indent: indentation size.

    :returns:
    """
    if not arguments:
        arguments = {}
    return (' ' * indent) + (
        'fprintf(file, "{} %s[] = {{{{ %s }}}};\\n", {}.c_str(), {}.c_str());\n'.format(type, name, values).format(**arguments))


def makeGenLoop(loopIdx, condition, contents, arguments=None, indent=4):
    """
    Create a loop statement in the CPP generator.

    :param loopIdx: loop control variable.
    :param condition: condition of loop statement.
    :param contents: list of code lines inside loop body.
    :param arguments: dictionary containing the key-values used for the string formatting.
    :param indent: indentation size.

    :return:
    """
    if not arguments:
        arguments = {}

    lines = [(' ' * indent) + ('for (uint32_t %s = 0; %s; %s++) {{\n' % (loopIdx, condition, loopIdx)).format(**arguments)] \
            + contents + [(' ' * indent) + '}\n']

    return ''.join(lines)


# TODO: replace this with makeGenConditions?
def makeGenCond(condition, contents_if, contents_else=None, arguments=None, indent=4):
    """
    Create an if/else  statement in the CPP generator.


    :param condition: condition of if/else statement.
    :param contents_if: list of code lines inside if body.
    :param contents_else: list of code lines inside else body.
    :param arguments: dictionary containing the key-values used for the string formatting.
    :param indent: indentation size.

    :return:
    """
    else_cont = [(' ' * indent) + '} else {\n'] + contents_else + [(' ' * indent) + '}\n'] if contents_else else [(' ' * indent) + '}\n']
    lines = [(' ' * indent) + ('if (%s) {\n' % (condition).format(**arguments))] + contents_if + else_cont

    return ''.join(lines)


def makeGenConditions(cases, arguments=None, indent=4):
    """

    :param cases: list of tuples. Each tuple has the (condition, body) format.

    :param arguments: dictionary containing the key-values used for the string formatting.
    :param indent: indentation size.
    :return: formatted cpp code
    """

    indent_str = ' ' * indent

    lines = []
    for idx, case in enumerate(cases):
        # case[0] -> condition
        # case[1] -> body (list)
        if case[0]:
            if idx == 0:
                start = indent_str + 'if'
            else:
                start = ' else if'

            condition = '%s (%s)' % (start, case[0].format(**arguments))
        else:
            condition = ' else'

        lines.append(condition)
        lines.append(' {\n')
        lines.extend(case[1])
        lines.append(indent_str + '}')

    assert len(lines) >= 4, "a single entry should be in the condition"
    lines[-1] += '\n'

    return ''.join(lines)


def makeGenSwitch(condition, cases, case_contents, default_content, indent=4):
    """
    Create a switch statement in the CPP generator.

    :param condition: condition of the switch statement
    :param cases: list of the enum labels
    :param case_contents:  list of list of strings containing the body of each case by line
    :param default_content: list of list of strings containing the body of the default case
    :param indent: indentation size
    :return:
    """
    switch = []
    indentation = ' ' * indent
    switch.append(2 * indentation + 'switch (%s) {\n' % condition)

    for case, case_content in zip(cases, case_contents):
        switch.append(3 * indentation + 'case %s: {\n' % case)
        for line in case_content:
            switch.append(4 * indentation + line)
        switch.append(3 * indentation + '}\n')

    switch.append(3 * indentation + 'default: {\n')
    for line in default_content:
        switch.append(4 * indentation + line)
    switch.append(3 * indentation + '}\n')
    switch.append(2 * indentation + '}\n')

    return ''.join(switch)


def makeOutStructSet(value, arguments=None, isLastArg=False, indent=4):
    """
    Create a structure element setting for the vulkan application.

    :param value: contents of the structure member for the initializer.
    :param arguments: dictionary containing the key-values used for the string formatting.
    :param isLastArg: boolean value if the line should be ended
    :param indent: indentation size.

    :return:
    """
    if not arguments:
        arguments = {}
    lineEnding = '' if isLastArg else '<< std::endl'
    return ((' ' * indent) + 'structBody << "\\t" << %s << "," %s;\n'.format(**arguments) % (value, lineEnding)).format(**arguments)


def printOutStream(values, arguments=None, indent=4):
    """
    Output a single line into the CPP consumer.


    :param values: list of contents to print the out stream.
    :param arguments: dictionary containing the key-values used for the string formatting.
    :param indent: indentation size.

    :return:
    """
    if not arguments:
        arguments = {}
    return (' ' * indent) + 'out << %s << std::endl;\n' % ' << '.join(values).format(**arguments)


def buildInputArray(arg, valueSuffix='', indent=0):
    """
    Build an array of values collection in the CPP consumer for a given argument.

    :param arg: argumentum to read/process.
    :param valueSuffix: suffix characters to use when building the value list (eg.: "UL")
    :param indent: indentation.

    :return: a tuple of (code to insert into CPP consumer, argument for the vk* method invocation, placeholder for fprintf).
    """
    arrayElementType = 'uint8_t' if arg.base_type == 'void' else arg.base_type

    output = [
        makeGenVar('{arg.name}Array', arg.name, locals(), indent=indent),
        makeGenCond('{arg.array_length} > 0', [
                makeGenVarCall('std::string', '{arg.name}Values', 'toStringJoin',
                               ['{arg.name}->GetPointer()', '{arg.name}->GetPointer() + {arg.array_length}',
                                '[&](const auto current) {{ return std::to_string(current) + "{valueSuffix}"; }}',
                                '", "'], locals(), indent=indent+4),
                makeCppArray('{arrayElementType}', '{arg.name}Array', '{arg.name}Values', locals(), indent=indent + 4)
            ],
            [makeGen('{arg.name}Array = "NULL";', locals(), indent=indent+4)],
            locals(), indent=indent),
    ]

    callArg = '{arg.name}Array.c_str()'.format(arg=arg)
    callTemplate = '%s'

    return ''.join(output), callArg, callTemplate


def makeParamList(cmdInfo, additionalParams):
    paramList = [param.name for param in cmdInfo[2]]
    if cmdInfo[0] != 'void':
        paramList.insert(0, 'returnValue')
    paramList.extend(additionalParams)
    return ', '.join(paramList)


class VulkanCppConsumerBodyGeneratorOptions(BaseGeneratorOptions):
    """Options for generating a C++ class for Vulkan capture file to CPP source generation"""
    def __init__(self,
                 blacklists = None,         # Path to JSON file listing apicalls and structs to ignore.
                 platform_types = None,      # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
                 filename = None,
                 directory = '.',
                 prefix_text = '',
                 protect_file = False,
                 protect_feature = True,
                 versions = CPP_CONSUMER_VULKAN_VERSION_PAT,
                 add_extensions = CPP_CONSUMER_ADD_EXTENSION_PAT,
                 remove_extensions = CPP_CONSUMER_REMOVE_EXTENSION_PAT):
        BaseGeneratorOptions.__init__(self, blacklists=blacklists, platform_types=platform_types,
                                      filename=filename, directory=directory, prefix_text=prefix_text,
                                      protect_file=protect_file, protect_feature=protect_feature,
                                      versions=versions, default_extensions="dis",
                                      add_extensions=add_extensions,
                                      remove_extensions=remove_extensions)


# VulkanCppConsumerBodyGenerator - subclass of BaseGenerator.
# Generates C++ member definitions for the VulkanCppConsumer class responsible for
# generating a textfile containing decoded Vulkan API call parameter data.
class VulkanCppConsumerBodyGenerator(BaseGenerator):
    """Generate a C++ class for Vulkan capture file to CPP source generation"""
    # Track the name of variables in order to generate unique names.
    appInfoId = 1
    variableMap = Counter()

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
     ):
        BaseGenerator.__init__(
            self,
            process_cmds=True,
            process_structs=True,
            feature_break=True,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )
        # The generation of these functions are suspended for a while.
        self.skippedApiFuncs = [
            'vkGetPipelineCacheData',
        ]
        self.reverseAliasMap = {}
        self.extApiFuncs = []

        self.stype_values = dict()
        self.structs_with_handle_ptrs = []
        self.structs_with_handles = dict()

    def writeout(self, *args, **kwargs):
        write(*args, **kwargs, file=self.outFile)

    def genStruct(self, typeinfo, typename, alias):
        """
        Process struct informations

        Note: Using method from replay consumber generator
        """
        BaseGenerator.genStruct(self, typeinfo, typename, alias)

        if not alias:
            self.check_struct_member_handles(
                typename, self.structs_with_handles,
                self.structs_with_handle_ptrs
            )

            stype = self.make_structure_type_enum(typeinfo, typename)
            if stype:
                self.stype_values[typename] = stype

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        self.APICALL_BLACKLIST += CPP_APICALL_BLACKLIST
        self.reverseAliasMap = getReverseAliasMap(self)
        self.extApiFuncs = getExtApiFuncs(self.featureDictionary)

        self.writeout('#include "generated/generated_vulkan_cpp_consumer.h"')
        self.newline()
        self.writeout('#include "decode/vulkan_cpp_consumer_base.h"')
        self.writeout('#include "decode/vulkan_cpp_structs.h"')
        self.writeout('#include "generated/generated_vulkan_cpp_structs.h"')
        self.writeout('#include "generated/generated_vulkan_enum_to_string.h"')
        self.writeout('#include "generated/generated_vulkan_cpp_consumer_extension.h"')
        self.writeout('#include "util/defines.h"')
        self.writeout('#include "vulkan/vulkan.h"')
        self.newline()
        self.writeout('#include <iostream>')
        self.writeout('#include <sstream>')
        self.newline()
        self.writeout('GFXRECON_BEGIN_NAMESPACE(gfxrecon)')
        self.writeout('GFXRECON_BEGIN_NAMESPACE(decode)')
        self.newline()

    # Method override
    def endFile(self):
        self.newline()
        self.writeout('GFXRECON_END_NAMESPACE(decode)')
        self.writeout('GFXRECON_END_NAMESPACE(gfxrecon)')

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    #
    # Indicates that the current feature has C++ code to generate.
    def need_feature_generation(self):
        if self.feature_cmd_params or self.struct_names:
            return True
        return False

    #
    # Performs C++ code generation for the feature.
    def generate_feature(self):
        first = True

        cmdnames = self.get_filtered_cmd_names()
        cmdnames.sort()

        for cmd in cmdnames:
            info = self.feature_cmd_params[cmd]
            info = self.feature_cmd_params[cmd]
            returnType, values = info[0], info[2]

            cmddef = '' if first else '\n'
            cmddef += self.make_consumer_func_decl(returnType, 'VulkanCppConsumer::Process_' + cmd, values) + '\n'
            cmddef += '{\n'
            if cmd in CPP_APICALL_INTERCEPT_LIST:
                paramList = makeParamList(info, [])
                cmddef += makeGen('Intercept_{cmd}({paramList});', locals(), indent=4)
            if cmd in CPP_APICALL_GENERATE:
                paramList = makeParamList(info, [])
                cmddef += makeGen('Generate_{cmd}({paramList});', locals(), indent=4)
            else:
                cmddef += makeGen("FILE* file = GetFrameFile();", indent=4)
                cmddef += self.makeConsumerFuncBody(returnType, cmd, values)
            cmddef += makeGenCall('Post_APICall'.format(cmd), ['format::ApiCallId::ApiCall_' + cmd], locals(), indent=4)
            cmddef += '}'
            self.writeout(cmddef)
            first = False

    #
    # Return VulkanCppConsumer class member function definition.
    def makeConsumerFuncBody(self, returnType, name, values):
        # Add a TODO into the final generated source for skipped functions.
        if name in self.skippedApiFuncs:
            return '    fprintf(file, "// TODO: Support {name} function.\\n");\n'.format(**locals())

        needsToBeLoaded = False
        if name in self.extApiFuncs:
            needsToBeLoaded = True

        valueFormatDict = {
            'uint32_t': '%u',
            'uint16_t': '%u',
            'VkBool32': '%u',
            'VkDeviceSize': '%lu',
            'uint64_t': '%lu',
            'size_t': '%lu',
            'int32_t': '%d',
            'float': '%f',
            'double': '%lf',
            'void': '',
        }
        valueSuffixDict = {
            'VkDeviceSize': 'UL',
            'uint64_t': 'UL',
        }

        body = ''
        callArgs = []
        callTempl = []

        for arg in values:
            originalBaseType = arg.base_type
            if arg.base_type in self.reverseAliasMap:
                arg.base_type = self.reverseAliasMap[arg.base_type]

            body += makeGen('/* {arg.name} */', locals(), indent=0)
            if arg.is_pointer and self.is_struct(arg.base_type) and self.is_input_pointer(arg):
                if arg.base_type == 'VkAllocationCallbacks':
                    callArgs.append('"nullptr"')
                    callTempl.append('%s')
                    continue

                streamName = "stream_{arg.name}".format(**locals())
                body += makeGen('std::stringstream {streamName};', locals(), indent=4)

                if arg.is_array:
                    #body += makeGen('std::string {arg.name}Names;', locals(), indent=4)
                    body += makeGenVar('{arg.name}Array', None, locals(), indent=4)

                    # TODO: maybe only do this if there is any contents to process in the cpp:
                    body += makeGen('PointerPairContainer<decltype({arg.name}->GetPointer()), decltype({arg.name}->GetMetaStructPointer())> {arg.name}Pair{{ {arg.name}->GetPointer(), {arg.name}->GetMetaStructPointer(), {arg.array_length} }};', locals(), indent=4)
                    body += makeGenVarCall('std::string', '{arg.name}Names', 'toStringJoin',
                                           ['{arg.name}Pair.begin()',
                                            '{arg.name}Pair.end()',
                                            '[&](auto pair) {{ return GenerateStruct_{arg.base_type}({streamName}, pair.t1, pair.t2, *this); }}',
                                            '", "'], locals(), indent=4)

                    body += makeCppOutputStream(streamName)
                    body += makeGenConditions([
                                ['{arg.array_length} == 1', [makeGen('{arg.name}Array = "&" + {arg.name}Names;', locals(), indent=8)]],
                                ['{arg.array_length} > 1', [
                                    makeGenVar('{arg.name}Array', arg.name, locals(), indent=8, addType=False), # generate the CPP name
                                    makeCppArray('{arg.base_type}', '{arg.name}Array', '{arg.name}Names', locals(), indent=8)]],
                            ], locals(), indent=4)

                    callArgs.append('{arg.name}Array.c_str()'.format(arg=arg))
                    callTempl.append('%s')
                else:
                    body += makeGenVarCall('std::string', '{arg.name}Struct',
                                           'GenerateStruct_{arg.base_type}',
                                           ['{streamName}',
                                            '{arg.name}->GetPointer()',
                                            '{arg.name}->GetMetaStructPointer()',
                                            '*this'],
                                           locals(), indent=4)
                    body += makeCppOutputStream(streamName)

                    callArgs.append('{arg.name}Struct.c_str()'.format(arg=arg))
                    callTempl.append('&%s')

            elif arg.is_pointer and self.is_handle(arg.base_type) and self.is_output_parameter(arg):
                assert values.index(arg) == (len(values) - 1), "The handle output pointer should be the last argument"

                varName = '{arg.name}Name'.format(arg=arg)
                body += makeGenVar(varName, '{arg.name}', locals(), indent=4)
                if arg.is_array:
                    callTempl.append('%s')
                    arrayInfo = '[%d]'
                    arrayFuncDelimiter = ', '
                    arrayValue = arg.array_length.replace('->', '->GetPointer()->')
                else:
                    callTempl.append('&%s')
                    arrayInfo = ''
                    arrayValue = ''
                    arrayFuncDelimiter = ''
                body += self.printKnownVariables(arg, varName, arrayValue, useThis=False, indent=4)

                callArgs.append(varName + '.c_str()')

                if returnType == 'VkResult':
                    body += makeGenCond('returnValue == VK_SUCCESS', [
                                makeGenCall('this->AddHandles', [varName, '{arg.name}->GetPointer(){arrayFuncDelimiter}{arrayValue}'], locals(), indent=8),
                            ], [],
                            locals(), indent=4)
                else:
                    body += makeGenCall('this->AddHandles', [varName, '{arg.name}->GetPointer(){arrayFuncDelimiter}{arrayValue}'], locals(), indent=4)

            # TODO: Create a separate function for common parts.
            elif arg.is_pointer and self.is_output_parameter(arg):
                # TODO: do a double check on this:
                #assert arg.base_type == 'void', 'The arg.base_type should be void'

                body += makeGenVar('{arg.name}Name', '{arg.name}', locals(), indent=4)

                if originalBaseType in self.stype_values: # The output parameter has an sType value, generate the struct, just to be safe for now.
                    streamName = "stream_{arg.name}".format(**locals())
                    body += makeGen('std::stringstream {streamName};', locals(), indent=4)

                    body += makeGenVarCall(None, '{arg.name}Name',
                                           'GenerateStruct_{arg.base_type}',
                                           ['{streamName}',
                                            '{arg.name}->GetPointer()',
                                            '{arg.name}->GetMetaStructPointer()',
                                            '*this'],
                                           locals(), indent=4)
                    body += makeCppOutputStream(streamName)
                    callTempl.append('&%s')
                    callArgs.append('{arg.name}Name.c_str()'.format(arg=arg))
                    continue
                if arg.is_array:
                    callTempl.append('%s')
                    arrayValue = ', {arg.array_length}'.format(arg=arg)
                    if arg.array_length_value.base_type == 'size_t':
                        arrayInfo = '[%ld]'
                    else:
                        arrayInfo = '[%d]'

                    if arg.array_length_value.is_pointer:
                        if arg.array_length_value.base_type != 'size_t':
                            body += makeGen('const uint32_t* in_{arg.array_length_value.name} = {arg.array_length_value.name}->GetPointer();',locals(), indent=4)
                        else:
                            body += makeGen('long unsigned int* in_{arg.array_length_value.name} = {arg.array_length_value.name}->GetPointer();',locals(), indent=4)
                        arrayValue = ', *in_{arg.array_length_value.name}'.format(arg=arg)
                    else:
                        arrayValue = ', {arg.array_length_value.name}'.format(arg=arg)

                else:
                    callTempl.append('&%s')
                    arrayInfo = ''
                    arrayValue = ''

                callArgs.append('{arg.name}Name.c_str()'.format(arg=arg))

                varType = 'uint8_t' if arg.base_type == 'void' else arg.base_type
                if arg.pointer_count > 1:
                    varType += '*' * (arg.pointer_count - 1)
                body += makeGen('fprintf(file, "{varType} %s{arrayInfo};\\n", {arg.name}Name.c_str(){arrayValue});', locals(), indent=4)
            elif self.is_handle(arg.base_type):
                if arg.is_array:
                    # Generate an array of strings containing the handle id names
                    strArrayName = arg.name + "Array"

                    body += makeGenVar(strArrayName, None, locals(), indent=4)
                    body += makeGenVarCall('std::string', '{arg.name}Values', 'toStringJoin',
                                           ['{arg.name}->GetPointer()',
                                            '{arg.name}->GetPointer() + {arg.array_length}',
                                            '[&](const format::HandleId current) {{ return this->GetHandle(current); }}',
                                            '", "'], locals(), indent=4)

                    body += makeGenConditions([
                                ['{arg.array_length} == 1', [makeGen('{arg.name}Array = "&" + {arg.name}Values;', locals(), indent=8)]],
                                ['{arg.array_length} > 1', [
                                    makeGenVar(strArrayName, strArrayName, indent=8, addType=False), # generate the CPP name
                                    makeCppArray('{arg.base_type}', '{arg.name}Array', '{arg.name}Values', locals(), indent=8)]],
                            ], locals(), indent=4)

                    callArgs.append('{0}.c_str()'.format(strArrayName))
                    callTempl.append('%s')
                else:
                    callArgs.append('this->GetHandle({argName}).c_str()'.format(argName=arg.name))
                    callTempl.append('%s')
            elif self.is_enum(arg.base_type) or self.is_flags(arg.base_type):
                callArgs.append('util::ToString<{argType}>({argName}).c_str()'.format(argType=arg.base_type, argName=arg.name))
                callTempl.append('%s')
            elif self.is_input_pointer(arg):
                # There should be only primitive types here
                valueSuffix = valueSuffixDict.get(arg.base_type, '')

                if arg.is_array:
                    newArray, callArg, callTemplate = buildInputArray(arg, valueSuffix=valueSuffix, indent=4)
                    body += newArray
                else:
                    assert arg.base_type == 'void'
                    # encoding void* inputs is tricky at the moment, hope for the best
                    body += makeGenVar('{arg.name}Name', '{arg.name}', locals(), indent=4)
                    body += makeGen('fprintf(file, "void* %s;\\n", {arg.name}Name.c_str());', locals(), indent=4)

                    callArg = '{arg.name}Name.c_str()'.format(arg=arg)
                    callTemplate = '%s'

                callArgs.append(callArg)
                callTempl.append(callTemplate)
            elif arg.is_pointer:
                assert self.is_output_parameter(arg)
                body += makeGenVar('{arg.name}Name', '{arg.name}', locals(), indent=4)
                body += makeGen('fprintf(file, "{arg.base_type} %s;\\n", {arg.name}Name.c_str());', locals(), indent=4)

                callArgs.append('{arg.name}Name.c_str()'.format(arg=arg))
                callTempl.append('&%s')
            else:
                # simple input argument (float, etc..)
                valueSuffix = valueSuffixDict.get(arg.base_type, '')
                valueFormat = valueFormatDict[arg.base_type]

                callArgs.append('{arg.name}'.format(arg=arg))
                callTempl.append(valueFormat + valueSuffix)

        # Build the vk* function call with arguments
        if needsToBeLoaded:
            body += makeGen('m_pfnLoader.AddMethodName("{}");'.format(name), locals(), indent=4)
            functionCall = 'loaded_{}({})'.format(name, ', '.join(callTempl))
        else:
            functionCall = '{}({})'.format(name, ', '.join(callTempl)) # vk function call

        if returnType == 'VkResult':
            if name in CPP_APICALL_DO_NOT_CHECK:
                functionCall = '{}'.format(functionCall)
            else:
                # wrap function call into a macro call
                functionCall = 'VK_CALL_CHECK({}, %s)'.format(functionCall)  # '%s' is the captured 'VkResult returnValue'
                callArgs.append('util::ToString<VkResult>(returnValue).c_str()')

        fprintfArgs = [
            'file',
            '"{};\\n"'.format(functionCall), # double quote is intended to make sure this is a string in the cpp
        ]
        fprintfArgs.extend(callArgs)
        body += makeGenCall('fprintf', fprintfArgs, locals(), indent=4)

        if name in CPP_CONSUMER_API_POST_CALL:
            # Arguments order for POST api calls:
            # first part: normal api call arguments (just like for the Process_... api calls)
            # second part: strings containing the value/variable name of the arguments
            postArguments = [arg.name for arg in values]
            postArguments.extend([
                arg[:-len(".c_str()")] if arg.endswith(".c_str()") else arg
                for arg in callArgs
            ])

            body += makeGenCall('Post_{}'.format(name), postArguments, locals(), indent=4)

        return body

    def nextVarId(self, varName, separator=''):
        varname = varName + separator + str(self.variableMap[varName])
        self.variableMap[varName] += 1
        return varname

    def printKnownVariables(self, arg, varName, arrayValue, useThis=True, indent=4):
        """
        Output the `AddKnownVariables()` function call into the CPP consumer.

        :param arg: object that describes the variable
        :param varName: the name of the variable in the generated code
        :param arrayValue: if the variable is an array, arrayValue will contain the pointer to it.
        :param useThis: use 'consumer.' if True, otherwise access attributes with the object of class.
        :param indent: indentation size.

        :return:
        """
        object = ''

        if useThis:
            object = 'consumer.'

        assert(self.is_handle(arg.base_type))
        params = [
            '"%s"' % arg.base_type,
            varName,
        ]

        if self.is_output_parameter(arg) or arg.is_pointer:
            params.append('%s->GetPointer()' % arg.name)
            if arg.is_array:
                params.append(arrayValue)
        else:
            params.append(arg.name)

        return (' ' * indent) + object + 'AddKnownVariables(%s);\n' % ', '.join(params)
