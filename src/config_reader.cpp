#include "config_reader.hpp"

ConfigReader::ConfigReader(std::string file_name)
{
    read(file_name);
}

void ConfigReader::read(std::string file_name)
{
    std::ifstream c_file(file_name);
    if(c_file.is_open())
    {

        std::cout << "Reading the config file" << std::endl;

        std::string line;
        while(getline(c_file, line))
        {
            if(line[0] == '#' || line.empty()) continue;

            unsigned int delimiter_pos = line.find("=");
            std::string key = line.substr(0, delimiter_pos);
            std::string value = line.substr(delimiter_pos + 1);

            add_and_set_option(key, value);
        }


        c_file.close();
    }
    else
    {
        std::cout << "Failed to open the config.txt file!" << std::endl;
        std::exit(-1);
    }   

    std::cout << "Read successfully the config file" << std::endl;
}

void ConfigReader::add_and_set_option(std::string key, std::string value)
{
    std::cout << key << ":" << value << std::endl;
    m_Keys.push_back(key);
    m_Values.push_back(value);
}

std::string ConfigReader::get_value_str(std::string key)
{
    for(unsigned int i = 0; i < m_Keys.size(); i++)
    {
        if(m_Keys.at(i) == key)
            return m_Values.at(i);
    }
}

unsigned int ConfigReader::get_value_ui(std::string key)
{
    return std::stoul(get_value_str(key));
}