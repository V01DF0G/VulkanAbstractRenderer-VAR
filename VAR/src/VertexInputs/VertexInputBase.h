#pragma once
#include "Pch.h"
#include "Base/VulkanBase.h"

class VertexInputBase
{
public:
	virtual VkVertexInputBindingDescription getBindingDescription(uint32_t bindingPos) = 0;
	virtual std::vector<VkVertexInputAttributeDescription> getAttributeDescription(uint32_t bindingPos) = 0;
	virtual uint32_t getSizeOfObject() = 0;
};