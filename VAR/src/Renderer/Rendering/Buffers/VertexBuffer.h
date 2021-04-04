#pragma once
#include "VulkanBase.h"
#include "../VertexInputs/VertexInputBase.h"
#include "Device/LogicalDevice.h"


namespace VAR_CORE
{
	class VertexBuffer
	{
	public:
		VertexBuffer(std::shared_ptr<LogicalDevice> TargetedDevice, std::vector<VertexInputBase*> TargetedVertices);
		void createVertexBuffer();
		~VertexBuffer();
		std::vector<VertexInputBase*> getTargetVertices() const { return m_TargetVertices; }
		VkBuffer getVkbuffer() const { return m_Vkbuffer; }
	private:
		std::shared_ptr<LogicalDevice> m_TargetDevice;

		VkBufferCreateInfo m_VkBufferInfo = {};
		VkBuffer m_Vkbuffer = nullptr;
		VkMemoryRequirements m_memRequirements = {};
		VkMemoryAllocateInfo m_allocationInfo = {};
		VkDeviceMemory m_VkBufferMem = nullptr;

		std::vector<VertexInputBase*> m_TargetVertices = {};

	};
}
