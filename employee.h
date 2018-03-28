#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <inbtw.h>

using namespace std;
class Employee{
public:
    string id,name,email,password,address,phone;
    void enterId(){
        cout <<"enter id =\t";cin >>id;cout <<endl;
    }
    void enter(){
        cout <<setw(20)<<"Enter name =\t";cin >>name;cout <<endl;
        cout <<setw(20)<<"Enter email =\t";cin >>email;cout <<endl;
        cout <<setw(20)<<"Enter password =\t";cin >>password;cout <<endl;
        cout <<setw(20)<<"Enter address =\t";cin >>address;cout <<endl;
        cout <<setw(20)<<"Enter phone =\t";cin >>phone;cout <<endl;
    }
    void show(){
        cout <<" _______________________________________________________________________________________________________"<<endl;
        cout <<"|                                       Employee's details                                              |"<<endl;
        cout <<"|_______________________________________________________________________________________________________|"<<endl;
        cout <<"|"<<setw(20)<<"id"<<setw(20)<<"name"<<setw(20)<<"email"<<setw(20)<<"address"<<setw(20)<<"phone"<<"   |"<<endl;
        cout <<"|"<<setw(20)<<id<<setw(20)<<name<<setw(20)<<email<<setw(20)<<address<<setw(20)<<phone<<"   |"<<endl;
        cout <<"|_______________________________________________________________________________________________________|"<<endl;
    }
    void enterLogin(){
        cout <<setw(20)<<"Enter email =\t";cin >>email;cout <<endl;
        cout <<setw(20)<<"Enter password =\t";cin >>password;cout <<endl;
    }

    void setAdmin()
    {
        SetAdmin(id);

    }
    bool isAdmin(){
        return IsAdmin(id);
    }



};


#endif // EMPLOYEE_H_INCLUDED
