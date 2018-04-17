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
#include <gtime.h>
#include <timoff.h>
#include <taskdetails.h>


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

    void createDatabase()
    {
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    int qstate;
    string query;
    const char* q;

    conn = mysql_init(0);
    if(conn)
        cout<<"connection object ok, conn="<<conn<<endl;
    else
        cout<<"conn object problem: "<<mysql_error(conn);
    conn = mysql_real_connect(conn,"localhost","root","",NULL,0,NULL,0);

    if(conn)
        cout<<"test without database  ok, conn="<<conn<<endl;
    else
        cout<<"conn object problem: "<<mysql_error(conn);


        // Delet if EXISTS
         query="DROP DATABASE IF EXISTS employee_managment";
        q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate){
            cout<< " database deleted successfully";
        }
        else{
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }
        // End delete

        // Create Database
         query="create database employee_managment";
         q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate){
            cout<< " database employee_managment created successfully\n";
        }
        else{
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }
        // End create

        // Create Tabeles
        // create employee
        {
        query="CREATE TABLE employee_managment.Employee(`id` int not null AUTO_INCREMENT, `name` VARCHAR(255), `email` VARCHAR(255), `password` VARCHAR(255), `address` VARCHAR(255), `phone` VARCHAR(255), PRIMARY KEY (id));";
        }
         q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate){
            cout<< "Employee Tabel created successfully\n";
        }
        else{
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }
        //end employee

        //create project
        {
        query="CREATE TABLE employee_managment.project(`id` int not null AUTO_INCREMENT, `title` VARCHAR(255), `description` VARCHAR(255), `status` VARCHAR(255), PRIMARY KEY (id))";
        }
         q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate){
            cout<< "Project Tabel created successfully\n";
        }
        else{
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }
        //end project

        //create task
        {
        query="CREATE TABLE employee_managment.task(`id` int not null AUTO_INCREMENT, `title` VARCHAR(255) DEFAULT 'NONE', `status` VARCHAR(255) DEFAULT 'NONE', `timeSpend` VARCHAR(255) DEFAULT 'NONE', `endTemp` VARCHAR(255) DEFAULT 'NONE', `startTemp` VARCHAR(255) DEFAULT 'NONE' , `project_id` int not null, `employee_id` int not null, PRIMARY KEY (id));";
        }
         q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate){
            cout<< "Task Tabel created successfully\n";
        }
        else{
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }
        //end task

        //create day
        {
        query="CREATE TABLE employee_managment.day(`id` int not null AUTO_INCREMENT, `date` VARCHAR(255), `startTime` VARCHAR(255), `endTime` VARCHAR(255), `timeSpend` INT DEFAULT '0', `employee_id` int, PRIMARY KEY (id));";
        }
         q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate){
            cout<< "Day Tabel created successfully\n";
        }
        else{
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }
        //end day

        //create time_off
        {
        query="CREATE TABLE employee_managment.time_off(`id` int not null AUTO_INCREMENT, `from` VARCHAR(255), `to` VARCHAR(255), `employee_id` int, PRIMARY KEY (id));";
        }
         q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate){
            cout<< "Time_off Tabel created successfully\n";
        }
        else{
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }
        //end time_off

        //create admin
        {
        query="CREATE TABLE employee_managment.admin(`id` int not null AUTO_INCREMENT, `employee_id` int, PRIMARY KEY (id));";
        }
         q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate){
            cout<< "Admin Tabel created successfully\n";
        }
        else{
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }
        //end admin

         //insert employee
        {
        query="INSERT INTO employee_managment.employee(`id`, `name`, `email`, `password`, `address`, `phone`) VALUES (1,'admin','admin@mail.com','admin','Norrkoping','071234567');";
        }
         q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate){
            cout<< "employee inserted successfully\n";
        }
        else{
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }
        //end employee

        //insert admin
        {
        query="INSERT INTO employee_managment.admin(`id`, `employee_id`) VALUES (1,1);";
        }
         q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate){
            cout<< "Admin inserted  successfully\n";
        }
        else{
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }
        //end admin
        mysql_close(conn);

    }

    // Start ikram
    void insertTask(Task t){
        string query ="INSERT INTO `task`(`title`, `status`,`project_id`) VALUES ('"+t.title+"', '"+t.status+"','"+t.projectId+"')";
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
        qstate = mysql_query(conn,q);
    }

    //show specific task by id
    Task selectTask(string id){
        Task t;
        string query ="SELECT * FROM `task` WHERE `id`="+id;
        const char* q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate)
        {
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {
                t.id = row[0];
                t.title = row[1];
                t.status = row[2];
                t.timeSpend = row[3];
                t.endTemp = row[4];
                t.startTemp = row[5];
                t.projectId = row[6];
                t.employeeId =row[7];
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
                t.timeSpend = row[3];
                t.endTemp = row[4];
                t.startTemp = row[5];
                t.projectId = row[6];
                t.employeeId =row[7];
                tasks.push_back(t);

            }
        }
            else{
                    cout<<"query error: "<<mysql_error(conn)<<endl;
                }
        return tasks;
    }

    /*list<TaskDetails>getSpendTimeDetails(string id){
        list<TaskDetails> details;
        string query ="SELECT * FROM `taskdetails` WHERE `task_id`="+id;
        const char* q = query.c_str();
        cout<<"query is: "<<q<<endl;
        qstate = mysql_query(conn,q);
        if(!qstate)
        {
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {
                TaskDetails td;
                td.id = row[0];
                td.taskId = row[1];
                td.employeeId = row[2];
                td.timeSpend = row[3];
                details.push_back(td);
            }
        }
        else
        {
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }
        return details;
    }*/

    /*Task getTaskDetails(string id){
        Task t;
        string query ="SELECT * FROM `task` WHERE employee_id ="+id;
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
                t.endtemp = row[4];
                t.starttemp = row[5];
                t.project_id = row[6];
                t.employee_id =row[7];
            }
        }
            else{
                    cout<<"query error: "<<mysql_error(conn)<<endl;
                }
        return t;
    }*/

    //Ikram + Gab
    void startTask(string taskId, string employeeId){
        CustomTime c;
        Day d;
        string checkStatus;
        string query ="SELECT * FROM `task` WHERE `id`="+taskId;
        const char* q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate)
        {
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {
                checkStatus = row[2];
            }
        }
        else
        {
            cout<<"query problem: "<<mysql_error(conn)<<endl;
        }

        long current = CustomTime().getTimestampDate();
        string getTimestamp = d.longToString(current);
        if(checkStatus == "Ended")
        {
            cout << "Its already Ended, Start a New Task instead" << endl;
        }
        else
        {
        string query2 ="UPDATE `task` SET `status`='Started',`startTemp`='"+getTimestamp+"', `employee_id`='"+employeeId+"' WHERE id="+taskId;
        const char* q2 = query2.c_str();
        qstate = mysql_query(conn,q2);
        }
        cout << "muu" << endl;
    }


    void pauseTask(string id){
        Day d;
        CustomTime c;

        string checkStatus;
        string startTime;
        string getTimeSpend;
        long current = CustomTime().getTimestampDate();
        string getTimestamp = d.longToString(current);


        string query ="SELECT * FROM `task` WHERE `id`="+id;
        const char* q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate)
        {
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {
                checkStatus = row[2];
                getTimeSpend = row[3];
                startTime = row[5];
            }
        }
        else
        {
            cout<<"query problem: "<<mysql_error(conn)<<endl;
        }

        if(checkStatus == "Paused" || checkStatus == "Ended")
        {
            cout << "Its already in pause, Start the Task instead" << endl;
        }
        else
        {
        string query1="UPDATE `task` SET `status`='Paused',`endTemp`='"+getTimestamp+"' WHERE `id`="+id;
        const char* q1 = query1.c_str();
        qstate = mysql_query(conn,q1);
        }

        long GetTimeSpend = atol(getTimeSpend.c_str());
        long getStartTime = atol(startTime.c_str());
        long result = current - getStartTime;
        long newResult = result + GetTimeSpend;

        c = CustomTime(newResult);

        stringstream re;    re<<newResult;   string lastResult = re.str();

        string FullDate = c.date() + " " + c.Time();
        cout << c.Time()  << endl;

        if(checkStatus == "Paused" || checkStatus == "Ended")
        {

        }
        else
        {
        string query3 ="UPDATE `task` SET `timeSpend`="+lastResult+" WHERE `id`="+id;
        const char* q3 = query3.c_str();
        qstate = mysql_query(conn,q3);
        }
        cout << result << endl;
    }

    void endTask(string id){
        Day d;
        CustomTime c;
        string checkStatus;
        string startTime;
        string getTimeSpend;
        long current = CustomTime().getTimestampDate();
        string getTimestamp = d.longToString(current);

        string query ="SELECT * FROM `task` WHERE `id`="+id;
        const char* q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate)
        {
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {
                checkStatus = row[2];
                getTimeSpend = row[3];
                startTime = row[5];
            }
        }
        else
        {
            cout<<"query problem: "<<mysql_error(conn)<<endl;
        }
        if(checkStatus == "Paused" || checkStatus == "Ended")
        {
            cout << "Its already Ended, Start a New Task instead" << endl;
        }
        else
        {
        string query1="UPDATE `task` SET `status`='Ended',`endTemp`='"+getTimestamp+"' WHERE `id`="+id;
        const char* q1 = query1.c_str();
        qstate = mysql_query(conn,q1);
        }

        long GetTimeSpend = atol(getTimeSpend.c_str());
        long getStartTime = atol(startTime.c_str());
        long result = current - getStartTime;
        long newResult = result + GetTimeSpend;

        c = CustomTime(newResult);
        stringstream re;    re<<newResult;   string lastResult = re.str();
        if(checkStatus == "Paused" || checkStatus == "Ended"){}
        else
        {
        string query3 ="UPDATE `task` SET `timeSpend`='"+lastResult+"' WHERE `id`="+id;
        const char* q3 = query3.c_str();
        qstate = mysql_query(conn,q3);
        }
    }
    // End ikram



    //MOHAMAD code

    // Employee process.
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

    //day process.
    list<Day> selectEmployeesWorkForPeriod(long date1,long date2 ,string id){

        Day d;
       string date3= d.longToString(date1), date4= d.longToString(date2);
        list <Day> days;
        string query = " select date, start_time ,end_time,time_spend ,employee_id from day left join employee on day.employee_id=employee.id having `date`>= '"+date3+"' and `date`<='"+date4+"'  order by employee_id";
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
                d.employeeId   = row[4];

                d.start    =d.stringToLong(start);
                d.endTime  =d.stringToLong(endTime);
                d.date     =d.stringToLong(date);
                d.timeSpend=d.stringToLong(timeSpend);
                 if (id==d.employeeId){
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

        string query = "INSERT INTO `day`( `start`,`endTime`,`timeSpend`,`employee_id`,`date`) VALUES ('"+start+"','"+endTime+"','"+timeSpend+"','"+d.employeeId+"','"+date+"')";
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
                d.employeeId  =row[1];
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

        string query = "update  `day` set `start` ="+start+",`endTime` ="+endTime+",`employee_id`="+d.employeeId+",`date`="+date+" ,`timeSpend`="+timeSpend+" where id="+d.id;
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

        string query = "INSERT INTO `time_off`( `from`,`to`,`employee_id`) VALUES ('"+from+"','"+to+"','"+timeOf.employeeId+"')";
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
               timeOf.employeeId  = row[3];

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

        string query = "update  `time_off` set `from` ="+from+",`to` ="+to+",`employee_id`="+timeOf.employeeId+" where id="+timeOf.id;
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
    list<TimeOff>selectTimesOff( string employeeId){
        list<TimeOff>timesOff;
        string query ="SELECT * from `time_off` WHERE employee_id="+employeeId;
        const char* q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate)
        {
            res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {
                TimeOff timeOf;
                Day d;
                timeOf.id           = row[0];
                string from         = row[1];
                string to           = row[2];
                timeOf.employeeId  = row[3];

                timeOf.from    =d.stringToLong(from);
                timeOf.to      =d.stringToLong(to);

                timesOff.push_back(timeOf);

            }
        }
            else{
                    cout<<"query error: "<<mysql_error(conn)<<endl;
                }
        return timesOff;
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
            string query="UPDATE `project` SET `title`='"+p.title+"',`description`='"+p.description+"' WHERE id="+p.id;
            const char* q = query.c_str();
            qstate = mysql_query(conn,q);
            if(!qstate)
                cout<<"Project updated successfully..."<<endl;
            else
                cout<<"query problem: "<<mysql_error(conn)<<endl;
    }

        void deleteProject(string id){
            string query="DELETE FROM `project` WHERE id="+id;
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

    list<Task>selectProjectTasks( string projectId){
        list<Task>tasks;
        string query ="SELECT * FROM `task` WHERE project_id="+projectId;
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
                t.timeSpend = row[3];
                t.endTemp = row[4];
                t.startTemp = row[5];
                t.projectId = row[6];
                t.employeeId =row[7];
                tasks.push_back(t);

            }
        }
            else{
                    cout<<"query error: "<<mysql_error(conn)<<endl;
                }
        return tasks;
    }

    list<Task>selectEmployeeTasks( string employeeId){
        list<Task>tasks;
        string query ="SELECT * FROM `task` WHERE employee_id="+employeeId;
        const char* q = query.c_str();
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
                t.timeSpend = row[3];
                t.endTemp = row[4];
                t.startTemp = row[5];
                t.projectId = row[6];
                t.employeeId =row[7];
                tasks.push_back(t);

            }
        }
            else{
                    cout<<"query error: "<<mysql_error(conn)<<endl;
                }
        return tasks;
    }

    // end hamzA

    //Start Gab
    void setAdmin(string employeeId)
    {
        if(!isAdmin(employeeId)){

            string query="insert into admin(employee_id) values("+employeeId+")";
            const char* q = query.c_str();
            qstate = mysql_query(conn,q);
        }
    }

    void setEmployeTask(string taskId,string employeeId)
    {
        string query ="UPDATE `task` SET `employee_id`='"+employeeId+"' WHERE `id` ="+taskId;
        const char* q = query.c_str();
        qstate = mysql_query(conn,q);
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
