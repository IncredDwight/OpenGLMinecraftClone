
#ifndef VertexBuffer_hpp
#define VertexBuffer_hpp

#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"

struct Vertex{
    glm::vec3 Position;
    glm::vec4 Color;
    glm::vec2 TextureCoord;
    
public:
    Vertex(glm::vec3 position, glm::vec4 color){
        Position = position;
        Color = color;
    }
    
    Vertex(glm::vec3 position, glm::vec2 textureCoord){
        Position = position;
        TextureCoord = textureCoord;
    }
    
};

class VertexBuffer{
private:
    unsigned int _id;
public:
    VertexBuffer(unsigned long size, void* data);
    ~VertexBuffer();
    void Bind();
    void UnBind();
};

#endif
