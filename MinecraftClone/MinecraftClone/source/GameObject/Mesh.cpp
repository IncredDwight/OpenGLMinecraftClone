
#include "Mesh.hpp"
#include <string>
#include <iostream>
Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, const std::string& fileName){
    _vertices = vertices;
    _indices = indices;
    
    _vertexBuffer = new VertexBuffer(sizeof(Vertex) * vertices.size(), &vertices[0]);
    _indexBuffer = new IndexBuffer(sizeof(unsigned int) * indices.size(), &indices[0]);
    _texture = new Texture(fileName, GL_TEXTURE_2D);
}

void Mesh::Draw(){
    _vertexBuffer->Bind();
    
    glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(_indices.size()), GL_UNSIGNED_INT, 0);
}
