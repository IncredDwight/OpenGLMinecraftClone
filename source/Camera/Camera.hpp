
#ifndef Camera_hpp
#define Camera_hpp

#include <stdio.h>
#include "Shader.hpp"
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"

class Camera{
private:
    const float RATIO = 800.0f / 600.0f;
    const float NEAR_PLANE = 0.1f;
    const float FAR_PLANE = 150.0f;
    const glm::vec3 UP_DIRECTION = glm::vec3(0, 1, 0);

public:
    glm::vec3 Position;
    glm::vec3 Orientation = glm::vec3(0, 0, -1);
    
    Camera(glm::vec3 position, float fov, Shader& shader);
    
    void SetOrientation(glm::vec3 orientation);
    void Update(Shader& shader);
};
#endif
