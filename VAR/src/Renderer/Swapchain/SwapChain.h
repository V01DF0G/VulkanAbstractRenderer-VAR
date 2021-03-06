#pragma once

#include <Pch.h>
#include <VulkanBase.h>
#include "Utilities/CustomTypes/SwapchainSupportDetails.h"
#include "Device/PhysicalDevice.h"
#include "Device/LogicalDevice.h"
#include "Window/WindowMultiPlatform.h"

namespace VAR_CORE
{
	class SwapChain
	{
	public:
		SwapChain::SwapChain(std::shared_ptr<LogicalDevice> TargetDevice, std::shared_ptr<PhysicalDevices> TargetPhysDevice, std::shared_ptr<WindowMP> TargetWindow)
			:m_TargetedLogicalDevice(TargetDevice), m_TargetedPhysicalDevices(TargetPhysDevice), m_TargetedWindow(TargetWindow)
		{
		}
	
		void PopulateSupportDetails();
		void CreateSwapchain();
		void ChooseExtSurPreModes();
	
	
		virtual ~SwapChain();
	
		inline VkSwapchainKHR getVkSwapChain() const { return VkSwapchain; }
		inline SwapchainSupportDetails getSupportDetails() const { return supportDetails; }
		inline std::vector<VkImage> getSwapchainImages() const { return swapChainImages; }
		inline VkSurfaceFormatKHR getcurrentSwapchainSurfaceFormat() const { return currentSurfaceFormat; }
		inline VkFormat getcurrentSwapchainImageFormat() const { return currentSwapchainImageFormat; }
		inline VkExtent2D getcurrentSwapchainExtent() const { return currentSwapchainExtent; }
		inline VkPresentModeKHR getcurrentPresentationMode() const { return currentPresentationMode; }
	
	private:
		SwapchainSupportDetails supportDetails = {};
	
		std::shared_ptr<LogicalDevice> m_TargetedLogicalDevice = nullptr;
		std::shared_ptr<PhysicalDevices> m_TargetedPhysicalDevices = nullptr;
		std::shared_ptr<WindowMP> m_TargetedWindow = nullptr;
	
		VkSwapchainKHR VkSwapchain = VK_NULL_HANDLE;
		VkSwapchainCreateInfoKHR VkSwapchainInfo = {};
		std::vector<VkImage> swapChainImages = { VK_NULL_HANDLE };
		VkFormat currentSwapchainImageFormat = VK_FORMAT_UNDEFINED;
	
		VkExtent2D currentSwapchainExtent = { 0, 0 };
		VkSurfaceFormatKHR currentSurfaceFormat = { VK_FORMAT_UNDEFINED, VK_COLOR_SPACE_MAX_ENUM_KHR };
		VkPresentModeKHR currentPresentationMode = VK_PRESENT_MODE_MAX_ENUM_KHR;
	
		void chooseSwapSurfaceFormat();
		void chooseSwapPresentationMode();
		void chooseSwapchainExtent();
		
	};
}
