#include "Pch.h"
#include "Instance.h"
#include "../Logger/Logger.h"


Instance::Instance()
{
	if (m_ValLayer != nullptr && !m_ValLayer->CheckValidationLayerSupport())
	{
		RENDER_LOG_ERR("Validation Layers were requested but there is no support for them in this machine !");
		delete m_ValLayer;
		m_ValLayer = nullptr;
	}
	
	InstanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	InstanceCreateInfo.pApplicationInfo = m_AppInfo.m_VKAppInfo.get();

	auto extensions = getRequiredExtensions();
	InstanceCreateInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
	InstanceCreateInfo.ppEnabledExtensionNames = extensions.data();

	if (m_ValLayer == nullptr)
	{
		InstanceCreateInfo.enabledLayerCount = 0;
		InstanceCreateInfo.pNext = nullptr;
	}
	else
	{
		m_ValLayer->readyCreateInfo();
	}

	if (vkCreateInstance(&InstanceCreateInfo, nullptr, &m_VkInstance) != VK_SUCCESS)
	{
		RENDER_LOG_CRIT("Failed to create the instance !");
	}
	else
	{
		RENDER_LOG_INFO("Successfully created the Instance !");
	}
	if (m_ValLayer != nullptr)
	{
	m_ValLayer->initDebugMessenger();
	}
}

Instance::~Instance()
{
	if (m_ValLayer != nullptr)
	{
		m_ValLayer->~ValidationLayers();
		m_ValLayer;
	}
	vkDestroyInstance(m_VkInstance, nullptr);

}

std::vector<const char*> Instance::getRequiredExtensions()
{
	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions;
	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

	if (enableValidationLayers) 
	{
		extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
	}

	return extensions;
}

