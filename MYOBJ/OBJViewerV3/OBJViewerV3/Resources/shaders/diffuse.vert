#version 430 core


layout(location = 0) in vec3 vertex;
layout(location = 1) in vec3 normal;
in vec2 uv;

uniform mat4 MVP;
uniform mat4 ModelViewMatrix;

out vec3 worldpos;
out vec3 worldnormal;

void main()
{
    worldpos = (ModelViewMatrix * vec4(vertex,1)).xyz;
    worldnormal = (ModelViewMatrix * vec4(normal,0)).xyz;
    gl_Position = MVP * vec4(vertex,1);
}
