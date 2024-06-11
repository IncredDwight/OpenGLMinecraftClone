//#define GL_SILENCE_DEPRECATION
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.hpp"
#include "VertexBuffer.hpp"
#include "VertexArray.hpp"
#include "IndexBuffer.hpp"
#include <string>
#include <iostream>


int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1400, 600, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    
    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
    
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glViewport(0, 0, screenWidth, screenHeight);
    glewInit();
    
    float vertices[] = {
        0.0f,  0.0f, 0.0f, 0.0f, 0.5f, 0.5f, 1.0f,
        0.5f,  0.5f, 0.0f, 0.1f, 1.0f, 0.5f, 1.0f,
        0.5f,  0.0f, 0.0f, 0.1f, 0.5f, 0.5f, 1.0f,
        0.0f,  0.5f, 0.0f, 0.1f, 0.5f, 0.5f, 1.0f
    };
    
    unsigned int indicies[] = {
        0, 1, 2,
        0, 1, 3
    };
    
    VertexBuffer vertexBuffer(sizeof(vertices), vertices);
    VertexArray vertexArray(7 * sizeof(float));
    
    IndexBuffer indexBuffer(sizeof(indicies), indicies);
    
    VertexLayout layout0(0, 3, GL_FLOAT, 0);
    VertexLayout layout1(1, 4, GL_FLOAT, 3 * sizeof(float));
    vertexArray.AddLayout(layout0);
    vertexArray.AddLayout(layout1);
    
    std::string shaderFilePath = "/Users/yaroslavvalchyshen/Desktop/Programming/GitHub/OpenGLMinecraftClone/MinecraftClone/MinecraftClone/resources/Shaders/Basic.shader";
    
    Shader shader(shaderFilePath);
    
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);
        glfwSwapBuffers(window);
        

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
