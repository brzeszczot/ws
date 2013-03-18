// Web Service 18.03.2013
// brzeszczot@gmail.com
#include <iostream>
#include "Vars.hpp"
#include "qdecoder.h"

//#include <boost/regex.hpp>
//const boost::regex reg_int("[0-9]{1,3}");
//    if(boost::regex_match(this->post["name"], reg_int))
//        cout << " GOOD! " << endl;

using namespace std;

int main()
{
    Vars *v = new Vars();


    qentry_t *req = qcgireq_parse(NULL, Q_CGI_GET);

    char *value = (char *)req->getstr(req, "query", false);
    if (value == NULL) value = "(nothing)";
    string sss(value);

    //qcgires_setcontenttype(req, "text/html");
    cout << "Content-type: text/html" << endl << endl;// dwie nowe linie!!!!!!!
    cout << "You entered: " << sss << endl;

    req->free(req);

    return 0;
}
