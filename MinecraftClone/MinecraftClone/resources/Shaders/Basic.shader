#shader vertex
#version 410 core

 
layout(location = 0) in vec3 position;
layout(location = 1) in vec4 color;

out vec4 vertexColor;

void main()
{
    gl_Position = vec4(position.x, position.y, position.z, 1);
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

