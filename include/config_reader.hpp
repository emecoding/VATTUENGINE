#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class ConfigReader
{

public: 
    ConfigReader(std::string file_name);

    std::string get_value_str(std::string key);
    unsigned int get_value_ui(std::string key);

private:
    std::vector<std::string> m_Keys;
    std::vector<std::string> m_Values;

    void read(std::string file_name);
    void add_and_set_option(std::string key, std::string value);

};