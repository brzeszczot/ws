#include "Logic.hpp"

using namespace std;

Logic::Logic(Engine *eng)
{
    engine = eng;

    engine->xml->data["message"] = "Nothing to do here...";
    engine->resp << engine->xml->Send();


/*
        // testowanie POST
        engine->resp << "<html><body>Test"
            "<form method=post enctype=\"multipart/form-data\">"
            "<input type=text name=name1 value='" << engine->post["name1"] << "' />"
            "<input type=text name=name2 value='" << engine->post["name2"] << "' />"
            "<input type=text name=name3 value='" << engine->post["name3"] << "' />"
            "<input type=submit value=submit /></form><br />";
*/
/*
        // testowanie DB
        engine->db.query("SELECT * FROM test");
        for(int ii=0;ii<engine->db.results.size();ii++)
            cout << engine->db.results[ii]["name"];
*/
/*
        // testowanie POST, GET, ENV
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
*/
}

Logic::~Logic()
{

}
