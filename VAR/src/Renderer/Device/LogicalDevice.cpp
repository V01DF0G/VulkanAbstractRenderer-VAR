#include "LogicalDevice.h"

LogicalDevice::LogicalDevice(PhysicalDevices& TargetDevice)
{
	VkDeviceQueueCreateInfo queueCreateInfo = {};
	queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
	queueCreateInfo.pNext = nullptr;
	queueCreateInfo.queueCount = 1;
	queueCreateInfo.queueFamilyIndex;
	queueCreateInfo.pQueuePriorities;



	VkDeviceCreateInfo logDevCreateInfo= {};
	logDevCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	logDevCreateInfo.pNext = nullptr;
	logDevCreateInfo.queueCreateInfoCount = 0;
	logDevCreateInfo.pQueueCreateInfos = 0;
}

LogicalDevice::~LogicalDevice()
{

}
