
#include "Mesh.hpp"
#include <string>
#include <iostream>
Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices){
    _vertices = vertices;
    _indices = indices;
    
    std::cout << &vertices[0] << std::endl;
    std::cout << &vertices << std::endl;
    _vertexBuffer = new VertexBuffer(sizeof(Vertex) * vertices.size(), &vertices[0]);
    _indexBuffer = new IndexBuffer(sizeof(unsigned int) * indices.size(), &indices[0]);
}

void Mesh::Draw(){
    glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(_indices.size()), GL_UNSIGNED_INT, 0);
}
