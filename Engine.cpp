#include "Engine.hpp"

namespace cgi = boost::cgi;
using namespace std;

Engine::Engine(std::string project_name)
{
    full_config_path = CONF_PATH + project_name + "/" + CONF_NAME;
    full_env_path = ENV_PATH + project_name + "/Trunk/";
    config = new Config(full_config_path);
}

int Engine::Draw(string content_type)
{
    resp << cgi::content_type(content_type);
    return cgi::commit(req, resp);
}

Engine::~Engine()
{
    delete config;
}
