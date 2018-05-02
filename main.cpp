#include <iostream>
#include <string>
#include <login.h>
#include <iomanip>
#include <stdlib.h>
#include <day.h>
#include <gtime.h>
#include <gtime.h>
#include <employee.h>
#include <project.h>
#include <projectMenu.h>
#include <show.h>
#include <sugges.h>

using namespace std;

Loging l;
long temp=0;
bool cancl=false;
long currentTimeStart;

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
void ManageTaskMenu(string proId);
void TimeOffMenu();
void workTimesMenu(string id);
void showAllEmployee();
void showAllProject();

void inbtwInsertEmployee();
void inbtwUpdateEmployee();
void inbtwDeleteEmployee();
void inbtwShowEmployees();
void inbtwSignEmployeeAsAdmin();
void inbtwShowWorkDetails(string id);
void inbtwShowTaskForEmployee(string id);
void inbtwShowTimeOff(string id);


Employee selectEmployeeByEmail(std::string email);
Employee selectEmployeeById(std::string id);


void ShowAllTask();

int main()
{
    char n;

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
		switch (n){
		case '1':{

            while(!l.loged)
            {
                system("cls");
                l.login();
            }
            if(l.loged)
            {
                if(l.e.isAdmin()){
                   temp=employeeLoginRecord(l.e.id);
                    AdminMenu();
                    l.logout();
                }
                else{
                    temp=employeeLoginRecord(l.e.id);
                    EmployeeMenu();
                    l.logout();
                }
            }
            else{
                l.logout();
            }
        }
            break;

        case '2':
            createDatabase();
            system("pause");
		    break;

        case '0': exit(0);
        case '*': exit(0) ;

		default: "\a"; break;
		}

	} while (n != '0');

    return 0;
}

void AdminMenu()
{


    char n;
    system("cls");
    showProjectsWithTasksForAdmin();
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
	case '1':
        ManageProjectMenu();
	    break;
	case '2':
        ManageEmployeeMenu();
        break;

   	case '0':{
   	    employeeLogoutRecord(l.e.id,temp);
   	 //   convertTaskStatusIfStatusWasStarted(l.e.id, temp);
        l.logout();
        }
        return;
    case '*' :return;
	default: cout << "\a";

	}

	AdminMenu();
}

//Mohamad code updated
void ManageEmployeeMenu()
{

    Employee e;
    char n;
    system("cls");
	PrintMessage("ADMIN MANAGE EMPLOYEE");
    PrintMessage("                                 ", false, false);
	PrintMessage("1.  Create Employee              ", false, false);
    PrintMessage("2.  Update Employee              ", false, false);
    PrintMessage("3.  Delete Employee              ", false, false);
    PrintMessage("4.  Show all Employees/Work times", false, false);
    PrintMessage("5.  Sign Employee as Admin       ", false, false);
    PrintMessage("                                 ", false, false);
	PrintMessage("0.  Back to Admin Menu           ", false, false);
    PrintMessage("                                 ", false, false);
	PrintMessage("Enter Your Choice (0-5)");
	cout<< ">";	cin >> n;

	switch (n)
	{
	case '1':{
	    //Create Employee
	    insertEmployee();
        system("pause");
	}
	    break;
	case '2':{
        //Update Employee
        updateEmployee();
        system("pause");
	}
        break;
    case '3':{
        //Delete Employee
        deleteEmployee();
        system("pause");
    }
	    break;
    case '4':{
        //Show all Employees
        system("cls");
        showEmployee();
        cout <<" ___________________________________________________________"<<endl;
        cout <<"|    Enter the id you need to show  the work's detail       |"<<endl;
        cout <<"|___________________________________________________________|"<<endl;
        e.enterId();
        if (e.check==true){
        system("cls");
        workTimesMenu(e.id);
        system("pause");
        }

    }
	    break;
    case '5' :{
        //Sign Employee as Admin
        showEmployee();
        signEmployeeAsAdmin();
        system("pause");
    }
   	case '0':return;
   	case '*' :return;
	default: cout << "\a";
	}

	ManageEmployeeMenu();
}
//end updated

