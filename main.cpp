// Web Service
// brzeszczot@gmail.com

#define PROJECT_NAME    "test"
#define CONF_PATH       "/usr/local/angel.com/psphpconf/"
#define LOG_PATH        "/var/log/angel/psphp-"

#include <iostream>
#include "Engine.hpp"
#include "Logger.hpp"
#include "Xml.hpp"
#include "Logic.hpp"

using namespace std;

void catchReport(string s, Xml *xml)
{
    DEBUG(DBG_ERROR, s);
    xml->data["message"] = s;
    cout << "Content-type: text/xml\n\n" << xml->Send();
}

int main(int argc, char **argv)
{
    // set up logger
    const string full_log_path((string)LOG_PATH + (string)PROJECT_NAME + "/" + (string)PROJECT_NAME);
    DEBUG_CONF(PROJECT_NAME, full_log_path, Logger::file_on, DBG_DEBUG, DBG_ERROR);
    DEBUG(DBG_DEBUG, "=== START ===");

    Xml *xml = new Xml(Xml::MESSAGE_PAGE);

    try
    {
        Engine *engine = new Engine(PROJECT_NAME, CONF_PATH, (string)argv[0], xml);
        Logic logic(engine);

        return engine->Draw(CTYPE_XML);
    }
    catch(string s)
    {
        catchReport(s, xml);
    }
    catch(exception &e)
    {
        catchReport(e.what(), xml);
    }

    return 0;
}

