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

using namespace std;

Loging l;

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

//Headers
void AdminMenu();
void ManageEmployeeMenu();
void EmployeeMenu();
void ManageProjectMenu();
void ManageTaskMenu(string ProId);
void TimeOffMenu();
void manageProjectMenu();
void workTimesMenu(string id);
void showAllEmployee();
void showAllProject();
void showAllProjects();
void inbtwInsertEmployee();
void inbtwUpdateEmployee();
void inbtwDeleteEmployee();
void inbtwShowEmployees();
void inbtwSignEmployeeAsAdmin();
void inbtwShowWorkDetails(string id);
void inbtwShowTaskForEmployee(string id);
void inbtwShowTimeOff(string id);


void ShowAllTask();
/*
int main()
{
    Task t;
    Database db;
    db.startTask("1","1");
   // db.endTask("1");
    t = db.selectTask("1");
    CustomTime c (stringToLong(t.time_spend));
    cout << c.hour << ":" << c.minut;
}

*/

/*
int main()
{
<<<<<<< HEAD
    Task t;
    Database db;
    t.enterId();
    t = db.selectTask(t.id);
    long timestamp = stringToLong(t.time_spend);
    timestamp = timestamp - 3600;
    CustomTime ct(timestamp);
    cout<< ct.hour<< ":" << ct.minut;


}
*/
int main()
{
    int n;
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


		PrintMessage("Please Select your option (0-2): ");
		cout<< ">";	cin >> n;
		switch (n)
		{
		case 1:
            while(!l.loged)
            {
                system("cls");
                l.login();
            }
            if(l.loged)
            {
                if(l.e.isAdmin())
                {
                    AdminMenu();
                    l.logout();
                }
                else
                {
                    EmployeeMenu();
                    l.logout();
                }
            }
            else{
                l.logout();
            };
            break;

        case 2:
            createDatabase();
            system("pause");
		    break;

        case 0: exit(0);
		default: "\a"; break;
		}
	} while (n != 0);
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

   	case 0:
   	    l.logout();
        return;
	default: cout << "\a";

	}
	AdminMenu();
}

//Mohamad code updated
void ManageEmployeeMenu()
{
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
	PrintMessage("0.  Back to Admin Menu         ", false, false);
    PrintMessage("                               ", false, false);
	PrintMessage("Enter Your Choice (0-5)");
	cout<< ">";	cin >> n;
	switch (n)
	{
	case 1:{
	    //Create Employee
	    inbtwInsertEmployee();
        system("pause");
	}
	    break;
	case 2:{
        //Update Employee
        inbtwUpdateEmployee();
        system("pause");
	}
        break;
    case 3:{
        //Delete Employee
        inbtwDeleteEmployee();
        system("pause");
    }
	    break;
    case 4:{
        //Show all Employees
        system("cls");
        inbtwShowEmployees();
        system("pause");
    }
	    break;
    case 5 :{
        //Sign Employee as Admin
        inbtwSignEmployeeAsAdmin();
        system("pause");
    }
   	case 0:return;
	default: cout << "\a";
	}
	ManageEmployeeMenu();
}
//end updated

void workTimesMenu(string id){
    int n;
	PrintMessage(" show Works Times for Employee          ");
    PrintMessage("                                        ", false, false);
    PrintMessage("1.  Show works details for date period  ", false, false);
	PrintMessage("2.  Show the Tasks                      ", false, false);
    PrintMessage("3.  Show Time off                       ", false, false);
    PrintMessage("                                        ", false, false);
	PrintMessage("0.  Back                                ", false, false);
    PrintMessage("                                        ", false, false);
	PrintMessage("Enter Your Choice (0-5)");
	cout<< ">";	cin >> n;
	switch (n)
	{
	case 1:{
       // Show work details
        inbtwShowWorkDetails(id);
        system("pause");
	}
	    break;
	case 2:{
	    // Show the Tasks
	    inbtwShowTaskForEmployee(id);
        system("pause");
    }
        break;
    case 3:{
        // Show Time off
        inbtwShowTimeOff(id);
        system("pause");
    }
        break;
   	case 0:return;
	default: cout << "\a";

	}
	system("cls");
	workTimesMenu(id);
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
    PrintMessage("3.  Delete Project            ", false, false);
    PrintMessage("4.  Update Project             ", false, false);
    PrintMessage("                               ", false, false);
	PrintMessage("0.  Back to Admin Menu         ", false, false);
    PrintMessage("                               ", false, false);
	PrintMessage("Enter Your Choice (0-4)");
	cout<< ">";	cin >> n;
	switch (n)
	{
	case 1:
	    //show and enter task menu
        showAllProjects();
        p.enterId();
	    ManageTaskMenu(p.id);
	    break;
	case 2:
	    //create project
        p.Add();
        break;
    case 3:
        //delete project
        p.enterId();
        p.Delete(p.id);
        system("pause");
	    break;
    case 4:
        //update Project
        p.Update();
        break;
   	case 0:return;
	default: cout << "\a";

	}
	ManageProjectMenu();
}

