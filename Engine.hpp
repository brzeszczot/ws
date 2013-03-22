#ifndef ENGINE_HPP_INCLUDED
#define ENGINE_HPP_INCLUDED

#define HTML            "text/html"
#define CONF_NAME       "conf.ini"
#define CONF_MAIN       "main"

#include "boost/cgi/cgi.hpp"
#include "Config.hpp"
#include "Functions.hpp"
#include "Bmysql.hpp"
#include "Logger.hpp"

class Engine
{
    public:
        Engine(std::string p_name, std::string conf_path, std::string project_path);
        ~Engine();
        int Draw(std::string content_type = HTML);
        boost::cgi::request req;
        boost::cgi::response resp;
        std::map<std::string, std::string> post;
        std::map<std::string, std::string> get;
        std::map<std::string, std::string> env;
        Config conf;
        Bmysql db;
        std::string full_config_path;
        std::string full_env_path;
        std::string project_name;
};

#endif // ENGINE_HPP_INCLUDED
