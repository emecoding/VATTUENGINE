#pragma once

#include <string>
#include <vector>
#include <iostream>

#include <glm/vec3.hpp>

#include "Resources/texture.hpp"

class Entity
{
public:
    Entity(std::string name);

    void initialize_entity(unsigned int m_Entity_index);

    glm::vec3 position;
    glm::vec3 size;
    glm::vec3 rotation;

    Texture texture;

protected:
    std::string m_Name;

private:
    unsigned int m_Entity_index;
};