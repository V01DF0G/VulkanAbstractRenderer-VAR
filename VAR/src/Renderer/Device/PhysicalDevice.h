#pragma once
#include "Pch.h"
#include "Base/VulkanBase.h"
#include "Instance.h"
#include "Window/WindowMultiPlatform.h"
#include "Utilities/CustomTypes/QueueFamiliyIndices.h"


class PhysicalDevices
{
public:
	PhysicalDevices(std::shared_ptr<Instance> TargetInstance, std::shared_ptr<WindowMP> Targetwindow);
	void checkCompWithVulkan();
	void PickBestPhysicalDevice();

	inline VkPhysicalDevice getSelectedPhysDevice() { return selectedVKPhysDevice; }


	inline QueueFamilyIndices getFamilyIndices() { return FamilyIndices; }
	inline VkPhysicalDeviceProperties getDeviceProps() { return PhysDevProps; }
	inline VkPhysicalDeviceFeatures getDeviceFeatures() { return PhysDevFeatures; }
	std::vector<const char*> getPhysicalDeviceExtensions() { return PhysicalDeviceExtensions; }
	inline bool getextensionSupportStatus() { return DeviceExtensionSupportStatus; }


	virtual ~PhysicalDevices();
	

private:
	uint32_t DeviceCount = 0;

	std::shared_ptr<Instance> m_TargetedInstance = nullptr;
	std::shared_ptr<WindowMP> m_TargetedWindow = nullptr;

	bool DeviceExtensionSupportStatus = false;

	VkPhysicalDevice selectedVKPhysDevice = VK_NULL_HANDLE;
	std::vector<VkPhysicalDevice> VKPhysDevices;
	VkPhysicalDeviceProperties PhysDevProps;
	VkPhysicalDeviceFeatures PhysDevFeatures;
	std::vector<VkQueueFamilyProperties> PhysDevQueueFams;
	QueueFamilyIndices FamilyIndices;
	void findQueueFamilies(VkPhysicalDevice targetDevice, VkSurfaceKHR targetSurface);
	void CheckDeviceExtensionSupport(VkPhysicalDevice targetDevice);
	bool isPhysicalDeviceSuitable(VkPhysicalDevice targetDevice, VkSurfaceKHR targetSurface);

	std::vector<const char*> PhysicalDeviceExtensions =
	{
		VK_KHR_SWAPCHAIN_EXTENSION_NAME
	};
};