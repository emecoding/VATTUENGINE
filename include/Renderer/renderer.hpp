#pragma once

#include "Entity/entity.hpp"
#include "Scene/scene_manager.hpp"
#include "Resources/shader.hpp"
#include "Window/window.hpp"

#include "glad.h"
#include <GLFW/glfw3.h>

class Renderer
{
public:
    Renderer(SceneManager* scene_manager, Window* window);

    void render_entity(Entity entity, Shader shader);

private:
    unsigned int m_Sprite_VAO;

    SceneManager* m_Scene_manager;
    Window* m_Window;

    void initialize_render_data();

};