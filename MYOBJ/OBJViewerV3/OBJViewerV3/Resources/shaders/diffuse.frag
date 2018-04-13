#version 430 core

vec3 lightdir;

in vec3 worldpos;
in vec3 worldnormal;

out vec4 fColor;

void main()
{
    lightdir = normalize(vec3(-1,-1,-1));
    vec3 L = -lightdir;
    vec3 N = normalize(worldnormal);
    fColor = dot(L,N)*vec4(1,1,1,1);
}