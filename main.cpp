#include <iostream>
#include <string>
#include <login.h>
#include <iomanip>
#include <stdlib.h>
#include <day.h>
#include <gtime.h>
#include <database.h>

using namespace std;
void manageEmployeeMenu();
void employeeMenu();
void manageProjectMenu();
void showProjectsMenu();
void projectUpdateMenu();
void manageTaskMenu();

#include <gtime.h>

using namespace std;
/*
void createDatabase(){
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
    conn = mysql_real_connect(conn,"localhost","root","password",NULL,0,NULL,0);

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
        query="CREATE TABLE employee_managment.project(`id` int not null AUTO_INCREMENT, `title` VARCHAR(255), `description` VARCHAR(255), `status` VARCHAR(255), PRIMARY KEY (id));";
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
        query="CREATE TABLE employee_managment.task(`id` int not null AUTO_INCREMENT, `title` VARCHAR(255), `status` VARCHAR(255), `time_spend` VARCHAR(255), `created` VARCHAR(255), `start` VARCHAR(255), `project_id` int, `employee_id` int, PRIMARY KEY (id));";
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
        mysql_close(conn);

}
*/


int main()
{ // test Mohamad


//ent test Mohamad


/*
    CustomTime c;
    cout << c.date() << "  " << c.Time() << endl;
    c.getTimestampDate("2018/10/11 23:15:13");
    //c.getTimestampDate("2017/07/26 00:00:00");
*/

/*

    Loging l;
    while(!l.loged){
        cin.get();
        cin.ignore();
        system("cls");
        l.login();
    }
    if(l.loged){
        if(l.e.isAdmin()){
            //adminMenu(l);
            cout<< "admin"<< endl;
            l.e.show();
        }
        else{
            //employeeMenu(l);
            cout<< "employee"<< endl;
            l.e.show();
            //l.e.setAdmin();
        }
    }
*/

    return 0;
}

void manageEmployeeMenu(){
    int choice;
    cout << "==========================================" <<endl;
    cout << right << setw(25) << "Manage Employee" <<endl;
    cout << "==========================================" <<endl;
    cout << endl;
    cout << " 1. Add Employee" << endl;
    cout << " 2. Update Employee" << endl;
    cout << " 3. Delete Employee" << endl;
    cout << " 4. Show All Employees" << endl;
    cout << " 5. Sign Employee as admin" << endl;
    cout << " 6. Back" << endl;
    cout << " \n Enter your choice(1-6):";
    cin >> choice;
    switch(choice){
        case 1:cout << " 1. Add Employee" << endl;break;
        case 2:break;
        case 3:break;
        case 4:break;
        case 5:break;
        case 6:break;
    }


}

void employeeMenu(){
    int choice;
    cout << "==========================================" <<endl;
    cout << right << setw(25) << "Hello Employee" <<endl;
    cout << "==========================================" <<endl;
    cout << endl;
    cout << " 1. START" << endl;
    cout << " 2. PAUSE" << endl;
    cout << " 3. FINISH" << endl;
    cout << " 4. MANAGE TIMEOFF" << endl;
    cout << " 5. LOGOUT" << endl;
    cout << " \n Enter your choice(1-5):";
    cin >> choice;
    switch(choice){
        case 1:cout << " 1. START" << endl;break;
        case 2:cout << " 2. PAUSE" << endl;break;
        case 3:cout << " 3. FINISH" << endl;break;
        case 4:cout << " 4. MANAGE TIMEOFF" << endl;break;
        case 5:cout << " 5. LOGOUT" << endl;break;
   }
 }

 void manageProjectMenu(){
    int choice;
    cout << "==========================================" <<endl;
    cout << right << setw(25) << "Manage Project" <<endl;
    cout << "==========================================" <<endl;
    cout << endl;
    cout << " 1. Show all project" << endl;
    cout << " 2. Add project" << endl;
    cout << " 3. Back" << endl;
    cout << " \n Enter your choice(1-3):";
    cin >> choice;
    switch(choice){
        case 1:
            cout << " 1. Show all project" << endl;
            showProjectsMenu();
            break;
        case 2:cout << " 1. Add project" << endl;break;
        case 3:cout << "back"<< endl;break;
        default:break;
    }
 }
void showProjectsMenu(){
    int choice;
    cout << "==========================================" <<endl;
    cout << right << setw(25) << " Show project" <<endl;
    cout << "==========================================" <<endl;
    cout << endl;
    cout << " 1. Update project   " << endl;
    cout << " 2. Delete project" << endl;
    cout << " 3. Back" << endl;
    cout << " \n Enter your choice(1-3):";
    cin >> choice;
    switch(choice){
        case 1:
            cout << " 1. Update project" << endl;
            projectUpdateMenu();
            break;
        case 2:cout << " 2. Delete project" << endl;break;
        case 3:cout << " 3. Back"<< endl;break;
        default:break;

    }
}
void projectUpdateMenu(){
    int choice;
    cout << "==========================================" <<endl;
    cout << right << setw(25) << " Update project" <<endl;
    cout << "==========================================" <<endl;
    cout << endl;
    cout << " 1. Update details   " << endl;
    cout << " 2. Mange task" << endl;
    cout << " 3. Back" << endl;
    cout << " \n Enter your choice(1-3):";
    cin >> choice;
    switch(choice){
        case 1:cout << " 1. Update details" << endl;break;
        case 2:
            cout << " 2. Mange task" << endl;
            manageTaskMenu();
            break;
        case 3:cout << " 3. Back"<< endl;break;
        default:break;

    }
}
void manageTaskMenu(){
    int choice;
    cout << "==========================================" <<endl;
    cout << right << setw(25) << " Manage task" <<endl;
    cout << "==========================================" <<endl;
    cout << endl;
    cout << " 1. Add task   " << endl;
    cout << " 2. Delete" << endl;
    cout << " 3. Update task" << endl;
    cout << " 4. Show task" << endl;
    cout << " 5. Sign Employee to task" << endl;
    cout << " 6. Back" << endl;
    cout << " \n Enter your choice(1-6):";
    cin >> choice;
    switch(choice){
        case 1:cout << " 1. Add tasl" << endl;break;
        case 2:cout << " 2. Delete task" << endl;break;
        case 3:cout << " 3. Update task" << endl;break;
        case 4:cout << " 4. Show task" << endl;break;
        case 5:cout << " 5. Sign Employee to task"<< endl;break;
        case 6:cout << " 6. Back"<< endl;break;
        default:break;
    }
}


void manageTimeOff(){
    int choice;
    cout << "==========================================" <<endl;
    cout << right << setw(25) << "Manage Time Off" <<endl;
    cout << "==========================================" <<endl;
    cout << endl;
    cout << " 1. Add" << endl;
    cout << " 2. Delete" << endl;
    cout << " 0. Back to Employee Menu" << endl;
    cout << " \n Enter your choice(0-2):";
    cin >> choice;
    switch(choice){
        case 1:cout << " 1. Add" << endl;break;
        case 2:cout << " 2. Delete" << endl;break;
        case 0:cout << " 0. Back to Employee Menu" << endl;break;
    }
 }


