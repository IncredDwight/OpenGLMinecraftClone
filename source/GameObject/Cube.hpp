
#ifndef Cube_hpp
#define Cube_hpp

#include <stdio.h>
#include <vector>
#include "GameObject.hpp"

struct CubeTextureCoord{
public:
    glm::vec2 sideCoord;
    glm::vec2 topCoord;
    glm::vec2 btmCoord;
    CubeTextureCoord(glm::vec2 sideCoord, glm::vec2 topCoord, glm::vec2 btmCoord){
        this->sideCoord = sideCoord;
        this->topCoord = topCoord;
        this->btmCoord = btmCoord;
    }
    CubeTextureCoord(glm::vec2 sideCoord){
        this->sideCoord = sideCoord;
        this->topCoord = sideCoord;
        this->btmCoord = sideCoord;
    }
};

class Cube : public GameObject{
public:
    Cube(glm::vec3 position, glm::vec4 color);
    Cube(glm::vec3 positiom, CubeTextureCoord textureCoord);
    static std::vector<Vertex> GetVerticies(CubeTextureCoord textureCoord);
};

#endif
