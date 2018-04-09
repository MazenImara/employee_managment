#include <iostream>
#include <string>
#include <login.h>
#include <iomanip>
#include <stdlib.h>
#include <day.h>
#include <gtime.h>
#include <database.h>
#include <gtime.h>
#include <database.h>
#include <task.h>
#include <employee.h>
#include <project.h>
#include <projectMenu.h>
#include <show.h>

using namespace std;



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
void showAllEmployee();
void showAllProject();
void showAllProjects();


void ShowAllTask();


int main()
{
    Database db;
    int n;
    string courseId;
	do {
		system("cls");
		PrintMessage("EMPLOYEE MANAGEMENT");
		PrintMessage("                      ", false, false);
		PrintMessage("1. LOGIN              ", false, false);
		PrintMessage("                      ", false, false);
        PrintMessage("2. CREATE DATABASE    ", false, false);
		PrintMessage("                      ", false, false);
		PrintMessage("0. EXIT               ", false, false);
		PrintMessage("                      ", false, false);


		PrintMessage("Please Select your option (0-1): ");
		cout<< ">";	cin >> n;
		switch (n)
		{
		case 1:
            AdminMenu();
        case 2:
            //ShowAllTask();
//            showAllEmployee();
            db.createDatabase();
            system("pause");
		    break;
        case 0: exit(0);break;
		default: "\a"; break;
		}


	} while (n != 0);


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
        cout <<"|    Enter the id you nedd to show his work times           |"<<endl;
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
    e.enterId();
    system("cls");
    e=db.selectEmployeeById(e.id);
    e.show();
	PrintMessage(" show Works Times for Employee    ");
    PrintMessage("                                  ", false, false);
    PrintMessage("1.  Show work details             ", false, false);
	PrintMessage("2.  Show the Tasks                ", false, false);
    PrintMessage("3.  Show Time off                 ", false, false);
    PrintMessage("                                  ", false, false);
	PrintMessage("0.  LOGOUT                        ", false, false);
    PrintMessage("                                  ", false, false);
	PrintMessage("Enter Your Choice (0-3)");
	cout<< ">";	cin >> n;
	switch (n)
	{
	case 1:
       // Show work details
        cin.get();
        cin.ignore();
	    break;
	case 2:
	    // Show the Tasks
        cin.get();
        cin.ignore();

        break;
    case 3:
        // Show Time off

        cin.get();
        cin.ignore();
        break;
   	case 0:return;
	default: cout << "\a";

	}
	workTimesMenu();
}


void ManageProjectMenu()
{
    Database db;
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
        p.enter();
        p.status = "new";
        db.insertProject(p);
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
    PrintMessage("5.  Sign Employee To Task      ", false, false);
    PrintMessage("                               ", false, false);
	PrintMessage("0.  LOGOUT                     ", false, false);
    PrintMessage("                               ", false, false);
	PrintMessage("Enter Your Choice (0-5)");
	cout<< ">";	cin >> n;
	switch (n)
	{
	case 1:
	    //add Task
	    t.enter();
	    db.insertTask(t);
	    t.showAdd();
	    system("pause");
	    break;
	case 2:
	    //Del Task
        t.enterId();
        db.deleteTask(t.id);
        system("pause");
        break;
    case 3:
        //update Task
        t.enterId();
        t.enter();
        db.updateTask(t);
        system("pause");
	    break;
    case 4:
        //show all Task
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

void EmployeeMenu()
{
    Employee e;
    int n;
    system("cls");
    ShowAllTask();

	PrintMessage("EMPLOYEE MENU");
    PrintMessage("                               ", false, false);
	PrintMessage("1.  Start Task                 ", false, false);
    PrintMessage("2.  Pause Task                 ", false, false);
	PrintMessage("3.  Finish Task                ", false, false);
    PrintMessage("4.  Manage TimeOff             ", false, false);
    PrintMessage("                               ", false, false);
	PrintMessage("0.  LOGOUT                     ", false, false);
    PrintMessage("                               ", false, false);
	PrintMessage("Enter Your Choice (0-4)");
	cout<< ">";	cin >> n;
	switch (n)
	{
	case 1:
        //Start Task
	    break;
	case 2:
        //Pause
        break;
	case 3:
        //Finish
	    break;
	case 4:
        //Manage Time off
        break;

   	case 0:return;
	default: cout << "\a";

	}
	EmployeeMenu();
}

 void ShowAllTask()
 {
    Database db ;
    list<Task> ts =  db.selectTasks();
    Task t;
    for(t:ts){
        t.show();
    }
      db.close();
}

void showAllEmployee()
{
    Database db;
    Employee e;

    list<Employee> employees;
    employees = db.selectEmployees();
    for(e :employees)
    {
        e.show();

    }
    db.close();
}

void showAllProjects(){
    Database db;
    Project p;
    list<Project> projects;
    projects = db.selectProjects();
    for(p:projects){
        p.show();
    }
    db.close();
}
