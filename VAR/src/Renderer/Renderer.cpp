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
	RENDER_LOG_INFO(std::string("DriverVersion: ") + std::to_string(m_physicalDevice->getDeviceProps().vendorID));
	RENDER_LOG_INFO(std::string("GPU: ") + std::string(m_physicalDevice->getDeviceProps().deviceName));	
	m_Swapchain->PopulateSupportDetails();
	m_LogicalDevice->CreateLogicalDevice();	
	m_Swapchain->ChooseExtSurPreModes();
	m_Swapchain->CreateSwapchain();
	m_ImageViews->CreateImageViews();

	m_window->Run();
	
	while (m_window->getStatus() && !glfwWindowShouldClose(m_window->getGlfwWindow()))
	{
		glfwPollEvents();
	}
}

Renderer::~Renderer()
{
}
