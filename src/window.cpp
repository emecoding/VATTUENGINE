#include "Window/window.hpp"

Window::Window(unsigned int width, unsigned int height, const char* caption)
{
    m_Width = width;
    m_Height = height;
    m_Caption = caption;

    m_BGColor = new glm::vec4(0.2f, 0.3f, 0.3f, 1.0f);

    initialize_window();
}

void Window::initialize_window()
{
    set_glfw_window_hints();

    m_GLFWWindow = glfwCreateWindow(m_Width, m_Height, m_Caption, NULL, NULL);
    if(m_GLFWWindow == NULL)
    {
        std::cout << "Failed to create GLFW window..." << std::endl;
        std::exit(-1);   
    }

    

    glfwMakeContextCurrent(m_GLFWWindow);
}

void Window::set_glfw_window_hints()
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
}

bool Window::should_close() { return glfwWindowShouldClose(m_GLFWWindow); }

void Window::clear()
{
    glClearColor(m_BGColor->x, m_BGColor->y, m_BGColor->z, m_BGColor->a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::process_window_related_input()
{
    if (glfwGetKey(m_GLFWWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        set_window_should_close(true);
}

void Window::swap_buffers() { glfwSwapBuffers(m_GLFWWindow); }
void Window::poll_events() { glfwPollEvents(); }
void Window::set_window_should_close(bool val) { glfwSetWindowShouldClose(m_GLFWWindow, val); }