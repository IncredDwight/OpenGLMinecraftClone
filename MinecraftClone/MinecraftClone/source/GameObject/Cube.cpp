
#include "Cube.hpp"

Cube::Cube(glm::vec3 position, glm::vec4 color) : GameObject(position){
    
    Vertex vertices[] = {
        Vertex{glm::vec3(-1.0f, -1.0f, -1.0f), color, glm::vec3(-1.0f, 0.0f, 0.0f)},
        Vertex{glm::vec3(1.0f, -1.0f, -1.0f),  color, glm::vec3(1.0f, 0.0f, 0.0f)},
        Vertex{glm::vec3(1.0f,  1.0f, -1.0f),  color},//        textureUnit.x * (sideCoord.x + 1), textureUnit.y * (sideCoord.y + 1),
        Vertex{glm::vec3(-1.0f,  1.0f, -1.0f), color},//        sideCoord.x * textureUnit.x, textureUnit.y * (sideCoord.y + 1),

        Vertex{glm::vec3(-1.0f, -1.0f,  1.0f), color},//        sideCoord.x * textureUnit.x, sideCoord.y * textureUnit.y,
        Vertex{glm::vec3(1.0f, -1.0f,  1.0f),  color},//        textureUnit.x * (sideCoord.x + 1), sideCoord.y * textureUnit.y,
        Vertex{glm::vec3(1.0f,  1.0f,  1.0f),  color},//        textureUnit.x * (sideCoord.x + 1), textureUnit.y * (sideCoord.y + 1),
        Vertex{glm::vec3(-1.0f,  1.0f,  1.0f), color},//        sideCoord.x * textureUnit.x, textureUnit.y * (sideCoord.y + 1),
                      
        Vertex{glm::vec3(-1.0f,  1.0f, -1.0f), color},//        sideCoord.x * textureUnit.x, textureUnit.y * (sideCoord.y + 1),
        Vertex{glm::vec3(-1.0f,  1.0f,  1.0f), color},//         textureUnit.x * (sideCoord.x + 1), textureUnit.y * (sideCoord.y + 1),
        Vertex{glm::vec3(-1.0f, -1.0f, -1.0f), color},//        textureUnit.x * (sideCoord.x + 1), sideCoord.y * textureUnit.y,
                     
        Vertex{glm::vec3(1.0f,  1.0f,  1.0f),  color},//        sideCoord.x * textureUnit.x, textureUnit.y * (sideCoord.y + 1),
        Vertex{glm::vec3(1.0f, -1.0f,  1.0f),  color}, //       sideCoord.x * textureUnit.x, sideCoord.y * textureUnit.y,
                    
        Vertex{glm::vec3(1.0f,  1.0f, -1.0f),  color},//        textureUnit.x * (topCoord.x + 1), textureUnit.y * (topCoord.y + 1),
        Vertex{glm::vec3(-1.0f,  1.0f, -1.0f), color},//        topCoord.x * textureUnit.x, textureUnit.y * (topCoord.y + 1),
        Vertex{glm::vec3(-1.0f,  1.0f,  1.0f), color},//        topCoord.x * textureUnit.x, topCoord.y * textureUnit.y,
        Vertex{glm::vec3(1.0f,  1.0f,  1.0f),  color},//        textureUnit.x * (topCoord.x + 1), topCoord.y * textureUnit.y,
                    
        Vertex{glm::vec3(-1.0f, -1.0f, -1.0f), color},//        btmCoord.x * textureUnit.x, btmCoord.y * textureUnit.y,
        Vertex{glm::vec3(1.0f, -1.0f, -1.0f),  color},//        textureUnit.x * (btmCoord.x + 1), btmCoord.y * textureUnit.y,
        Vertex{glm::vec3(1.0f, -1.0f,  1.0f),  color},//        textureUnit.x * (btmCoord.x + 1), textureUnit.y * (btmCoord.y + 1),
        Vertex{glm::vec3(-1.0f, -1.0f,  1.0f), color} //        btmCoord.x * textureUnit.x, textureUnit.y * (btmCoord.y + 1),
    };
    
    unsigned int indicies[] = {
        0, 1, 2, 2, 3, 0,
        4, 5, 6, 6, 7, 4,
        0, 8, 9, 9, 10, 0,
        1, 2, 11, 11, 12, 1,
        17, 18, 19, 19, 20, 17,
        13, 14, 15, 15, 16, 13
    };
    
    std::vector<Vertex> _verticies(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
    std::vector<unsigned int> _indices(indicies, indicies + sizeof(indicies) / sizeof(unsigned int));
    _mesh = new Mesh(_verticies, _indices, "");
}

Cube::Cube(glm::vec3 position, CubeTextureCoord textureCoord) : GameObject(position){
    
    int textureHeight = 62;
    int textureWidth = 16;
    glm::vec2 textureUnit = glm::vec2((float) 1 / textureWidth, (float) 1 / textureHeight);
    glm::vec2 sideCoord = textureCoord.sideCoord;
    glm::vec2 topCoord = textureCoord.topCoord;
    glm::vec2 btmCoord = textureCoord.btmCoord;
    
    Vertex vertices[] = {
        Vertex{glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec2(sideCoord.x * textureUnit.x, sideCoord.y * textureUnit.y), glm::vec3(-1.0f, 0.0f, 0.0f)},
        Vertex{glm::vec3(1.0f, -1.0f, -1.0f),  glm::vec2(textureUnit.x * (sideCoord.x + 1), sideCoord.y * textureUnit.y), glm::vec3(1.0f, 0.0f, 0.0f)},
        Vertex{glm::vec3(1.0f,  1.0f, -1.0f),  glm::vec2(textureUnit.x * (sideCoord.x + 1), textureUnit.y * (sideCoord.y + 1)),
            glm::vec3(0.0f, 0.0f, -1.0f)
        },
        Vertex{glm::vec3(-1.0f,  1.0f, -1.0f), glm::vec2(sideCoord.x * textureUnit.x, textureUnit.y * (sideCoord.y + 1)),
            glm::vec3(0.0f, 1.0f, 0.0f)
        },

        Vertex{glm::vec3(-1.0f, -1.0f,  1.0f), glm::vec2(sideCoord.x * textureUnit.x, sideCoord.y * textureUnit.y),
            glm::vec3(0.0f, 0.0f, 1.0f)
        },
        Vertex{glm::vec3(1.0f, -1.0f,  1.0f),  glm::vec2(textureUnit.x * (sideCoord.x + 1), sideCoord.y * textureUnit.y),
            glm::vec3(0.0f, -1.0f, 0.0f)
        },
        Vertex{glm::vec3(1.0f,  1.0f,  1.0f),  glm::vec2(textureUnit.x * (sideCoord.x + 1), textureUnit.y * (sideCoord.y + 1)),
            glm::vec3(0.0f, 0.0f, 1.0f)
        },
        Vertex{glm::vec3(-1.0f,  1.0f,  1.0f), glm::vec2(sideCoord.x * textureUnit.x, textureUnit.y * (sideCoord.y + 1)),
            glm::vec3(-1.0f, 0.0f, 0.0f)
        },
                      
        Vertex{glm::vec3(-1.0f,  1.0f, -1.0f), glm::vec2(sideCoord.x * textureUnit.x, textureUnit.y * (sideCoord.y + 1)),
            glm::vec3(0.0f, 1.0f, -1.0f)
        },
        Vertex{glm::vec3(-1.0f,  1.0f,  1.0f), glm::vec2(textureUnit.x * (sideCoord.x + 1), textureUnit.y * (sideCoord.y + 1)),
            glm::vec3(-1.0f, 0.0f, 0.0f)
        },
        Vertex{glm::vec3(-1.0f, -1.0f,  1.0f), glm::vec2(textureUnit.x * (sideCoord.x + 1), sideCoord.y * textureUnit.y),
            glm::vec3(0.0f, 0.0f, 1.0f)
        },
                     
        Vertex{glm::vec3(1.0f,  1.0f,  1.0f),  glm::vec2(sideCoord.x * textureUnit.x, textureUnit.y * (sideCoord.y + 1)),
            glm::vec3(0.0f, 0.0f, 1.0f)
        },
        Vertex{glm::vec3(1.0f, -1.0f,  1.0f),  glm::vec2(sideCoord.x * textureUnit.x, sideCoord.y * textureUnit.y),
            glm::vec3(0.0f, -1.0f, 0.0f)
        },
                    
        Vertex{glm::vec3(1.0f,  1.0f, -1.0f),  glm::vec2(textureUnit.x * (topCoord.x + 1), textureUnit.y * (topCoord.y + 1)),
            glm::vec3(0.0f, 0.0f, -1.0f)
        },
        Vertex{glm::vec3(-1.0f,  1.0f, -1.0f), glm::vec2(topCoord.x * textureUnit.x, textureUnit.y * (topCoord.y + 1)),
            glm::vec3(0.0f, 1.0f, 0.0f)
        },
        Vertex{glm::vec3(-1.0f,  1.0f,  1.0f), glm::vec2(topCoord.x * textureUnit.x, topCoord.y * textureUnit.y),
            glm::vec3(-1.0f, 0.0f, 0.0f)
        },
        Vertex{glm::vec3(1.0f,  1.0f,  1.0f),  glm::vec2(textureUnit.x * (topCoord.x + 1), topCoord.y * textureUnit.y),
            glm::vec3(0.0f, 0.0f, 1.0f)
        },
                    
        Vertex{glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec2(btmCoord.x * textureUnit.x, btmCoord.y * textureUnit.y),
            glm::vec3(-1.0f, 0.0f, 0.0f)
        },
        Vertex{glm::vec3(1.0f, -1.0f, -1.0f),  glm::vec2(textureUnit.x * (btmCoord.x + 1), btmCoord.y * textureUnit.y),
            glm::vec3(1.0f, 0.0f, 0.0f)
        },
        Vertex{glm::vec3(1.0f, -1.0f,  1.0f),  glm::vec2(textureUnit.x * (btmCoord.x + 1), textureUnit.y * (btmCoord.y + 1)),
            glm::vec3(0.0f, -1.0f, 0.0f)
        },
        Vertex{glm::vec3(-1.0f, -1.0f,  1.0f), glm::vec2(btmCoord.x * textureUnit.x, textureUnit.y * (btmCoord.y + 1)),
            glm::vec3(0.0f, 0.0f, 1.0f)
        },
    };
    
    unsigned int indicies[] = {
        0, 1, 2, 2, 3, 0,
        4, 5, 6, 6, 7, 4,
        0, 8, 9, 9, 10, 0,
        1, 2, 11, 11, 12, 1,
        17, 18, 19, 19, 20, 17,
        13, 14, 15, 15, 16, 13
    };
    
    std::vector<Vertex> _verticies(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
    std::vector<unsigned int> _indices(indicies, indicies + sizeof(indicies) / sizeof(unsigned int));
    _mesh = new Mesh(_verticies, _indices, "/Users/yaroslavvalchyshen/Desktop/Programming/GitHub/OpenGLMinecraftClone/MinecraftClone/MinecraftClone/resources/Textures/TextureMap.png");
}

std::vector<Vertex> Cube::GetVerticies(CubeTextureCoord textureCoord){
    int textureHeight = 62;
    int textureWidth = 16;
    glm::vec2 textureUnit = glm::vec2((float) 1 / textureWidth, (float) 1 / textureHeight);
    glm::vec2 sideCoord = textureCoord.sideCoord;
    glm::vec2 topCoord = textureCoord.topCoord;
    glm::vec2 btmCoord = textureCoord.btmCoord;
    
    Vertex vertices[] = {
        Vertex{glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec2(sideCoord.x * textureUnit.x, sideCoord.y * textureUnit.y), glm::vec3(-1.0f, 0.0f, 0.0f)},
        Vertex{glm::vec3(1.0f, -1.0f, -1.0f),  glm::vec2(textureUnit.x * (sideCoord.x + 1), sideCoord.y * textureUnit.y), glm::vec3(1.0f, 0.0f, 0.0f)},
        Vertex{glm::vec3(1.0f,  1.0f, -1.0f),  glm::vec2(textureUnit.x * (sideCoord.x + 1), textureUnit.y * (sideCoord.y + 1)),
            glm::vec3(0.0f, 0.0f, -1.0f)
        },
        Vertex{glm::vec3(-1.0f,  1.0f, -1.0f), glm::vec2(sideCoord.x * textureUnit.x, textureUnit.y * (sideCoord.y + 1)),
            glm::vec3(0.0f, 1.0f, 0.0f)
        },

        Vertex{glm::vec3(-1.0f, -1.0f,  1.0f), glm::vec2(sideCoord.x * textureUnit.x, sideCoord.y * textureUnit.y),
            glm::vec3(0.0f, 0.0f, 1.0f)
        },
        Vertex{glm::vec3(1.0f, -1.0f,  1.0f),  glm::vec2(textureUnit.x * (sideCoord.x + 1), sideCoord.y * textureUnit.y),
            glm::vec3(0.0f, -1.0f, 0.0f)
        },
        Vertex{glm::vec3(1.0f,  1.0f,  1.0f),  glm::vec2(textureUnit.x * (sideCoord.x + 1), textureUnit.y * (sideCoord.y + 1)),
            glm::vec3(0.0f, 0.0f, 1.0f)
        },
        Vertex{glm::vec3(-1.0f,  1.0f,  1.0f), glm::vec2(sideCoord.x * textureUnit.x, textureUnit.y * (sideCoord.y + 1)),
            glm::vec3(-1.0f, 0.0f, 0.0f)
        },
                      
        Vertex{glm::vec3(-1.0f,  1.0f, -1.0f), glm::vec2(sideCoord.x * textureUnit.x, textureUnit.y * (sideCoord.y + 1)),
            glm::vec3(0.0f, 1.0f, -1.0f)
        },
        Vertex{glm::vec3(-1.0f,  1.0f,  1.0f), glm::vec2(textureUnit.x * (sideCoord.x + 1), textureUnit.y * (sideCoord.y + 1)),
            glm::vec3(-1.0f, 0.0f, 0.0f)
        },
        Vertex{glm::vec3(-1.0f, -1.0f,  1.0f), glm::vec2(textureUnit.x * (sideCoord.x + 1), sideCoord.y * textureUnit.y),
            glm::vec3(0.0f, 0.0f, 1.0f)
        },
                     
        Vertex{glm::vec3(1.0f,  1.0f,  1.0f),  glm::vec2(sideCoord.x * textureUnit.x, textureUnit.y * (sideCoord.y + 1)),
            glm::vec3(0.0f, 0.0f, 1.0f)
        },
        Vertex{glm::vec3(1.0f, -1.0f,  1.0f),  glm::vec2(sideCoord.x * textureUnit.x, sideCoord.y * textureUnit.y),
            glm::vec3(0.0f, -1.0f, 0.0f)
        },
                    
        Vertex{glm::vec3(1.0f,  1.0f, -1.0f),  glm::vec2(textureUnit.x * (topCoord.x + 1), textureUnit.y * (topCoord.y + 1)),
            glm::vec3(0.0f, 0.0f, -1.0f)
        },
        Vertex{glm::vec3(-1.0f,  1.0f, -1.0f), glm::vec2(topCoord.x * textureUnit.x, textureUnit.y * (topCoord.y + 1)),
            glm::vec3(0.0f, 1.0f, 0.0f)
        },
        Vertex{glm::vec3(-1.0f,  1.0f,  1.0f), glm::vec2(topCoord.x * textureUnit.x, topCoord.y * textureUnit.y),
            glm::vec3(-1.0f, 0.0f, 0.0f)
        },
        Vertex{glm::vec3(1.0f,  1.0f,  1.0f),  glm::vec2(textureUnit.x * (topCoord.x + 1), topCoord.y * textureUnit.y),
            glm::vec3(0.0f, 0.0f, 1.0f)
        },
                    
        Vertex{glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec2(btmCoord.x * textureUnit.x, btmCoord.y * textureUnit.y),
            glm::vec3(-1.0f, 0.0f, 0.0f)
        },
        Vertex{glm::vec3(1.0f, -1.0f, -1.0f),  glm::vec2(textureUnit.x * (btmCoord.x + 1), btmCoord.y * textureUnit.y),
            glm::vec3(1.0f, 0.0f, 0.0f)
        },
        Vertex{glm::vec3(1.0f, -1.0f,  1.0f),  glm::vec2(textureUnit.x * (btmCoord.x + 1), textureUnit.y * (btmCoord.y + 1)),
            glm::vec3(0.0f, -1.0f, 0.0f)
        },
        Vertex{glm::vec3(-1.0f, -1.0f,  1.0f), glm::vec2(btmCoord.x * textureUnit.x, textureUnit.y * (btmCoord.y + 1)),
            glm::vec3(0.0f, 0.0f, 1.0f)
        },
    };
    
    std::vector<Vertex> verticies(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
    
    return verticies;
}

