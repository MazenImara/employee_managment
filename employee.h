#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <inbtw.h>
#include <database.h>
#include <gtime.h>

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
       cout <<" __________________________________________________________________________________________________________________________________"<<endl;
       cout <<"|                                                      Employee's details                                                          |"<<endl;
       cout <<"|__________________________________________________________________________________________________________________________________|"<<endl;
       cout <<"|"<<setw(10)<<"id"<<setw(20)<<"Name"<<setw(30)<<"Email"<<setw(20)<<"Password"<<setw(30)<<"Address"<<setw(20)<<"Phone"<<"|"<< endl;
       cout <<"|"<<setw(10)<<id<<setw(20)<<name<<setw(30)<<email<<setw(20)<<"Password"<<setw(30)<<address<<setw(20)<<phone<<"|"<<endl;
       cout <<"|__________________________________________________________________________________________________________________________________|"<<endl;
    }
    void enterLogin(){
        cout <<setw(20)<<"Enter email =\t";cin >>email;cout <<endl;
        cout <<setw(20)<<"Enter password =\t";cin >>password;cout <<endl;
    }

    void setAdmin(){
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
    string getTime(){
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

        string FullDate = dateY + "-" + dateM + "-" + dateD + " " + shour + ":" + sminut + ":" + ssecond;

  /*
        string year= longToString(c.year);
        string month= longToString(c.month);
        string day= longToString(c.day);
        string  hour= longToString(c.hour);
        string minut= longToString(c.minut);
        string second= longToString(c.second);
        string date=year+"/"+month+"/"+day+" "+hour+":"+minut+":"+second;
        //c.timeStamp= c.CustomTime(date);
    */
    cout <<FullDate;
        return FullDate;
    }
};


#endif // EMPLOYEE_H_INCLUDED
