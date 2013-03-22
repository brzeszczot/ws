#include "Xml.hpp"

using boost::property_tree::ptree;
using boost::property_tree::write_xml;
using boost::property_tree::xml_writer_settings;
using namespace std;

string Xml::Send(map<string, string> &d, map<string, string> &opt)
{
    data = d;
    options = opt;
    switch(xml_type)
    {
        case MESSAGE_PAGE: return message_page(); break;
        case QUESTION_PAGE: return question_page(); break;
        case QM_PAGE: return qm_page(); break;
    }
}

string Xml::message_page()
{
    ptree tree;
    //tree.add("angelxml.<xmlattr>.version", "1.0");
    for (int i = 0; i < 3; i++)
    {
        ptree& variable = tree.add("angelxml.variables.var", "");
        //variable.add("title", "jakis tekst");
        variable.add("<xmlattr>.name", "callGUID");
        variable.add("<xmlattr>.value", i * 34);
    }
    ptree& message = tree.add("angelxml.message.goto", "");
    message.add("<xmlattr>.destination", "/65000");

    tree.add("angelxml.message.play", "");

    ptree& prompt = tree.add("angelxml.message.play.prompt", ".");
    prompt.add("<xmlattr>.type", "text");

    stringstream ss;
    write_xml(ss, tree);

    return ss.str();
}

string Xml::question_page()
{

}

string Xml::qm_page()
{

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
