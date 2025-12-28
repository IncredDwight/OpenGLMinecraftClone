#shader vertex
#version 410 core

 
layout(location = 0) in vec3 position;
layout(location = 1) in vec4 color;
layout(location = 2) in vec2 textureCoord;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

out vec4 vertexColor;
out vec2 vertexTextureCoord;

void main()
{
    gl_Position = u_projection * u_view * u_model * vec4(position, 1);
    vertexColor = color;
    vertexTextureCoord = textureCoord;
}

#shader fragment
#version 410 core

in vec4 vertexColor;
in vec2 vertexTextureCoord;

out vec4 color;
uniform sampler2D sampler;

void main()
{
    vec4 textureColor = texture(sampler, vertexTextureCoord);
    color = textureColor;
}

