#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED
#include <iostream>
#include <string>
#include <database.h>
#include <employee.h>

using namespace std;

class Loging{
    public:
        Employee e;
        bool loged = false;

        void login(){
            e.enterLogin();
            Database db;
            e = db.getLoginEmployee(e);
            if(e.id.empty()){
                cout<< "Email or password is wrong"<< endl;
            }
            else{
                loged = true;
            }
        }

        void logout(){
            Employee E;
            e = E;
            loged = false;
        }
};

#endif // LOGIN_H_INCLUDED
