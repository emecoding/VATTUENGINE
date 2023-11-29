#include "Scene/scene.hpp"

Scene::Scene(std::string name)
{
    m_Name = name;
}

Entity* Scene::add_entity()
{
    Entity* entity = new Entity("New Entity(" + std::to_string(m_Entities->size()) + ")");
    entity->initialize_entity(m_Entities->size());
    m_Entities->push_back(entity);
    return entity;
}

Entity* Scene::add_entity(Entity* entity)
{
    entity->initialize_entity(m_Entities->size());
    m_Entities->push_back(entity);
    return entity;
}

void Scene::run_scene(Time* time)
{
    for(int i = 0; i < m_Entities->size(); i++)
    {
        m_Entities->at(i)->update(time);
    }
}