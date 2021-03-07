#include "Renderer.h"
#include "Logger.h"

namespace VAR_CORE
{
	namespace VAR_SIMPLE_RENDERER
	{

		Renderer::Renderer()
		{
			Log::init();
		}

		void Renderer::AllocateRendererObjects()
		{

			m_instance = std::make_shared<Instance>();
			m_window = std::make_shared<WindowMP>();
			m_physicalDevice = std::make_shared<PhysicalDevices>(m_instance, m_window);
			m_LogicalDevice = std::make_shared<LogicalDevice>(m_instance, m_physicalDevice);
			m_Swapchain = std::make_shared<SwapChain>(m_LogicalDevice, m_physicalDevice, m_window);
			m_ImageViews = std::make_shared<ImageViews>(m_LogicalDevice, m_Swapchain);
			m_PipelineLayout = std::make_shared<PipelineLayout>(m_LogicalDevice);
			m_RenderPass = std::make_shared<RenderPass>(m_LogicalDevice, m_Swapchain);
			m_ShaderModules = std::make_shared<ShaderModules>(m_LogicalDevice, ShaderLocs);
			m_GraphicsPipeline = std::make_shared<GraphicsPipeline>(m_LogicalDevice, m_PipelineLayout, m_RenderPass, m_ShaderModules);
			m_FrameBufferPool = std::make_shared<FrameBufferPool>(m_LogicalDevice, m_RenderPass, m_ImageViews);
			m_CommandBufferPool = std::make_shared<CommandBufferPool>(m_LogicalDevice, m_physicalDevice, m_RenderPass, m_FrameBufferPool, m_GraphicsPipeline);
			m_GraphicsThreadPool = std::make_shared<GraphicsThreadPool>(m_LogicalDevice);
			m_FrameDrawer = std::make_shared<FrameDrawer>(m_LogicalDevice, m_Swapchain, m_CommandBufferPool, m_GraphicsThreadPool);
		}

		void Renderer::Init()
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

	}
}