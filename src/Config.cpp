#include "Config.hpp"

using namespace std;

Config::Config()
{
}

Config::Config(const string &path, string main_category)
{
    Load(path, main_category);
}

size_t Config::Load(const string &path, string main_category)
{
    conf_path = path;
    using boost::property_tree::ptree;
    ptree pt;
    read_ini(conf_path, pt);

    string cat_full_name(main_category + ".categories_list");
    categories = Functions::split(pt.get<string>(cat_full_name), LIST_SEPARATOR);
    categories.push_back(main_category);
    for(size_t ii=0; ii<categories.size(); ii++)
        BOOST_FOREACH(ptree::value_type &v, pt.get_child(categories[ii].c_str()))
            items[categories[ii].c_str()][v.first.data()] = v.second.data();

    return categories.size();
}

Config::~Config()
{

}
