#pragma once

#include "Pch.h"
#include "Base/VulkanBase.h"
#include "ApplicationInfo.h"
#include "ValidationLayers.h"

class Instance
{
public:
	Instance();

	~Instance();


	// getters

	VkInstance& getVkInstance() { return m_VkInstance; }
	ValidationLayers* getUsedValidationLayers() { return m_ValLayer;}

private:	
#ifdef NDEBUG
	bool enableValidationLayers = false;
	ValidationLayers* m_ValLayer = nullptr;
#else
	bool enableValidationLayers = true;
	ValidationLayers *m_ValLayer =  new ValidationLayers(&this->m_VkInstance,&this->InstanceCreateInfo); 	
#endif
	VkInstanceCreateInfo InstanceCreateInfo = {};
	VkInstance m_VkInstance;
	AppInfo	m_AppInfo;
	



	std::vector<const char*> getRequiredExtensions();

	// Constants





	// Constants

};
