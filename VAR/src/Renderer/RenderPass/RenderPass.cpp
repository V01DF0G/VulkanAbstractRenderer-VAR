#include "RenderPass.h"
#include "Logger.h"



RenderPass::RenderPass(std::shared_ptr<LogicalDevice> TargetedDevice, std::shared_ptr<SwapChain> TargetedSwapchain)
	:m_targetDevice(TargetedDevice), m_targetSwapchain(TargetedSwapchain)
{
	
	m_AttachmentDescription.samples = VK_SAMPLE_COUNT_1_BIT;
	m_AttachmentDescription.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
	m_AttachmentDescription.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
	m_AttachmentDescription.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
	m_AttachmentDescription.finalLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

	m_AttachmentReference.attachment = 0;
	m_AttachmentReference.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

	m_SubpassInfo.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
	m_SubpassInfo.colorAttachmentCount = 1;
	m_SubpassInfo.pColorAttachments = &m_AttachmentReference;

	m_VkRenderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
	m_VkRenderPassInfo.attachmentCount = 1;
	m_VkRenderPassInfo.pAttachments = &m_AttachmentDescription;
	m_VkRenderPassInfo.subpassCount = 1;
	m_VkRenderPassInfo.pSubpasses = &m_SubpassInfo;

}

RenderPass::~RenderPass()
{
	vkDestroyRenderPass(m_targetDevice->GetVkLogicalDevice(), m_VkRenderPass, nullptr);
}

void RenderPass::createRenderPass()
{
	m_AttachmentDescription.format = getTargetedSwapchain()->getcurrentSwapchainImageFormat();

	if (vkCreateRenderPass(m_targetDevice->GetVkLogicalDevice(), &m_VkRenderPassInfo, nullptr, &m_VkRenderPass) != VK_SUCCESS) 
	{
		RENDER_LOG_CRIT("failed to create render pass!");
	}
	else
	{
		RENDER_LOG_INFO("Succesfully Created the render pass!");
	}		

}
