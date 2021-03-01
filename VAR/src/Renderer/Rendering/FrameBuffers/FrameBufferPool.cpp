#include "FrameBufferPool.h"
#include "Logger.h"


FrameBufferPool::FrameBufferPool(std::shared_ptr<LogicalDevice> TargetedDevice, std::shared_ptr<RenderPass> TargetedRenderPass, std::shared_ptr<ImageViews> TargetedImageViews)
	:m_TargetDevice(TargetedDevice), m_TargetRenderPass(TargetedRenderPass), m_TargetImageViews(TargetedImageViews)
{
	m_FrameBufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
}

FrameBufferPool::~FrameBufferPool()
{
	for (VkFramebuffer &frbuffer : m_FrameBuffers)
	{
		vkDestroyFramebuffer(m_TargetDevice->GetVkLogicalDevice(), frbuffer, nullptr);
	}
}

void FrameBufferPool::createFrameBuffers()
{	
	std::vector<VkImageView> temp = m_TargetImageViews->getVkImageViews();

	m_FrameBufferInfo.renderPass = m_TargetRenderPass->getvkRenderPass();
	m_FrameBufferInfo.attachmentCount = 1;
	m_FrameBufferInfo.width = m_TargetImageViews->getTargetedSwapchain()->getcurrentSwapchainExtent().width;
	m_FrameBufferInfo.height = m_TargetImageViews->getTargetedSwapchain()->getcurrentSwapchainExtent().height;
	m_FrameBufferInfo.layers = 1;

	m_FrameBuffers.resize(temp.size());

	for (size_t i = 0; i < temp.size(); i++)
	{
	m_FrameBufferInfo.pAttachments = &temp[i];
	if (vkCreateFramebuffer(m_TargetDevice->GetVkLogicalDevice(), &m_FrameBufferInfo, nullptr, &m_FrameBuffers[i]) != VK_SUCCESS)
	{
			RENDER_LOG_CRIT("Failed to create framebuffer!");
	}	
	else
	{
			RENDER_LOG_INFO("Succesfully created framebuffer!");
	}
	}

}
