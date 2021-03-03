#pragma once
#include "Pch.h"
#include "Base/VulkanBase.h"
#include "Instances/Instance.h"
#include "PhysicalDevice.h"


class LogicalDevice
{
public:
	LogicalDevice(std::shared_ptr<Instance> TargetInstance, std::shared_ptr<PhysicalDevices> TargetDevice);
	void CreateLogicalDevice();

	inline VkDevice GetVkLogicalDevice() { return m_VkLogicalDevice; }
	inline VkQueue getGraphicsQueue() { return m_graphicsQueue; }
	inline VkQueue getPresentationQueue() { return m_presentQueue; }

	 ~LogicalDevice();
private:
	VkQueue m_graphicsQueue = VK_NULL_HANDLE;
	VkQueue m_presentQueue = VK_NULL_HANDLE;
	VkDevice m_VkLogicalDevice= VK_NULL_HANDLE;
	std::vector<VkDeviceQueueCreateInfo> m_deviceQueueCreateInfos;
	VkDeviceCreateInfo m_deviceCreateInfo = {};
	std::shared_ptr<Instance> m_Instance = nullptr;
	std::vector<const char*> m_ValidationString = {};
	std::shared_ptr<PhysicalDevices> m_physDevices = nullptr;
	VkPhysicalDeviceFeatures m_PhysicalDeviceFeatures;

};

