#pragma once

#include "Pch.h"
#include "VulkanBase.h"
#include "Instance.h"
#include "PhysicalDevice.h"
#include "LogicalDevice.h"
#include "WindowMultiPlatform.h"
#include "Swapchain/SwapChain.h"
#include "ImageViews/ImageViews.h"
#include "ShaderModules/ShaderModules.h"
#include "PipelineLayout/PipelineLayout.h"
#include "RenderPass/RenderPass.h"
#include "GraphicsPipeline/GraphicsPipeline.h"
#include "Rendering/FrameBuffers/FrameBufferPool.h"
#include "Rendering/CommandBuffers/CommandBufferPool.h"
#include "Rendering/MultiThreading/GraphicsThreadPool.h"
#include "Rendering/FrameDrawer.h"

class Renderer
{
public:
	Renderer();

	 ~Renderer();

private:
	std::vector<const char*> ShaderLocs = { "./src/Shaders/Compiled/Vertex/test.vert.spv", "./src/Shaders/Compiled/Fragment/test.frag.spv" };
	std::shared_ptr<Instance> m_instance = std::make_shared<Instance>();
	std::shared_ptr<WindowMP> m_window = std::make_shared<WindowMP>();
	std::shared_ptr<PhysicalDevices> m_physicalDevice = std::make_shared<PhysicalDevices>(m_instance, m_window);
	std::shared_ptr<LogicalDevice> m_LogicalDevice = std::make_shared<LogicalDevice>(m_instance, m_physicalDevice);
	std::shared_ptr<SwapChain> m_Swapchain = std::make_shared<SwapChain>(m_LogicalDevice, m_physicalDevice, m_window);
	std::shared_ptr<ImageViews> m_ImageViews = std::make_shared<ImageViews>(m_LogicalDevice, m_Swapchain);
	std::shared_ptr<PipelineLayout> m_PipelineLayout = std::make_shared<PipelineLayout>(m_LogicalDevice);
	std::shared_ptr<RenderPass> m_RenderPass = std::make_shared<RenderPass>(m_LogicalDevice, m_Swapchain);
	std::shared_ptr<ShaderModules> m_ShaderModules = std::make_shared<ShaderModules>(m_LogicalDevice, ShaderLocs);
	std::shared_ptr<GraphicsPipeline> m_GraphicsPipeline = std::make_shared<GraphicsPipeline>(m_LogicalDevice, m_PipelineLayout, m_RenderPass, m_ShaderModules);
	std::shared_ptr<FrameBufferPool> m_FrameBufferPool = std::make_shared<FrameBufferPool>(m_LogicalDevice, m_RenderPass, m_ImageViews);
	std::shared_ptr<CommandBufferPool> m_CommandBufferPool = std::make_shared<CommandBufferPool>(m_LogicalDevice, m_physicalDevice, m_RenderPass, m_FrameBufferPool, m_GraphicsPipeline);
	std::shared_ptr<GraphicsThreadPool> m_GraphicsThreadPool = std::make_shared<GraphicsThreadPool>(m_LogicalDevice);
	std::shared_ptr<FrameDrawer> m_FrameDrawer = std::make_shared<FrameDrawer>(m_LogicalDevice, m_Swapchain, m_CommandBufferPool, m_GraphicsThreadPool);
};