void workTimesMenu(string id){
    char n;
    Employee e;
    Day d;
    e=selectEmployeeById(id);
    e.showHeaderWithId();
    e.showDataWithId();
    e.showLineWhitId();
	PrintMessage("    Show Works Times for Employee       ");
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
	case '1':{
       // Show work details
       d=d.enterPeriod();
       if (d.check==true){
       showDays(d.period1,d.period2,e.id);
       system("pause");
       }
	}
	    break;
	case '2':{
	    // Show the Tasks
        showTaskForEmployee(e.id);
        system("pause");
    }
        break;
    case '3':{

        // Show Time off
        showTimesOffWithId(e.id);
        system("pause");
    }
        break;
   	case '0':return;
   	case '*' :return;
	default: cout << "\a";

	}
	system("cls");
	workTimesMenu(id);
}


void ManageProjectMenu()
{
    Project p;
    char n;
    system("cls");
    inbtwShowAllProjects();
	PrintMessage("MANAGE PROJECT");
    PrintMessage("                               ", false, false);
	PrintMessage("1.  Manage Project             ", false, false);
    PrintMessage("2.  Add Project                ", false, false);
    PrintMessage("3.  Delete Project             ", false, false);
    PrintMessage("4.  Update Project             ", false, false);
    PrintMessage("                               ", false, false);
	PrintMessage("0.  Back to Admin Menu         ", false, false);
    PrintMessage("                               ", false, false);
	PrintMessage("Enter Your Choice (0-4)");
	cout<< ">";	cin >> n;
    switch (n){
	case '1':{
	    //MangeProject
        p.enterId();
        if (p.check==true){
	       ManageTaskMenu(p.id);
        }
	    }
	    break;
	case '2':
	    //create project
        p.Add();
        break;
    case '3':
        //delete project
        p.enterId();
        if (p.check==true){
            p.Delete(p.id);
            system("pause");
        }

	    break;
    case '4':{
        //update Project
        p.Update();
    }
        break;
   	case '0' :return;
    case '*' :return;
	default: cout << "\a";
	}
	ManageProjectMenu();
	}
//updating the cases for task from ikram
void ManageTaskMenu(string proId){
    Employee e;
    Task t;
    char n;
    system("cls");
    //inbtwShowAllTasks();
    showAllTasksForProject(proId);
	PrintMessage("MANAGE TASK");
    PrintMessage("                                      ", false, false);
	PrintMessage("1.  Add Task                          ", false, false);
    PrintMessage("2.  Delete Task                       ", false, false);
    PrintMessage("3.  Update Task                       ", false, false);
    PrintMessage("4.  Sign Employee To Task             ", false, false);
    PrintMessage("5.  Suggestion for selected project   ", false, false);
    PrintMessage("                                      ", false, false);
	PrintMessage("0.  Back to Manage Project            ", false, false);
    PrintMessage("                                      ", false, false);
	PrintMessage("Enter Your Choice (0-5)");
	cout<< ">";	cin >> n;
	switch (n)
	{
	case '1':{
	    //create Task
	    t.add(proId);
	    system("pause");
	}
	    break;
	case '2':
	    //Delete Task
        t.enterId();
        if (t.check==true){
            t.deleteT(t.id);
            system("pause");
        }

        break;
    case '3':{
        //update Task
        t.update();
        system("pause");
    }
        break;

    case '4':{
        //Sign Employee to Task
        showEmployee();
        signEmployeeToTask();
        system("pause");

    }
	    break;

    case '5':{
        //Suggestion task.
         showSuggessByProjectId(proId);
         system("pause");
    }
	    break;
   	case '0': return;
   	case '*' :return;
	default: cout << "\a";
	}

	ManageTaskMenu(proId);
}
//ending updating by ikram

