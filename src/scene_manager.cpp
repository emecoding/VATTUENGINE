#include "Scene/scene_manager.hpp"

SceneManager::SceneManager()
{

}

Scene* SceneManager::add_scene(std::string name)
{
    Scene* new_scene = new Scene(name);
    m_Scenes->push_back(new_scene);
    return new_scene;
}

Scene* SceneManager::add_scene()
{
    std::string name = "New Scene(" + std::to_string(m_Scenes->size()) + ")";
    return add_scene(name);
}