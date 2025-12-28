
#ifndef CameraRotation_hpp
#define CameraRotation_hpp

#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Camera.hpp"
#include "MouseInput.hpp"

#include <string>
#include <iostream>

class CameraRotation{
private:
    Camera* _camera;
    
    float _yaw;
    float _pitch;
    float _lastX;
    float _lastY;
    float _sentivity = 0.25f;
public:
    CameraRotation(Camera* camera);
    void Rotate();
    
};

#endif /* CameraRotation_hpp */
