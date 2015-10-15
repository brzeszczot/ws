#include "Bmysql.hpp"

using namespace std;

Bmysql::Bmysql()
{
}

Bmysql::Bmysql(string host, string user, string pass, string db)
{
    this->connect(host, user, pass, db);
}

void Bmysql::connect(std::string host, std::string user, std::string pass, std::string db)
{
    this->sock = mysql_init(0);

    if(!this->sock)
    {
        this->serror += mysql_error(this->sock);
        throw string("sock handle failed: "+this->serror);
    }

    if(!mysql_real_connect(this->sock, host.c_str(), user.c_str(), pass.c_str(), db.c_str(), 0, NULL, 0))
    {
        this->serror += mysql_error(this->sock);
        throw string("connection fail: "+this->serror);
    }

    mysql_set_character_set(this->sock, "utf8");
    //cout << "connection character set: " << mysql_character_set_name(this->sock) << endl;
    this->sql.clear();
    this->query_and = true;
    this->str_limit.clear();
    this->order = Bmysql::ASC;
}

void Bmysql::limit(size_t start, size_t limit)
{
    std::stringstream out;
    this->str_limit = " LIMIT ";
    if(limit==0)        out << limit << ',' << start;
    else if(limit>0)    out << start << ',' << limit;
    this->str_limit+=out.str();
}

void Bmysql::prepare_where()
{
    if(this->where.size()>0)
    {
        this->sql+=" WHERE ";
        map<string,string>::iterator it;
        size_t where_count = 0;
        for(it=this->where.begin();it!=this->where.end();++it)
        {
            this->sql+=it->first+" = '"+it->second+"'";
            if(where_count<(this->where.size()-1))
            {
                if(this->query_and)
                    this->sql+=" AND ";
                else
                    this->sql+=" OR ";
            }
            where_count++;
        }
    }
}

int Bmysql::insert(std::string table)
{
    if(this->in.size()>0)
    {
        this->sql.clear();
        this->sql+="INSERT INTO ";
        this->sql+=table+" ";

        map<string,string>::iterator it;
        size_t in_count = 0;
        string col_name = "(";
        string col_value = "(";
        for(it=this->in.begin();it!=this->in.end();++it,in_count++)
        {
            col_name+=it->first;
            col_value+="'"+it->second+"'";
            if(in_count<(this->in.size()-1))
            {
                col_name+=", ";
                col_value+=", ";
            }
        }
        col_name+=")";
        col_value+=")";
        this->sql+=col_name+" VALUES "+col_value;
        return this->query(this->sql);
    }
    return 0;
}

int Bmysql::update(std::string table)
{
    if(this->in.size()>0)
    {
        this->sql.clear();
        this->sql+="UPDATE ";
        this->sql+=table+" SET ";

        map<string,string>::iterator it;
        size_t in_count = 0;
        for(it=this->in.begin();it!=this->in.end();++it,in_count++)
        {
            this->sql+=it->first+" = '"+it->second+"'";
            if(in_count<(this->in.size()-1))
                this->sql+=", ";
        }
        this->prepare_where();
        return this->query(this->sql);
    }
    return 0;
}

int Bmysql::select(std::string table)
{
    this->sql.clear();
    this->sql+="SELECT * FROM ";
    this->sql+=table;

    this->prepare_where();
    // prepare groupby
    if(this->groupby.size()>0)
    {
        this->sql+=" GROUP BY ";
        for(size_t ii=0;ii<this->groupby.size();ii++)
        {
            this->sql+=this->groupby[ii];
            if(ii<(this->groupby.size()-1))
                this->sql+=",";
        }
    }
    // prepare orderby
    if(this->orderby.size()>0)
    {
        this->sql+=" ORDER BY ";
        for(size_t ii=0;ii<this->orderby.size();ii++)
        {
            this->sql+=this->orderby[ii];
            if(ii<(this->orderby.size()-1))
                this->sql+=",";
        }
        if(this->order==Bmysql::ASC)    this->sql+=" ASC";
        else if(this->order==Bmysql::DESC)    this->sql+=" DESC";
    }
    // prepare limit
    if(this->str_limit.size()>0)    this->sql+=this->str_limit;

    return this->query(this->sql);
}

int Bmysql::query(string sql)
{
    //this->sql = sql;
    unsigned long bytes = strlen(sql.c_str());
    int stat = mysql_real_query(this->sock, sql.c_str(), bytes);
    if(stat!=0)
    {
        this->serror = "query fail: ";
        this->serror += mysql_error(this->sock);
        throw this->serror;
    }
    long affected = mysql_affected_rows(this->sock);
    size_t found;
    found = sql.find("SELECT");
    if(found!=string::npos && found==0)
    {
        this->result = mysql_store_result(this->sock);
        //this->num_results = mysql_field_count(this->sock);
        //this->num_results = mysql_num_fields(this->result);
        this->num_results = mysql_num_rows(this->result);
        if(this->num_results==0)
            return 0;

        while((this->fields = mysql_fetch_field(this->result)) != NULL)
            this->fields_names.push_back(this->fields->name);

        while((this->row = mysql_fetch_row(this->result)) != NULL)
        {
            //unsigned long *lengths;
            //lengths = mysql_fetch_lengths(this->result);
            for(unsigned int ii=0;ii<this->fields_names.size();ii++)
                this->record[this->fields_names[ii]] = this->row[ii];
            this->results.push_back(this->record);
        }
        mysql_free_result(this->result);
        return this->num_results;
    }
    else if(affected!=-1) return affected;
    else return -1;
/*
    found = sql.find("INSERT");
    if(found!=string::npos && found==0 && affected!=-1) return affected;
    found = sql.find("UPDATE");
    if(found!=string::npos && found==0 && affected!=-1) return affected;
    found = sql.find("DELETE");
    if(found!=string::npos && found==0 && affected!=-1) return affected;
    found = sql.find("SHOW");
    if(found!=string::npos && found==0 && affected!=-1) return affected;
*/
}

Bmysql::~Bmysql()
{
    mysql_close(this->sock);
}
/*
        Bmysql bmysql("localhost","root","asas34","brzeszcz_mysql");
        int res;

        //res = bmysql.query("INSERT INTO patients (id,name,surname,bdate,sex,description) VALUES (NULL,'Anna','Gołębiewska','1986-09-29','1','Biedronka')");
        //res = bmysql.query("DELETE FROM patients WHERE name = 'Anna'");
        //res = bmysql.query("UPDATE patients SET description = 'LOOOOOOOOOOOOL' WHERE name = 'Anna'");
        //res = bmysql.query("SELECT * FROM patients");
        //res = bmysql.query();

        //bmysql.where["sex"] = "0";
        //bmysql.where["name"] = "Artur";
        //bmysql.where["1"] = "1";
        //bmysql.where["2"] = "2";
        //bmysql.query_and = false;
        //bmysql.limit(3);
        //bmysql.orderby.push_back("sex");
        //bmysql.orderby.push_back("bdate");
        //bmysql.order = Bmysql::DESC;
        //bmysql.groupby.push_back("name");
        //bmysql.groupby.push_back("sex");
        //bmysql.in["name"] = "Jan";
        //bmysql.in["surname"] = "Nowak";
        //bmysql.in["bdate"] = "1960-04-26";
        //bmysql.in["sex"] = "0";
        //bmysql.in["description"] = "LOOOOOOOOOOL";
        //res = bmysql.update("patients");
        //res = bmysql.insert("patients");
        res = bmysql.select("patients");

        //////bmysql.results[ii]["id"]
*/
