
#include "IndexBuffer.hpp"

IndexBuffer::IndexBuffer(unsigned long size, void* data){
    glGenBuffers(1, &_id);
    Bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer(){
    glDeleteBuffers(1, &_id);
}

void IndexBuffer::Bind(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id);
}

void IndexBuffer::UnBind(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}


