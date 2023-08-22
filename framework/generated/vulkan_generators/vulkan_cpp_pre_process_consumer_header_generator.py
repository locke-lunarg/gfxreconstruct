#!/usr/bin/python3 -i
#
# Copyright (c) 2021 Samsung
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
from vulkan_cpp_consumer_body_generator import CPP_CONSUMER_ADD_EXTENSION_PAT, CPP_CONSUMER_VULKAN_VERSION_PAT, \
    CPP_CONSUMER_REMOVE_EXTENSION_PAT


class VulkanCppPreProcessConsumerHeaderGeneratorOptions(BaseGeneratorOptions):
    """Options for generating cpp code pre processing"""

    def __init__(self,
                 class_name,
                 base_class_header,
                 is_override,
                 constructorArgs = '',
                 blacklists = None,         # Path to JSON file listing apicalls and structs to ignore.
                 platform_types = None,      # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
                 filename = None,
                 directory = '.',
                 prefix_text = '',
                 protect_file = False,
                 protect_feature = True,
                 versions = CPP_CONSUMER_VULKAN_VERSION_PAT,
                 add_extensions = CPP_CONSUMER_ADD_EXTENSION_PAT,
                 remove_extensions  = CPP_CONSUMER_REMOVE_EXTENSION_PAT):
        BaseGeneratorOptions.__init__(self, blacklists=blacklists, platform_types=platform_types,
                                      filename=filename, directory=directory, prefix_text=prefix_text,
                                      protect_file=protect_file, protect_feature=protect_feature,
                                      versions=versions, default_extensions="dis",
                                      add_extensions=add_extensions,
                                      remove_extensions=remove_extensions)
        self.is_override = is_override


# VulkanCppPreProcessConsumerGenerator - subclass of BaseGenerator.
# Generates the header of vulkan command functions for pre processing.
class VulkanCppPreProcessConsumerHeaderGenerator(BaseGenerator):
    """Generates code pre processing function headers"""

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

    def writeout(self, *args, **kwargs):
        write(*args, **kwargs, file=self.outFile)

    def newline(self):
        write('', file=self.outFile)

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        self.writeout('#include "decode/vulkan_cpp_pre_process_consumer_base.h"')
        self.writeout('#include "util/defines.h"')
        self.writeout('#include "vulkan/vulkan.h"')
        self.newline()
        self.writeout('GFXRECON_BEGIN_NAMESPACE(gfxrecon)')
        self.writeout('GFXRECON_BEGIN_NAMESPACE(decode)')
        self.newline()
        self.writeout('class VulkanCppPreProcessConsumer : public VulkanCppPreProcessConsumerBase')
        self.writeout('{')
        self.writeout(self.indent('public:', spaces=2))
        self.writeout(self.indent('VulkanCppPreProcessConsumer() {}', spaces=4))
        self.newline()
        self.writeout(self.indent('virtual ~VulkanCppPreProcessConsumer() override {}', spaces=4))

    # Method override
    def endFile(self):

        self.writeout('};')
        self.newline()

        self.writeout('GFXRECON_END_NAMESPACE(decode)')
        self.writeout('GFXRECON_END_NAMESPACE(gfxrecon)')

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def need_feature_generation(self):
        if self.feature_cmd_params or self.struct_names:
            return True
        return False

    def generate_feature(self):
        first = True
        for cmd in self.get_filtered_cmd_names():
            info = self.feature_cmd_params[cmd]
            returnType = info[0]
            values = info[2]

            decl = self.make_consumer_func_decl(returnType, 'Process_' + cmd, values)

            cmddef = '' if first else '\n'
            if self.genOpts.is_override:
                cmddef += self.indent('virtual ' + decl + ' override;', self.INDENT_SIZE)
            else:
                cmddef += self.indent('virtual ' + decl + ' {}', self.INDENT_SIZE)

            write(cmddef, file=self.outFile)
            first = False
