#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED
#include<employee.h>
#include <iostream>
#include <string>
#include <windows.h>
#include <mysql.h>
#include<list>

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


//mohamad code



    Employee selectEmployee(string id){
        Employee e;
        string query = "select * from  employee where id=" + id;
        const char* q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate){{}
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res)){
                e.id = row[0];
                e.name = row[1];
                e.email = row[2];
                e.password = row[3];
                e.address=row[4];
                e.phone= row[5];
            }
        }
        else{
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }
        return e;
    }
    void insertEmployee(Employee e){
        string query = "INSERT INTO `employee`( `name`,`email`,`password`, `address`,`phone`) VALUES ('"+e.name+"','"+e.email+"','"+e.password+"','"+e.address+"','"+e.phone+"')";
        const char* q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate)
            cout<<"record inserted successfully..."<<endl;
        else
            cout<<"query problem: "<<mysql_error(conn)<<endl;
    }
    void updateEmployee( Employee e){
        string query = "update  employee set name='"+e.name+"','"+e.email+"',password='"+e.password+"',address='"+e.address+"',phone='"+e.phone+"' where id="+e.id;
        const char* q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate)
            cout<<"record updated successfully..."<<endl;
        else
            cout<<"query problem: "<<mysql_error(conn)<<endl;
    }
    void deleteEmployee (string id){
        string query = "DELETE FROM `employee`  where id="+id;
        const char* q = query.c_str();
        cout <<query<<endl;
        qstate = mysql_query(conn,q);
        if(!qstate)
            cout<<"record deleted successfully..."<<endl;
        else
            cout<<"query problem: "<<mysql_error(conn)<<endl;
    }
    list<Employee> selectEmployees(){
        list <Employee> employees;
        string query = "select * from  employee" ;
        const char* q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate){
            mysql_store_result(conn);
            while(row=mysql_fetch_row(res)){
                Employee e;
                e.id = row[0];
                e.name = row[1];
                e.email=row[2];
                e.password = row[3];
                e.address  = row[4];
                e.phone = row[5];
                employees.push_back(e);
            }
        }
        else{
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }
        return employees;
    }
    Employee getLoginEmployee(Employee em){
        Employee e;
        string query = "SELECT * FROM `employee` WHERE `email` = '"+em.email+"' AND `password`= '"+em.password+"'";
        const char* q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate){
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res)){
               e.id = row[0];
               e.name = row[1];
               e.email = row[2];
               e.password = row[3];
               e.address=row[4];
               e.phone= row[5];
            }
       }
       else{
            cout<<"query error: "<<mysql_error(conn)<<endl;
       }
       return e;
    }
};
// end code Mohamad



#endif // DATABASE_H_INCLUDED
