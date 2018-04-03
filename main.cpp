#include <iostream>
#include <string>
#include <login.h>
#include <iomanip>
#include <stdlib.h>
#include <day.h>
#include <gtime.h>

using namespace std;
void manageEmployeeMenu();
void employeeMenu();
void manageProjectMenu();
void showProjectsMenu();
void projectUpdateMenu();
void manageTaskMenu();


int main()
{ // test Mohamad
    Database db,data;
    Day d,day;


    //d.employee_id=23;
    //d.startTime=20180122122333;
    //cout <<d.longToString(20180122122333);
    //d.endTime=20180123122444;
    //d.timeSpend=12;
   // d.enterStart();
    //d.enterEnd();
    //d.timeSpend=33;
    day=db.selectDay("27");
    //cout<<day.startTime<<endl;
    //cout<<day.endTime;
    //db.insertDay(d);

 cin.get();
cin.ignore();


    manageProjectMenu();




//ent test Mohamad



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

