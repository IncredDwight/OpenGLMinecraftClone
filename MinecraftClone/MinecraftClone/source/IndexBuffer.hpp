
#ifndef IndexBuffer_hpp
#define IndexBuffer_hpp

#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class IndexBuffer{
public:
    IndexBuffer(unsigned long size, void* data);
    ~IndexBuffer();

private:
    unsigned int _id;
    
    void Bind();
    void UnBind();
};

#endif
