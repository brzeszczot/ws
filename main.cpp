// Web Service
// brzeszczot@gmail.com

#include <iostream>
#include "Engine.hpp"

using namespace std;

template<typename Map>
void map_iterate(Map &m, map<string, string> &mm)
{
    for(typename Map::const_iterator it(m.begin()); it!=m.end(); ++it)
        mm[it->first.c_str()] = it->second.c_str();
}

int main(int argc, char **argv)
{
    Engine engine("test");

    engine.resp << "<html><body>Test"
            "<form method=post enctype=\"multipart/form-data\">"
            "<input type=text name=name1 value='" << engine.req.post["name1"] << "' />"
            "<input type=text name=name2 value='" << engine.req.post["name2"] << "' />"
            "<input type=text name=name3 value='" << engine.req.post["name3"] << "' />"
            "<input type=submit value=submit /></form><br />";

    map_iterate(engine.req.post, engine.post);
    map_iterate(engine.req.env, engine.env);
    map_iterate(engine.req.get, engine.get);

    for(map<string, string>::iterator it(engine.post.begin()); it!=engine.post.end(); ++it)
        engine.resp << it->first << ": " << it->second << "<br />";
    engine.resp << "<br />";
    for(map<string, string>::iterator it(engine.get.begin()); it!=engine.get.end(); ++it)
        engine.resp << it->first << ": " << it->second << "<br />";
    engine.resp << "<br />";
//    for(map<string, string>::iterator it(engine.env.begin()); it!=engine.env.end(); ++it)
//        engine.resp << it->first << ": " << it->second << "<br />";
//    engine.resp << "<br />";

    return engine.Draw();
}

