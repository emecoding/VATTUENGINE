#pragma once

#include "stb_image.h"

#include "glad.h"
#include <GLFW/glfw3.h>

#include "resource.hpp"

#include <iostream>
#include <string>

class Texture : public Resource
{
public:
    Texture(std::string name, const char* file_path);
    Texture();

    void use();

private:
    unsigned int texture_id;
};