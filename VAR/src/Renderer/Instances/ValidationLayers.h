#pragma once
#include "Pch.h"
#include "Base/VulkanBase.h"
//#include "Instance.h"
//#include "Instance.h"


class ValidationLayers
{
public:
	ValidationLayers(VkInstance* Inst = VK_NULL_HANDLE, VkInstanceCreateInfo *InstCreateInfo = VK_NULL_HANDLE)
		:m_VkInstanceAdress(Inst), m_VkInstanceCreateInfoAdress(InstCreateInfo)
	{
	}

	bool CheckValidationLayerSupport();

	void readyCreateInfo();
	void initDebugMessenger();

	~ValidationLayers();
	// Getters
	std::vector<const char*> getValidationLayerString() { return validationLayers; }


private:
	const std::vector<const char*> validationLayers = { "VK_LAYER_KHRONOS_validation" };
	
	VkInstance *m_VkInstanceAdress = nullptr;
	 VkInstanceCreateInfo *m_VkInstanceCreateInfoAdress = nullptr;

	 VkDebugUtilsMessengerCreateInfoEXT m_DebugMessengerInfo = {};
	VkDebugUtilsMessengerEXT m_DebugMessenger = VK_NULL_HANDLE;

	bool CreationStatus = false;

	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallBack
	(
		VkDebugUtilsMessageSeverityFlagBitsEXT messageseverity,
		VkDebugUtilsMessageTypeFlagsEXT messageType,
		const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
		void* pUserData
	);

	VkResult CreateDebugUtilsMessengerEXT(const VkAllocationCallbacks* pAllocator);

	void DestroyDebugUtilsMessengerEXT(const VkAllocationCallbacks* pAllocator)
	{
		auto func = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(*m_VkInstanceAdress, "vkDestroyDebugUtilsMessengerEXT");
		if (func != nullptr) func(*m_VkInstanceAdress, m_DebugMessenger, pAllocator);
	}

	inline void populateDebugMessengerCreateInfo()
	{
		m_DebugMessengerInfo = {};
		m_DebugMessengerInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
		m_DebugMessengerInfo.messageSeverity = //VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT
			/*|*/ VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT
			| VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
			//| VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT;
		m_DebugMessengerInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
		m_DebugMessengerInfo.pfnUserCallback = debugCallBack;
	}

};


