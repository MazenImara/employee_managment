#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED
#include <iostream>
#include <string>
#include <windows.h>
#include <gtime.h>

using namespace std;


class Task{
public:
    string id, title, status, time_spend, endtemp, starttemp, project_id, employee_id;


public:
    void enterId(){
        cout<<"\nEnter id: ";cin>>id;
        }
    void enter(){
        cout<<"\nEnter Title: ";cin>>title;
    }
    void show(){
       cout <<" __________________________________________________________________________________________________________________________________"<<endl;
       cout <<"|                                                      Task's details                                                              |"<<endl;
       cout <<"|__________________________________________________________________________________________________________________________________|"<<endl;
       cout <<"|"<<setw(5)<<"id"<<setw(20)<<"Title"<<setw(30)<<"Status"<<setw(20)<<"Time Spend"<<setw(30)<<"Start temp"<<setw(20)<<"End Temp"<<setw(5)<<"Employe Id"<<setw(5)<<"id"<<"|"<< endl;
       cout <<"|"<<setw(5)<<id<<setw(20)<<title<<setw(30)<<status<<setw(20)<<time_spend<<setw(30)<<starttemp<<setw(20)<<endtemp<<setw(20)<<project_id<<setw(20)<<employee_id<<"|"<<endl;
       cout <<"|__________________________________________________________________________________________________________________________________|"<<endl;
    }
    /*
    void show(){
        cout<<"\nId: "<< id <<"\tTitle: "<< title <<"\tStatus: "<< status <<"\tTime Spend: "<< time_spend <<"\tDate Created: "<< date_created <<"\tProject id: "<< project_id <<"\tEmployee id: "<< employee_id <<endl;
    }
    */
    void showAdd()
    {
        cout<<"\nId: "<< id <<"\tTitle: "<< title << endl;
    }
};


#endif // TASK_H_INCLUDED