void ManageTaskMenu(string ProId)
{
    Task t;
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
	PrintMessage("0.  Back to Manage Project     ", false, false);
    PrintMessage("                               ", false, false);
	PrintMessage("Enter Your Choice (0-5)");
	cout<< ">";	cin >> n;
	switch (n)
	{
	case 1:
	    //create Task
	    t.Add(ProId);
	    break;
	case 2:
	    //Delete Task
        t.enterId();
        t.Delete(t.id);
        break;
    case 3:
        //update Task
        t.Update();
	    break;
    case 4:
        //show all Task
        ShowAllTask();
	    system("pause");
	    break;
    case 5:
        //Sign Employee to Task
        t.setEmployeTask();
	    break;
   	case 0:return;
	default: cout << "\a";

	}
	ManageTaskMenu(ProId);
}

void EmployeeMenu()
{

    Employee e;
    Task t;
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
        cout<< "for task ";
        t.enterId();
        t.start(t.id, l.e.id);
	    break;
	case 2:
        //Pause
        t.enterId();
        t.pause(t.id);
        break;
	case 3:
        //Finish
        t.enterId();
        t.ended(t.id);
	    break;
	case 4:{
        //Manage Time off
	    TimeOffMenu();
	}
        break;
   	case 0:
        l.logout();
        return;
	default: cout << "\a";

	}
	EmployeeMenu();
}
void TimeOffMenu(){
    TimeOff timeOf;
    Database db;
    int n;
    string choice;
    Show s;
    system("cls");
    PrintMessage("MANAGE TimeOff");
    PrintMessage("                               ", false, false);
    PrintMessage("1.  Show your TimesOff         ", false, false);
    PrintMessage("2.  Add TimeOff                ", false, false);
    PrintMessage("3.  Update TimeOff             ", false, false);
    PrintMessage("4.  Delete  TimeOff            ", false, false);
    PrintMessage("                               ", false, false);
    PrintMessage("0.  Back to Menu               ", false, false);
    PrintMessage("                               ", false, false);
    PrintMessage("Enter Your Choice (0-5)");
    cout<< ">";	cin >> n;
    switch (n){
        case 1:{
            //show All TimeOff.
            s.TimeOff(l.e.id);
            system("pause");
            break;
       }
       case 2:{
           //Add timeOff.
           timeOf=timeOf.enter(l.e.id);
           db.insertTimeOff(timeOf);
           s.TimeOff(l.e.id);
           system("pause");
           break;
       }
       case 3:{
           //Update TimeOff.
           string id;
           system("cls");
           s.AllTimesOff(l.e.id);
           cout <<"+-------------------------------------------+"<<endl;
           cout <<"|  Enter the Id that you need to update it  |"<<endl;
           cout <<"+-------------------------------------------+"<<endl;
           cout <<"|     id="; cin>>id;
           cout <<"+-------------------------------------------+"<<endl;
           system("cls");
           timeOf=db.selectTimeOff(id);
           timeOf.show();
           cout <<" ________________________"<<endl;
           cout <<"|  Enter New details     |"<<endl;
           timeOf=timeOf.enter(l.e.id);
           timeOf.id=id;
           db.updateTimeOff(timeOf);
           system("pause");
           break;
       }
       case 4:{
           //Delete TimeOff.
            s.AllTimesOff(l.e.id);
            cout <<"+-----------------------------------------------------------+"<<endl;
            cout <<"|   Enter id for the timeOff that you need to delete it     |"<<endl;
            cout <<"+-----------------------------------------------------------+"<<endl;
            cout <<"          id="; cin>>timeOf.id; cout<<endl;
            cout <<"+-----------------------------------------------------------+"<<endl;
            timeOf=db.selectTimeOff(timeOf.id);
            timeOf.show();
            cout <<"+--------------------------+"<<endl;
            cout <<"|  Are you sure press(Y/N) |"<<endl;
            cout <<"+--------------------------+"<<endl;
            cin>>choice;
            if (choice=="y" || choice=="Y"){
            db.deleteTimeOff(timeOf.id);
            }
            system("pause");
           break;
       }
       case 0: return;
	  default: cout << "\a";
    }
     TimeOffMenu();
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

