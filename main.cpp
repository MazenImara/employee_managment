#include <iostream>
#include <string>
#include <login.h>
#include <iomanip>
#include <stdlib.h>
#include <gtime.h>

using namespace std;

int main()
{
    CustomTime c;
    cout << c.date() << "  " << c.Time() << endl;
    c.getTimestampDate("2018/10/11 23:15:13");
    //c.getTimestampDate("2017/07/26 00:00:00");


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
