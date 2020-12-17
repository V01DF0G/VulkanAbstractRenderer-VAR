#include "Pch.h"
#include "Instance.h"
#include "../Logger/Logger.h"


Instance::Instance()
{
	if (enableValidationLayers && !checkValidationLayerSupport())
	{
		RENDER_LOG_CRIT("Validation Layers requested but there is no support for them");
	}
	std::unique_ptr<VkInstanceCreateInfo> InstanceCreateInfo(new VkInstanceCreateInfo());
	InstanceCreateInfo->sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	InstanceCreateInfo->pApplicationInfo = m_AppInfo.m_VKAppInfo.get();

	auto extensions = getRequiredExtensions();
	InstanceCreateInfo->enabledExtensionCount = static_cast<uint32_t>(extensions.size());
	InstanceCreateInfo->ppEnabledExtensionNames = extensions.data();

	VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo;

	if (enableValidationLayers == true && checkValidationLayerSupport())
	{
		InstanceCreateInfo->enabledLayerCount = static_cast<uint32_t>(ValLayer.size());
		InstanceCreateInfo->ppEnabledLayerNames = ValLayer.data();
		
		populateDebugMessengerCreateInfo(debugCreateInfo);
		InstanceCreateInfo->pNext = (VkDebugUtilsMessengerCreateInfoEXT*)&debugCreateInfo;
	}
	else
	{
		InstanceCreateInfo->enabledLayerCount = 0;

		InstanceCreateInfo->pNext = nullptr;
	}

	if (vkCreateInstance(InstanceCreateInfo.get(), nullptr, &m_VkInstance) != VK_SUCCESS)
	{
		RENDER_LOG_CRIT("Failed to create the instance !");
	}
	else
	{
		RENDER_LOG_INFO("Successfully created the Instance !");
	}
	if (enableValidationLayers)
	{
		setupDebugMessenger();
	}
}

Instance::~Instance()
{
	if (enableValidationLayers);
	{
		DestroyDebugUtilsMessengerEXT(m_VkInstance, debugMessenger, nullptr);
	}
	vkDestroyInstance(m_VkInstance, nullptr);

}

VKAPI_ATTR VkBool32 VKAPI_CALL Instance::debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageseverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData)
{
	switch (messageseverity)
	{
	case VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT:
		RENDER_LOG_INFO("{0}", pCallbackData->pMessage);
		return VK_FALSE;
	case VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT:
		RENDER_LOG_TRACE("{0}", pCallbackData->pMessage);
		return VK_FALSE;
	case VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT:
		RENDER_LOG_WARN("{0}", pCallbackData->pMessage);
		return VK_FALSE;
	case VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT:
		RENDER_LOG_ERR("{0}", pCallbackData->pMessage);
		return VK_TRUE;
	default:
		return VK_FALSE;
	}
}

void Instance::setupDebugMessenger()
{
	if (!enableValidationLayers)
	{
		return;
	}

	VkDebugUtilsMessengerCreateInfoEXT createInfo;
	populateDebugMessengerCreateInfo(createInfo);

	if (CreateDebugUtilsMessengerEXT(m_VkInstance, &createInfo, nullptr, &debugMessenger) != VK_SUCCESS)
	{
		RENDER_LOG_ERR("failed to set up debug messenger!");
		exit(1);
	}
}

