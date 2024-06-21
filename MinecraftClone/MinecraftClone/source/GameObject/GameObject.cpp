
#include "GameObject.hpp"

GameObject::GameObject(glm::vec3 position){
    Position = position;
    _model = glm::translate(glm::mat4(1.0f), Position);
    
}

void GameObject::Update(Shader& shader){
    //_model = glm::translate(glm::mat4(1.0f), Position);
    //_model = glm::rotate(_model, glm::radians(0.25f), glm::vec3(0, 1, 0));
    shader.SetUniformMat4f("u_model", _model);
    
    _mesh->Draw();
}

void GameObject::MoveRight(){
    Position.x += 0.0005f;
    Position.y -= 0.0005f;
}
