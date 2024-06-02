
#ifndef Shader_hpp
#define Shader_hpp

#include <stdio.h>
#include <string>
#include <GLFW/glfw3.h>

class Shader {
private:
    unsigned int _id;
    
    unsigned int CreateProgram(std::string& vertexShader, std::string& fragmentShader);
    unsigned int CreateShader(unsigned int type, std::string& source);
    void ParseShader(const std::string& filePath, std::string* vertexShader, std::string* fragmentShader);
    
public:
    Shader(const std::string& filePath);
    ~Shader();
};
#endif /* Shader_hpp */
