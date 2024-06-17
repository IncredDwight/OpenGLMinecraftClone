
#include "GameObject.hpp"

GameObject::GameObject(glm::vec3 position){
    _mesh = new Mesh(_verticies, _indices);
    
    Position = position;
}

void GameObject::Update(Shader &shader){
    _model = glm::translate(glm::mat4(1.0f), Position);
    shader.SetUniformMat4f("u_model", _model);
    
    _mesh->Draw();
}
