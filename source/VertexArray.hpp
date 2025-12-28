
#ifndef VertexArray_hpp
#define VertexArray_hpp

#include <stdio.h>
#include <vector>
#include "VertexLayout.hpp"

class VertexArray{
private:
    unsigned int _id;
    unsigned int _stride;
    std::vector<VertexLayout> _layouts;
    
public:
    VertexArray(unsigned int stride);
    void Bind();
    void UnBind();
    void AddLayout(VertexLayout vertexLayout);
    void LoadLayouts();
    
};

#endif
