#include "Entity/camera.hpp"

Camera::Camera()
{
    position = glm::vec3(0.0f, 0.0f, 0.0f);
}

glm::mat4 Camera::get_orthographic_projection(unsigned int width, unsigned int height)
{
    return glm::ortho(0.0f, (float)width, (float)height, 0.0f, -1.0f, 1.0f);
}

glm::mat4 Camera::get_view_projection()
{
    return glm::translate(glm::mat4(1.0f), position);
}