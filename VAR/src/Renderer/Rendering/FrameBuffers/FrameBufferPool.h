#pragma once

#include "Pch.h"
#include "Base/VulkanBase.h"
#include "RenderPass/RenderPass.h"
#include "ImageViews/ImageViews.h"

class FrameBufferPool
{
public:
	FrameBufferPool(std::shared_ptr<LogicalDevice> TargetedDevice, std::shared_ptr<RenderPass> TargetedRenderPass, std::shared_ptr<ImageViews> TargetedImageViews);
	~FrameBufferPool();

	void createFrameBuffers();

	inline std::vector<VkFramebuffer> getFrameBuffers() const { return m_FrameBuffers; }
private:
	std::shared_ptr<LogicalDevice> m_TargetDevice;
	std::shared_ptr<RenderPass> m_TargetRenderPass;
	std::shared_ptr<ImageViews> m_TargetImageViews;

	std::vector<VkFramebuffer> m_FrameBuffers;
	VkFramebufferCreateInfo m_FrameBufferInfo = {};

};
