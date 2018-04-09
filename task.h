#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED
#include <iostream>
#include <string>
#include <windows.h>


using namespace std;

class Task{

public:
    string id;
    string title;
    string status;
    string time_spend;
    string starttemp;
    string endtemp;
    string project_id;
    string employee_id;
public:
    void enterId(){
        cout<<"\nEnter id: ";cin>>id;
        }
    void enter(){
        cout<<"\nEnter Title: ";cin>>title;
    }
    void show(){
        cout<<"\nId: "<< id <<"\tTitle: "<< title <<"\tStatus: "<< status <<"\tTime Spend: "<< time_spend <<"\tEnd Temp "<< endtemp <<"\Start Temp "<< starttemp<<"\tProject id: "<< project_id <<"\tEmployee id: "<< employee_id <<endl;
    }



    };


#endif // TASK_H_INCLUDED
