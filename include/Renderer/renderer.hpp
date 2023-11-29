#pragma once

#include "Entity/entity.hpp"

#include "glad.h"
#include <GLFW/glfw3.h>

class Renderer
{
public:
    Renderer();

    void render_entity(Entity entity);

private:
    unsigned int m_Sprite_VAO;

    void initialize_render_data();

};