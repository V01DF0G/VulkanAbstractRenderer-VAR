#pragma once
#include "glm/glm.hpp"
#include "VertexInputs/VertexInputBase.h"

struct Vertex : VertexInputBase
{
	glm::vec2 pos;
	glm::vec3 col;

	uint32_t getSizeOfObject() override { return sizeof(Vertex); }

	VkVertexInputBindingDescription getBindingDescription(uint32_t bindingPos) override
	{
		size_t a = sizeof(VertexInputBase);
		size_t b = sizeof(Vertex);

		VkVertexInputBindingDescription bindingDescription{};
		bindingDescription.binding = 0;
		bindingDescription.stride = sizeof(Vertex);
		bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;
		return bindingDescription;
	}

	std::vector<VkVertexInputAttributeDescription> getAttributeDescription(uint32_t bindingPos) override
	{
		std::vector< VkVertexInputAttributeDescription> temparray;
		VkVertexInputAttributeDescription temp;
		
		//vec2 pos;
		temp.binding = 0;
		temp.location = 0;
		temp.format = VK_FORMAT_R32G32_SFLOAT;
		temp.offset = offsetof(Vertex, pos);
		
		temparray.push_back(temp);

		//vec3 col;
		temp.binding = 0;
		temp.location = 1;
		temp.format = VK_FORMAT_R32G32B32_SFLOAT;
		temp.offset = offsetof(Vertex, col);

		temparray.push_back(temp);

		int x = 0;
		return temparray;

	}
};
