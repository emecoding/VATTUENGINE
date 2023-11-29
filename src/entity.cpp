#include "Entity/entity.hpp"

Entity::Entity(std::string name)
{
    m_Name = name;
}

void Entity::initialize_entity(unsigned int m_Entity_index)
{
    this->m_Entity_index = m_Entity_index;
}