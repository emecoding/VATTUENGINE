#pragma once

#include <vector>
#include <string>

#include "glad.h"
#include <GLFW/glfw3.h>

#include "shader.hpp"
#include "texture.hpp"

class ResourceManager
{
public:
    ResourceManager();

    Shader create_shader(std::string name, const char* vertex_path, const char* fragment_path);
    Shader get_shader(std::string name);

    Texture create_texture(std::string name, const char* file_path);
    Texture get_texture(std::string name);

    void terminate_resources();

private:
    std::vector<Shader> m_Shaders;
    std::vector<Texture> m_Textures;
};