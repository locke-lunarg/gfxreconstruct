/*
** Copyright (c) 2024-2025 LunarG, Inc.
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

#include <fcntl.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#include <iostream>

#include <vulkan/vulkan_core.h>

#include <util/logging.h>

#include "external_memory_fd_export_app.h"

#ifdef __linux__
#define HAVE_MSGHDR_MSG_CONTROL
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(external_memory_fd_export)

void App::configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig* test_config)
{
    instance_builder.enable_extension(VK_KHR_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME);
    instance_builder.set_headless(true);
}

void App::configure_physical_device_selector(test::PhysicalDeviceSelector& phys_device_selector,
                                             vkmock::TestConfig*           test_config)
{
    phys_device_selector.add_required_extension(VK_KHR_EXTERNAL_MEMORY_EXTENSION_NAME);
    phys_device_selector.add_required_extension(VK_KHR_EXTERNAL_MEMORY_FD_EXTENSION_NAME);

    // External images commonly report requiresDedicatedAllocation, so the image allocation below carries a
    // VkMemoryDedicatedAllocateInfo.
    phys_device_selector.add_required_extension(VK_KHR_GET_MEMORY_REQUIREMENTS_2_EXTENSION_NAME);
    phys_device_selector.add_required_extension(VK_KHR_DEDICATED_ALLOCATION_EXTENSION_NAME);
}

uint32_t App::find_memory_type(uint32_t memoryTypeBits, VkMemoryPropertyFlags memory_property_flags)
{
    VkPhysicalDeviceMemoryProperties memory_properties;
    init.inst_disp.getPhysicalDeviceMemoryProperties(init.physical_device, &memory_properties);

    for (uint32_t i = 0; i < memory_properties.memoryTypeCount; ++i)
    {
        if ((memoryTypeBits & (1 << i)) && (memory_properties.memoryTypes[i].propertyFlags & memory_property_flags) > 0)
        {
            return i;
            break;
        }
    }

    throw std::runtime_error("Export App Could not find required memory type");
}

void App::create_buffer()
{
    VkExternalMemoryBufferCreateInfo external_mem_buf_create_info = {};
    external_mem_buf_create_info.sType       = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO;
    external_mem_buf_create_info.handleTypes = VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT;

    VkBufferCreateInfo buffer_create_info    = {};
    buffer_create_info.sType                 = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    buffer_create_info.pNext                 = &external_mem_buf_create_info;
    buffer_create_info.flags                 = 0u;
    buffer_create_info.size                  = buffer_size_;
    buffer_create_info.usage                 = VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
    buffer_create_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    buffer_create_info.queueFamilyIndexCount = 0u;
    buffer_create_info.pQueueFamilyIndices   = nullptr;
    VkResult result                          = init.disp.createBuffer(&buffer_create_info, nullptr, &buffer_);
    VERIFY_VK_RESULT("Export App Failed to create buffer", result);

    VkMemoryRequirements buf_mem_requirements;
    init.disp.getBufferMemoryRequirements(buffer_, &buf_mem_requirements);

    VkExportMemoryAllocateInfo export_mem_alloc_info = {};
    export_mem_alloc_info.sType                      = VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO;
    export_mem_alloc_info.handleTypes                = VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT;

    VkMemoryAllocateInfo buf_mem_allocate_info;
    buf_mem_allocate_info.sType          = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    buf_mem_allocate_info.pNext          = &export_mem_alloc_info;
    buf_mem_allocate_info.allocationSize = buf_mem_requirements.size;
    buf_mem_allocate_info.memoryTypeIndex =
        find_memory_type(buf_mem_requirements.memoryTypeBits,
                         VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
    result = init.disp.allocateMemory(&buf_mem_allocate_info, nullptr, &exportable_memory_);
    VERIFY_VK_RESULT("Export App Failed to exportable memory", result);

    result = init.disp.bindBufferMemory(buffer_, exportable_memory_, 0u);
    VERIFY_VK_RESULT("Export App Failed to bind memory", result);

    uint32_t* data = nullptr;
    result         = init.disp.mapMemory(exportable_memory_, 0u, buffer_size_, 0u, reinterpret_cast<void**>(&data));
    VERIFY_VK_RESULT("Export App Failed to map buffer memory", result);
    for (uint32_t i = 0; i < buffer_size_ / sizeof(uint32_t); ++i)
    {
        data[i] = i;
    }

    init.disp.unmapMemory(exportable_memory_);
}

void App::create_image()
{
    VkExternalMemoryImageCreateInfo external_mem_img_create_info = {};
    external_mem_img_create_info.sType                           = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO;
    external_mem_img_create_info.handleTypes                     = VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT;

    VkImageCreateInfo image_create_info     = {};
    image_create_info.sType                 = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
    image_create_info.pNext                 = &external_mem_img_create_info;
    image_create_info.flags                 = 0u;
    image_create_info.imageType             = VK_IMAGE_TYPE_2D;
    image_create_info.format                = VK_FORMAT_R8G8B8A8_UNORM;
    image_create_info.extent                = { image_extent_, image_extent_, 1u };
    image_create_info.mipLevels             = 1u;
    image_create_info.arrayLayers           = 1u;
    image_create_info.samples               = VK_SAMPLE_COUNT_1_BIT;
    image_create_info.tiling                = VK_IMAGE_TILING_OPTIMAL;
    image_create_info.usage                 = VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_SAMPLED_BIT;
    image_create_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    image_create_info.queueFamilyIndexCount = 0u;
    image_create_info.pQueueFamilyIndices   = nullptr;
    image_create_info.initialLayout         = VK_IMAGE_LAYOUT_UNDEFINED;
    VkResult result                         = init.disp.createImage(&image_create_info, nullptr, &image_);
    VERIFY_VK_RESULT("Export App Failed to create image", result);

    VkMemoryRequirements img_mem_requirements;
    init.disp.getImageMemoryRequirements(image_, &img_mem_requirements);

    VkExportMemoryAllocateInfo export_mem_alloc_info = {};
    export_mem_alloc_info.sType                      = VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO;
    export_mem_alloc_info.handleTypes                = VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT;

    // Always dedicated: legal whether or not the driver demands it, and it is what an external image normally
    // gets in practice.
    VkMemoryDedicatedAllocateInfo dedicated_alloc_info = {};
    dedicated_alloc_info.sType                         = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO;
    dedicated_alloc_info.pNext                         = &export_mem_alloc_info;
    dedicated_alloc_info.image                         = image_;

    VkMemoryAllocateInfo img_mem_allocate_info = {};
    img_mem_allocate_info.sType                = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    img_mem_allocate_info.pNext                = &dedicated_alloc_info;
    img_mem_allocate_info.allocationSize       = img_mem_requirements.size;
    img_mem_allocate_info.memoryTypeIndex =
        find_memory_type(img_mem_requirements.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    result = init.disp.allocateMemory(&img_mem_allocate_info, nullptr, &exportable_image_memory_);
    VERIFY_VK_RESULT("Export App Failed to allocate exportable image memory", result);

    result = init.disp.bindImageMemory(image_, exportable_image_memory_, 0u);
    VERIFY_VK_RESULT("Export App Failed to bind image memory", result);
}

int App::get_exportable_fd(VkDeviceMemory memory)
{
    VkMemoryGetFdInfoKHR get_fd_info = {};
    get_fd_info.sType                = VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR;
    get_fd_info.handleType           = VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT;
    get_fd_info.memory               = memory;

    int      exportable_fd = -1;
    VkResult result        = init.disp.getMemoryFdKHR(&get_fd_info, &exportable_fd);
    VERIFY_VK_RESULT("Export App Failed to get memory fd", result);
    return exportable_fd;
}

void App::send_exportable_fds(int buffer_fd, int image_fd)
{
    // Need to send the fd to the importer process
    int external_socket = socket(PF_UNIX, SOCK_STREAM, 0);
    if (external_socket < 0)
    {
        GFXRECON_LOG_ERROR("Export App Failed to create socket (%d)", external_socket);
        throw std::runtime_error("Export App Failed to create socket");
    }
    sockaddr_un un = {};
    un.sun_family  = AF_UNIX;

    const char* socket_name = "/tmp/.external-memory";
    snprintf(un.sun_path, sizeof(un.sun_path), "%s", socket_name);
    unlink(un.sun_path);

    int result = bind(external_socket, reinterpret_cast<struct sockaddr*>(&un), sizeof(un));
    if (result)
    {
        GFXRECON_LOG_ERROR("Export App Failed to bind socket (%d)", result);
        throw std::runtime_error("Export App Failed to bind socket");
    }

    result = listen(external_socket, 1);
    if (result < 0)
    {
        GFXRECON_LOG_ERROR("Export App Failed to listen on socket (%d)", result);
        throw std::runtime_error("Export App Failed to listen on socket");
    }

    GFXRECON_LOG_INFO("Waiting for importer to connect");
    // Blocking
    int conn_fd = accept(external_socket, nullptr, nullptr);
    if (conn_fd < 0)
    {
        GFXRECON_LOG_ERROR("Export App Failed to accept on socket (%d)", conn_fd);
        throw std::runtime_error("Export App Failed to accept on socket");
    }

    // Send both fds, buffer first. Each sendmsg carries exactly one SCM_RIGHTS descriptor, so the importer
    // receives them in the same order.
    for (int fd : { buffer_fd, image_fd })
    {
        ssize_t send_result = send_int(conn_fd, fd);
        if (send_result < 0)
        {
            GFXRECON_LOG_ERROR("Export App Failed to send_int on socket (%d)", send_result);
            throw std::runtime_error("Export App Failed to send_int on socket");
        }
    }

    close(conn_fd);
    close(external_socket);
}

ssize_t App::send_int(int conn_fd, int data)
{
    struct msghdr msg = {};
    struct iovec  iov[1];

#ifdef HAVE_MSGHDR_MSG_CONTROL
    union
    {
        struct cmsghdr cm;
        char           control[CMSG_SPACE(sizeof(int))];
    } control_un = {};

    msg.msg_control    = control_un.control;
    msg.msg_controllen = sizeof(control_un.control);

    struct cmsghdr* cmptr                     = CMSG_FIRSTHDR(&msg);
    cmptr->cmsg_len                           = CMSG_LEN(sizeof(int));
    cmptr->cmsg_level                         = SOL_SOCKET;
    cmptr->cmsg_type                          = SCM_RIGHTS;
    *reinterpret_cast<int*>(CMSG_DATA(cmptr)) = data;
#else
    msg.msg_accrights    = (caddr_t)&data;
    msg.msg_accrightslen = sizeof(int);
#endif

    msg.msg_name    = NULL;
    msg.msg_namelen = 0;

    char c[]        = "1";
    iov[0].iov_base = c;
    iov[0].iov_len  = 1;
    msg.msg_iov     = iov;
    msg.msg_iovlen  = 1;

    return sendmsg(conn_fd, &msg, 0);
}

bool App::frame(const int frame_num)
{
    return false;
}

void App::cleanup()
{
    init.disp.destroyImage(image_, nullptr);
    init.disp.freeMemory(exportable_image_memory_, nullptr);

    init.disp.destroyBuffer(buffer_, nullptr);
    init.disp.freeMemory(exportable_memory_, nullptr);
}

void App::setup()
{
    create_buffer();
    create_image();

    int buffer_fd = get_exportable_fd(exportable_memory_);
    int image_fd  = get_exportable_fd(exportable_image_memory_);
    GFXRECON_LOG_INFO("Exporting buffer fd (%d) and image fd (%d)", buffer_fd, image_fd);
    send_exportable_fds(buffer_fd, image_fd);
}

GFXRECON_END_NAMESPACE(external_memory_fd_export)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)
