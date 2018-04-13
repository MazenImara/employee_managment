#ifndef SHOW_H_INCLUDED
#define SHOW_H_INCLUDED
#include <employee.h>
#include <task.h>
#include <project.h>
#include <database.h>
#include <list>
#include <gtime.h>
#include <timoff.h>


using namespace std;
class Show{
public:
    Employee e;
    Task t;
    Project p;
    Day d;
    Database db;
    TimeOff timeOf;
    list<Employee> employess;
    list<TimeOff> timesOff;
    list<Task> tasks;

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
    int sum=0;
    cout <<" ________________________________________________________________________________"<<endl;
    cout <<"|                       Days's details for Employee                              |"<<endl;
    cout <<"|________________________________________________________________________________|"<<endl;
    cout <<"|"<<setw(18)<<"Date"<<setw(23)<<"startTime"<<setw(18)<<"endTime"<<setw(18)<<"timeSpend"<<setw(4)<<"  |"<< endl;
    list<Day> days;
    days = db.selectEmployeesWorkForPeriod(date1,date2,id);
    for ( d : days){
        CustomTime c1 =CustomTime(d.date),c2=CustomTime(d.start),c3=CustomTime(d.endTime);
        cout <<"|"<<setw(20)<<c1.date()<<setw(20)<<c2.Time()<<setw(20)<<c3.Time()<<setw(15)<<d.timeSpend<<setw(6)<<" |"<<endl;
        sum = sum + d.timeSpend;
    }
    cout <<"|________________________________________________________________________________|"<<endl;
    cout <<"|   the total timeSpend for this period  is =\t "<<setw(17)<<sum<<setw(16)<<"|"<<endl;
    cout <<"|________________________________________________________________________________|"<<endl;
}
void TimeOff(string id){
    cout <<" ___________________________________________________________"<<endl;
    cout <<"|                       Your TimesOff                       |"<<endl;
    cout <<"|___________________________________________________________|"<<endl;
    cout <<"|"<<setw(15)<<"From"<<setw(30)<<"To"<<setw(15)<<"|"<< endl;
    cout <<"|___________________________________________________________|"<<endl;

    timesOff = db.selectTimesOff(id);
    for ( timeOf : timesOff){
        CustomTime c1 =CustomTime(timeOf.from),c2=CustomTime(timeOf.to);
        cout <<"|"<<setw(10)<<c1.date()<<"  "<<setw(10)<<c1.Time()<<setw(20)<<c2.date()<<"  "<<setw(10)<<c2.Time()<<setw(6)<<"|"<<endl;
    }
    cout <<"|___________________________________________________________|"<<endl;
}
void AllTimesOff(string id){
    cout <<" _____________________________________________________________________"<<endl;
    cout <<"|                               Your TimesOff                         |"<<endl;
    cout <<"|_____________________________________________________________________|"<<endl;
    cout <<"|"<<setw(5)<<"ID"<<setw(18)<<"From"<<setw(32)<<"To"<<"              |"<< endl;
    cout <<"|_____________________________________________________________________|"<<endl;

    timesOff = db.selectTimesOff(id);
    for ( timeOf : timesOff){
        CustomTime c1 =CustomTime(timeOf.from),c2=CustomTime(timeOf.to);
        cout <<"|"<<setw(5)<<timeOf.id<<setw(15)<<c1.date()<<"  "<<setw(6)<<c1.Time()<<setw(24)<<c2.date()<<"  "<<setw(6)<<c2.Time()<<setw(10)<<"|"<<endl;
    }
    cout <<"|_____________________________________________________________________|"<<endl;
}
void  TaskForEmployee(string employee_id){
    cout <<"+------------------------------------------------------------------------------------------------------------------------------------------------------+"<<endl;
    cout <<"|                                                        Your Tasks                                                                                    |"<<endl;
    cout <<"+------------------------------------------------------------------------------------------------------------------------------------------------------+"<<endl;
    cout <<"|"<<setw(10)<<"Title"<<setw(10)<<"Status"<<setw(20)<<"StartTemp"<<setw(30)<<"EndTemp"<<setw(25)<<"TimeSpend"<<setw(30)<<"ProjectId"<<setw(26)<<"|"<< endl;
    cout <<"|______________________________________________________________________________________________________________________________________________________|"<<endl;

    tasks = db.selectEmployeeTasks(employee_id);
    for ( t : tasks){
           long starttemp=d.stringToLong(t.starttemp),endtemp=d.stringToLong(t.endtemp);
        CustomTime c1 =CustomTime(starttemp),c2=CustomTime(endtemp);
        cout <<"|"<<setw(10)<<t.title<<setw(10)<<t.status<<setw(15)<<c1.date()<<"  "<<setw(8)<<c1.Time()<<setw(20)<<c2.date()<<"  "<<setw(8)<<c2.Time()<<setw(16)<<t.time_spend<<setw(30)<<t.project_id<<setw(30)<<"|"<< endl;
    }
    cout <<"|______________________________________________________________________________________________________________________________________________________|"<<endl;

    }

};
     //Mohamad code

#endif // SHOW_H_INCLUDED
