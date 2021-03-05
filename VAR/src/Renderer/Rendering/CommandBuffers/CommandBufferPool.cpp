#include "CommandBufferPool.h"
#include "Logger.h"



CommandBufferPool::CommandBufferPool(std::shared_ptr<LogicalDevice> TargetedDevice, std::shared_ptr<PhysicalDevices> TargetedPhysDevs, std::shared_ptr<RenderPass> TargetedRenderPass, std::shared_ptr<FrameBufferPool> TargetedFrameBuffer, std::shared_ptr<GraphicsPipeline> TargetedGraphicsPipeline)
	:m_TargetDevice(TargetedDevice), m_TargetPhysicalDevice(TargetedPhysDevs), m_TargetRenderPass(TargetedRenderPass), m_TargetFrameBufferPool(TargetedFrameBuffer), m_TargetGraphicsPipeline(TargetedGraphicsPipeline)
{
	m_CommandPoolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
	m_CommandBufferAllocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
	m_commandBufferBeginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
	m_TargetedRenderPassBeginInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
}

CommandBufferPool::~CommandBufferPool()
{
	vkDestroyCommandPool(m_TargetDevice->GetVkLogicalDevice(), m_CommandPool, nullptr);
}

void CommandBufferPool::createCommandPool()
{
	m_CommandPoolInfo.queueFamilyIndex = m_TargetPhysicalDevice->getFamilyIndices().graphicsFamily;
	m_CommandPoolInfo.flags = 0;

	if (vkCreateCommandPool(m_TargetDevice->GetVkLogicalDevice(), &m_CommandPoolInfo, nullptr, &m_CommandPool) != VK_SUCCESS)
	{
		RENDER_LOG_CRIT("Failed to create command pool!");
	}
	else
	{
		RENDER_LOG_INFO("Succesfully created command pool!");
	}
}

void CommandBufferPool::createCommandBuffers()
{
	m_CommandBuffers.resize(m_TargetFrameBufferPool->getFrameBuffers().size());
	m_CommandBufferAllocInfo.commandPool = m_CommandPool;
	m_CommandBufferAllocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
	m_CommandBufferAllocInfo.commandBufferCount = m_CommandBuffers.size(); // uin32_t castas

	if (vkAllocateCommandBuffers(m_TargetDevice->GetVkLogicalDevice(), &m_CommandBufferAllocInfo, m_CommandBuffers.data()) != VK_SUCCESS)
	{
		RENDER_LOG_CRIT("Failed to allocate command buffers!");
	}
	else
	{
		RENDER_LOG_INFO("Succesfully allocated command buffers!");
	}
}

void CommandBufferPool::startCommandBufferRecord()
{
	for (VkCommandBuffer& combuffer : m_CommandBuffers)
	{
		m_commandBufferBeginInfo.flags = 0; // Parameter
		m_commandBufferBeginInfo.pInheritanceInfo = nullptr; //Parameter

		if (vkBeginCommandBuffer(combuffer, &m_commandBufferBeginInfo) != VK_SUCCESS)
		{
			RENDER_LOG_CRIT("Failed to begin recording of the command buffer !");
		}
		else
		{
			RENDER_LOG_INFO("Succesfully started recording the command buffer !");
		}
	}
}

void CommandBufferPool::startTargetedRenderPass()
{
	m_TargetedRenderPassBeginInfo.renderPass = m_TargetRenderPass->getvkRenderPass();
	m_TargetedRenderPassBeginInfo.renderArea.offset = { 0 , 0 };
	m_TargetedRenderPassBeginInfo.renderArea.extent = m_TargetRenderPass->getTargetedSwapchain()->getcurrentSwapchainExtent();
	VkClearValue clearColor = { 0.0f, 0.0f, 0.0f, 1.0f };
	m_TargetedRenderPassBeginInfo.clearValueCount = 1;
	m_TargetedRenderPassBeginInfo.pClearValues = &clearColor;
	for (size_t i = 0; i < m_CommandBuffers.size(); i++)
	{
		m_TargetedRenderPassBeginInfo.framebuffer = m_TargetFrameBufferPool->getFrameBuffers()[i];

		vkCmdBeginRenderPass(m_CommandBuffers[i], &m_TargetedRenderPassBeginInfo, VK_SUBPASS_CONTENTS_INLINE);

		vkCmdBindPipeline(m_CommandBuffers[i], VK_PIPELINE_BIND_POINT_GRAPHICS, m_TargetGraphicsPipeline->getvkPipeline());

		vkCmdDraw(m_CommandBuffers[i], 3, 1, 0, 0);

		vkCmdEndRenderPass(m_CommandBuffers[i]);

		if (vkEndCommandBuffer(m_CommandBuffers[i]) != VK_SUCCESS)
		{
			RENDER_LOG_CRIT("Failed to record command buffer");
		}
		else
		{
			RENDER_LOG_INFO("Succesfully recorded command buffer");
		}

	}
	
}

