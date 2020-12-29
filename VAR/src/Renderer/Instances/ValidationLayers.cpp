#include "ValidationLayers.h"
#include "Logger.h"

bool ValidationLayers::CheckValidationLayerSupport()
{
	uint32_t layerCount;
	vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

	std::vector<VkLayerProperties> availableLayers(layerCount);
	vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

	for (const char* layerName : validationLayers) {
		bool layerFound = false;

		for (const auto& layerProperties : availableLayers) {
			if (strcmp(layerName, layerProperties.layerName) == 0) {
				layerFound = true;
				break;
			}
		}

		if (!layerFound) {
			return false;
		}
	}

	return true;
}

void ValidationLayers::readyCreateInfo()
{
	m_VkInstanceCreateInfoAdress->enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
	m_VkInstanceCreateInfoAdress->ppEnabledLayerNames = validationLayers.data();

	populateDebugMessengerCreateInfo();
	m_VkInstanceCreateInfoAdress->pNext = &m_DebugMessengerInfo;
}

void ValidationLayers::initDebugMessenger()
{
	if (CreateDebugUtilsMessengerEXT(nullptr) != VK_SUCCESS)
	{
		RENDER_LOG_ERR("Failed to init Debug Messenger !");
	}
	else
	{
		CreationStatus = true;
	}
}
ValidationLayers::~ValidationLayers()
{
	if(CreationStatus)
	DestroyDebugUtilsMessengerEXT(nullptr);
}

VKAPI_ATTR VkBool32 VKAPI_CALL ValidationLayers::debugCallBack(VkDebugUtilsMessageSeverityFlagBitsEXT messageseverity,
	VkDebugUtilsMessageTypeFlagsEXT messageType,
	const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
	void* pUserData)
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

VkResult ValidationLayers::CreateDebugUtilsMessengerEXT(const VkAllocationCallbacks* pAllocator)
{
	auto func = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(*m_VkInstanceAdress, "vkCreateDebugUtilsMessengerEXT");
	if (func != nullptr) {
		return func(*m_VkInstanceAdress, &m_DebugMessengerInfo, pAllocator, &m_DebugMessenger);
	}
	else {
		return VK_ERROR_EXTENSION_NOT_PRESENT;
	}
}

