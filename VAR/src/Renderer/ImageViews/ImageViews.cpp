#include "Pch.h"
#include "ImageViews.h"
#include "Logger.h"


void ImageViews::CreateImageViews()
{
	VkImageViews.resize(m_TargetedSwapchain->getSwapchainImages().size());
	bool CreationStatus = true;
	for (size_t i = 0; i < VkImageViews.size(); i++) 
	{
		VkImageViewCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
		createInfo.image = m_TargetedSwapchain->getSwapchainImages()[i];
		createInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
		createInfo.format = m_TargetedSwapchain->getcurrentSurfaceFormat().format;
		createInfo.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
		createInfo.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
		createInfo.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
		createInfo.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;
		createInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
		createInfo.subresourceRange.baseMipLevel = 0;
		createInfo.subresourceRange.levelCount = 1;
		createInfo.subresourceRange.baseArrayLayer = 0;
		createInfo.subresourceRange.layerCount = 1;

		if (vkCreateImageView(m_TargetedDevice->GetVkLogicalDevice(), &createInfo, nullptr, &VkImageViews[i]) != VK_SUCCESS) 
		{
			RENDER_LOG_ERR("Failed to create ImageView Nr. {0}/{1}", i+1, VkImageViews.size());
			CreationStatus = false;
		}
	}
	if (CreationStatus == true)
	{
		RENDER_LOG_INFO("All {0} ImageView creation is the success", VkImageViews.size());
	}
	else
	{
		RENDER_LOG_CRIT("Failed to create all possible ImageViews !")
	}
}

ImageViews::~ImageViews()
{
	for (VkImageView imageView : VkImageViews) 
	{
		vkDestroyImageView(m_TargetedDevice->GetVkLogicalDevice(), imageView, nullptr);
	}
}
