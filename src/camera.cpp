#include "Entity/camera.hpp"

Camera::Camera()
{
    
}

glm::mat4 Camera::get_orthographic_projection(unsigned int width, unsigned int height)
{
    return glm::ortho(0.0f, (float)width, (float)height, 0.0f, -1.0f, 1.0f);
}