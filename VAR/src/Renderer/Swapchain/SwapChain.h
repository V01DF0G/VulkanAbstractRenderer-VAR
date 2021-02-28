#pragma once

#include <Pch.h>
#include <VulkanBase.h>
#include "Utilities/CustomTypes/SwapchainSupportDetails.h"
#include "Device/PhysicalDevice.h"
#include "Device/LogicalDevice.h"
#include "Window/WindowMultiPlatform.h"

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

	VkSwapchainKHR VkSwapchain;
	VkSwapchainCreateInfoKHR VkSwapchainInfo = {};
	std::vector<VkImage> swapChainImages;
	VkFormat currentSwapchainImageFormat;

	VkExtent2D currentSwapchainExtent;
	VkSurfaceFormatKHR currentSurfaceFormat;
	VkPresentModeKHR currentPresentationMode;

	void chooseSwapSurfaceFormat();
	void chooseSwapPresentationMode();
	void chooseSwapchainExtent();
	
};
