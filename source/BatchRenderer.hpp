//
//  BatchRenderer.hpp
//  MinecraftClone
//
//  Created by Yaroslav Valchyshen on 6/21/24.
//

#ifndef BatchRenderer_hpp
#define BatchRenderer_hpp

#include <stdio.h>
#include <vector>
#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"

class BatchRenderer{
private:
    static VertexBuffer* _vertexBuffer;
    static IndexBuffer* _indexBuffer;
    static Vertex* _vertices;
    static Vertex* _vertexPointer;
    

public:
    static void Init();
    static void Draw(glm::vec3 worldPosition, std::vector<Vertex>& verticies);
    static void Update();
};


#endif
