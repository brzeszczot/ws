#include "Engine.hpp"

namespace cgi = boost::cgi;
using namespace std;

template<typename Map>
void map_iterate(Map &m, map<string, string> &mm)
{
    for(typename Map::const_iterator it(m.begin()); it!=m.end(); ++it)
        mm[it->first.c_str()] = it->second.c_str();
}

Engine::Engine(string project_name, string project_path)
{
    full_config_path = CONF_PATH + project_name + "/" + CONF_NAME;
    full_env_path = project_path;
    conf.Load(full_config_path, CONF_MAIN);

    // set up maps variables
    map_iterate(req.post, post);
    map_iterate(req.env, env);
    map_iterate(req.get, get);

    // connect with DB if in config exist [database] category
    if(conf.items[CONF_MAIN]["database_enabled"] == "true")
        db.connect(conf.items["database"]["host"], conf.items["database"]["user"], conf.items["database"]["pass"], conf.items["database"]["base"]);
}

int Engine::Draw(string content_type)
{
    resp << cgi::content_type(content_type);
    return cgi::commit(req, resp);
}

Engine::~Engine()
{
}
