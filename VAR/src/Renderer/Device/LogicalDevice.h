#pragma once
#include "Pch.h"
#include "Base/VulkanBase.h"
#include "Instances/Instance.h"
#include "PhysicalDevice.h"


class LogicalDevice
{
public:
	LogicalDevice(std::shared_ptr<Instance> TargetInstance, std::shared_ptr<PhysicalDevices> TargetDevice);

	 ~LogicalDevice();
private:
	VkQueue m_graphicsQueue = VK_NULL_HANDLE;
	VkDevice m_VkLogicalDevice= VK_NULL_HANDLE;
	VkDeviceQueueCreateInfo m_deviceQueueCreateInfo = {};
	VkDeviceCreateInfo m_deviceCreateInfo = {};
	std::shared_ptr<Instance> m_Instance = nullptr;
	std::vector<const char*> m_ValidationString = {};
	std::shared_ptr<PhysicalDevices> m_physDevices = nullptr;
	VkPhysicalDeviceFeatures m_PhysicalDeviceFeatures;
};

