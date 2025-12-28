
#ifndef Mesh_hpp
#define Mesh_hpp

#include <stdio.h>
#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"
#include "Texture.hpp"
#include <vector>

class Mesh{
private:
    std::vector<Vertex> _vertices;
    std::vector<unsigned int> _indices;
    //Texture* _texture;
    
    VertexBuffer* _vertexBuffer;
    IndexBuffer* _indexBuffer;
    
public:
    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, const std::string& textureFileName);
    void Draw();
    
};

#endif
