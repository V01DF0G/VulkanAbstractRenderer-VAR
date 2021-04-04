#include "FrameDrawer.h"
#include "Logger.h"


namespace VAR_CORE
{
	FrameDrawer::FrameDrawer(std::shared_ptr<LogicalDevice> TargetedDevice, std::shared_ptr<SwapChain> TargetedSwapchain, std::shared_ptr<CommandBufferPool> TargetedCommandPool, std::shared_ptr<GraphicsThreadPool> TargetedGThreadPool)
		:m_TargetDevice(TargetedDevice), m_TargetSwapchain(TargetedSwapchain), m_TargetCommandPool(TargetedCommandPool), m_TargetGThreadPool(TargetedGThreadPool)
	{
		m_SubmitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
		m_SubmitInfo.waitSemaphoreCount = 1;
		m_SubmitInfo.commandBufferCount = 1;
		m_SubmitInfo.signalSemaphoreCount = 1;
	
		m_PresentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
		m_PresentInfo.waitSemaphoreCount = 1;
		m_PresentInfo.swapchainCount = 1;
	}
	
	FrameDrawer::~FrameDrawer()
	{
	}
	
	void FrameDrawer::drawFrame()
	{
		vkWaitForFences(m_TargetDevice->GetVkLogicalDevice(), 1, &m_TargetGThreadPool->getinFlightFences()[currentframe], VK_TRUE, UINT64_MAX);
	
		vkAcquireNextImageKHR(m_TargetDevice->GetVkLogicalDevice(), m_TargetSwapchain->getVkSwapChain(), UINT64_MAX, m_TargetGThreadPool->getImageAvailabaleSemaphores()[currentframe], VK_NULL_HANDLE, &imageIndex);
	
		if (m_TargetGThreadPool->getimagesInFlight()[imageIndex] != VK_NULL_HANDLE) 
		{
			vkWaitForFences(m_TargetDevice->GetVkLogicalDevice(), 1, &m_TargetGThreadPool->getimagesInFlight()[imageIndex], VK_TRUE, UINT64_MAX);
		}
	
		m_TargetGThreadPool->getimagesInFlight()[imageIndex] = m_TargetGThreadPool->getinFlightFences()[currentframe];
	
		VkSemaphore waitSemaphores[] = { m_TargetGThreadPool->getImageAvailabaleSemaphores()[currentframe] };
	
		m_SubmitInfo.pWaitSemaphores = waitSemaphores;
		m_SubmitInfo.pWaitDstStageMask = &waitstages;
	
		VkCommandBuffer combufs[] = { m_TargetCommandPool->getCommandBuffers()[imageIndex] };
	
		m_SubmitInfo.pCommandBuffers = combufs;
	
		VkSemaphore signalSemaphores[] = { m_TargetGThreadPool->getImageAvailabaleSemaphores()[currentframe] };
		m_SubmitInfo.pSignalSemaphores = signalSemaphores;
	
		vkResetFences(m_TargetDevice->GetVkLogicalDevice(), 1, &m_TargetGThreadPool->getinFlightFences()[currentframe]);

		if (vkQueueSubmit(m_TargetDevice->getGraphicsQueue(), 1, &m_SubmitInfo, m_TargetGThreadPool->getinFlightFences()[currentframe]))
		{
			RENDER_LOG_CRIT("Failed to submit command buffer!");
		}
	
		m_PresentInfo.pWaitSemaphores = signalSemaphores;
		VkSwapchainKHR swapChains[] = { m_TargetSwapchain->getVkSwapChain() };
		m_PresentInfo.pSwapchains = swapChains;
	
		m_PresentInfo.pImageIndices = &imageIndex;
	
		vkQueuePresentKHR(m_TargetDevice->getPresentationQueue(), &m_PresentInfo);
	
		currentframe = (currentframe + 1) % MAX_FRAMES_IN_FLIGHT;
	
	}
}