void EmployeeMenu(){
    char n;
    Task t;
    system("cls");
    showProjectsWithTasks(l.e.id);
	PrintMessage("EMPLOYEE MENU");
    PrintMessage("                               ", false, false);
	PrintMessage("1.  Start Task                 ", false, false);
    PrintMessage("2.  Pause Task                 ", false, false);
	PrintMessage("3.  Finish Task                ", false, false);
    PrintMessage("4.  Manage TimeOff             ", false, false);
    PrintMessage("5.  show all Suggestions       ", false, false);
    PrintMessage("                               ", false, false);
	PrintMessage("0.  LOGOUT                     ", false, false);
    PrintMessage("                               ", false, false);
	PrintMessage("Enter Your Choice (0-4)");
	cout<< ">";	cin >> n;
	switch (n)
	{
	case '1':{
        //Start Task
        t.enterId();
        if (t.check==true){
            CustomTime c;
            t.start(t.id,l.e.id);
            string currentTime =c.fullDateTime2();
            currentTimeStart=c.getTimestampDate(currentTime);
            system("pause");
        }

	}
	    break;
	case '2':{
        //Pause
        t.enterId();
        if (t.check==true){
            t.pause(t.id);
            system("pause");
        }

	}
        break;
	case '3':{
        //Finish
        t.enterId();
        if (t.check==true){
        t.ended(t.id);
        system("pause");
        }
	}
	    break;
	case '4':{
        //Manage Time off
	    TimeOffMenu();
	}
	case '5':{
        //show all suggestion
	    showAllSuggess();
	    system("pause");
	}
        break;
   	case '0':{
        employeeLogoutRecord(l.e.id,temp);
        convertTaskStatusIfStatusWasStarted(l.e.id, currentTimeStart);
        l.logout();
    }
        return;
    case '*':return;
	default: cout << "\a";

	}
	EmployeeMenu();
}
void TimeOffMenu(){
    TimeOff timeOf;
    char n;
    string choice;
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
       case '1':{
            //show All TimeOff.
            showTimeOff(l.e.id);
            system("pause");
            break;
       }
       case '2':{
           //Add timeOff.
           timeOf=timeOf.enter(l.e.id);
           if(timeOf.check==true){
              insertTimeOff(timeOf);
              showTimeOff(l.e.id);
              system("pause");
           }
           break;
       }
       case '3':{
           //Update TimeOff.
           string id;
           system("cls");
           showTimesOffWithId(l.e.id);
           cout <<"+-------------------------------------------+"<<endl;
           cout <<"|  Enter the Id that you need to update it  |"<<endl;
           cout <<"+-------------------------------------------+"<<endl;
           cout <<"|     id="; cin>>id;
           cout <<"+-------------------------------------------+"<<endl;
           if (id!="*"){
           system("cls");
           timeOf=selectTimeOff(id);
           timeOf.show();
           cout <<" ________________________"<<endl;
           cout <<"|  Enter New details     |"<<endl;
           timeOf=timeOf.enter(l.e.id);
           timeOf.id=id;
           updateTimeOff(timeOf);
           system("pause");
           }
           break;
       }
       case '4':{
           //Delete TimeOff.
            showTimesOffWithId(l.e.id);
            cout <<"+-----------------------------------------------------------+"<<endl;
            cout <<"|   Enter id for the timeOff that you need to delete it     |"<<endl;
            cout <<"+-----------------------------------------------------------+"<<endl;
            cout <<"          id="; cin>>timeOf.id; cout<<endl;
            cout <<"+-----------------------------------------------------------+"<<endl;
            if (timeOf.id!="*"){
            timeOf=selectTimeOff(timeOf.id);
            timeOf.show();
            cout <<"+--------------------------+"<<endl;
            cout <<"|  Are you sure press(Y/N) |"<<endl;
            cout <<"+--------------------------+"<<endl;
            cin>>choice;
            if (choice=="y" || choice=="Y"){
            deleteTimeOff(timeOf.id);
            }
            system("pause");
            }
           break;
       }
       case '0': return;
       case '*': break;
	  default: cout << "\a";
    }
     TimeOffMenu();
    }
