#pragma once
#include <Pch.h>
#include <VulkanBase.h>
#include "Swapchain/SwapChain.h"
#include "Device/LogicalDevice.h"

namespace VAR_CORE
{
	class ImageViews
	{
	public:
		ImageViews(std::shared_ptr<LogicalDevice> TargetDevice, std::shared_ptr<SwapChain> TargetSwapchain)
			:m_TargetedSwapchain(TargetSwapchain), m_TargetedDevice(TargetDevice)
		{};
	
		void CreateImageViews();
	
		virtual ~ImageViews();
	
		inline std::vector<VkImageView> getVkImageViews() const { return VkImageViews; }
		inline std::shared_ptr<SwapChain> getTargetedSwapchain() const { return m_TargetedSwapchain; }
	private:
		std::vector<VkImageView> VkImageViews;
	
		std::shared_ptr<SwapChain> m_TargetedSwapchain = nullptr;
		std::shared_ptr<LogicalDevice> m_TargetedDevice = nullptr;
	};
}

