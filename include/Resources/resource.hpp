#pragma once

#include <string>

class Resource
{
public:
    std::string get_name() { return m_Name; }

protected:
    std::string m_Name;
};