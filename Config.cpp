#include "Config.hpp"

using namespace std;

Config::Config(const string &path)
{
    conf_path = path;
    Load();
}

size_t Config::Load()
{
    using boost::property_tree::ptree;
    ptree pt;
    read_ini(conf_path, pt);

    categories = Functions::split(pt.get<string>("main.categories"), LIST_SEPARATOR);
    categories.push_back("main");
    for(size_t ii=0; ii<categories.size(); ii++)
        BOOST_FOREACH(ptree::value_type &v, pt.get_child(categories[ii].c_str()))
            items[categories[ii].c_str()][v.first.data()] = v.second.data();

    return categories.size();
}

Config::~Config()
{

}
