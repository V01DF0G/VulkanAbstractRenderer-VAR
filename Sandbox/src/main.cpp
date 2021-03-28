#include "Renderer/Renderer.h"
#include "glm/glm.hpp"


int main()
{
	std::vector<const char*> shaderList = { "./src/Shaders/Compiled/Vertex/test.vert.spv", "./src/Shaders/Compiled/Fragment/test.frag.spv" };
	VAR_CORE::VAR_SIMPLE_RENDERER::Renderer a;
	a.setShaderLocs(shaderList);
	a.AllocateRendererObjects();
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