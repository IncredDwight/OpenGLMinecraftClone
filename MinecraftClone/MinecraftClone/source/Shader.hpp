
#ifndef Shader_hpp
#define Shader_hpp

#include <stdio.h>
#include <string>
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Shader {
private:
    unsigned int _id;
    
    unsigned int CreateProgram(std::string& vertexShader, std::string& fragmentShader);
    unsigned int CreateShader(unsigned int type, std::string& source);
    void ParseShader(const std::string& filePath, std::string* vertexShader, std::string* fragmentShader);
    
    unsigned int GetUniformLocation(const std::string& name);
    
public:
    Shader(const std::string& filePath);
    ~Shader();
    
    void SetUniformMat4f(const std::string& name, glm::mat4& matrix);
    glm::mat4 GetUniformMat4f(const std::string& name);
};
#endif /* Shader_hpp */
