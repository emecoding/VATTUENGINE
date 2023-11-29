#pragma once

#include <string>
#include <vector>

#include "Entity/entity.hpp"
#include "Entity/camera.hpp"
#include "time.hpp"

class Scene
{
public:
    Scene(std::string name);

    Entity* add_entity();
    Entity* add_entity(Entity* entity);
    
    Camera* create_basic_camera() { return new Camera(); }
    Camera* get_scene_camera() { return m_Scene_camera; }

    Camera* set_scene_camera(Camera* camera) { m_Scene_camera = camera; return m_Scene_camera; }
    void run_scene(Time* time);


private:
    std::string m_Name;

    std::vector<Entity*>* m_Entities = new std::vector<Entity*>;

    Camera* m_Scene_camera = NULL;

};