
#ifndef VertexBuffer_hpp
#define VertexBuffer_hpp

#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

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
