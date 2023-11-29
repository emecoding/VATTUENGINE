#pragma once

#include <string>
#include <vector>
#include <iostream>

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Resources/texture.hpp"
#include "time.hpp"

class Entity
{
public:
    Entity(std::string name);
    Entity();

    void initialize_entity(unsigned int m_Entity_index);
    virtual void update(Time* time)
    {

    }

    glm::vec3 position;
    glm::vec3 size;
    glm::vec3 rotation;

    Texture texture;

    glm::mat4 create_transform_matrix();

protected:
    std::string m_Name = "";

private:
    unsigned int m_Entity_index;
};