#ifndef BMYSQL_HPP_INCLUDED
#define BMYSQL_HPP_INCLUDED

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <mysql/mysql.h>
#include <cstring>

class Bmysql
{
    private:
        MYSQL *sock;
        MYSQL_RES *result;
        MYSQL_FIELD *fields;
        MYSQL_ROW row;
        std::string serror;
    public:
        Bmysql();
        Bmysql(std::string host, std::string user, std::string pass, std::string db);
        virtual ~Bmysql();
        void connect(std::string host, std::string user, std::string pass, std::string db);
        int query(std::string sql = "SHOW TABLES");
        int select(std::string table);
        int update(std::string table);
        int insert(std::string table);
        void limit(size_t start = 0, size_t limit = 0);
        std::vector<std::string> fields_names;
        typedef std::map<std::string, std::string> REC;
        REC record;
        std::vector<Bmysql::REC> results;
        unsigned int num_results;
        void prepare_where();
        std::map<std::string,std::string> where;
        std::map<std::string,std::string> in;
        bool query_and;
        std::string str_limit;
        std::string sql;
        std::vector<std::string> orderby;
        enum SORT {ASC,DESC};
        SORT order;
        std::vector<std::string> groupby;
};

#endif // BMYSQL_HPP_INCLUDED
