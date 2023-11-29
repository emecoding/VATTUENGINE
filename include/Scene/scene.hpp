#pragma once

#include <string>
#include <vector>

#include "Entity/entity.hpp"

class Scene
{
public:
    Scene(std::string name);

    Entity add_entity();

private:
    std::string m_Name;

    std::vector<Entity> m_Entities;

};