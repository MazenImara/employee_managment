#include <iostream>
#include <string>
//#include <login.h>
#include <iomanip>
#include <stdlib.h>
#include <gtime.h>
#include <employee.h>
#include <project.h>
#include <projectMenu.h>

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

void AdminMenu();
void ManageEmployeeMenu();
void EmployeeMenu();
void ManageProjectMenu();
void ManageTaskMenu();
void manageProjectMenu();

void showAllProject()
{

}

int main()
{
    int n;
    string courseId;
	do {
		system("cls");
		PrintMessage("EMPLOYEE MANAGEMENT");
		PrintMessage("                      ", false, false);
		PrintMessage("1. LOGIN              ", false, false);
		PrintMessage("                      ", false, false);
		PrintMessage("0. EXIT               ", false, false);
		PrintMessage("                      ", false, false);

		PrintMessage("Please Select your option (0-1): ");
		cout<< ">";	cin >> n;
		switch (n)
		{
		case 1:
            AdminMenu();
		    break;

		    break;
        case 0: exit(0);
		default: "\a"; break;
		}

	} while (n != 0);

	return 0;
    /*
    CustomTime c;
    cout << c.date() << "  " << c.Time() << endl;
    c.getTimestampDate("2018/10/11 23:15:13");
    //c.getTimestampDate("2017/07/26 00:00:00");
    */

/*
    Loging l;
    while(!l.loged){
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
        manageProjectMenu();
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
	case 1:
	    //
	    break;
	case 2:
        //
        break;
    case 3:
        //
	    break;
    case 4:
        e.show();
	    break;
   	case 0:return;
	default: cout << "\a";

	}
	ManageEmployeeMenu();
}

void ManageProjectMenu()
{
    Project p;
    int n;
    system("cls");
	PrintMessage("MANAGE PROJECT");
    PrintMessage("                               ", false, false);
	PrintMessage("1.  Show Project               ", false, false);
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
	    p.show();
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

