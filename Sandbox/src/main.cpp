#include "Renderer/Renderer.h"
#include "glm/glm.hpp"
#include "Vertex/Vertex.h"


int main()
{
	std::vector<Vertex> vertices;
	Vertex temp;
	temp.pos = { 0.0f, -0.5f };
	temp.col = { 1.0f, 0.0f, 0.0f };

	vertices.emplace_back(temp);

	temp.pos = { 0.5f, 0.5f };
	temp.col = { 1.0f, 1.0f, 1.0f };

	vertices.emplace_back(temp);

	temp.pos = { -0.5f, 0.5f };
	temp.col = { 0.0f, 0.0f, 1.0f };

	vertices.emplace_back(temp);

	std::vector<VertexInputBase*> generalizedVertices;
	generalizedVertices.reserve(vertices.size());
	for (int i = 0; i < vertices.size(); i++)
	{
		generalizedVertices.emplace_back(&vertices[i]);

	}

	std::vector<const char*> shaderList = { "./src/Shaders/Compiled/Vertex/test.vert.spv", "./src/Shaders/Compiled/Fragment/test.frag.spv" };
	VAR_CORE::VAR_SIMPLE_RENDERER::Renderer a;
	a.setShaderLocs(shaderList);
	
	a.AllocateRendererObjects();
	a.setupPipelineforInput(generalizedVertices);
	a.Init();

	glm::vec2 abs = { 0.5, 0.1 };

	int aasd = 5;

	while (a.isRendererRunning())
	{
		a.rendererDrawFrame();
		a.rendererPollEvents();
	}

	return 0;
}