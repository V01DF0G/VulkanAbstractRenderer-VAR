#include "Swapchain.h"
#include "Logger.h"





void SwapChain::PopulateSupportDetails()
{
	if (!m_TargetedPhysicalDevices->getextensionSupportStatus())
	{
		RENDER_LOG_CRIT("Swapchain is not supported on this device !");
	}

	vkGetPhysicalDeviceSurfaceCapabilitiesKHR(m_TargetedPhysicalDevices->getSelectedPhysDevice(), m_TargetedWindow->getSurface(), &supportDetails.Surfacecapabilities);

	uint32_t formatCount = 0;
	vkGetPhysicalDeviceSurfaceFormatsKHR(m_TargetedPhysicalDevices->getSelectedPhysDevice(), m_TargetedWindow->getSurface(), &formatCount, nullptr);

	if (formatCount != 0) {
		supportDetails.Surfaceformats.resize(formatCount);
		vkGetPhysicalDeviceSurfaceFormatsKHR(m_TargetedPhysicalDevices->getSelectedPhysDevice(), m_TargetedWindow->getSurface(), &formatCount, supportDetails.Surfaceformats.data());
	}

	uint32_t presentModeCount = 0;
	vkGetPhysicalDeviceSurfacePresentModesKHR(m_TargetedPhysicalDevices->getSelectedPhysDevice(), m_TargetedWindow->getSurface(), &presentModeCount, nullptr);

	if (presentModeCount != 0) {
		supportDetails.presentationModes.resize(presentModeCount);
		vkGetPhysicalDeviceSurfacePresentModesKHR(m_TargetedPhysicalDevices->getSelectedPhysDevice(), m_TargetedWindow->getSurface(), &presentModeCount, supportDetails.presentationModes.data());
	}

	if (!supportDetails.SwapchainSupported())
	{
		RENDER_LOG_CRIT("Created swapchain will not be suitable for a task !")
	}

}

void SwapChain::CreateSwapchain()
{
	uint32_t imageCount = supportDetails.Surfacecapabilities.minImageCount + 1;
	if (supportDetails.Surfacecapabilities.maxImageCount > 0 && imageCount > supportDetails.Surfacecapabilities.maxImageCount)
	{
		imageCount = supportDetails.Surfacecapabilities.maxImageCount;
	}

	VkSwapchainInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
	VkSwapchainInfo.surface = m_TargetedWindow->getSurface();

	VkSwapchainInfo.minImageCount = imageCount;
	VkSwapchainInfo.imageFormat = currentSurfaceFormat.format;
	VkSwapchainInfo.imageColorSpace = currentSurfaceFormat.colorSpace;
	VkSwapchainInfo.imageExtent = currentSwapchainExtent;
	VkSwapchainInfo.imageArrayLayers = 1;
	VkSwapchainInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;

	std::vector<uint32_t> queueFamilyIndices({ m_TargetedPhysicalDevices->getFamilyIndices().graphicsFamily, m_TargetedPhysicalDevices->getFamilyIndices().presentationFamily });

	if (m_TargetedPhysicalDevices->getFamilyIndices().graphicsFamily != m_TargetedPhysicalDevices->getFamilyIndices().presentationFamily)
	{
		VkSwapchainInfo.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
		VkSwapchainInfo.queueFamilyIndexCount = static_cast<uint32_t>(queueFamilyIndices.size());
		VkSwapchainInfo.pQueueFamilyIndices = queueFamilyIndices.data();
	}
	else
	{
		VkSwapchainInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
	}

	VkSwapchainInfo.preTransform = supportDetails.Surfacecapabilities.currentTransform;
	VkSwapchainInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
	VkSwapchainInfo.presentMode = currentPresentationMode;
	VkSwapchainInfo.clipped = VK_TRUE;

	VkSwapchainInfo.oldSwapchain = VK_NULL_HANDLE;

	if (vkCreateSwapchainKHR(m_TargetedLogicalDevice->GetVkLogicalDevice(), &VkSwapchainInfo, nullptr, &VkSwapchain) != VK_SUCCESS) 
	{
		RENDER_LOG_CRIT("Failed to create Swapchain!");
	}
	else
	{
		RENDER_LOG_INFO("Successfully created the swapchain !");
	}

	vkGetSwapchainImagesKHR(m_TargetedLogicalDevice->GetVkLogicalDevice(), VkSwapchain, &imageCount, nullptr);
	swapChainImages.resize(imageCount);
	vkGetSwapchainImagesKHR(m_TargetedLogicalDevice->GetVkLogicalDevice(), VkSwapchain, &imageCount, swapChainImages.data());
}

void SwapChain::ChooseExtSurPreModes()
{
	chooseSwapchainExtent();
	chooseSwapPresentationMode();
	chooseSwapSurfaceFormat();
}

SwapChain::~SwapChain()
{
	vkDestroySwapchainKHR(m_TargetedLogicalDevice->GetVkLogicalDevice(), VkSwapchain, nullptr);
}

void SwapChain::chooseSwapSurfaceFormat()
{
	for (const auto& availableFormat : supportDetails.Surfaceformats)
	{
		if (availableFormat.format == VK_FORMAT_B8G8R8A8_SRGB && availableFormat.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR)
		{
		  currentSurfaceFormat = availableFormat;
		  return;
			
		}
	}

	currentSurfaceFormat = supportDetails.Surfaceformats[0];
}

void SwapChain::chooseSwapPresentationMode()
{
	for (const auto& availablePresentMode : supportDetails.presentationModes) 
	{
		if (availablePresentMode == VK_PRESENT_MODE_MAILBOX_KHR) 
		{
			currentPresentationMode = availablePresentMode;
			return;
		}
	}

	currentPresentationMode = VK_PRESENT_MODE_FIFO_KHR;
}

void SwapChain::chooseSwapchainExtent()
{
	if (supportDetails.Surfacecapabilities.currentExtent.width != UINT32_MAX) 
	{
		currentSwapchainExtent = supportDetails.Surfacecapabilities.currentExtent;
		return;
	}
	else 
	{
		int width, height;
		glfwGetFramebufferSize(m_TargetedWindow->getGlfwWindow(), &width, &height);

		VkExtent2D actualExtent = 
		{
			static_cast<uint32_t>(width),
			static_cast<uint32_t>(height)
		};
		
		actualExtent.width = std::clamp(actualExtent.width, supportDetails.Surfacecapabilities.minImageExtent.width, supportDetails.Surfacecapabilities.maxImageExtent.width);
		actualExtent.height = std::clamp(actualExtent.height, supportDetails.Surfacecapabilities.minImageExtent.width, supportDetails.Surfacecapabilities.maxImageExtent.height);
		currentSwapchainExtent = std::move(actualExtent);
	}
}

