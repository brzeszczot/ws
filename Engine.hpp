#ifndef ENGINE_HPP_INCLUDED
#define ENGINE_HPP_INCLUDED

#define PROJECT_NAME    "test"
#define HTML            "text/html"
#define ENV_PATH        "/usr/local/angel.com/psphp/"
#define CONF_PATH       "/usr/local/angel.com/psphpconf/"
#define CONF_NAME       "conf.ini"

#include "boost/cgi/cgi.hpp"
#include "Config.hpp"

class Engine
{
    public:
        Engine(std::string project_name = PROJECT_NAME);
        ~Engine();
        int Draw(std::string content_type = HTML);
        boost::cgi::request req;
        boost::cgi::response resp;
        std::map<std::string, std::string> post;
        std::map<std::string, std::string> get;
        std::map<std::string, std::string> env;
        std::map<std::string, std::string> conf;
    private:
        Config *config;
        std::string full_config_path;
        std::string full_env_path;
};

#endif // ENGINE_HPP_INCLUDED
