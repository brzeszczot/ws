#include "Functions.hpp"

using namespace std;

namespace Functions
{
    vector<string> &split(const string &s, char delim, vector<string> &elems)
    {
        stringstream ss(s);
        string item;
        while(getline(ss, item, delim))
            elems.push_back(item);
        return elems;
    }

    vector<string> split(const string &s, char delim)
    {
        vector<string> elems;
        return split(s, delim, elems);
    }
}
