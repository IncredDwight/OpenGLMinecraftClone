
#include "VertexArray.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>


VertexArray::VertexArray(unsigned int stride){
    glGenVertexArrays(1, &_id);
    _stride = stride;
    Bind();
}

void VertexArray::Bind(){
    glBindVertexArray(_id);
}

void VertexArray::UnBind(){
    glBindVertexArray(0);
}

void VertexArray::AddLayout(VertexLayout vertexLayout){
    _layouts.push_back(vertexLayout);
    for (int i = 0; i < _layouts.size(); i++) {
        glEnableVertexAttribArray(_layouts[i].GetId());
        glVertexAttribPointer(_layouts[i].GetId(),
                              _layouts[i].GetElementsAmount(),
                              _layouts[i].GetType(),
                              GL_FALSE,
                              _stride,
                              (void*) _layouts[i].GetOffset());
        
    }
}
