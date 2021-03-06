#include "PipelineLayout.h"
#include "Logger.h"


namespace VAR_CORE
{
	PipelineLayout::PipelineLayout(std::shared_ptr<LogicalDevice> TargetedDevice)
		: m_TargetDevice(TargetedDevice)
	{
		m_LayoutCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		m_LayoutCreateInfo.setLayoutCount = 0;
		m_LayoutCreateInfo.pSetLayouts = 0;
		m_LayoutCreateInfo.pushConstantRangeCount = 0;
		m_LayoutCreateInfo.pPushConstantRanges = nullptr;
	
		
	}
	
	PipelineLayout::~PipelineLayout()
	{
		vkDestroyPipelineLayout(m_TargetDevice->GetVkLogicalDevice(), m_vkPipelineLayout, nullptr);
	}
	
	void PipelineLayout::createPipelineLayout()
	{
		if (vkCreatePipelineLayout(m_TargetDevice->GetVkLogicalDevice(), &m_LayoutCreateInfo, nullptr, &m_vkPipelineLayout) != VK_SUCCESS)
		{
			RENDER_LOG_CRIT("Failed to create pipeline Layout");
		}
		else
		{
			RENDER_LOG_INFO("Succesfully Created pipeline Layout !");
		}
	}
}
