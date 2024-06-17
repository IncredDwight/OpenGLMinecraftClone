
#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include "Mesh.hpp"
#include "Shader.hpp"
#include <vector>
#include "../glm/glm.hpp"

class GameObject{
    
protected:
    std::vector<Vertex> _verticies;
    std::vector<unsigned int> _indices;
    
    glm::mat4 _model;
    Mesh* _mesh;
    
public:
    glm::vec3 Position;
    
    GameObject(glm::vec3 position);
    virtual void Update(Shader& shader);
};

#endif
