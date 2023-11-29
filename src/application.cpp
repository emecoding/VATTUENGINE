#include "application.hpp"

Application::Application()
{
    
    m_ConfigReader = new ConfigReader("config.txt");
    m_SceneManager = new SceneManager();
    m_ResourceManager = new ResourceManager();

    initialize_glfw();
    
    m_Window = new Window(m_ConfigReader->get_value_ui("window_width"), m_ConfigReader->get_value_ui("window_height"), m_ConfigReader->get_value_str("window_caption").c_str());

    initialize_glad();

    m_Renderer = new Renderer(m_SceneManager, m_Window);
}

void Application::run()
{
    Shader example_shader = m_ResourceManager->create_shader("EXAMPLE", "res/shaders/example_vert_shader.vs", "res/shaders/example_frag_shader.fs");
    m_ResourceManager->create_texture("EXAMPLE_TEXTURE", "res/textures/example_texture.png");

    Scene example_scene = m_SceneManager->add_scene("EXAMPLE SCENE");
    example_scene.set_scene_camera(example_scene.create_basic_camera());

    Entity example_entity = example_scene.add_entity();
    example_entity.texture = m_ResourceManager->get_texture("EXAMPLE_TEXTURE");

    example_entity.position.x = 100.0f;
    example_entity.position.y = 100.0f;
    example_entity.position.z = 0.0f;

    example_entity.size.x = 100.0f;
    example_entity.size.y = 100.0f;
    example_entity.size.z = 1.0f;

    example_shader.use();

    while(!m_Window->should_close())
    {
        m_Window->clear();
        m_Window->process_window_related_input();

        m_Renderer->render_entity(example_entity, example_shader);

        m_Window->swap_buffers();
        m_Window->poll_events();
    }
}

void Application::terminate()
{
    m_ResourceManager->terminate_resources();
    glfwTerminate();
}

void Application::initialize_glfw()
{
    if(!glfwInit())
    {
        std::cout << "Failed to initialize glfw" << std::endl;
        std::exit(-1);
    }
}

void Application::initialize_glad()
{
    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        std::cout << "Failed to initialize glad" << std::endl;
        std::exit(-1);
    }
}