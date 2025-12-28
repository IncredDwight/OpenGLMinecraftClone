//#define GL_SILENCE_DEPRECATION
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.hpp"
#include "VertexBuffer.hpp"
#include "VertexArray.hpp"
#include "IndexBuffer.hpp"
#include "Camera/Camera.hpp"
#include "GameObject/Mesh.hpp"
#include "GameObject/Rectangle.hpp"
#include "GameObject/Cube.hpp"
#include "Texture.hpp"
#include "Camera/CameraMovement.hpp"
#include "Camera/CameraRotation.hpp"
#include "Camera/MouseInput.hpp"
#include "BatchRenderer.hpp"
#include "SimplexNoise.h"
#include <string>
#include <iostream>
#include <filesystem>

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
    
    std::string shaderFilePath = "resources/Shaders/Basic.shader";
    std::string textureFilePath = "resources/Textures/TextureMap.png";
    Texture texture(textureFilePath, GL_TEXTURE_2D);
    Shader shader(shaderFilePath);
    CubeTextureCoord grassBlock(glm::vec2(9, 37), glm::vec2(8, 37), glm::vec2(2, 61));
    CubeTextureCoord snowGrassBlock(glm::vec2(4, 57), glm::vec2(2, 57), glm::vec2(2, 61));
    
    CubeTextureCoord dirtBlock(glm::vec2(2, 61), glm::vec2(2, 61), glm::vec2(2, 61));
    CubeTextureCoord stoneBlock(glm::vec2(1, 61), glm::vec2(1, 61), glm::vec2(1, 61));
    
    Cube cube(glm::vec3(-1.5f, 0.0f, -3.0f), snowGrassBlock);
    //Cube cube1(glm::vec3(1.5f, 0.0f, -3.0f), snowGrassBlock);
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
    
    CameraMovement cameraMovement(2, window, &camera);
    CameraRotation cameraRotation(&camera);
    
    glfwSetCursorPosCallback(window, MouseInput::GetInput);
    
    BatchRenderer::Init();
    std::vector<Vertex> verticies = Cube::GetVerticies(snowGrassBlock);
    
    /*for (int x = 0; x < 50; x++) {
            for (int z = 0; z < 50; z++) {
                CubeTextureCoord* texture = nullptr;
                
                float noise = SimplexNoise::noise(x * scale + offset.x, z * scale + offset.y);
                
                if(noise >= 0.5f){
                    texture = &snowGrassBlock;
                }
                else if(noise >= -0.2f)
                {
                    texture = &grassBlock;
                }
                else if(noise >= -0.5f)
                {
                    texture = &dirtBlock;
                }
                else
                    texture = &stoneBlock;
                cube.push_back({glm::vec3(x, (int)(noise * 10), z), *texture});
                for (int y = -12; y < (int)(noise * 10); y++) {
                    cube.push_back({glm::vec3(x, y, z), (noise - y <= 5) ? dirtBlock : stoneBlock});
                }
                
            }
        }
    */
    
    std::vector<Vertex> verticies0 = Cube::GetVerticies(grassBlock);
    std::vector<Vertex> verticies1 = Cube::GetVerticies(snowGrassBlock);
    std::vector<Vertex> dirtVerticies = Cube::GetVerticies(dirtBlock);
    std::vector<Vertex> stoneVerticies = Cube::GetVerticies(stoneBlock);
    std::vector<Vertex> assignedVerticies = verticies0;
    float scale = 0.025f;
    glm::vec2 offset = glm::vec2(0.1f, 0.1f);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        camera.Update(shader);
        
        glClear(GL_COLOR_BUFFER_BIT);
        shader.SetUniformMat4f("u_model", model);
        /*cube.Update(shader);
        vertexArray.LoadLayouts();
        cube1.Update(shader);*/
        vertexArray.LoadLayouts();
        
        cameraMovement.MoveRight();
        cameraMovement.MoveLeft();
        cameraMovement.MoveForward();
        cameraMovement.MoveBackwards();
        cameraRotation.Rotate();
        
        vertexArray.Bind();
        vertexArray.LoadLayouts();
        
        vertexArray.LoadLayouts();
        //BatchRenderer::Update();
        
        //scale *= 1.0005;
        
        //offset = glm::vec2(offset.x + 0.0005f, offset.y + 0.0005f);
        
        if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
            offset = glm::vec2(offset.x + 0.05f, offset.y);
        if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
            offset = glm::vec2(offset.x - 0.05f, offset.y);
        if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
            offset = glm::vec2(offset.x, offset.y + 0.05f);
        if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
            offset = glm::vec2(offset.x, offset.y - 0.05f);
        if(glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
            scale -= 0.0005f;
        if(glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
            scale += 0.0005f;
        
        for (int x = 0; x < 50; x++) {
            for (int z = 0; z < 50; z++) {
                BatchRenderer::Draw(glm::vec3(x, -10, z), stoneVerticies);
            }
        }
        
        for (int x = 0; x < 50; x++) {
            for (int z = 0; z < 50; z++) {
                float noise = SimplexNoise::noise(x * scale + offset.x, z * scale + offset.y);
                assignedVerticies = verticies0;
                if(noise >= 0.5f)
                    assignedVerticies = verticies1;
                
                
                BatchRenderer::Draw(glm::vec3(x, (int)(noise * 10), z), assignedVerticies);
                
                for (int y = -10; y < (int)(noise * 10); y++)
                    BatchRenderer::Draw(glm::vec3(x, y, z), dirtVerticies);
                
            }
        }
        
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
