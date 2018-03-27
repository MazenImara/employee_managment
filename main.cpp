#include <iostream>
#include <string>
#include <database.h>
#include <task.h>
#include <iomanip>


using namespace std;


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

int main(){
    //Menu for manage employee

    manageEmployeeMenu();

    return 0;
}


