#include "Resources/texture.hpp"

Texture::Texture()
{
    
}

Texture::Texture(std::string name, const char* file_path)
{
    m_Name = name;

    stbi_set_flip_vertically_on_load(true);  

    glGenTextures(1, &texture_id);
    glBindTexture(GL_TEXTURE_2D, texture_id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nr_channels;
    unsigned char* data = stbi_load(file_path, &width, &height, &nr_channels, 0);
    if(data)
    {
        unsigned int color_channel_type = (nr_channels == 4 ? GL_RGBA : GL_RGB);
        glTexImage2D(GL_TEXTURE_2D, 0, color_channel_type, width, height, 0, color_channel_type, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture '" << file_path << "'..." << std::endl;
    }

    stbi_image_free(data);

    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::use()
{
    glBindTexture(GL_TEXTURE_2D, texture_id);
}