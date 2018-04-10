#ifndef SHOW_H_INCLUDED
#define SHOW_H_INCLUDED
#include <employee.h>
#include <task.h>
#include <project.h>
#include <database.h>
#include <list>
#include <gtime.h>






using namespace std;
class Show{
public:
    Employee e;
    Task t;
    Project p;
    Day d;
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

void Days( long date1, long date2,string id){
    Database db;
    Day d1,d2;

    int sum=0;
                  cout <<" ________________________________________________________________________________________________"<<endl;
                  cout <<"|                               Days's details for Employee                                      |"<<endl;
                  cout <<"|________________________________________________________________________________________________|"<<endl;
                  cout <<"|"<<setw(20)<<"Date"<<setw(20)<<"startTime"<<setw(20)<<"endTime"<<setw(20)<<"timeSpend"<<setw(16)<<"Employee_id"<<"|"<< endl;
                  list<Day> days;
                  days = db.selectEmployeesWorkForPeriod(date1,date2,id);
                  for ( d : days){
                                  CustomTime c1 =CustomTime(d.date),c2=CustomTime(d.start),c3=CustomTime(d.endTime);
                  cout <<"|"<<setw(20)<<c1.date()<<setw(20)<<c2.Time()<<setw(20)<<c3.Time()<<setw(20)<<d.timeSpend<<setw(16)<<d.employee_id<<"|"<<endl;

                   sum = sum + d.timeSpend;
                 }
                  cout <<"|________________________________________________________________________________________________|"<<endl;
                  cout <<"|   the total timeSpend for this period  is =\t "<<setw(25)<<sum<<setw(24)<<"|"<<endl;
                  cout <<"|________________________________________________________________________________________________|"<<endl;
}


};

#endif // SHOW_H_INCLUDED
