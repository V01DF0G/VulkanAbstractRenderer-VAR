#include "Pch.h"
#include "Renderer.h"
#include "Logger.h"


Renderer::Renderer()
{
	m_window->createWindow(); // Creates Window
	m_instance->createInstance(); // Creates instance 
	m_physicalDevice->checkCompWithVulkan(); // Checks whether the physical device is compatible with vulkan;
	m_window->createSurface(m_instance->getVkInstance()); // Creates surface
	m_physicalDevice->PickBestPhysicalDevice(); // Picks Best physicalDevice
	RENDER_LOG_INFO("Vulkan API Version: {0}.{1}.{2}", m_instance->getUsedMajorVulkanVersion(), m_instance->getUsedMinorVulkanVersion(), m_instance->getUsedPatchVulkanVersion());
	RENDER_LOG_INFO("GPU: {0}", m_physicalDevice->getDeviceProps().deviceName);	
	m_Swapchain->PopulateSupportDetails();
	m_LogicalDevice->CreateLogicalDevice();	
	m_Swapchain->ChooseExtSurPreModes();
	m_Swapchain->CreateSwapchain();
	m_ImageViews->CreateImageViews();

	m_window->Run();

	std::vector<unsigned int> spirv = ShaderCompiler::compileGlslToSvp("VAR/Shaders/GLSL/Vertex/test.vert");
	
	while (m_window->getStatus() && !glfwWindowShouldClose(m_window->getGlfwWindow()))
	{
		glfwPollEvents();
	}
}

Renderer::~Renderer()
{
}
