
#include "VertexBuffer.hpp"

VertexBuffer::VertexBuffer(unsigned long size, void* data){
    glGenBuffers(1, &_id);
    Bind();
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer(){
    glDeleteBuffers(1, &_id);
}

void VertexBuffer::Bind(){
    glBindBuffer(GL_ARRAY_BUFFER, _id);
}

void VertexBuffer::UnBind(){
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
