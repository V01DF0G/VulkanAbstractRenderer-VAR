#include "LogicalDevice.h"
#include "Logger.h"

LogicalDevice::LogicalDevice(std::shared_ptr<Instance> TargetInstance,std::shared_ptr<PhysicalDevices> TargetDevice)
	:m_Instance(TargetInstance), m_physDevices(TargetDevice)
{
	
}

void LogicalDevice::CreateLogicalDevice()
{
	float queuPriority = 1.0f;
	std::set<uint32_t> uniqueQueueFamilies = { m_physDevices->getFamilyIndices().graphicsFamily, m_physDevices->getFamilyIndices().presentationFamily };

	for (uint32_t queueFamily : uniqueQueueFamilies) 
	{
		VkDeviceQueueCreateInfo queueCreateInfo{};
		queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
		queueCreateInfo.queueFamilyIndex = queueFamily;
		queueCreateInfo.queueCount = 1;
		queueCreateInfo.pQueuePriorities = &queuPriority;
		m_deviceQueueCreateInfos.push_back(queueCreateInfo);
	}


	m_deviceCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;

	m_deviceCreateInfo.queueCreateInfoCount = static_cast<uint32_t>(m_deviceQueueCreateInfos.size());
	m_deviceCreateInfo.pQueueCreateInfos = m_deviceQueueCreateInfos.data();


	VkPhysicalDeviceFeatures tempFeatures = m_physDevices->getDeviceFeatures();
	m_deviceCreateInfo.pEnabledFeatures = &tempFeatures;

	m_deviceCreateInfo.enabledExtensionCount = static_cast<uint32_t>(m_physDevices->getPhysicalDeviceExtensions().size());
	std::vector<const char*> tempExtensionNames = m_physDevices->getPhysicalDeviceExtensions();
	m_deviceCreateInfo.ppEnabledExtensionNames = tempExtensionNames.data();


	if (m_Instance->getUsedValidationLayers() != nullptr)
	{
		m_ValidationString = m_Instance->getUsedValidationLayers()->getValidationLayerString();
		m_deviceCreateInfo.enabledLayerCount = static_cast<uint32_t>(m_ValidationString.size());
		m_deviceCreateInfo.ppEnabledLayerNames = m_ValidationString.data();

	}
	else
	{
		m_deviceCreateInfo.enabledLayerCount = 0;
		m_deviceCreateInfo.ppEnabledLayerNames = nullptr;
	}

	if (vkCreateDevice(m_physDevices->getSelectedPhysDevice(), &m_deviceCreateInfo, nullptr, &m_VkLogicalDevice) != VK_SUCCESS)
	{
		RENDER_LOG_CRIT("Failed to create logical device");
	}
	else
	{
		RENDER_LOG_INFO("Successfully created logical device !");
	}
	vkGetDeviceQueue(m_VkLogicalDevice, m_physDevices->getFamilyIndices().graphicsFamily, 0, &m_graphicsQueue);
	vkGetDeviceQueue(m_VkLogicalDevice, m_physDevices->getFamilyIndices().presentationFamily, 0, &m_presentQueue);
}


LogicalDevice::~LogicalDevice()
{
	vkDestroyDevice(m_VkLogicalDevice, nullptr);
}
