#pragma once

#include "Pch.h"
#include "Base/VulkanBase.h"
#include "ApplicationInfo.h"
#include "ValidationLayers.h"

namespace VAR_CORE
{
	class Instance
	{
	public:
		Instance();
	
		~Instance();
	
		void createInstance();
	
	
		// getters
	
		inline VkInstance& getVkInstance() { return m_VkInstance; }
		inline ValidationLayers* getUsedValidationLayers() { return m_ValLayer;}
		inline uint32_t getUsedRawVulkanVersion() { return m_AppInfo.m_APIVersion; }
		inline uint32_t getUsedMajorVulkanVersion() { return VK_VERSION_MAJOR(m_AppInfo.m_APIVersion); }
		inline uint32_t getUsedMinorVulkanVersion() { return VK_VERSION_MINOR(m_AppInfo.m_APIVersion); }
		inline uint32_t getUsedPatchVulkanVersion() { return VK_VERSION_PATCH(m_AppInfo.m_APIVersion); }
	
	private:	
	#ifdef NDEBUG
		bool enableValidationLayers = false;
		ValidationLayers* m_ValLayer = nullptr;
	#else
		bool enableValidationLayers = true;
		ValidationLayers *m_ValLayer =  new ValidationLayers(&this->m_VkInstance,&this->InstanceCreateInfo); 	
	#endif
		VkInstanceCreateInfo InstanceCreateInfo = {};
		VkInstance m_VkInstance = VK_NULL_HANDLE;
		AppInfo m_AppInfo = {};
		
		std::vector<const char*> getRequiredExtensions();
	
		// Constants
		// Constants
	
	};
}
