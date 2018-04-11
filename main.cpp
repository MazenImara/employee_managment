//#include <timeOff.h>
#include <iostream>
#include <string>
#include <login.h>
#include <iomanip>
#include <stdlib.h>
#include <day.h>
#include <gtime.h>
#include <database.h>
#include <gtime.h>
#include <employee.h>
#include <project.h>
#include <projectMenu.h>
#include <show.h>
#include <timoff.h>


using namespace std;

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
        query="CREATE TABLE employee_managment.task(`id` int not null AUTO_INCREMENT, `title` VARCHAR(255), `status` VARCHAR(255), `time_spend` INT, `endtemp` TIMESTAMP, `starttemp` TIMESTAMP , `project_id` int, `employee_id` int, PRIMARY KEY (id));";
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

        //create status
        {
        query="CREATE TABLE employee_managment.status(`id` int not null AUTO_INCREMENT, `start` VARCHAR(255), `pause` VARCHAR(255), `task_id` int, PRIMARY KEY (id));";
        }
         q = query.c_str();
        qstate = mysql_query(conn,q);
        if(!qstate){
            cout<< "Task-status Tabel created successfully\n";
        }
        else{
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }
        //end status

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

void PrintMessage(string message, bool printTop = true, bool printBottom = true)
{
	if (printTop)
	{

		cout << "+----------------------------------------+" << endl;
		cout << "|";
	}
	else
	{
		cout << "|";
	}
	bool front = true;
	for (int i = message.length(); i < 40; i++)
	{
		if (front)
		{
			message = " " + message;
		}
		else
		{
			message = message + " ";
		}
		front = !front;
	}
	cout << message.c_str();
	if (printBottom)
	{
		cout << "|" << endl;
		cout << "+----------------------------------------+" << endl;
	}
	else
	{
		cout << "|" << endl;
	}
}
using namespace std;


/*
void manageEmployeeMenu();
void employeeMenu();
void manageProjectMenu();
void projectUpdateMenu();
void manageTaskMenu();
*/



void AdminMenu();
void ManageEmployeeMenu();
void EmployeeMenu();
void ManageProjectMenu();
void ManageTaskMenu();
void manageProjectMenu();
void workTimesMenu();

void showAllProject()
{

}

void ShowAllTask();



