#pragma once
#include "Pch.h"
#include "Base/VulkanBase.h"
#include "Instances/Instance.h"
#include "PhysicalDevice.h"


class LogicalDevice
{
public:
	LogicalDevice(PhysicalDevices &TargetDevice);

	virtual ~LogicalDevice();
private:
	VkQueue graphicsQueue;
	VkDevice VkLogicalDevice;
	VkDeviceQueueCreateInfo deviceQueueCreateInfo;
	VkDeviceCreateInfo deviceCreateInfo;
	// Create the external struct which encompasses Logical Device CreateInfos;
};

