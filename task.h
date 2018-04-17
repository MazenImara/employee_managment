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
        cout << "\nEnter id of the task: "; cin >> id;
    }
    void enter()
    {
        cout << "\nEnter title of the task: "; cin >> title;
    }

    void show()
    {
        cout << " __________________________________________________________________________________________________________________________________"<<endl;
        cout << "|                                                      Task's details                                                              |"<<endl;
        cout << "|__________________________________________________________________________________________________________________________________|"<<endl;
        cout << "|"<<setw(5)<<"id"<<setw(10)<<"Title"<<setw(17)<<"Status"<<setw(20)<<"Time Spend"<<setw(17)<<"Start temp"<<setw(20)<<"End Temp"<<setw(20)<<"Project Id"<<setw(16)<<"Employee Id"<<setw(6)<<"|"<<endl;
        cout << "|"<<setw(4)<<id<<setw(15)<<title<<setw(15)<<status<<setw(15)<<timeSpend<<setw(18)<<startTemp<<setw(25)<<endTemp<<setw(10)<<projectId<<setw(17)<<employeeId<<setw(12)<<"|"<<endl;
        cout << "|__________________________________________________________________________________________________________________________________|"<<endl;

    }

    void showAdd()
    {
        cout << "\nId: " << id << "\tTitle: " << title << endl;
    }

    void showTask(string id)
    {
        inbtwShowTask(id);
    }

    void setEmployeTask()
    {
        inbtwSignEmployeeToTask();
    }

    void add(string id)
    {
        inbtwInsertTask(id);
    }

    void deleteT(string id)
    {
        inbtwDeleteTask(id);
    }

    void update()
    {
        inbtwUpdateTask();
    }

    void showAll()
    {
        inbtwShowAllTasks();
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
