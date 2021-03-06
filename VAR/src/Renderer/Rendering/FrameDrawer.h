#pragma once

#include "Pch.h"
#include "Base/VulkanBase.h"
#include "Device/LogicalDevice.h"
#include "Swapchain/SwapChain.h"
#include "Rendering/CommandBuffers/CommandBufferPool.h"
#include "Rendering/MultiThreading/GraphicsThreadPool.h"


namespace VAR_CORE
{
	class FrameDrawer
	{
	public:
		FrameDrawer(std::shared_ptr<LogicalDevice> TargetedDevice, std::shared_ptr<SwapChain> TargetedSwapchain,std::shared_ptr<CommandBufferPool> TargetedCommandPool, std::shared_ptr<GraphicsThreadPool> TargetedGThreadPool);
		~FrameDrawer();
	
		void drawFrame();
	private:
		uint32_t currentframe = 0;
		uint32_t imageIndex = 0;
		VkPipelineStageFlags waitstages = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
	
		std::shared_ptr<LogicalDevice> m_TargetDevice = nullptr;
		std::shared_ptr<SwapChain> m_TargetSwapchain = nullptr;
		std::shared_ptr <CommandBufferPool> m_TargetCommandPool = nullptr;
		std::shared_ptr<GraphicsThreadPool> m_TargetGThreadPool = nullptr;
	
		VkSubmitInfo m_SubmitInfo = {};
		VkPresentInfoKHR m_PresentInfo = {};
	
		
	
	};
}