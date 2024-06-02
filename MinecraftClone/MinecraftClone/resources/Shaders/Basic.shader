#shader vertex
#version 410 core
 
layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texCoord;

out vec2 texCoord0;

void main()
{
    gl_Position = position
}

#shader fragment
#version 410 core

layout(location = 0) out vec4 color;


void main()
{
    color = color;
}

