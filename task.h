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
       cout <<"|"<<setw(5)<<"id"<<setw(8)<<"Title"<<setw(10)<<"Status"<<setw(15)<<"Time Spend"<<setw(30)<<"Start temp"<<setw(30)<<"End Temp"<<setw(30)<<"Project id"<<setw(20)<<"Employee Id"<<setw(11)<<"|"<< endl;
       cout <<"|"<<setw(4)<<id<<setw(8)<<title<<setw(12)<<status<<setw(10)<<timeSpend<<setw(30)<<startTemp<<setw(30)<<endTemp<<setw(30)<<projectId<<setw(20)<<employeeId<<setw(11)<<"|"<<endl;
       cout <<"|__________________________________________________________________________________________________________________________________|"<<endl;
    }

    void showAdd()
    {
        cout << "\nId: " << id << "\tTitle: " << title << endl;
    }

    void getTask(string id)
    {
        getTask(id);
    }

    void setEmployeTask()
    {
        SetEmployeTask();
    }

    void add(string id)
    {
        insertTask(id);
    }

    void Delete(string id)
    {
        deleteTask(id);
    }

    void update()
    {
        updateTask();
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
