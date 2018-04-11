#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED
#include <iostream>
#include <string>
#include <windows.h>
#include <gtime.h>
#include <inbtw.h>

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
    /*
    void show(){
        PrintMessage("Task's Details");
        PrintMessage("ID  |  Title  |  Status  |  Timespend  |  Start Temp  |  End Temp  |  Project Id  |  Employee",false,false);
    } */

    void show(){
       cout <<" __________________________________________________________________________________________________________________________________"<<endl;
       cout <<"|                                                      Task's details                                                              |"<<endl;
       cout <<"|__________________________________________________________________________________________________________________________________|"<<endl;
       cout <<"|"<<setw(5)<<"id"<<setw(8)<<"Title"<<setw(10)<<"Status"<<setw(15)<<"Time Spend"<<setw(30)<<"Start temp"<<setw(30)<<"End Temp"<<setw(30)<<"Employe Id"<<setw(20)<<"Project id"<<setw(11)<<"|"<< endl;
       cout <<"|"<<setw(4)<<id<<setw(8)<<title<<setw(12)<<status<<setw(10)<<time_spend<<setw(30)<<starttemp<<setw(30)<<endtemp<<setw(30)<<project_id<<setw(20)<<employee_id<<setw(11)<<"|"<<endl;
       cout <<"|__________________________________________________________________________________________________________________________________|"<<endl;

    }

    /*void show(){
        cout<<"\nId: "<< id <<"\tTitle: "<< title <<"\tStatus: "<< status <<"\tTime Spend: "<< time_spend <<"\tDate Created: "<< date_created <<"\tProject id: "<< project_id <<"\tEmployee id: "<< employee_id <<endl;
    }*/

    void showAdd()
    {
        cout<<"\nId: "<< id <<"\tTitle: "<< title << endl;
    }

    void getTask(string id)
    {
        GetTask(id);
    }

    void setEmployeTask()
    {
        SetEmployeTask();
    }


    /*void start()
    {
        getTask(id);
    }*/
};


#endif // TASK_H_INCLUDED
