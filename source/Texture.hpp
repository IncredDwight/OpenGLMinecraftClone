
#ifndef Texture_hpp
#define Texture_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "stb-master/stb_image.h"

class Texture{
public:
    Texture(const std::string& fileName, unsigned int target);
    
private:
    unsigned int _textureId;
    unsigned int _target;
    
    void Bind();
    void Load(const std::string& fileName);
};

#endif
