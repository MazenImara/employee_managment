#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED


#include <iostream>
#include <iomanip>
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

    void enterNewTitle()
    {
        cout << "\nEnter the new title of the task: "; cin >> title;
    }


    //header of all
    void header()
    {
        cout<<" ______________________________________________________________________________________________________________________________________________"<<endl;
        cout<<"|                                                                                                                                              |"<<endl;
        cout<<"|                                                      Task's details                                                                          |"<<endl;
        cout<<"|______________________________________________________________________________________________________________________________________________|"<<endl;
        cout<<"|"<<setw(5)<<"id"<<setw(15)<<"Title"<<setw(10)<<"Status"<<setw(15)<<"Time Spend"<<setw(20)<<"Start temp"<<setw(20)<<"End Temp"<<setw(20)<<"Project Id"<<setw(15)<<"Employee Id"/*<<setw(15)<<"Employee Name"*/<<setw(8)<<"|"<<endl;
        cout<<"|______________________________________________________________________________________________________________________________________________|"<<endl;
    }
    //list of all
    void show()
    {
        cout<<"|"<<setw(5)<<id<<setw(15)<<title<<setw(10)<<status<<setw(15)<<timeSpend << "\t"<<setw(20)<<startTemp<<setw(20)<<endTemp<<setw(20)<<projectId<<setw(15)<<employeeId/*<<setw(15)<<e.name*/<<setw(6)<<"|"<<endl;
        cout<<"|______________________________________________________________________________________________________________________________________________|"<<endl;
    }


    //header for admin
    void headerProjectTasks()
    {
        cout<<" ______________________________________________________________________________________________"<<endl;
        cout<<"|                                                                                              |"<<endl;
        cout<<"|                            Task's details                                                    |"<<endl;
        cout<<"|______________________________________________________________________________________________|"<<endl;
        cout<<"|"<<setw(10)<<"Task id"<<setw(15)<<"Title"<<setw(15)<<"Status"<<setw(15)<<"Time Spend"<<setw(15)<<"Employee Id"/*<<setw(20)<<"Employee Name"*/<<setw(5)<<"|"<<endl;
        cout<<"|______________________________________________________________________________________________|"<<endl;
    }
    //list for admin
     void showProjectTasks()
    {

        cout<<"|"<<setw(10)<<id<<setw(15)<<title<<setw(15)<<status<<setw(15)<<timeSpend<<setw(15)<<employeeId/*<<setw(20)<<e.name*/<<setw(5)<<"|"<<endl;
        cout<<"|______________________________________________________________________________________________|"<<endl;
    }


        //header for admin
    void headerEmployeeTasks()
    {
        cout<<" ______________________________________________________________________________"<<endl;
        cout<<"|______________________________________________________________________________|"<<endl;
        cout<<"|                        Task's details                                        |"<<endl;
        cout<<"|______________________________________________________________________________|"<<endl;
        cout<<"|"<<setw(10)<<"Task id"<<setw(15)<<"Title"<<setw(15)<<"Status"<<setw(15)<<"Time Spend"<<setw(10)<<"|"<<endl;
        cout<<"|______________________________________________________________________________|"<<endl;
    }
    //list for admin
     void showEmployeeTasks()
    {
        cout<<"|"<<setw(10)<<id<<setw(15)<<title<<setw(15)<<status<<setw(15)<<timeSpend<<setw(10)<<"|"<<endl;
        cout<<"|______________________________________________________________________________|"<<endl;
    }


    void showHeaderWithId(){
        cout<<" __________________________________________________________________________________________________________________________________"<<endl;
        cout<<"|                                                                                                                                  |"<<endl;
        cout<<"|                                                      Task's details                                                              |"<<endl;
        cout<<"|__________________________________________________________________________________________________________________________________|"<<endl;
        cout<<"|"<<setw(5)<<"id"<<setw(10)<<"Title"<<setw(17)<<"Status"<<setw(20)<<"Time Spend"<<setw(17)<<"Start temp"<<setw(20)<<"End Temp"<<setw(20)<<"Project Id"<<setw(16)<<"Employee Id"<<setw(6)<<"|"<<endl;
        cout<<"|__________________________________________________________________________________________________________________________________|"<<endl;
    }

    void showLineWithId(){
        cout<<"|__________________________________________________________________________________________________________________________________|"<<endl;
    }

    void showHeaderWithoutId(){
        cout <<"+------------------------------------------------------------------------------------------------------------------------------------------------------+"<<endl;
        cout <<"|                                                        Your Tasks                                                                                    |"<<endl;
        cout <<"+------------------------------------------------------------------------------------------------------------------------------------------------------+"<<endl;
        cout <<"|"<<setw(10)<<"Title"<<setw(10)<<"Status"<<setw(20)<<"StartTemp"<<setw(30)<<"EndTemp"<<setw(25)<<"TimeSpend"<<setw(30)<<"ProjectId"<<setw(26)<<"|"<< endl;
        cout <<"|______________________________________________________________________________________________________________________________________________________|"<<endl;
    }

    void showLineWithoutId(){
        cout <<"|______________________________________________________________________________________________________________________________________________________|"<<endl;
    }

    void showAdd()
    {
        cout << "\nId: " << id << "\tTitle: " << title << endl;
    }

    void showTask(string id)
    {
        inbtwShowTask(id);
    }

    void add(string projectId)
    {
        inbtwInsertTask(projectId);
    }

    void deleteT(string id)
    {
        inbtwDeleteTask(id);
    }

    void update()
    {
        inbtwUpdateTask();
    }

   void signEmployeToTask(string id, string employeeId)
    {
        inbtwSignEmployeeToTask(id , employeeId);
    }

    void start(string taskId, string employeeId)
    {
        inbtwStartTask(taskId, employeeId);
    }

    void pause(string id)
    {
        inbtwPauseTask(id);
    }

    void ended(string id)
    {
        inbtwEndTask(id);
    }
};


#endif // TASK_H_INCLUDED
