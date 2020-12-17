#pragma once

#include "Pch.h"
#include "Base/VulkanBase.h"
#include "ApplicationInfo.h"
//#include "ValidationLayers.h"

class Instance
{
public:
	Instance();

	~Instance();


	// getters

	VkInstance getVkInstance() { return m_VkInstance; }
private:

#ifdef NDEBUG
	bool enableValidationLayers = false;
#else
	bool enableValidationLayers = true;
#endif

	VkInstance m_VkInstance;
	AppInfo	m_AppInfo;
	VkDebugUtilsMessengerEXT debugMessenger;
	//VkDebugUtilsMessengerEXT debugMessenger;
	//std::shared_ptr<ValidationLayer> ValidLayer = nullptr;

	// Constants


	// Constants

};
