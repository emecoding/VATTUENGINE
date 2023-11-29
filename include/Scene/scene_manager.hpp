#pragma once

#include <vector>
#include <sstream>
#include <string>

#include "scene.hpp"

class SceneManager
{
public: 
    SceneManager();

    Scene add_scene(std::string name);
    Scene add_scene();

private:
    std::vector<Scene> m_Scenes;
    
    unsigned int current_scene_index = 0;
};