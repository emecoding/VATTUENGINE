#pragma once

#include <vector>
#include <string>

#include "shader.hpp"

class ResourceManager
{
public:
    ResourceManager();

    Shader create_shader(std::string name, const char* vertex_path, const char* fragment_path);
    Shader get_shader(std::string name);

private:
    std::vector<Shader> m_Shaders;
};