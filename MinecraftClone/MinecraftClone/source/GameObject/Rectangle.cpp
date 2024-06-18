
#include "Rectangle.hpp"

Rectangle::Rectangle(glm::vec3 position) : GameObject(position){
    Vertex vertices[] = {
        Vertex(glm::vec3(0.0f,  0.0f, 0.0f), glm::vec4(0.0f, 0.5f, 0.5f, 1.0f)),
        Vertex(glm::vec3(0.5f,  0.5f, 0.0f), glm::vec4(0.1f, 1.0f, 0.5f, 1.0f)),
        Vertex(glm::vec3(0.5f,  0.0f, 0.0f), glm::vec4(0.1f, 0.5f, 0.5f, 1.0f)),
        Vertex(glm::vec3(0.0f,  0.5f, 0.0f), glm::vec4(0.1f, 0.5f, 0.5f, 1.0f))
    };
    
    unsigned int indicies[] = {
        0, 1, 2,
        0, 1, 3
    };
    
    std::vector<Vertex> _verticies(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
    std::vector<unsigned int> _indices(indicies, indicies + sizeof(indicies) / sizeof(unsigned int));
    _mesh = new Mesh(_verticies, _indices, "");
}
