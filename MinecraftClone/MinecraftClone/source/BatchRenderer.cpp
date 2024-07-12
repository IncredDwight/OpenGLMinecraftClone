
#include "BatchRenderer.hpp"
#include <iostream>
#include <string>

static size_t CubeCount = 200;
static size_t VertexCubeCount = CubeCount * 21;
static size_t MaxIndicesCubeCount = CubeCount * 36;
static uint32_t IndexCount;

Vertex* BatchRenderer::_vertices;
Vertex* BatchRenderer::_vertexPointer;
VertexBuffer* BatchRenderer::_vertexBuffer;
IndexBuffer* BatchRenderer::_indexBuffer;

void BatchRenderer::Init(){
    _vertices = new Vertex[VertexCubeCount];
    _vertexPointer = _vertices;
    
    _vertexBuffer = new VertexBuffer(sizeof(Vertex) * VertexCubeCount, _vertices);
    
    uint32_t indicies[MaxIndicesCubeCount];
    uint32_t offset = 0;
    for (int i = 0; i < MaxIndicesCubeCount; i += 36) {
        //Front Face
                indicies[i + 0] = 0 + offset;
                indicies[i + 1] = 1 + offset;
                indicies[i + 2] = 2 + offset;
                indicies[i + 3] = 2 + offset;
                indicies[i + 4] = 3 + offset;
                indicies[i + 5] = 0 + offset;
                
                //Back face
                indicies[i + 6] = 4 + offset;
                indicies[i + 7] = 5 + offset;
                indicies[i + 8] = 6 + offset;
                indicies[i + 9] = 6 + offset;
                indicies[i + 10] = 7 + offset;
                indicies[i + 11] = 4 + offset;
                
                //Left face
                indicies[i + 12] = 0 + offset;
                indicies[i + 13] = 8 + offset;
                indicies[i + 14] = 9 + offset;
                indicies[i + 15] = 9 + offset;
                indicies[i + 16] = 10 + offset;
                indicies[i + 17] = 0 + offset;
                
                //Right face
                indicies[i + 18] = 1 + offset;
                indicies[i + 19] = 2 + offset;
                indicies[i + 20] = 11 + offset;
                indicies[i + 21] = 11 + offset;
                indicies[i + 22] = 12 + offset;
                indicies[i + 23] = 1 + offset;
                
                //Bottom face
                indicies[i + 24] = 17 + offset;
                indicies[i + 25] = 18 + offset;
                indicies[i + 26] = 19 + offset;
                indicies[i + 27] = 19 + offset;
                indicies[i + 28] = 20 + offset;
                indicies[i + 29] = 17 + offset;
                
                //Top face
                indicies[i + 30] = 13 + offset;
                indicies[i + 31] = 14 + offset;
                indicies[i + 32] = 15 + offset;
                indicies[i + 33] = 15 + offset;
                indicies[i + 34] = 16 + offset;
                indicies[i + 35] = 13 + offset;

                offset += 21;
    }
    _indexBuffer = new IndexBuffer(sizeof(indicies), indicies);
}

void BatchRenderer::Draw(glm::vec3 worldPosition, std::vector<Vertex>& verticies){
    if(IndexCount >= MaxIndicesCubeCount)
    {
        //_vertexBuffer->Bind();
        GLsizeiptr size = (uint8_t*)_vertexPointer - (uint8_t*)_vertices;
        glBufferSubData(GL_ARRAY_BUFFER, 0, size, _vertices);
        glDrawElements(GL_TRIANGLES, IndexCount, GL_UNSIGNED_INT, nullptr);
        IndexCount = 0;
        _vertexPointer = _vertices;
    }
    
    for (int i = 0; i < verticies.size(); i++) {
        _vertexPointer->Position = verticies[i].Position + glm::vec3(2 * worldPosition.x, 2 * worldPosition.y, 2 * worldPosition.z);
        _vertexPointer->TextureCoord = verticies[i].TextureCoord;
        _vertexPointer++;
    }
    IndexCount += 36;
}
