
#include "CameraMovement.hpp"

CameraMovement::CameraMovement(float speed, GLFWwindow* window, Camera* camera){
    _speed = speed;
    this->_window = window;
    this->_camera = camera;
}

void CameraMovement::MoveRight(){
    if(glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS)
        //glm::vec3 rightDirection = glm::normalize(glm::cross(_camera->Orientation))
        _camera->Position += glm::cross(_camera->Orientation, glm::vec3(0, 1, 0)) * _speed;
    
}

void CameraMovement::MoveLeft(){
    if(glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS)
        _camera->Position += -glm::cross(_camera->Orientation, glm::vec3(0, 1, 0)) * _speed;
}

void CameraMovement::MoveForward(){
    if(glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS)
        _camera->Position += _camera->Orientation * _speed;
}

void CameraMovement::MoveBackwards(){
    if(glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS)
        _camera->Position += -_camera->Orientation * _speed;
}

