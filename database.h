#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED




#include <iostream>
#include <string>
#include <windows.h>
#include <mysql.h>
#include <project.h>
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

    //hamza


            void insertProject(Project p){
            string query="insert into project(title,description,status) values('"+p.title+"','"+p.description+"','"+p.status+"')";
            const char* q = query.c_str();
            qstate = mysql_query(conn,q);
            if(!qstate)
                cout<<"Project inserted successfully..."<<endl;
            else
                cout<<"query problem: "<<mysql_error(conn)<<endl;
        }

        void updateProject(Project p){
            string query="UPDATE `project` SET `title`='"+p.title+"',`description`='"+p.description+"',`status`='"+p.status+"' WHERE id="+p.id;
            const char* q = query.c_str();
            qstate = mysql_query(conn,q);
            if(!qstate)
                cout<<"Project updated successfully..."<<endl;
            else
                cout<<"query problem: "<<mysql_error(conn)<<endl;
    }

        void deleteProject(Project p){
            string query="DELETE FROM `project` WHERE id="+p.id;
            const char* q = query.c_str();
            qstate = mysql_query(conn,q);
            if(!qstate)
                cout<<"Project deleted successfully..."<<endl;
            else
                cout<<"query problem: "<<mysql_error(conn)<<endl;
        }

        Project selectProject(string id){
            Project p;
            string query="SELECT * FROM `project` WHERE id="+id;
            const char* q = query.c_str();
            qstate = mysql_query(conn,q);

            if(!qstate)
            {
                res = mysql_store_result(conn);
                while(row=mysql_fetch_row(res))
                {
                    p.id = row[0];
                    p.title = row[1];
                    p.description = row[2];
                    p.status = row[3];
                }
            }
            else
            {
                cout<<"query error: "<<mysql_error(conn)<<endl;
            }
            return p;

        }

        list<Project> selectProjects(){
        list<Project> projects;
        string query="SELECT * FROM `project`";
        const char* q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate){
             res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {
                Project p;
                p.id = row[0];
                p.title = row[1];
                p.description = row[2];
                p.status = row[3];
                projects.push_front(p);
            }
        }

        else{
            cout<<"query problem: "<<mysql_error(conn)<<endl;
        }
        return projects;
    }

    // end hamzA
};

#endif // DATABASE_H_INCLUDED
