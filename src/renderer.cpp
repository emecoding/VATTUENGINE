#include "Renderer/renderer.hpp"

Renderer::Renderer(SceneManager* scene_manager, Window* window)
{
    m_Scene_manager = scene_manager;
    m_Window = window;
    initialize_render_data();
}

void Renderer::initialize_render_data()
{
    unsigned int sprite_VBO;
    float sprite_vertices[] = 
    {
        //position  //tex coordinate
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,

        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f
    };

    glGenVertexArrays(1, &m_Sprite_VAO);
    glGenBuffers(1, &sprite_VBO);

    glBindBuffer(GL_ARRAY_BUFFER, sprite_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(sprite_vertices), sprite_vertices, GL_STATIC_DRAW);

    glBindVertexArray(m_Sprite_VAO);
    
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}


void Renderer::render_entity(Entity entity, Shader shader)
{   
    shader.set_uniform("projection", m_Scene_manager->get_current_scene().get_scene_camera().get_orthographic_projection(m_Window->get_width(), m_Window->get_height()));
    shader.set_uniform("transform", entity.create_transform_matrix());

    entity.texture.use();
    glBindVertexArray(m_Sprite_VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}