#include "Vars.hpp"

using namespace std;

Vars::Vars()
{
/*
    // read post data
    this->entry = qcgireq_parse(NULL, Q_CGI_POST);
    qentobj_t obj; // obj.size, obj.data, obj.name
    memset((void*)&obj, 0, sizeof(obj));
    while(entry->getnext(entry, &obj, NULL, false) == true)
        //cout << "|" << obj.name << "|" << endl;
        this->post[(string)obj.name] = (char*)obj.data;

    char *str = this->entry->getstr(entry, "VariableName1", false);
    printf("|%s|", str);
*/
/*
    // read post data
    this->entry = qcgireq_parse(NULL, Q_CGI_GET);
    //entry->putstr(entry, "key1", "hello world 1", false);
    memset((void*)&obj, 0, sizeof(obj)); // must be cleared before call
    while(entry->getnext(entry, &obj, NULL, false) == true)
        this->get[(string)obj.name] = (char*)obj.data;
*/
//    entry->free(entry);
}

Vars::~Vars()
{
}


