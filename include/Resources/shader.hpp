#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "glad.h"
#include <GLFW/glfw3.h>

#include "resource.hpp"

class Shader : public Resource
{
public:
    Shader(std::string name, const char* vertex_path, const char* fragment_path);

    unsigned int get_ID() { return m_ID; }

private:
    std::string read_data_from_shader_file(const char* path);

    unsigned int create_shader(unsigned int shader_type, const char* shader_data);
    unsigned int create_shader_program(unsigned int vertex_shader, unsigned int fragment_shader);

    unsigned int m_ID;

};