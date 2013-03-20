// Web Service
// brzeszczot@gmail.com
#define PROJECT_NAME    "test"
#include <iostream>
#include "Engine.hpp"
#include "boost/log/trivial.hpp"
#include "boost/log/common.hpp"
#include "boost/log/core.hpp"

using namespace std;

int main(int argc, char **argv)
{
    try
    {
        Engine *engine = new Engine(PROJECT_NAME, (string)argv[0]);

        boost::log::add_file_log("dupa.log");
      //  src::logger lg;
        BOOST_LOG_TRIVIAL(info) << "Ala ma kota!!!";

        engine->resp << "<html><body>Test"
            "<form method=post enctype=\"multipart/form-data\">"
            "<input type=text name=name1 value='" << engine->post["name1"] << "' />"
            "<input type=text name=name2 value='" << engine->post["name2"] << "' />"
            "<input type=text name=name3 value='" << engine->post["name3"] << "' />"
            "<input type=submit value=submit /></form><br />";

        engine->db.query("SELECT * FROM test");
        for(int ii=0;ii<engine->db.results.size();ii++)
            cout << engine->db.results[ii]["name"];

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

        return engine->Draw();
    }
    catch(string s)
    {
        cout << s << "@";
    }

    return 0;
}