int main()
{
    int n;
    string courseId;
	do {
		//system("cls");
		PrintMessage("EMPLOYEE MANAGEMENT");
		PrintMessage("                      ", false, false);
		PrintMessage("1. LOGIN              ", false, false);
		PrintMessage("                      ", false, false);
		PrintMessage("0. EXIT               ", false, false);
		PrintMessage("                      ", false, false);

        PrintMessage("2. CREATE DATABASE    ", false, false);
		PrintMessage("                      ", false, false);


		PrintMessage("Please Select your option (0-1): ");
		cout<< ">";	cin >> n;
		switch (n)
		{
		case 1:
            AdminMenu();
		    break;

        case 2:
            createDatabase();
            system("pause");
		    break;

        case 0: exit(0);
		default: "\a"; break;
		}


	} while (n != 0);




 // test Mohamad




//ent test Mohamad

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

void AdminMenu()
{
    int n;
    system("cls");
	PrintMessage("ADMIN MANAGE EMPLOYEE");
    PrintMessage("                               ", false, false);
	PrintMessage("1.  Management Project         ", false, false);
    PrintMessage("2.  Management Employee        ", false, false);
    PrintMessage("                               ", false, false);
	PrintMessage("0.  LOGOUT                     ", false, false);
    PrintMessage("                               ", false, false);
	PrintMessage("Enter Your Choice (0-5)");
	cout<< ">";	cin >> n;
	switch (n)
	{
	case 1:
        ManageProjectMenu();
	    break;
	case 2:
        ManageEmployeeMenu();
        break;

   	case 0:return;
	default: cout << "\a";

	}
	AdminMenu();
}


void ManageEmployeeMenu()
{
    Employee e;
    Database db;
    Show s;
    int n;
    system("cls");
	PrintMessage("ADMIN MANAGE EMPLOYEE");
    PrintMessage("                               ", false, false);
	PrintMessage("1.  Create Employee            ", false, false);
    PrintMessage("2.  Update Employee            ", false, false);
    PrintMessage("3.  Delete Employee            ", false, false);
    PrintMessage("4.  Show all Employees         ", false, false);
    PrintMessage("5.  Sign Employee as Admin     ", false, false);
    PrintMessage("                               ", false, false);
	PrintMessage("0.  LOGOUT                     ", false, false);
    PrintMessage("                               ", false, false);
	PrintMessage("Enter Your Choice (0-5)");
	cout<< ">";	cin >> n;
	switch (n)
	{
	case 1:{
	    //Create Employee
	    e.enter();
	    db.insertEmployee(e);
	    e=db.selectEmployeeByEmail(e.email);
	    e.show();
        cin.get();
        cin.ignore();
	}
	    break;
	case 2:{
        //Update Employee
        s.Employee();
        e.enterId();
        e=db.selectEmployeeById(e.id);
        e.show();
        cout<<"enter new details "<<endl;
        e.enter();
        db.updateEmployee(e);
        cin.get();
        cin.ignore();
	}
        break;
    case 3:{
        //Delete Employee
        s.Employee();
        e.enterId();
        e=db.selectEmployeeById(e.id);
        e.show();
        cout<<"are you sure press Y/N"<<endl;
        string  choice;
        cin>>choice ;
        if (choice=="y" || choice=="Y"){
            db.deleteEmployee(e.id);
        }
        cin.get();
        cin.ignore();
    }
	    break;
    case 4:{
        //Show all Employees
        system("cls");
        s.Employee();
        cout <<" ___________________________________________________________"<<endl;
        cout <<"|    Enter the id you need to show  the work's detail       |"<<endl;
        cout <<"|___________________________________________________________|"<<endl;

        workTimesMenu();
        cin.get();
        cin.ignore();
    }
	    break;
    case 5 :{
        //Sign Employee as Admin


    }
   	case 0:return;
	default: cout << "\a";

	}
	ManageEmployeeMenu();
}
void workTimesMenu(){
    int n;
    Employee e;
    Database db;
    Show s;
    e.enterId();
    system("cls");
    e=db.selectEmployeeById(e.id);
    e.show();
	PrintMessage(" show Works Times for Employee          ");
    PrintMessage("                                        ", false, false);
    PrintMessage("1.  Show works details for date period  ", false, false);
	PrintMessage("2.  Show the Tasks                      ", false, false);
    PrintMessage("3.  Show Time off                       ", false, false);
    PrintMessage("                                        ", false, false);
	PrintMessage("0.  LOGOUT                              ", false, false);
    PrintMessage("                                        ", false, false);
	PrintMessage("Enter Your Choice (0-5)");
	cout<< ">";	cin >> n;
	switch (n)
	{
	case 1:{
       // Show work details
       cout <<"+---------------------------------------------------------+"<<endl;
       cout <<"|Enter the date period that you need to show work details |"<<endl;
       cout <<"+---------------------------------------------------------+"<<endl;
       CustomTime t;
       string date1=e.getDate(),date2=e.getDate();
       date1 =date1+" "+ "00"+ ":" + "00" + ":" + "00";
       date2 =date2+" "+ "00"+ ":" + "00" + ":" + "00";
       long date3=t.getTimestampDate(date1);
       long date4=t.getTimestampDate(date2);
       s.Days(date3,date4,e.id);
       cin.get();
       cin.ignore();
	}
	    break;
	case 2:
	    // Show the Tasks

        cin.get();
        cin.ignore();

        break;
    case 3:{
        // Show Time off

        TimeOff timeOf;
        timeOf=db.selectTimeOff(e.id);

        timeOf.show();
        cin.get();
        cin.ignore();
    }
        break;
   	case 0:return;
	default: cout << "\a";

	}
	workTimesMenu();
}


void ManageProjectMenu()
{
    Project p;
    int n;
    system("cls");
	PrintMessage("MANAGE PROJECT");
    PrintMessage("                               ", false, false);
	PrintMessage("1.  Show Project/Enter Task    ", false, false);
    PrintMessage("2.  Add Project                ", false, false);
    PrintMessage("3.  Deleted Project            ", false, false);
    PrintMessage("4.  Update Project             ", false, false);
    PrintMessage("                               ", false, false);
	PrintMessage("0.  LOGOUT                     ", false, false);
    PrintMessage("                               ", false, false);
	PrintMessage("Enter Your Choice (0-4)");
	cout<< ">";	cin >> n;
	switch (n)
	{
	case 1:
	    ManageTaskMenu();
	    system("pause");
	    break;
	case 2:
        //
        break;
    case 3:
        //
	    break;
   	case 0:return;
	default: cout << "\a";

	}
	ManageProjectMenu();
}

void ManageTaskMenu()
{
    Task t;
    Database db;
    int n;
    system("cls");
	PrintMessage("MANAGE TASK");
    PrintMessage("                               ", false, false);
	PrintMessage("1.  Add Task                   ", false, false);
    PrintMessage("2.  Delete Task                ", false, false);
    PrintMessage("3.  Update Task                ", false, false);
    PrintMessage("4.  Show All Task              ", false, false);
    PrintMessage("4.  Sign Employee To Task      ", false, false);
    PrintMessage("                               ", false, false);
	PrintMessage("0.  LOGOUT                     ", false, false);
    PrintMessage("                               ", false, false);
	PrintMessage("Enter Your Choice (0-4)");
	cout<< ">";	cin >> n;
	switch (n)
	{
	case 1:
	    t.enter();
	    db.insertTask(t);
	    t.showAdd();
	    system("pause");
	    break;
	case 2:
        t.enterId();
        db.deleteTask(t.id);
        system("pause");
        break;
    case 3:
        t.enterId();
        t.enter();
        db.updateTask(t);
        system("pause");
	    break;
    case 4:
        ShowAllTask();

	    system("pause");
	    break;
    case 5:
        //
	    break;
   	case 0:return;
	default: cout << "\a";

	}
	ManageTaskMenu();
}



/*
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
*/

 void ShowAllTask()
 {
     Database db;
     Task t;

     list<Task> tasks;
     tasks = db.selectTasks();
     for(Task t : tasks)
     {
         t.show();
     }
      db.close();
}


