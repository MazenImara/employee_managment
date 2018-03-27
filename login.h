#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED

#include <iostream>
#include <string>
#include <database.h>
#include <employee.h>

using namespace std;
class Login{
public:
    Employee e;
    bool loged;
    Login(){
        e.enterLogin();
        Database db;
        e = db.getLoginEmployee(e);
        loged = false;
        if(e.id.empty()){
            cout<< "Email or password is wrong"<< endl;
        }
        else{
            loged = true;
        }

    }
};

#endif // LOGIN_H_INCLUDED
