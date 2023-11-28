#include "application.hpp"

#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 600

Application::Application()
{
    m_ConfigReader = new ConfigReader("config.txt");

    initialize_glfw();
    
    m_Window = new Window(m_ConfigReader->get_value_ui("window_width"), m_ConfigReader->get_value_ui("window_height"), m_ConfigReader->get_value_str("window_caption").c_str());

    initialize_glad();
}

void Application::run()
{
    while(!m_Window->should_close())
    {
        m_Window->clear();
        m_Window->process_window_related_input();
        m_Window->swap_buffers();
        m_Window->poll_events();
    }
}

void Application::terminate()
{
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