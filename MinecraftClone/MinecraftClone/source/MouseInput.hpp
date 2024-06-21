
#ifndef MouseInput_hpp
#define MouseInput_hpp

#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class MouseInput{
private:
    static float _screenCenterX;
    static float _screenCenterY;
    static constexpr float SENSITIVITY = 0.1f;
    
public:
    static float Pitch;
    static float Yaw;
    static void GetInput(GLFWwindow *window, double xpos, double ypos);
};

#endif
