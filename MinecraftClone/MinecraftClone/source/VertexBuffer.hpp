
#ifndef VertexBuffer_hpp
#define VertexBuffer_hpp

#include <stdio.h>
#include <iostream>
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
    
    Vertex(){
        Position = glm::vec3(0, 0, 0);
        TextureCoord = glm::vec2(0, 0);
    }
    
    void Display(){
        std::cout << "Position: (" << Position.x << ", " << Position.y << ", " << Position.z << ")" << std::endl;
        std::cout << "TextureCoord: (" << TextureCoord.x << ", " << TextureCoord.y << ")" << std::endl;
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
