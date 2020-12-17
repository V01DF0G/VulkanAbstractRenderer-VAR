#pragma once
#include "Pch.h"
#include "Base/VulkanBase.h"
#include "Utilities/CustomTypes/QueueFamiliyIndices.h"


class PhysicalDevices
{
public:
	PhysicalDevices(VkInstance& TargetInstance);
	VkPhysicalDevice getSelectedPhysDevice() { return selectedVKPhysDevice; }


	QueueFamilyIndices getFamilyIndices() { return FamilyIndices; }
	VkPhysicalDeviceProperties getDeviceProps() { return PhysDevProps; }

	virtual ~PhysicalDevices();
private:
	uint32_t DeviceCount = 0;
	VkPhysicalDevice selectedVKPhysDevice = VK_NULL_HANDLE;
	std::vector<VkPhysicalDevice> VKPhysDevices;
	VkPhysicalDeviceProperties PhysDevProps;
	VkPhysicalDeviceFeatures PhysDevFeatures;
	std::vector<VkQueueFamilyProperties> PhysDevQueueFams;
	bool isPhysicalDeviceSuitable(VkPhysicalDevice targetDevice);
	QueueFamilyIndices FamilyIndices;
	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice targetDevice);
};