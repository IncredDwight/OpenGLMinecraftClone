
#include "Shader.hpp"
#include <iostream>
#include <fstream>

Shader::Shader(const std::string& filePath){
    std::string vertexShaderSource;
    std::string fragmentShaderSource;
    ParseShader(filePath, &vertexShaderSource, &fragmentShaderSource);
    
    _id = CreateProgram(vertexShaderSource, fragmentShaderSource);
}

Shader::~Shader(){
    glDeleteProgram(_id);
}

unsigned int Shader::CreateProgram(std::string& vertexShaderSource, std::string& fragmentShaderSource){
    unsigned int program = glCreateProgram();
    
    unsigned int vertexShader = CreateShader(GL_VERTEX_SHADER, vertexShaderSource);
    unsigned int fragmentShader = CreateShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
    
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    glUseProgram(program);
    
    return program;
}

unsigned int Shader::CreateShader(unsigned int type, std::string &source){
    unsigned int shader = glCreateShader(type);
    
    const char* src = source.c_str();
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);
    
    return shader;
}

void Shader::ParseShader(const std::string& filePath, std::string* vertexShader, std::string* fragmentShader){
    
    std::ifstream file(filePath);
    
    std::string line;
    std::string shader[2];
    
    int index = -1;
    
    while(std::getline(file, line)){
        if(line.find("shader") != std::string::npos){
            if(line.find("vertex") != std::string::npos)
                index = 0;
            else if(line.find("fragment") != std::string::npos)
                index = 1;
        }
        else{
            shader[index] += line + "\n";
        }
    }
    
    *vertexShader = shader[0];
    *fragmentShader = shader[1];
}
