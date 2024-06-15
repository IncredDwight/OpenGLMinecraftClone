#shader vertex
#version 410 core

 
layout(location = 0) in vec3 position;
layout(location = 1) in vec4 color;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

out vec4 vertexColor;

void main()
{
    gl_Position = u_projection * u_view * u_model * vec4(position, 1);
    vertexColor = color;
}

#shader fragment
#version 410 core

in vec4 vertexColor;
out vec4 color;

void main()
{
    color = vertexColor;
}

