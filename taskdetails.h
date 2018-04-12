#ifndef TASKDETAILS_H_INCLUDED
#define TASKDETAILS_H_INCLUDED
#include <iostream>
#include <string>
#include <task.h>
#include <employee.h>

using namespace std;

class TaskDetails{
public:
    string id, taskId, employeeId, timeSpend;

public:
    void showTimeSpend(){
        cout<< "Time Spend: "<< timeSpend <<endl;
    }
};

#endif // TASKDETAILS_H_INCLUDED
