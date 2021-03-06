#pragma once

#include "Pch.h"
#include "Base/VulkanBase.h"
#include "RenderPass/RenderPass.h"
#include "ImageViews/ImageViews.h"

namespace VAR_CORE
{
	class FrameBufferPool
	{
	public:
		FrameBufferPool(std::shared_ptr<LogicalDevice> TargetedDevice, std::shared_ptr<RenderPass> TargetedRenderPass, std::shared_ptr<ImageViews> TargetedImageViews);
		~FrameBufferPool();
	
		void createFrameBuffers();
	
		inline std::vector<VkFramebuffer> getFrameBuffers() const { return m_FrameBuffers; }
	private:
		std::shared_ptr<LogicalDevice> m_TargetDevice = nullptr;
		std::shared_ptr<RenderPass> m_TargetRenderPass = nullptr;
		std::shared_ptr<ImageViews> m_TargetImageViews = nullptr;
	
		std::vector<VkFramebuffer> m_FrameBuffers = {};
		VkFramebufferCreateInfo m_FrameBufferInfo = {};
	
	};
}
