#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED
#include <iostream>
#include <string>
#include <windows.h>
#include <mysql.h>
#include <task.h>
#include <list>


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

    // Start ikram
    void insertTask(Task t){
        string query ="INSERT INTO `task`(`title`) VALUES ('"+t.title+"')";
        const char* q = query.c_str();
        cout<<"query is: "<<q<<endl;
        qstate = mysql_query(conn,q);
        if(!qstate)
            cout<<"record inserted successfully..."<<endl;
        else
            cout<<"query problem: "<<mysql_error(conn)<<endl;
    }

    void deleteTask(string  id){
        string query ="DELETE FROM `Task` WHERE id ="+id;
        const char* q = query.c_str();
        cout<<"query is: "<<q<<endl;
        qstate = mysql_query(conn,q);
        if(!qstate)
            cout<<"record inserted successfully..."<<endl;
        else
            cout<<"query problem: "<<mysql_error(conn)<<endl;
    }

    void updateTask(Task t){
        string query ="UPDATE `task` SET `title`='"+t.title+"' WHERE `id` ="+t.id;
        const char* q = query.c_str();
        cout<<"query is: "<<q<<endl;
        qstate = mysql_query(conn,q);
        if(!qstate)
            cout<<"record inserted successfully..."<<endl;
        else
            cout<<"query problem: "<<mysql_error(conn)<<endl;
    }

    Task selectTask(string id){
        Task t;
        string query ="SELECT `id`, `title`, `status`, `time_spend`, `date_created`, `start`, `project_id`, `employee_id` FROM `task` WHERE `id`="+id;
        const char* q = query.c_str();
        cout<<"query is: "<<q<<endl;
        qstate = mysql_query(conn,q);
        if(!qstate)
        {
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {
                t.id = row[0];
                t.title = row[1];
                t.status = row[2];
                t.time_spend = row[3];
                t.date_created = row[4];
                t.start = row[5];
                t.project_id = row[6];
                t.employee_id =row[7];
            }
        }
            else{
                    cout<<"query error: "<<mysql_error(conn)<<endl;
                }
        return t;
    }

    list<Task>selectTasks(){
        list<Task>tasks;
        string query ="SELECT * FROM `task`";
                const char* q = query.c_str();
        cout<<"query is: "<<q<<endl;
        qstate = mysql_query(conn,q);
        if(!qstate)
        {
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {
                Task t;
                t.id = row[0];
                t.title = row[1];
                t.status = row[2];
                t.time_spend = row[3];
                t.date_created = row[4];
                t.start = row[5];
                t.project_id = row[6];
                t.employee_id =row[7];
                tasks.push_back(t);
            }
        }
            else{
                    cout<<"query error: "<<mysql_error(conn)<<endl;
                }
        return tasks;
    }
    // End ikram
};




#endif // DATABASE_H_INCLUDED

