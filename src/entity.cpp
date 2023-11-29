#include "Entity/entity.hpp"

Entity::Entity(std::string name)
{
    m_Name = name;
}

Entity::Entity()
{

}

void Entity::initialize_entity(unsigned int m_Entity_index)
{
    this->m_Entity_index = m_Entity_index;
    if(m_Name == "")
        m_Name = "New Entity(" + std::to_string(m_Entity_index) + ")";
}

glm::mat4 Entity::create_transform_matrix()
{
    glm::mat4 transform = glm::mat4(1.0f);
    transform = glm::translate(transform, position);
    transform = glm::scale(transform, size);

    return transform;
}