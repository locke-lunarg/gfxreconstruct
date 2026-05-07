/*
** Copyright (c) 2020 LunarG, Inc.
** Copyright (c) 2025 Arm Limited and/or its affiliates <open-source-office@arm.com>
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

#include "annotation_editor.h"
#include "decode/file_transformer.h"
#include "util/defines.h"
#include "format/format_util.h"

#include <unordered_set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

bool AnnotationEditor::Process()
{
    bool success = decode::FileTransformer::Process();
    if (success)
    {
        for (const auto& annotation : annotations_to_set_)
        {
            // add new annotations at the end
            success = success && WriteAnnotation(annotation.second.first, annotation.first, annotation.second.second);
        }
    }
    return success;
}

void AnnotationEditor::SetAnnotation(format::AnnotationType type, const std::string& label, const std::string& data)
{
    annotations_to_set_[label] = { type, data };
}

bool AnnotationEditor::ProcessAnnotation(decode::ParsedBlock& parsed_block)
{
    const auto& args                    = parsed_block.Get<decode::AnnotationArgs>();
    bool        success                 = true;
    const auto& annotation_modification = annotations_to_set_.find(args.label);

    if (annotation_modification != annotations_to_set_.end())
    {
        // remove annotation if data is empty
        if (!args.annotation_data.empty())
        {
            // replace existing annotation data
            success = WriteAnnotation(args.type, args.label, annotation_modification->second.second);
        }
        annotations_to_set_.erase(annotation_modification);
    }
    else
    {
        // keep existing annotation
        success = FileTransformer::ProcessAnnotation(parsed_block);
    }
    return success;
}

bool AnnotationEditor::WriteAnnotation(format::AnnotationType type, const std::string& label, const std::string& data)
{
    format::AnnotationHeader annotation;
    annotation.block_header.type = format::BlockType::kAnnotation;
    annotation.block_header.size = format::GetAnnotationBlockBaseSize() + label.size() + data.size();
    annotation.annotation_type   = type;
    annotation.label_length      = label.size();
    annotation.data_length       = data.size();

    if (!WriteBytes(&annotation, sizeof(annotation)) || !WriteBytes(label.data(), label.size()) ||
        !WriteBytes(data.data(), data.size()))
    {
        HandleBlockWriteError(decode::kErrorWritingBlockData, "Failed to write annotation meta-data block");
        return false;
    }

    return true;
}

GFXRECON_END_NAMESPACE(gfxrecon)
