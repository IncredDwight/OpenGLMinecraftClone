//#define GL_SILENCE_DEPRECATION
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.hpp"
#include "VertexBuffer.hpp"
#include "VertexArray.hpp"
#include "IndexBuffer.hpp"
#include "Camera.hpp"
#include "Mesh.hpp"
#include "Rectangle.hpp"
#include "Cube.hpp"
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
    glEnable(GL_DEPTH_TEST);
    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
    
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glViewport(0, 0, screenWidth, screenHeight);
    glewInit();
    
    VertexArray vertexArray(7 * sizeof(float));
    
    std::string shaderFilePath = "/Users/yaroslavvalchyshen/Desktop/Programming/GitHub/OpenGLMinecraftClone/MinecraftClone/MinecraftClone/resources/Shaders/Basic.shader";
    
    Shader shader(shaderFilePath);
    //Rectangle rectangle(glm::vec3(-0.5f, 0.0f, 0.0f));
    //Rectangle rectangle1(glm::vec3(0.5f, 0.0f, 0.0f));
    Cube cube(glm::vec3(-1.0f, 0.0f, -3.0f), glm::vec4(0.1f, 0.4f, 0.8f, 1.0f));
    Cube cube1(glm::vec3(2.0f, 0.0f, -3.0f), glm::vec4(0.65f, 0.5f, 0.5f, 1.0f));
    VertexLayout layout0(0, 3, GL_FLOAT, 0);
    VertexLayout layout1(1, 4, GL_FLOAT, 3 * sizeof(float));
    vertexArray.AddLayout(layout0);
    vertexArray.AddLayout(layout1);
    
    
    glm::mat4 model = glm::mat4(1.0f);
    glm::vec3 position = glm::vec3(0, 0, 1.5f);
    Camera camera(position, 45.0f, shader);
    
    shader.SetUniformMat4f("u_model", model);
    
    float rotation = 0;
    
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        rotation += 1;
        camera.Update(shader);
        camera.Position.z += 0.0025f;
        
        glClear(GL_COLOR_BUFFER_BIT);
   
        cube.Update(shader);
        vertexArray.LoadLayouts();
        cube1.Update(shader);
        vertexArray.LoadLayouts();
        

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
