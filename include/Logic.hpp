#ifndef LOGIC_HPP_INCLUDED
#define LOGIC_HPP_INCLUDED

#include <map>
#include <string>
#include "Engine.hpp"
#include "Xml.hpp"

class Logic
{
    public:
        Logic(Engine *eng);
        virtual ~Logic();
    private:
        Engine *engine;
        Xml *xml;
};

#endif // LOGIC_HPP_INCLUDED
