#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED




#include <iostream>
#include <string>
#include <windows.h>
#include <mysql.h>

using namespace std;


class Database{
public:
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    int qstate;
    Database(){
        conn = mysql_init(0);
        if(conn)
            cout<<"connection object ok, conn="<<conn<<endl;
        else
            cout<<"conn object problem: "<<mysql_error(conn);

        conn = mysql_real_connect(conn,"localhost","root","","employee_managment",0,NULL,0);

        if(conn)
            cout<<"connect to data base  successfully..."<<endl;
        else
            cout<<"conn object problem: "<<mysql_error(conn);
    }
    void close(){
        mysql_close(conn);
    }
};

#endif // DATABASE_H_INCLUDED
