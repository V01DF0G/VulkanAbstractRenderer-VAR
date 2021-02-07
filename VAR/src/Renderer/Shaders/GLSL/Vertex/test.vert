#version 460 //version 4.5

layout(location = 0) in vec3 positions;
layout(location = 1) in vec3 col;

layout(binding = 0) uniform  UboViewProjection 
{
	mat4 projection;
	mat4 view;

}uboViewProjection;


// Legacy
layout(binding = 1) uniform  UboModel
{
	mat4 model;

}uboModel;

layout(push_constant) uniform Pushmodel
{
	mat4 model;
}pushmodel;

layout(location = 0) out vec3 fragcolour;

void main()
{
	gl_Position = uboViewProjection.projection * uboViewProjection.view * pushmodel.model * vec4(positions,1.0);
	fragcolour = col;
}
