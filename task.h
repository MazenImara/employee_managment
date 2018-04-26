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
        Employee e;
        bool check=true;

    public:
        void enterId(){
            cout << "\nEnter id of the task: "; cin >> id;
            if (cancel(id)==false){
                check=false;
            }
        }

        void enter(){
            cout << "\nEnter title of the task: "; cin >> title;
            if (cancel(title)==false){
                check=false;
            }
        }

        void enterNewTitle(){
            cout << "\nEnter the new title of the task: "; cin >> title;
            if (cancel(title)==false){
                check=false;
            }
        }

        void header2(){
            cout<<" _____________________________________________________________________________________________"<<endl;
            cout<<"|                                                                                             |"<<endl;
            cout<<"|                                     Task's details                                          |"<<endl;
            cout<<"|_____________________________________________________________________________________________|"<<endl;
            cout<<"|"<<setw(5)<<"id"<<setw(10)<<"Title"<<setw(17)<<"Status"<<setw(20)<<"Time Spend"<<setw(20)<<"Project Id"<<setw(16)<<"EmployeeName"<<setw(6)<<"|"<<endl;
            cout<<"|_____________________________________________________________________________________________|"<<endl;
        }

        void show2(){
            cout<<"|"<<setw(4)<<id<<setw(15)<<title<<setw(15)<<status<<setw(15)<<timeSpend << "\t"<<setw(10)<<projectId<<setw(17)<<employeeId<<setw(12)<<"|"<<endl;
            cout<<"|_____________________________________________________________________________________________|"<<endl;
        }


        //header of all
        void header(){
            cout<<" ____________________________________________________________________________________________________________________________"<<endl;
            cout<<"|                                                                                                                            |"<<endl;
            cout<<"|                                                      Task's details                                                        |"<<endl;
            cout<<"|____________________________________________________________________________________________________________________________|"<<endl;
            cout<<"|"<<setw(5)<<"id"<<setw(15)<<"Title"<<setw(10)<<"Status"<<setw(15)<<"Time Spend"<<setw(20)<<"Start temp"<<setw(20)<<"End Temp"<<setw(20)<<"Project Id"<<setw(15)<<"Employee Id"<<setw(5)<<"|"<<endl;
            cout<<"|____________________________________________________________________________________________________________________________|"<<endl;
        }

        //list of all
        void show(){
            cout<<"|"<<setw(5)<<id<<setw(15)<<title<<setw(10)<<status<<setw(15)<<timeSpend<<setw(20)<<startTemp<<setw(20)<<endTemp<<setw(20)<<projectId<<setw(15)<<employeeId<<setw(5)<<"|"<<endl;
            cout<<"|____________________________________________________________________________________________________________________________|"<<endl;
        }


        //header for admin
        void headerProjectTasks(){
            cout<<" ______________________________________________________________________________________________"<<endl;
            cout<<"|                                                                                              |"<<endl;
            cout<<"|                            Task's details                                                    |"<<endl;
            cout<<"|______________________________________________________________________________________________|"<<endl;
            cout<<"|"<<setw(10)<<"Task id"<<setw(15)<<"Title"<<setw(15)<<"Status"<<setw(15)<<"Time Spend"<<setw(20)<<"Employee Name"<<setw(5)<<"|"<<endl;
            cout<<"|______________________________________________________________________________________________|"<<endl;
        }

        //list for admin
         void showProjectTasks(){
            cout<<"|"<<setw(10)<<id<<setw(15)<<title<<setw(15)<<status<<setw(15)<<timeSpend<<setw(20)<<e.name<<setw(5)<<"|"<<endl;
            cout<<"|______________________________________________________________________________________________|"<<endl;
        }


        //header for employee
        void headerEmployeeTasks(){
            cout<<" _______________________________________________________________________________"<<endl;
            cout<<"|                                                                               |"<<endl;
            cout<<"|                        Task's details                                         |"<<endl;
            cout<<"|_______________________________________________________________________________|"<<endl;
            cout<<"|"<<setw(10)<<"Task id"<<setw(15)<<"Title"<<setw(15)<<"Status"<<setw(15)<<"Time Spend"<<setw(20)<<"Employee Name"<<setw(5)<<"|"<<endl;
            cout<<"|_______________________________________________________________________________|"<<endl;
        }

        //list for employee
         void showEmployeeTasks(){
            cout<<"|"<<setw(10)<<id<<setw(15)<<title<<setw(15)<<status<<setw(15)<<timeSpend<<setw(20)<<e.name<<setw(5)<<"|"<<endl;
            cout<<"|_______________________________________________________________________________|"<<endl;
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

        void showAdd(){
            cout << "\nId: " << id << "\tTitle: " << title << endl;
        }

        void showTask(string id){
            inbtwShowTask(id);
        }

        void add(string projectId){
            inbtwInsertTask(projectId);
        }

        void deleteT(string id){
            inbtwDeleteTask(id);
        }

        void update(){
            inbtwUpdateTask();
        }

       void signEmployeToTask(string id, string employeeId){
            inbtwSignEmployeeToTask(id, employeeId);
        }

        void start(string taskId, string employeeId){
            inbtwStartTask(taskId, employeeId);
        }

        void pause(string id){
            inbtwPauseTask(id);
        }

        void ended(string id){
            inbtwEndTask(id);
        }

};


#endif // TASK_H_INCLUDED
