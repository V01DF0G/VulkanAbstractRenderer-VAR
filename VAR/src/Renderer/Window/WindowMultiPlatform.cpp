#include "Pch.h"
#include "Window/WindowMultiPlatform.h"
#include "../Logger/Logger.h"


namespace VAR_CORE
{
	WindowMP::WindowMP()
	{

	}

	void WindowMP::createWindow()
	{
		if (!gladLoaderLoadVulkan(VK_NULL_HANDLE, VK_NULL_HANDLE, VK_NULL_HANDLE)) // to init instance creation
		{
			RENDER_LOG_CRIT("Failed to load vulkan from glad")
		}

		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		m_GlfwWindow = glfwCreateWindow(m_window.m_Width, m_window.m_Height, m_window.m_Name.c_str(), nullptr, nullptr);

	}

	void WindowMP::createSurface(VkInstance& targetInstance)
	{
		m_instanceAdress = &targetInstance;

		if (glfwCreateWindowSurface(targetInstance, m_GlfwWindow, nullptr, &m_surface) != VK_SUCCESS)
		{
			RENDER_LOG_CRIT("Failed to create Window surface for Vulkan")
		}
		else
		{
			RENDER_LOG_INFO("Succesfuly created surface!");
		}
	}

	WindowMP::~WindowMP()
	{
		vkDestroySurfaceKHR(*m_instanceAdress, m_surface, nullptr);
	}
}