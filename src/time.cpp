#include "time.hpp"

void Time::initialize_time()
{
    Time::last_time = 0;
    Time::current_time = 0;
    Time::delta_time = 0;
}

void Time::update_time()
{
    current_time = glfwGetTime();
    delta_time =  current_time - last_time;
    last_time = current_time;
}