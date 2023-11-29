#include "Resources/resource_manager.hpp"

ResourceManager::ResourceManager()
{

}

Shader ResourceManager::create_shader(std::string name, const char* vertex_path, const char* framgment_path)
{
    Shader shader = Shader(name, vertex_path, framgment_path);
    m_Shaders.push_back(shader);
    return shader;
}

Shader ResourceManager::get_shader(std::string name)
{
    for(int i = 0; i < m_Shaders.size(); i++)
    {
        if(m_Shaders[i].get_name() == name)
            return m_Shaders[i];
    }
}