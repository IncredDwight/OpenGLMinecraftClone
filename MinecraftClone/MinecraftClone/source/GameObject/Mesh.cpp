
#include "Mesh.hpp"
#include <string>
#include <iostream>
Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices){
    _vertices = vertices;
    _indices = indices;
    
    
    _vertexBuffer = new VertexBuffer(sizeof(Vertex) * vertices.size(), &vertices[0]);
    _indexBuffer = new IndexBuffer(sizeof(unsigned int) * indices.size(), &indices[0]);
}

void Mesh::Draw(){
    _vertexBuffer->Bind();
    
    glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(_indices.size()), GL_UNSIGNED_INT, 0);
    //glDrawArrays(GL_TRIANGLES, 0, 21);
}
