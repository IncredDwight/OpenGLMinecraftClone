
#ifndef CameraMovement_hpp
#define CameraMovement_hpp

#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Camera.hpp"

class CameraMovement{
private:
    float _speed;
    GLFWwindow* _window;
    Camera* _camera;
    
public:
    CameraMovement(float speed, GLFWwindow *window, Camera* camera);
    void MoveLeft();
    void MoveRight();
    void MoveBackwards();
    void MoveForward();
};

#endif
