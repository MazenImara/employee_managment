#ifndef SHOW_H_INCLUDED
#define SHOW_H_INCLUDED
#include <employee.h>
#include <task.h>
#include <project.h>
#include <database.h>
#include <list>






using namespace std;
class Show{
public:
    Employee e;
    Task t;
    Project p;
    Database db;
    list<Employee> employess;

void Employee(){
    cout <<" __________________________________________________________________________________________________________________________________"<<endl;
    cout <<"|                                                      Employee's details                                                          |"<<endl;
    cout <<"|__________________________________________________________________________________________________________________________________|"<<endl;
    cout <<"|"<<setw(10)<<"id"<<setw(20)<<"Name"<<setw(30)<<"Email"<<setw(20)<<"Password"<<setw(30)<<"Address"<<setw(20)<<"Phone"<<"|"<< endl;
    employess = db.selectEmployees();
    for ( e : employess){
        cout <<"|"<<setw(10)<<e.id<<setw(20)<<e.name<<setw(30)<<e.email<<setw(20)<<e.password<<setw(30)<<e.address<<setw(20)<<e.phone<<"|"<<endl;
    }
    cout <<"|__________________________________________________________________________________________________________________________________|"<<endl;

}

};

#endif // SHOW_H_INCLUDED
