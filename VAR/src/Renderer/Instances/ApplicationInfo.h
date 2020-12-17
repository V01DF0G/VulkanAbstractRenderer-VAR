#pragma once
#include "Pch.h"
#include "Base/VulkanBase.h"

struct AppInfo
{
	AppInfo(const char* App_Name = "VAR", const char* Engine_Name = "No Engine", uint32_t AppVersion = VK_MAKE_VERSION(0, 0, 1), uint32_t EngineVersion = VK_MAKE_VERSION(0,0,1), uint32_t APIVersion = VK_API_VERSION_1_2, void* Pnext = nullptr) // Making the default values for struct constructor
		: m_App_Name(App_Name), m_Engine_Name(Engine_Name), m_AppVersion(AppVersion), m_EngineVersion(EngineVersion), m_APIVersion(APIVersion), m_Pnext(Pnext) // Defining the acess point values for versatility 
	{
		std::unique_ptr<VkApplicationInfo> VKAppInfo(new VkApplicationInfo()); // When AppInfo() will be called it will definetly create and fill out the Vulkan Application information in memory because the standard demands it for instance creation. 
		VKAppInfo->sType = VK_STRUCTURE_TYPE_APPLICATION_INFO; // Structure type (important)
		VKAppInfo->apiVersion = APIVersion; // Used vulkan API (important)
		VKAppInfo->applicationVersion = AppVersion; // Custom Application Version (trivial)
		VKAppInfo->engineVersion = EngineVersion; // Custom Engine version (trivial)
		VKAppInfo->pApplicationName = App_Name; // Custom Application name (trivial)
		VKAppInfo->pEngineName = Engine_Name; // Custom Engine name (trivial)
		VKAppInfo->pNext = Pnext; // Pointer to the next function which it will go through, generally it is nullpointer because vulkan can automatically set where the function goes next (trivial/important only when using another pointer).
		m_VKAppInfo = std::move(VKAppInfo); // Move local pointer to accessor pointer hence it is a smart pointer VKappInfo will be deleted because it is empty
	}
	 //Accessors for versatility 
	const char* m_App_Name;
	const char* m_Engine_Name;
	uint32_t m_AppVersion;
	uint32_t m_EngineVersion;
	uint32_t m_APIVersion;
	void* m_Pnext;
	std::unique_ptr<VkApplicationInfo> m_VKAppInfo; // Pointer to the duplicate-less VkAppInfo VkApplicationInfo vulkan specific type 
};