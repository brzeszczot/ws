#ifndef FUNCTIONS_HPP_INCLUDED
#define FUNCTIONS_HPP_INCLUDED

#include <string>
#include <sstream>
#include <vector>
#include <map>

namespace Functions
{
    const std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
    const std::vector<std::string> split(const std::string &s, char delim);
};

#endif // FUNCTIONS_HPP_INCLUDED
