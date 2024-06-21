#include "CameraRotation.hpp"

CameraRotation::CameraRotation(Camera* camera){
    _camera = camera;
    
    _lastX = 800 / 2;
    _lastY = 600 / 2;
    _pitch = 0;
    _yaw = 0;
}

void CameraRotation::Rotate(){
    glm::vec3 orientation;
    orientation.x = cos(glm::radians(MouseInput::Pitch)) * sin(glm::radians(MouseInput::Yaw));
    orientation.y = cos(glm::radians(MouseInput::Yaw));
    orientation.z = sin(glm::radians(MouseInput::Pitch)) * sin(glm::radians(MouseInput::Yaw));
    orientation = glm::normalize(orientation);
    
    _camera->Orientation = orientation;
    
}
