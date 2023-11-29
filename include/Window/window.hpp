#pragma once

#include <iostream>
#include <string>


#include <GLFW/glfw3.h>
#include <glm/vec4.hpp>


class Window
{
    
public:
    Window(unsigned int width, unsigned int height, const char* caption);

    bool should_close();

    unsigned int get_width() { return m_Width; }
    unsigned int get_height() { return m_Height; }

    void clear();
    void process_window_related_input();
    void swap_buffers();
    void poll_events();
    void set_window_should_close(bool val);

private:
    unsigned int m_Width, m_Height;

    const char* m_Caption;

    GLFWwindow* m_GLFWWindow;
    glm::vec4* m_BGColor;

    void initialize_window();
    void set_glfw_window_hints();

};