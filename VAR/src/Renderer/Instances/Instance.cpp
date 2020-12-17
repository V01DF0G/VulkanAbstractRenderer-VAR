#include "Pch.h"
#include "Instance.h"
#include "../Logger/Logger.h"


Instance::Instance()
{
	std::unique_ptr<VkInstanceCreateInfo> InstanceCreateInfo(new VkInstanceCreateInfo());
	InstanceCreateInfo->sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	InstanceCreateInfo->pApplicationInfo = m_AppInfo.m_VKAppInfo.get();

	InstanceCreateInfo->enabledLayerCount = 0;

	InstanceCreateInfo->pNext = nullptr;

	if (vkCreateInstance(InstanceCreateInfo.get(), nullptr, &m_VkInstance) != VK_SUCCESS)
	{
		RENDER_LOG_CRIT("Failed to create the instance !");
	}
	else
	{
		RENDER_LOG_INFO("Successfully created the Instance !");
	}
}

Instance::~Instance()
{
	vkDestroyInstance(m_VkInstance, nullptr);
}


