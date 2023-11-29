#pragma once

#include <string>
#include <vector>

#include "Entity/entity.hpp"
#include "Entity/camera.hpp"

class Scene
{
public:
    Scene(std::string name);

    Entity add_entity();
    
    Camera create_basic_camera() { return Camera(); }
    Camera get_scene_camera() { return m_Scene_camera; }

    void set_scene_camera(Camera camera) { m_Scene_camera = camera; }


private:
    std::string m_Name;

    std::vector<Entity> m_Entities;

    Camera m_Scene_camera;

};