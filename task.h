#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED
#include <iostream>
#include <string>
#include <windows.h>


using namespace std;

class Task{
//    t.started();
<<<<<<< HEAD
 //   t.paused();
   // t.ended();
=======
//    t.paused();
//    t.ended();
>>>>>>> 56b303365a62222217270de948b68424ff311b65
public:
    string id;
    string title;
    string status;
    string time_spend;
    string date_created;
    string start;
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
        cout<<"\nId: "<< id <<"\tTitle: "<< title <<"\tStatus: "<< status <<"\tTime Spend: "<< time_spend <<"\tDate Created: "<< date_created <<"\tProject id: "<< project_id <<"\tEmployee id: "<< employee_id <<endl;
    }
    void started(){
        Task t;
        cout<<"\nEnter id of the task: ";cin>>id;
    }
    void ended(){
        cout<<"\nEnter id of the task: ";cin>>id;
    }
};

#endif // TASK_H_INCLUDED
