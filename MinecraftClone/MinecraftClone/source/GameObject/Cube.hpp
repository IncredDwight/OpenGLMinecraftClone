
#ifndef Cube_hpp
#define Cube_hpp

#include <stdio.h>
#include "GameObject.hpp"

class Cube : public GameObject{
public:
    Cube(glm::vec3 position, glm::vec4 color);
};

#endif
