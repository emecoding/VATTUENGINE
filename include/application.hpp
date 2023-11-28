#pragma once

#include "glad.h"
#include <GLFW/glfw3.h>


#include "Window/window.hpp"
#include "config_reader.hpp"

class Application
{

public:
    Application();

    void run();
    void terminate();
    
private:
    Window* m_Window;
    ConfigReader* m_ConfigReader;

    void initialize_glfw();
    void initialize_glad();

};