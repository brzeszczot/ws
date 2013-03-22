// Web Service
// brzeszczot@gmail.com

#define PROJECT_NAME    "test"
#define CONF_PATH       "/usr/local/angel.com/psphpconf/"
#define LOG_PATH        "/var/log/angel/psphp-"

#include <iostream>
#include "Engine.hpp"
#include "Logger.hpp"
#include "Xml.hpp"

using namespace std;

int main(int argc, char **argv)
{
    // set up logger
    const string full_log_path((string)LOG_PATH + (string)PROJECT_NAME + "/" + (string)PROJECT_NAME);
    DEBUG_CONF(PROJECT_NAME, full_log_path, Logger::file_on, DBG_DEBUG, DBG_ERROR);
    DEBUG(DBG_DEBUG, "=== START ===");

    try
    {
        Engine *engine = new Engine(PROJECT_NAME, CONF_PATH, (string)argv[0]);



        map<string, string> d;
        map<string, string> opt;
        Xml xml;
        cout << xml.Send(d, opt) << "@";



        engine->resp << "<html><body>Test"
            "<form method=post enctype=\"multipart/form-data\">"
            "<input type=text name=name1 value='" << engine->post["name1"] << "' />"
            "<input type=text name=name2 value='" << engine->post["name2"] << "' />"
            "<input type=text name=name3 value='" << engine->post["name3"] << "' />"
            "<input type=submit value=submit /></form><br />";
/*
        engine->db.query("SELECT * FROM test");
        for(int ii=0;ii<engine->db.results.size();ii++)
            cout << engine->db.results[ii]["name"];
*/
        for(map<string, string>::iterator it(engine->post.begin()); it!=engine->post.end(); ++it)
            engine->resp << it->first << ": " << it->second << "<br />";
        engine->resp << "<br />";
        for(map<string, string>::iterator it(engine->get.begin()); it!=engine->get.end(); ++it)
            engine->resp << it->first << ": " << it->second << "<br />";
        engine->resp << "<br />";
        for(map<string, string>::iterator it(engine->env.begin()); it!=engine->env.end(); ++it)
            engine->resp << it->first << ": " << it->second << "<br />";
        engine->resp << "<br />";
        engine->resp << engine->full_env_path << "<br />";
        engine->resp << engine->full_config_path << "<br />";

        return engine->Draw();
    }
    catch(string s)
    {
        DEBUG(DBG_DEBUG, s);
    }
    catch(exception &e)
    {
        DEBUG(DBG_DEBUG, e.what());
    }

    return 0;
}

