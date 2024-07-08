
#include "MouseInput.hpp"

float MouseInput::_screenCenterX = 800 / 2;
float MouseInput::_screenCenterY = 600 / 2;
float MouseInput::Pitch = 0;
float MouseInput::Yaw = 0;

void MouseInput::GetInput(GLFWwindow* window, double xpos, double ypos){
    float xOffset = xpos - _screenCenterX;
    float yOffset = _screenCenterY - ypos;
    
    xOffset *= SENSITIVITY;
    yOffset *= SENSITIVITY;
    
    Pitch += xOffset;
    Yaw += yOffset;
    
    if(Yaw >= 0)
        Yaw = -1;
    else if(Yaw <= -180)
        Yaw = -179;
    
    int width, height;
    glfwGetWindowSize(window, &width, &height);
    glfwSetCursorPos(window, _screenCenterX, _screenCenterY);
    
}
