#pragma once

#include "glad.h"
#include <GLFW/glfw3.h>


#include "Window/window.hpp"
#include "Renderer/renderer.hpp"
#include "config_reader.hpp"
#include "Resources/shader.hpp"
#include "Resources/resource_manager.hpp"
#include "Scene/scene_manager.hpp"
#include "Entity/camera.hpp"

#include "Entity/entity.hpp"


class Application
{

public:
    Application();

    void run();
    void terminate();
    
private:
    Window* m_Window;
    Renderer* m_Renderer;
    ConfigReader* m_ConfigReader;
    SceneManager* m_SceneManager;
    ResourceManager* m_ResourceManager;

    void initialize_glfw();
    void initialize_glad();

};