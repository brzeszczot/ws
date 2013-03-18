#ifndef VARS_HPP_INCLUDED
#define VARS_HPP_INCLUDED

#include <iostream>
#include <map>
#include <string>
#include "qdecoder.h"

class Vars
{
    public:
        Vars();
        virtual ~Vars();
        std::map<std::string, std::string> post;
        std::map<std::string, std::string> get;
    private:
        qentry_t *entry;
};

#endif // VARS_HPP_INCLUDED
