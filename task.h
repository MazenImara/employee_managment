#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED
#include <iostream>
#include <string>
#include <windows.h>
#include <gtime.h>

using namespace std;

class Task{
public:
    string id, title, status, time_spend, date_created, endtemp, starttemp, project_id, employee_id;
public:
    void enterId(){
        cout<<"\nEnter id: ";cin>>id;
        }
    void enter(){
        cout<<"\nEnter Title: ";cin>>title;
    }
    void show(){
        cout<<"\nId: "<< id <<"\tTitle: "<< title <<"\tStatus: "<< status <<"\tTime Spend: "<< time_spend <<"\tDate Created: "<< date_created <<"\tProject id: "<< project_id <<"\tEmployee id: "<< employee_id <<endl;
    }
    void showAdd()
    {
        cout<<"\nId: "<< id <<"\tTitle: "<< title << endl;
    }
};

#endif // TASK_H_INCLUDED
