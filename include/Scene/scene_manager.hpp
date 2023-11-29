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
    Scene get_current_scene() { return m_Scenes[current_scene_index]; }

private:
    std::vector<Scene> m_Scenes;
    
    unsigned int current_scene_index = 0;
};