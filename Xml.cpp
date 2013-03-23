#include "Xml.hpp"

using boost::property_tree::ptree;
using boost::property_tree::write_xml;
using boost::property_tree::xml_writer_settings;
using namespace std;

string Xml::Send()
{
    if(options.size()==0)
    {
        xml_type = MESSAGE_PAGE;
        // set default variables for message page before config class is runned
        options["prompt"] = ".";
        options["destination"] = "1";
        options["type"] = "text";
    }

    switch(xml_type)
    {
        case MESSAGE_PAGE: return message_page(); break;
        case QUESTION_PAGE: return question_page(); break;
        case QM_PAGE: return qm_page(); break;
    }
    return NULL;
}

string Xml::message_page()
{
    ptree tree;
    //tree.add("angelxml.<xmlattr>.version", "1.0");
    for (map<string, string>::iterator it = data.begin(); it!=data.end(); ++it)
    {
        ptree& variable = tree.add("angelxml.variables.var", "");
        //variable.add("title", "jakis tekst");
        variable.add("<xmlattr>.name", it->first);
        variable.add("<xmlattr>.value", it->second);
    }
    ptree& message = tree.add("angelxml.message.goto", "");
    message.add("<xmlattr>.destination", "/" + options["destination"]);

    tree.add("angelxml.message.play", "");

    ptree& prompt = tree.add("angelxml.message.play.prompt", options["prompt"]);
    prompt.add("<xmlattr>.type", options["type"]);

    stringstream ss;
    write_xml(ss, tree);

    return ss.str();
}

string Xml::question_page()
{
    return string();
}

string Xml::qm_page()
{
    return string();
}

Xml::~Xml()
{

}

/*
<ANGELXML>
    <VARIABLES>
        <VAR name="status" value="ERROR"/>
        <VAR name="code" value="101"/>
        <VAR name="message" value="field __scriptName error: required"/>
    </VARIABLES>
    <MESSAGE>
        <GOTO destination="/65000"/>
        <PLAY>
            <PROMPT type="text">.</PROMPT>
        </PLAY>
    </MESSAGE>
</ANGELXML>
*/
