#include "Scene/scene.hpp"

Scene::Scene(std::string name)
{
    m_Name = name;
}

Entity Scene::add_entity()
{
    Entity entity = Entity("New Entity(" + std::to_string(m_Entities.size()) + ")");
    entity.initialize_entity(m_Entities.size());
    m_Entities.push_back(entity);
    return entity;
}