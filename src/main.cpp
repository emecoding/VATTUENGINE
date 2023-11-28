#include <iostream>
#include "application.hpp"
#include "Window/window.hpp"

int main()
{

    Application app = Application();
    app.run();
    app.terminate();
    
    return 0;
}