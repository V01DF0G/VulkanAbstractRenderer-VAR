#pragma once
#include <Pch.h>
#include <Base/VulkanBase.h>
#include "Device/LogicalDevice.h"
#include "Swapchain/SwapChain.h"

class PipelineLayout
{
public:
	PipelineLayout(std::shared_ptr<LogicalDevice> TargetedDevice);
	~PipelineLayout();

	inline VkPipelineLayout getvkPipelineLayout() const { return m_vkPipelineLayout; }
	void createPipelineLayout();
private:
	VkPipelineLayoutCreateInfo m_LayoutCreateInfo = {};
	VkPipelineLayout m_vkPipelineLayout = VK_NULL_HANDLE;
	std::shared_ptr<LogicalDevice> m_TargetDevice;
};