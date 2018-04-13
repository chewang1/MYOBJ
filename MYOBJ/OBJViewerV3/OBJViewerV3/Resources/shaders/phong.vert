#version 430 core

uniform mat4 MVP;
uniform mat4 ModelViewMatrix;
uniform mat4 modelMatrix;

layout(location = 0) in vec3 vertex;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 uv;
layout(location = 3) in vec4 color;

out vec2 v_texcoord;		//uv
out vec4 v_color;			//color
out vec3 worldpos;			//pos vector
out vec3 worldnormal;		//normal vector
out vec3 view;				//view vector
void main()
{
    worldpos = (ModelViewMatrix * vec4(vertex, 1)).xyz;
    worldnormal = (modelMatrix * vec4(normal, 0)).xyz;
	view = -worldpos;
    // Calculate vertex position in screen space
    gl_Position = MVP * vec4(vertex,1);

    v_texcoord = uv;
	v_color = color;
}
