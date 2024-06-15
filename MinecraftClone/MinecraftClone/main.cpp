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
    
    glm::mat4 model = glm::mat4(1.0f);
    glm::vec3 position = glm::vec3(0, 0, 1.5f);
    glm::vec3 direction = glm::vec3(0, 0, -1.0f);
    glm::mat4 view = glm::lookAt(position, position + direction, glm::vec3(0, 1, 0));
    
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    
    shader.SetUniformMat4f("u_model", model);
    shader.SetUniformMat4f("u_view", view);
    shader.SetUniformMat4f("u_projection", projection);
    
    
    float rotation = 0;
    
    while (!glfwWindowShouldClose(window))
    {
        model = glm::rotate(model, glm::radians(0.25f), glm::vec3(1, 1, 1));
        shader.SetUniformMat4f("u_model", model);
        rotation += 1;
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawElements(GL_TRIANGLES, sizeof(indicies) / sizeof(float), GL_UNSIGNED_INT, (void*)0);
        glfwSwapBuffers(window);
        

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
