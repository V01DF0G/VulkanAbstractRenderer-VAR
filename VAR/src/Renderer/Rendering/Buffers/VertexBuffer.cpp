#include "VertexBuffer.h"
#include "Logger.h"



VAR_CORE::VertexBuffer::VertexBuffer(std::shared_ptr<LogicalDevice> TargetedDevice, std::vector<VertexInputBase*> TargetedVertices)
	:m_TargetDevice(TargetedDevice), m_TargetVertices(TargetedVertices)
{
	//size_t abs = m_TargetVertices[0]->getSizeOfObject();
	m_VkBufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
	m_VkBufferInfo.size = m_TargetVertices[0]->getSizeOfObject() * m_TargetVertices.size();
	m_VkBufferInfo.usage = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT;
	m_VkBufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
	m_allocationInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
}

void VAR_CORE::VertexBuffer::createVertexBuffer()
{
	if (vkCreateBuffer(m_TargetDevice->GetVkLogicalDevice(), &m_VkBufferInfo, nullptr, &m_Vkbuffer) != VK_SUCCESS) 
	{
		RENDER_LOG_ERR("failed to create vertex buffer!");
	}

	vkGetBufferMemoryRequirements(m_TargetDevice->GetVkLogicalDevice(), m_Vkbuffer, &m_memRequirements);

	m_allocationInfo.allocationSize = m_memRequirements.size;
	m_allocationInfo.memoryTypeIndex = m_TargetDevice->findMemoryType(m_memRequirements.memoryTypeBits, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);

	if (vkAllocateMemory(m_TargetDevice->GetVkLogicalDevice(), &m_allocationInfo, nullptr, &m_VkBufferMem) != VK_SUCCESS)
	{
		RENDER_LOG_ERR("Failed to allocate memory for vertex Buffer");
	}

	vkBindBufferMemory(m_TargetDevice->GetVkLogicalDevice(), m_Vkbuffer, m_VkBufferMem, 0);
	void* data;
	vkMapMemory(m_TargetDevice->GetVkLogicalDevice(), m_VkBufferMem, 0, m_VkBufferInfo.size, 0, &data);
	memcpy(data, *m_TargetVertices.data(), (size_t)m_VkBufferInfo.size);
    vkUnmapMemory(m_TargetDevice->GetVkLogicalDevice(), m_VkBufferMem);
}

VAR_CORE::VertexBuffer::~VertexBuffer()
{
	vkDestroyBuffer(m_TargetDevice->GetVkLogicalDevice(), m_Vkbuffer, nullptr);
	vkFreeMemory(m_TargetDevice->GetVkLogicalDevice(), m_VkBufferMem, nullptr);
}
