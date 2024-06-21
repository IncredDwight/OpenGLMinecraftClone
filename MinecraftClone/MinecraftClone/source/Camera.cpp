
#include "Camera.hpp"
#include <string>
#include <iostream>

Camera::Camera(glm::vec3 position, float fov, Shader& shader){
    Position = position;
    
    glm::mat4 projection = glm::perspective(glm::radians(fov), RATIO, NEAR_PLANE, FAR_PLANE);
    
    shader.SetUniformMat4f("u_projection", projection);
}

void Camera::Update(Shader& shader){
    glm::mat4 view = glm::lookAt(Position, Position + Orientation, UP_DIRECTION);
    
    //std::cout << (Position + _orientation).x <<" "<< (Position + _orientation).y <<" "<< (Position + _orientation).z << std::endl;
    
    shader.SetUniformMat4f("u_view", view);
}
