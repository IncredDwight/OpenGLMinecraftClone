
#ifndef Mesh_hpp
#define Mesh_hpp

#include <stdio.h>
#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"
#include <vector>

class Mesh{
private:
    std::vector<Vertex> _vertices;
    std::vector<unsigned int> _indices;
    
    VertexBuffer* _vertexBuffer;
    IndexBuffer* _indexBuffer;
    
public:
    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
    void Draw();
    
};

#endif
