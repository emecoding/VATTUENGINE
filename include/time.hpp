#pragma once

#include <GLFW/glfw3.h>

class Time
{
public:
    double last_time;
    double current_time;
    double delta_time;

    void initialize_time();
    void update_time();
};