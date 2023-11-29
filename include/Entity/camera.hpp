#pragma once

#include "entity.hpp"

#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera : public Entity
{
public:
    Camera();

    glm::mat4 get_orthographic_projection(unsigned int width, unsigned int height);
    glm::mat4 get_view_projection();
};