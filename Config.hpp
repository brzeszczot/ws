#ifndef CONFIG_HPP_INCLUDED
#define CONFIG_HPP_INCLUDED

#define LIST_SEPARATOR ','
#include <vector>
#include <map>
#include "boost/foreach.hpp"
#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/ini_parser.hpp"
#include "Functions.hpp"

class Config
{
    private:
        std::string conf_path;
        typedef std::map<std::string, std::string> category;
        std::vector<std::string> categories;
    public:
        Config();
        Config(const std::string &path, std::string main_category);
        virtual ~Config();
        size_t Load(const std::string &path, std::string main_category);
        std::map<std::string, category> items;
};

#endif // CONFIG_HPP_INCLUDED
