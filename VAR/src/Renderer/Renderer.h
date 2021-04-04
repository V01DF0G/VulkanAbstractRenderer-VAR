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
#include "../VertexInputs/VertexInputBase.h"
#include "Rendering/Buffers/VertexBuffer.h"


namespace VAR_CORE
{
	namespace VAR_SIMPLE_RENDERER
	{	

		class Renderer
		{
		public:
			Renderer();
			void Init();
			void AllocateRendererObjects();
			void setShaderLocs(std::vector<const char*> val) { ShaderLocs = val; }
			void setupPipelineforInput(std::vector<VertexInputBase*> Inputs);
			inline bool isRendererRunning() { return m_window->isWindowRunning(); }
			inline void rendererPollEvents() { return glfwPollEvents(); }
			inline void rendererDrawFrame() { return m_FrameDrawer->drawFrame(); }

			~Renderer();

		private:
			std::vector<const char*> ShaderLocs;
			std::shared_ptr<Instance> m_instance = nullptr;
			std::shared_ptr<WindowMP> m_window = nullptr;
			std::shared_ptr<PhysicalDevices> m_physicalDevice = nullptr;
			std::shared_ptr<LogicalDevice> m_LogicalDevice = nullptr;
			std::shared_ptr<SwapChain> m_Swapchain = nullptr;
			std::shared_ptr<ImageViews> m_ImageViews = nullptr;
			std::shared_ptr<PipelineLayout> m_PipelineLayout = nullptr;
			std::shared_ptr<RenderPass> m_RenderPass = nullptr;
			std::shared_ptr<ShaderModules> m_ShaderModules = nullptr;
			std::shared_ptr<GraphicsPipeline> m_GraphicsPipeline = nullptr;
			std::shared_ptr<FrameBufferPool> m_FrameBufferPool = nullptr;
			std::shared_ptr<CommandBufferPool> m_CommandBufferPool = nullptr;
			std::shared_ptr<GraphicsThreadPool> m_GraphicsThreadPool = nullptr;
			std::shared_ptr<FrameDrawer> m_FrameDrawer = nullptr;

			std::vector<VertexInputBase*>* m_VertexInput = nullptr;
			std::shared_ptr<VertexBuffer> m_VertexBuffer = nullptr;
		};
	}
}