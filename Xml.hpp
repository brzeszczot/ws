#ifndef XML_HPP_INCLUDED
#define XML_HPP_INCLUDED

#include <string>
#include <sstream>
#include <map>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

class Xml
{
    public:
        typedef enum e_types {MESSAGE_PAGE, QUESTION_PAGE, QM_PAGE};
        Xml(e_types type = MESSAGE_PAGE): xml_type(type) {};
        virtual ~Xml();
        std::string Send();
        e_types xml_type;
        std::map<std::string, std::string> data;
        std::map<std::string, std::string> options;
    private:
        std::string message_page();
        std::string question_page();
        std::string qm_page();
};

#endif // XML_HPP_INCLUDED
