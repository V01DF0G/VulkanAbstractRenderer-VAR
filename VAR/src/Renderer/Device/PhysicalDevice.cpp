#include "PhysicalDevice.h"
#include "../Logger/Logger.h"

PhysicalDevices::PhysicalDevices(std::shared_ptr<Instance> TargetInstance, std::shared_ptr<WindowMP> Targetwindow)
	:m_TargetedInstance(TargetInstance), m_TargetedWindow(Targetwindow)
{
}

void PhysicalDevices::checkCompWithVulkan()
{
	vkEnumeratePhysicalDevices(m_TargetedInstance->getVkInstance(), &DeviceCount, nullptr);
	VKPhysDevices.resize(DeviceCount);

	if (DeviceCount == 0)
	{
		RENDER_LOG_CRIT("There are no GPU's that support Vulkan in your machine");
	}

	vkEnumeratePhysicalDevices(m_TargetedInstance->getVkInstance(), &DeviceCount, VKPhysDevices.data());
}

void PhysicalDevices::PickBestPhysicalDevice()
{
	for (auto& device : VKPhysDevices)
	{
		if (isPhysicalDeviceSuitable(device, m_TargetedWindow->getSurface()))
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

	int i = 0;
}

PhysicalDevices::~PhysicalDevices()
{

}



bool PhysicalDevices::isPhysicalDeviceSuitable(VkPhysicalDevice targetDevice, VkSurfaceKHR targetSurface)
{
	findQueueFamilies(targetDevice, targetSurface);
	CheckDeviceExtensionSupport(targetDevice);

	return FamilyIndices.isComplete();
}

void PhysicalDevices::findQueueFamilies(VkPhysicalDevice targetDevice, VkSurfaceKHR targetSurface)
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

		VkBool32 presentationSupport = false;
		vkGetPhysicalDeviceSurfaceSupportKHR(targetDevice, i, targetSurface , &presentationSupport);

		if (presentationSupport)
		{
			FamilyIndices.presentationFamily = i;
		}


		if (FamilyIndices.isComplete())
		{
			break;
		}
		i++;
	}
}

void PhysicalDevices::CheckDeviceExtensionSupport(VkPhysicalDevice Targetdevice)
{
	uint32_t extensionCount;
	vkEnumerateDeviceExtensionProperties(Targetdevice, nullptr, &extensionCount, nullptr);

	std::vector<VkExtensionProperties> availableExtensions(extensionCount);
	vkEnumerateDeviceExtensionProperties(Targetdevice, nullptr, &extensionCount, availableExtensions.data());

	std::set<std::string> requiredExtensions(PhysicalDeviceExtensions.begin(), PhysicalDeviceExtensions.end());

	for (const auto& extension : availableExtensions)
	{
		requiredExtensions.erase(extension.extensionName);
	}

	DeviceExtensionSupportStatus = requiredExtensions.empty();
}
