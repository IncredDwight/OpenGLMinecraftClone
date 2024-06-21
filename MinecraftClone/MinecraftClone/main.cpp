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
#include "Texture.hpp"
#include "CameraMovement.hpp"
#include "CameraRotation.hpp"
#include "MouseInput.hpp"
#include <string>
#include <iostream>

static void mouse();

static void mouse(){
   // cameraRotation.GetInput(window);
}

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
    glEnable(GL_DEPTH_TEST);
    
    VertexArray vertexArray(9 * sizeof(float));
    
    std::string shaderFilePath = "/Users/yaroslavvalchyshen/Desktop/Programming/GitHub/OpenGLMinecraftClone/MinecraftClone/MinecraftClone/resources/Shaders/Basic.shader";
    std::string textureFilePath = "/Users/yaroslavvalchyshen/Desktop/Programming/GitHub/OpenGLMinecraftClone/MinecraftClone/MinecraftClone/resources/Textures/TextureMap.png";
    Texture texture(textureFilePath, GL_TEXTURE_2D);
    Shader shader(shaderFilePath);
    CubeTextureCoord grassBlock(glm::vec2(9, 37), glm::vec2(8, 37), glm::vec2(2, 61));
    CubeTextureCoord snowGrassBlock(glm::vec2(4, 57), glm::vec2(2, 57), glm::vec2(2, 61));
    Cube cube(glm::vec3(-1.5f, 0.0f, -3.0f), snowGrassBlock);
    Cube cube1(glm::vec3(1.5f, 0.0f, -3.0f), snowGrassBlock);
    shader.SetUniform1i("sampler", 0);
    VertexLayout layout0(0, 3, GL_FLOAT, 0);
    VertexLayout layout1(1, 4, GL_FLOAT, 3 * sizeof(float));
    VertexLayout layout2(2, 2, GL_FLOAT, 7 * sizeof(float));
    vertexArray.AddLayout(layout0);
    vertexArray.AddLayout(layout1);
    vertexArray.AddLayout(layout2);
    shader.SetUniform1i("sampler", 0);
    
    
    std::vector<Cube> _cubes;
    
    for (int x = 0; x <= 10; x++) {
        for (int z = 0; z <= 10; z++) {
            Cube cube(glm::vec3(x, 0.0f, z), snowGrassBlock);
            _cubes.push_back(cube);
        }
    }
    
    glm::mat4 model = glm::mat4(1.0f);
    glm::vec3 position = glm::vec3(0, 2, 1.5f);
    Camera camera(position, 45.0f, shader);
    
    shader.SetUniformMat4f("u_model", model);
    
    float rotation = 0;
    
    CameraMovement cameraMovement(0.25f, window, &camera);
    CameraRotation cameraRotation(&camera);
    
    glfwSetCursorPosCallback(window, MouseInput::GetInput);
    
    
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        rotation += 1;
        camera.Update(shader);
        
        glClear(GL_COLOR_BUFFER_BIT);
   
        cube.Update(shader);
        vertexArray.LoadLayouts();
        cube1.Update(shader);
        vertexArray.LoadLayouts();
        
        cameraMovement.MoveRight();
        cameraMovement.MoveLeft();
        cameraMovement.MoveForward();
        cameraMovement.MoveBackwards();
        cameraRotation.Rotate();
        
        for (int i = 0; i < _cubes.size(); i++) {
            _cubes[i].Update(shader);
        }

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
