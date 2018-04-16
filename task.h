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
    string id, title, status, timeSpend, endTemp, startTemp, projectId, employeeId;



    public:
    void enterId()
    {
        cout << "\nEnter id: "; cin >> id;
    }
    void enter()
    {
        cout << "\nEnter Title: "; cin >> title;
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
       cout <<"|"<<setw(5)<<"id"<<setw(20)<<"Title"<<setw(30)<<"Status"<<setw(20)<<"Time Spend"<<setw(30)<<"Start temp"<<setw(20)<<"End Temp"<<setw(5)<<"Employe Id"<<setw(5)<<"id"<<"|"<< endl;
       cout <<"|"<<setw(5)<<id<<setw(20)<<title<<setw(30)<<status<<setw(20)<<timeSpend<<setw(30)<<startTemp<<setw(20)<<endTemp<<setw(20)<<projectId<<setw(20)<<employeeId<<"|"<<endl;
       cout <<"|__________________________________________________________________________________________________________________________________|"<<endl;
    }

    void showAdd()
    {
        cout << "\nId: " << id << "\tTitle: " << title << endl;
    }

    void getTask(string id)
    {
        GetTask(id);
    }

    void setEmployeTask()
    {
        SetEmployeTask();
    }

    void Add(string id)
    {
        GetInsertTask(id);
    }

    void Delete(string id)
    {
        GetDeleteTask(id);
    }

    void Update()
    {
        GetUpdateTask();
    }

    void start(string TId, string EId)
    {
        startTask(TId, EId);
    }
    void pause(string id)
    {
        pauseTask(id);
    }
    void ended(string id)
    {
        endTask(id);
    }
};


#endif // TASK_H_INCLUDED
