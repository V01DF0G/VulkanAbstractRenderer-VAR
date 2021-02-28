#pragma once

#include "Pch.h"
#include "Device/LogicalDevice.h"
#include "Swapchain/SwapChain.h"

class RenderPass
{
public:
	RenderPass(std::shared_ptr<LogicalDevice> TargetedDevice, std::shared_ptr<SwapChain> TargetedSwapchain);
	~RenderPass();

	void createRenderPass();

	inline VkRenderPass getvkRenderPass() const { return m_VkRenderPass; }
	inline std::shared_ptr<SwapChain> getTargetedSwapchain() const { return m_targetSwapchain; }

private:
	VkAttachmentDescription m_AttachmentDescription = {};
	VkAttachmentReference m_AttachmentReference = {};
	VkRenderPassCreateInfo m_VkRenderPassInfo = {};
	VkRenderPass m_VkRenderPass = VK_NULL_HANDLE;
	VkSubpassDescription m_SubpassInfo = {};

	std::shared_ptr<SwapChain> m_targetSwapchain;
	std::shared_ptr<LogicalDevice> m_targetDevice;
};