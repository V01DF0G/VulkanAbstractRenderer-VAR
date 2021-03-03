#include "Pch.h"
#include "Renderer.h"
#include "Logger.h"


Renderer::Renderer()
{
	m_window->createWindow(); // Creates Window
	m_instance->createInstance(); // Creates instance 
	m_physicalDevice->checkCompWithVulkan(); // Checks whether the physical device is compatible with vulkan;
	m_window->createSurface(m_instance->getVkInstance()); // Creates surface
	m_physicalDevice->PickBestPhysicalDevice(); // Picks Best physical Device
	RENDER_LOG_INFO("Vulkan API Version: {0}.{1}.{2}", m_instance->getUsedMajorVulkanVersion(), m_instance->getUsedMinorVulkanVersion(), m_instance->getUsedPatchVulkanVersion());
	RENDER_LOG_INFO("GPU: {0}", m_physicalDevice->getDeviceProps().deviceName);	
	m_Swapchain->PopulateSupportDetails();
	m_LogicalDevice->CreateLogicalDevice();	
	m_Swapchain->ChooseExtSurPreModes();
	m_Swapchain->CreateSwapchain();
	m_ImageViews->CreateImageViews();
	m_ShaderModules->createShaderModules();
	m_PipelineLayout->createPipelineLayout();
	m_RenderPass->createRenderPass();
	m_GraphicsPipeline->createGraphicsPipeline();

	m_FrameBufferPool->createFrameBuffers();

	m_CommandBufferPool->createCommandPool();
	m_CommandBufferPool->createCommandBuffers();
	m_CommandBufferPool->startCommandBufferRecord();
	m_CommandBufferPool->startTargetedRenderPass();
	m_GraphicsThreadPool->createSyncThreads(m_ImageViews->getVkImageViews().size());


	m_window->Run();
	
	while (m_window->getStatus() && !glfwWindowShouldClose(m_window->getGlfwWindow()))
	{
		
		m_FrameDrawer->drawFrame();
		glfwPollEvents();
	}

}

Renderer::~Renderer()
{
}
