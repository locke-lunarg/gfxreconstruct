/*
** Copyright (c) 2025 LunarG, Inc.
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

#include "generated/generated_dx12_device_prune_modifier.h"
#include <unordered_set>
#include <unordered_map>
#include <cstdint>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void Dx12DevicePruneModifier::Process_D3D12CreateDevice(const ApiCallInfo&           call_info,
                                                        HRESULT                      return_value,
                                                        format::HandleId             pAdapter,
                                                        D3D_FEATURE_LEVEL            MinimumFeatureLevel,
                                                        Decoded_GUID                 riid,
                                                        HandlePointerDecoder<void*>* ppDevice)
{
    if (return_value == S_OK && ppDevice->GetPointer() != nullptr)
    {
        GFXRECON_WRITE_CONSOLE("Found device = %u", *ppDevice->GetPointer());
        if (target_.count(*ppDevice->GetPointer()) > 0)
        {
            GFXRECON_WRITE_CONSOLE("Removing matching device = %u", *ppDevice->GetPointer());
            blocks_.insert(call_info.index);
            SetDeleteCurrentCall();
        }
    }
    else
    {
        GFXRECON_WRITE_CONSOLE("Removing unsuccessful create device, index %u", call_info.index);
        blocks_.insert(call_info.index);
        SetDeleteCurrentCall();
    }
}

void Dx12DevicePruneModifier::Process_ID3D12DeviceFactory_CreateDevice(const ApiCallInfo&           call_info,
                                                                       format::HandleId             object_id,
                                                                       HRESULT                      return_value,
                                                                       format::HandleId             adapter,
                                                                       D3D_FEATURE_LEVEL            FeatureLevel,
                                                                       Decoded_GUID                 riid,
                                                                       HandlePointerDecoder<void*>* ppvDevice)
{
    if (return_value == S_OK && ppvDevice->GetPointer() != nullptr)
    {
        GFXRECON_WRITE_CONSOLE("Found device = %u", *ppvDevice->GetPointer());
        if (target_.count(*ppvDevice->GetPointer()) > 0)
        {
            GFXRECON_WRITE_CONSOLE("Removing matching device = %u", *ppvDevice->GetPointer());
            blocks_.insert(call_info.index);
            SetDeleteCurrentCall();
        }
    }
    else
    {
        GFXRECON_WRITE_CONSOLE("Removing unsuccessful create device, index %u", call_info.index);
        blocks_.insert(call_info.index);
        SetDeleteCurrentCall();
    }
}

void Dx12DevicePruneModifier::Process_ID3D12SDKConfiguration1_CreateDeviceFactory(
    const ApiCallInfo&           call_info,
    format::HandleId             object_id,
    HRESULT                      return_value,
    UINT                         SDKVersion,
    StringDecoder*               SDKPath,
    Decoded_GUID                 riid,
    HandlePointerDecoder<void*>* ppvFactory)
{
    Mark(call_info, object_id);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
