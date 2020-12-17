#include "PhysicalDevice.h"
#include "../Logger/Logger.h"


PhysicalDevices::PhysicalDevices(VkInstance& TargetInstance)
{
	vkEnumeratePhysicalDevices(TargetInstance, &DeviceCount, VKPhysDevices.data());
	if (DeviceCount == 0)
	{
		RENDER_LOG_CRIT("There are no GPU's that support Vulkan in your machine");
	}

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

}

PhysicalDevices::~PhysicalDevices()
{

}



bool PhysicalDevices::isPhysicalDeviceSuitable(VkPhysicalDevice targetDevice)
{
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
