#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED
#include<employee.h>
#include <iostream>
#include <string>
#include <windows.h>
#include <mysql.h>
#include <list>
#include <task.h>
#include <project.h>
#include <day.h>
#include <sstream>
#include <ctime>
#include <timoff.h>






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
            cout<<"record delete successfully..."<<endl;
        else
            cout<<"query problem: "<<mysql_error(conn)<<endl;
    }

    void updateTask(Task t){
        string query ="UPDATE `task` SET `title`='"+t.title+"' WHERE `id` ="+t.id;
        const char* q = query.c_str();
        cout<<"query is: "<<q<<endl;
        qstate = mysql_query(conn,q);
        if(!qstate)
            cout<<"record updated successfully..."<<endl;
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
                t.project_id = row[5];
                t.employee_id =row[6];
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
                t.project_id = row[5];
                t.employee_id =row[6];
                tasks.push_back(t);

            }
        }
            else{
                    cout<<"query error: "<<mysql_error(conn)<<endl;
                }
        return tasks;
    }
    // End ikram
        void pause(Task t){
        string query ="UPDATE `task` SET `status`='"+t.pause+"' WHERE `id` ="+t.id;
        const char* q = query.c_str();
        cout<<"query is: "<<q<<endl;
        qstate = mysql_query(conn,q);
        if(!qstate)
            cout<<"record inserted successfully..."<<endl;
        else
            cout<<"query problem: "<<mysql_error(conn)<<endl;
    }
    //mohamad code


    Employee selectEmployeeById(string id){
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
    Employee selectEmployeeByEmail(string email){
        Employee e;
        string query = "select * from  employee where email='"+email+"'";
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
        string query = "update  employee set name='"+e.name+"',email='"+e.email+"',password='"+e.password+"',address='"+e.address+"',phone='"+e.phone+"' where id="+e.id;
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
        string query = "select * from  `employee`" ;
        const char* q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate){
            res=mysql_store_result(conn);
            while(row=mysql_fetch_row(res)){
                Employee e;
                e.id       = row[0];
                e.name     = row[1];
                e.email    = row[2];
                e.password = row[3];
                e.address  = row[4];
                e.phone    = row[5];
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
    list<Day> selectEmployeesWorkForPeriod(long date1,long date2 ,string id){


        Day d;
       string date3= d.longToString(date1), date4= d.longToString(date2);
        list <Day> days;
        string query = " select date, start_time ,end_time,time_spend ,employee_id from day left join employee on day.employee_id=employee.id having `date`>= '"+date3+"' and `date`<='"+date4+"'  order by employee_id";
                        // select date, start_time ,end_time,time_spend ,employee_id,time_spend from day left join employee on day.employee_id=employee.id having `date`>= '1514768400' and `date`<='1514768600'  order by employee_id;
      //  cout<<"query is "<<query ;
        const char* q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate){
            res=mysql_store_result(conn);

            while(row=mysql_fetch_row(res)){
                Day d;

                string date     = row[0];
                string start    = row[1];
                string endTime  = row[2];
                string timeSpend= row[3];
                d.employee_id   = row[4];

                d.start    =d.stringToLong(start);
                d.endTime  =d.stringToLong(endTime);
                d.date     =d.stringToLong(date);
                d.timeSpend=d.stringToLong(timeSpend);
                 if (id==d.employee_id){
                      days.push_back(d);
                 }
            }
        }
        else{
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }

        return days;
    }
    void insertDay(Day d){
        string start=d.longToString(d.start),endTime=d.longToString(d.endTime),date=d.longToString(d.date),timeSpend=d.longToString(d.timeSpend);

        string query = "INSERT INTO `day`( `start`,`end_time`,`time_spend`,`employee_id`,`date`) VALUES ('"+start+"','"+endTime+"','"+timeSpend+"','"+d.employee_id+"','"+date+"')";
        const char* q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate)
            cout<<"record inserted successfully..."<<endl;
        else
            cout<<"query problem: "<<mysql_error(conn)<<endl;
    }
    Day selectDay(string id){
        Day d;
        string query = "select * from  `day` where id=" + id;
        const char* q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate){{}
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res)){
                string start; //=d.longToString(d.start);
                string endTime;//=d.longToString(d.endTime),
                string timeSpend;//=d.longToString(d.timeSpend),
                string date; //=d.longToString(d.date);
                d.id           =row[0];
                d.employee_id  =row[1];
                date           =row[2];
                start          =row[3];
                endTime        =row[4];
                timeSpend      =row[5];
                d.start    =d.stringToLong(start);
                d.endTime  =d.stringToLong(endTime);
                d.date     =d.stringToLong(date);
                d.timeSpend=d.stringToLong(timeSpend);
            }
        }
        else{
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }
        return d;
    }
    void updateDay( Day d){

        string start=d.longToString(d.start),endTime=d.longToString(d.endTime),timeSpend=d.longToString(d.timeSpend),date=d.longToString(d.date);

        string query = "update  `day` set `start` ="+start+",`endtime` ="+endTime+",`employee_id`="+d.employee_id+",`date`="+date+" ,`timeSpend`="+timeSpend+" where id="+d.id;
        const char* q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate)
            cout<<"record updated successfully..."<<endl;
        else
            cout<<"query problem: "<<mysql_error(conn)<<endl;
    }
    void deleteDay (string id){
        string query = "DELETE FROM `day`  where id="+id;
        const char* q = query.c_str();
        cout <<query<<endl;
        qstate = mysql_query(conn,q);
        if(!qstate)
            cout<<"record deleted successfully..."<<endl;
        else
            cout<<"query problem: "<<mysql_error(conn)<<endl;
    }

    //time off process


    void insertTimeOff(TimeOff timeOf){
        Day d;
        string from=d.longToString(timeOf.from),to=d.longToString(timeOf.to);

        string query = "INSERT INTO `time_off`( `from`,`to`,`employee_id`) VALUES ('"+from+"','"+to+"','"+timeOf.employee_id+"')";
        const char* q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate)
            cout<<"record inserted successfully..."<<endl;
        else
            cout<<"query problem: "<<mysql_error(conn)<<endl;
    }
    TimeOff selectTimeOff(string id){
        TimeOff timeOf;
        Day d;
        string query = "select * from  `time_off` where id=" + id;
        const char* q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate){{}
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res)){
               // string start=d.longToString(d.start),endTime=d.longToString(d.endTime),timeSpend=d.longToString(d.timeSpend);
               timeOf.id           = row[0];
               string from         = row[1];
               string to           = row[2];
               timeOf.employee_id  = row[3];

                timeOf.from    =d.stringToLong(from);
                timeOf.to      =d.stringToLong(to);
            }
        }
        else{
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }
        return timeOf;
    }
    void updateTimeOff(TimeOff timeOf){
       Day d;
        string from=d.longToString(timeOf.from),to=d.longToString(timeOf.to);

        string query = "update  `time_off` set `from` ="+from+",`to` ="+to+",`employee_id`="+timeOf.employee_id+" where id="+timeOf.id;
        const char* q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate)
            cout<<"record updated successfully..."<<endl;
        else
            cout<<"query problem: "<<mysql_error(conn)<<endl;
    }
    void deleteTimeOff (string id){
        string query = "DELETE FROM `time_off`  where id="+id;
        const char* q = query.c_str();
        cout <<query<<endl;
        qstate = mysql_query(conn,q);
        if(!qstate)
            cout<<"record deleted successfully..."<<endl;
        else
            cout<<"query problem: "<<mysql_error(conn)<<endl;
    }


    // end code Mohamad

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

    //Start Gab
    void setAdmin(string employeeId)
    {
        if(!isAdmin(employeeId)){

            string query="insert into admin(employee_id) values("+employeeId+")";
            const char* q = query.c_str();
            qstate = mysql_query(conn,q);
            if(!qstate)
                cout<<"Project inserted successfully..."<<endl;
            else
                cout<<"query problem: "<<mysql_error(conn)<<endl;
        }
    }

    bool isAdmin(string employeeId)
    {
        bool is = false;
        string id;
        string query="SELECT * FROM `admin` WHERE employee_id="+employeeId;
        const char* q = query.c_str();
        qstate = mysql_query(conn,q);

        if(!qstate)
        {
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {
                id = row[0];
                employeeId = row[1];
            }
        }
        else
        {
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }
        if(!id.empty()){
            is = true;
        }
        return is;
    }
    //End Gab



};







#endif // DATABASE_H_INCLUDED
