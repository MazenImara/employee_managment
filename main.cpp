
#include <iostream>
#include <string>
//#include <windows.h>
#include <mysql.h>
#include <employee_managment.h>

using namespace std;
// all method headers:


// end of all method headers



// mohamed

// end mohamed

// mazen database class
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

        conn = mysql_real_connect(conn,"localhost","root","","c_test",0,NULL,0);

        if(conn)
            cout<<"connect to data base  successfully..."<<endl;
        else
            cout<<"conn object problem: "<<mysql_error(conn);
    }
    void close(){
        mysql_close(conn);
    }
};
// end mazen database class

int main()
{
    print();
    return 0;
}
