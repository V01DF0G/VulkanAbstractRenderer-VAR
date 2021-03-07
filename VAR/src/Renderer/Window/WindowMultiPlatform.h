#pragma once
#include "Pch.h"
#include "Base/VulkanBase.h"
#include "Instance.h"


namespace VAR_CORE
{
	struct DefWindow
	{
		uint32_t m_Width;
		uint32_t m_Height;
		std::string m_Name;

		DefWindow(uint32_t width = 720, uint32_t height = 720, std::string name = "Vulkan Abstract Renderer")
			: m_Width(width), m_Height(height), m_Name(name) {}
	};

	class WindowMP
	{
	public:
		WindowMP();
		void createWindow();
		void createSurface(VkInstance& targetInstance);
		void Run();

		~WindowMP();

		inline GLFWwindow* getGlfwWindow() { return m_GlfwWindow; }
		inline VkSurfaceKHR getSurface() { return m_surface; }
		inline bool getStatus() { return isRunning; }

	private:
		DefWindow m_window = {};
		GLFWwindow* m_GlfwWindow = nullptr;
		VkSurfaceKHR m_surface = VK_NULL_HANDLE;
		bool isRunning = false;
		VkInstance* m_instanceAdress = nullptr;
	};
}