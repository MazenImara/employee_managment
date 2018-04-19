#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <inbtw.h>
#include <database.h>
#include <gtime.h>

//MOHAMAD CODE

using namespace std;

class Employee{
public:
    string id,name,email,password,address,phone;

    void enterId(){
        cout <<"enter id of the employee =\t";cin >>id;cout <<endl;
    }
    void enter(){
        cout <<setw(20)<<"Enter name     =\t";cin >>name;cout <<endl;
        cout <<setw(20)<<"Enter email    =\t";cin >>email;cout <<endl;
        cout <<setw(20)<<"Enter password =\t";cin >>password;cout <<endl;
        cout <<setw(20)<<"Enter address  =\t";cin >>address;cout <<endl;
        cout <<setw(20)<<"Enter phone    =\t";cin >>phone;cout <<endl;
    }
    void showHeaderWithId(){
       cout <<" __________________________________________________________________________________________________________________________________"<<endl;
       cout <<"|                                                      Employee's details                                                          |"<<endl;
       cout <<"|__________________________________________________________________________________________________________________________________|"<<endl;
       cout <<"|"<<setw(10)<<"id"<<setw(20)<<"Name"<<setw(30)<<"Email"<<setw(20)<<"Password"<<setw(30)<<"Address"<<setw(20)<<"Phone"<<"|"<< endl;
    }
    void showDataWithId(){
       cout <<"|"<<setw(10)<<id<<setw(20)<<name<<setw(30)<<email<<setw(20)<<"Password"<<setw(30)<<address<<setw(20)<<phone<<"|"<<endl;
    }
    void showLineWhitId(){
       cout <<"|__________________________________________________________________________________________________________________________________|"<<endl;
    }
    void enterLogin(){
        cout <<setw(20)<<"Enter email =\t";cin >>email;cout <<endl;
        cout <<setw(20)<<"Enter password =\t";cin >>password;cout <<endl;
    }

    void setAdmin(  ){
        SetAdmin(id);
    }
    bool isAdmin(){
        return IsAdmin(id);
    }
    string longToString(long  number){
        std::stringstream ss;
        ss << number;
        return ss.str();
    }
    string getFullTime(){
        CustomTime c;
        cout <<"enter the date by form year/month/day :"<<endl;
        cin  >> c.year ,cout<<"/",cin>>c.month, cout<<"/",cin>>c.day ,cout <<endl;
        cout <<"enter the time by form hours:minute:second :"<<endl;
        cin  >> c.hour ;cout<<":";cin>>c.minut; cout<<":";cin>>c.second ;cout <<endl;

        time_t timeStamp=time(NULL);
        struct tm nowLocal=*localtime(&timeStamp);
        int day = nowLocal.tm_mday;
        int month = nowLocal.tm_mon+1;
        int year = nowLocal.tm_year+1900;
        int hour = nowLocal.tm_hour;
        int minut = nowLocal.tm_min;
        int second = nowLocal.tm_sec;

        year   = c.year;
        month  = c.month;
        day    = c.day;
        hour   = c.hour;
        minut  = c.minut;
        second = c.second;
        stringstream sy;    sy << year;      string dateY = sy.str();
        stringstream sm;    sm << month;     string dateM = sm.str();
        stringstream sd;    sd << day;       string dateD = sd.str();
        stringstream sh;    sh << hour;      string shour = sh.str();
        stringstream smi;   smi << minut;    string sminut = smi.str();
        stringstream ss;    ss << second;    string ssecond = ss.str();

        string FullDate = dateY + "/" + dateM + "/" + dateD + " " + shour + ":" + sminut + ":" + ssecond;

        cout <<FullDate;
        return FullDate;
    }
    string getDate(){
        CustomTime c;
        cout <<"enter the date by form year/month/day :"<<endl;
        cin  >> c.year ,cout<<"/",cin>>c.month, cout<<"/",cin>>c.day ,cout <<endl;

        time_t timeStamp=time(NULL);
        struct tm nowLocal=*localtime(&timeStamp);
        int day = nowLocal.tm_mday;
        int month = nowLocal.tm_mon+1;
        int year = nowLocal.tm_year+1900;

        year   = c.year;
        month  = c.month;
        day    = c.day;
        stringstream sy;    sy << year;      string dateY = sy.str();
        stringstream sm;    sm << month;     string dateM = sm.str();
        stringstream sd;    sd << day;       string dateD = sd.str();

        string date = dateY + "/" + dateM + "/" + dateD ;
        return date;
    }
};


#endif // EMPLOYEE_H_INCLUDED
