#include "LogicalDevice.h"
#include "Logger.h"

LogicalDevice::LogicalDevice(std::shared_ptr<Instance> TargetInstance,std::shared_ptr<PhysicalDevices> TargetDevice)
	:m_Instance(TargetInstance), m_physDevices(TargetDevice)
{
	m_PhysicalDeviceFeatures = m_physDevices->getDeviceFeatures();

	m_deviceQueueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
	m_deviceQueueCreateInfo.queueFamilyIndex = m_physDevices->getFamilyIndices().graphicsFamily.value();
	m_deviceQueueCreateInfo.queueCount = 1;

	float queuPriority = 1.0f;
	m_deviceQueueCreateInfo.pQueuePriorities = &queuPriority;

	m_deviceCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;

	m_deviceCreateInfo.pQueueCreateInfos = &m_deviceQueueCreateInfo;
	m_deviceCreateInfo.queueCreateInfoCount = 1;


	m_deviceCreateInfo.pEnabledFeatures = &m_PhysicalDeviceFeatures;

	m_deviceCreateInfo.enabledExtensionCount = 0;



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
	vkGetDeviceQueue(m_VkLogicalDevice, m_physDevices->getFamilyIndices().graphicsFamily.value(), 0, &m_graphicsQueue);

}

LogicalDevice::~LogicalDevice()
{
	vkDestroyDevice(m_VkLogicalDevice, nullptr);
}
