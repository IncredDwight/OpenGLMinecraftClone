#define STB_IMAGE_IMPLEMENTATION
#include "Texture.hpp"

Texture::Texture(const std::string& fileName, unsigned int target){
    _target = target;
    //glGenTextures(1, &_textureId);
    Load(fileName);
    Bind();
    
}

void Texture::Load(const std::string& fileName){
    stbi_set_flip_vertically_on_load(1);
    int width = 0, height = 0, bpp = 0;
    unsigned char* imageData = stbi_load(fileName.c_str(), &width, &height, &bpp, 4);
    if(!imageData)
        std::cout << "Cant load texture " << stbi_failure_reason() << std::endl;
    glGenTextures(1, &_textureId);
    glBindTexture(_target, _textureId);
    
    glTexImage2D(_target, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);
    glTexParameterf(_target, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(_target, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameterf(_target, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(_target, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
}

void Texture::Bind(){
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(_target, _textureId);
}
