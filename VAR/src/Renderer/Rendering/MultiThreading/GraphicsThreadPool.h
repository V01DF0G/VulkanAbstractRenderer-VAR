#pragma once

#include "Pch.h"
#include "Base/VulkanBase.h"
#include "LogicalDevice.h"

#define MAX_FRAMES_IN_FLIGHT 2

class GraphicsThreadPool
{
public:
	GraphicsThreadPool(std::shared_ptr<LogicalDevice> TargetedDevice);
	~GraphicsThreadPool();

	void createSyncThreads(uint32_t swapchainImageCount);

	std::vector<VkSemaphore>& getImageAvailabaleSemaphores() { return m_imageAvailableSemaphores; }
	std::vector<VkSemaphore>& getImageRenderFinisihedSemaphores() { return m_imageRenderFinisihedSemaphores; }
	std::vector<VkFence>& getinFlightFences() { return m_inFlightFences; }
	std::vector<VkFence>& getimagesInFlight() { return m_imagesInFlight; }

private:
	std::shared_ptr<LogicalDevice> m_TargetDevice = nullptr;

	std::vector<VkSemaphore> m_imageAvailableSemaphores = {};
	std::vector<VkSemaphore> m_imageRenderFinisihedSemaphores = {};
	std::vector<VkFence> m_inFlightFences = {};
	std::vector<VkFence> m_imagesInFlight = {};

	VkSemaphoreCreateInfo m_semaphoreCreateInfo = {};
	VkFenceCreateInfo m_fenceCreateInfo = {};
};