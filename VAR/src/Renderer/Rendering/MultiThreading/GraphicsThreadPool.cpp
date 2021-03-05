#include "GraphicsThreadPool.h"
#include "Logger.h"


GraphicsThreadPool::GraphicsThreadPool(std::shared_ptr<LogicalDevice> TargetedDevice)
	:m_TargetDevice(TargetedDevice)
{
	m_semaphoreCreateInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
	m_fenceCreateInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
}

GraphicsThreadPool::~GraphicsThreadPool()
{
	vkDeviceWaitIdle(m_TargetDevice->GetVkLogicalDevice());
	for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++)
	{
		vkDestroySemaphore(m_TargetDevice->GetVkLogicalDevice(), m_imageRenderFinisihedSemaphores[i], nullptr);
		vkDestroySemaphore(m_TargetDevice->GetVkLogicalDevice(), m_imageAvailableSemaphores[i], nullptr);
		vkDestroyFence(m_TargetDevice->GetVkLogicalDevice(), m_inFlightFences[i], nullptr);
		//vkDestroyFence(m_TargetDevice->GetVkLogicalDevice(), m_imagesInFlight[i], nullptr);
	}
}

void GraphicsThreadPool::createSyncThreads(uint32_t swapchainImageCount)
{
	m_imageAvailableSemaphores.resize(MAX_FRAMES_IN_FLIGHT);
	m_imageRenderFinisihedSemaphores.resize(MAX_FRAMES_IN_FLIGHT);
	m_inFlightFences.resize(MAX_FRAMES_IN_FLIGHT);
	m_imagesInFlight.resize(swapchainImageCount, VK_NULL_HANDLE);

	m_fenceCreateInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;

	for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++)
	{
		if (vkCreateSemaphore(m_TargetDevice->GetVkLogicalDevice(), &m_semaphoreCreateInfo, nullptr, &m_imageAvailableSemaphores[i]) != VK_SUCCESS ||
			vkCreateSemaphore(m_TargetDevice->GetVkLogicalDevice(), &m_semaphoreCreateInfo, nullptr, &m_imageRenderFinisihedSemaphores[i]) != VK_SUCCESS ||
			vkCreateFence(m_TargetDevice->GetVkLogicalDevice(), &m_fenceCreateInfo, nullptr, &m_inFlightFences[i]) != VK_SUCCESS)
		{
			RENDER_LOG_CRIT("Failed to create Sync Thread");
		}
		else
		{
			RENDER_LOG_INFO("Succesfully created sync Thread");
		}
	}
}
