#include "PhysicalDevice.h"
#include "../Logger/Logger.h"


PhysicalDevices::PhysicalDevices(VkInstance TargetInstance)
{

	vkEnumeratePhysicalDevices(TargetInstance, &DeviceCount, nullptr);
	VKPhysDevices.resize(DeviceCount);
	if (DeviceCount == 0)
	{
		RENDER_LOG_CRIT("There are no GPU's that support Vulkan in your machine");
	}
	
	
	vkEnumeratePhysicalDevices(TargetInstance, &DeviceCount, VKPhysDevices.data());

	for (auto& device : VKPhysDevices)
	{
		if (isPhysicalDeviceSuitable(device))
		{
			selectedVKPhysDevice = device;
			break;
		}
	}

	if (selectedVKPhysDevice == VK_NULL_HANDLE) 
	{
		RENDER_LOG_CRIT("failed to find a suitable GPU!");
	}

	vkGetPhysicalDeviceProperties(selectedVKPhysDevice, &PhysDevProps);
	vkGetPhysicalDeviceFeatures(selectedVKPhysDevice, &PhysDevFeatures);
}

PhysicalDevices::~PhysicalDevices()
{

}



bool PhysicalDevices::isPhysicalDeviceSuitable(VkPhysicalDevice targetDevice)
{
	findQueueFamilies(targetDevice);
	return FamilyIndices.isComplete();
}

QueueFamilyIndices PhysicalDevices::findQueueFamilies(VkPhysicalDevice targetDevice)
{

	uint32_t queueFamilyCount = 0;
	vkGetPhysicalDeviceQueueFamilyProperties(targetDevice, &queueFamilyCount, nullptr);

	PhysDevQueueFams.resize(queueFamilyCount);
	vkGetPhysicalDeviceQueueFamilyProperties(targetDevice, &queueFamilyCount, PhysDevQueueFams.data());

	int i = 0;
	for (const auto& queueFamily : PhysDevQueueFams)
	{
		if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT)
		{
			FamilyIndices.graphicsFamily = i;
		}

		if (FamilyIndices.isComplete())
		{
			break;
		}
		i++;
	}

	return FamilyIndices;
}
