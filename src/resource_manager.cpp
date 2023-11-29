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

Texture ResourceManager::create_texture(std::string name, const char* file_path)
{
    Texture texture = Texture(name, file_path);
    m_Textures.push_back(texture);
    return texture;
}

Texture ResourceManager::get_texture(std::string name)
{
    for(int i = 0; i < m_Textures.size(); i++)
    {
        if(m_Textures[i].get_name() == name)
            return m_Textures[i];
    }
}

void ResourceManager::terminate_resources()
{
    for(int i = 0; i < m_Shaders.size(); i++)
    {
        glDeleteProgram(m_Shaders[i].get_ID());
    }
}