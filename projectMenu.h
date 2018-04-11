#ifndef PROJECTMENU_H_INCLUDED
#define PROJECTMENU_H_INCLUDED
#include <iostream>
#include <string>
#include <iomanip>
#include <project.h>
#include <list>
#include <database.h>
using namespace std;


/*
void showAllProjects(){
    Database db;
    Project p;
    list<Project> projects;
    projects = db.selectProjects();
    for(p:projects){
        p.show();
    }
    db.close();
}
*/



void updateProject(){
    Database db;
    Project p;
    cout << "1. Update project" << endl;
    cout << "2. Delete project" << endl;

    int menuChoice;
    cin >> menuChoice;
    switch(menuChoice){
    case 1:
        p.enterId();
        p = db.selectProject(p.id);
        cout << "1. Update project details" << endl;
        cout << "2. Manage task" << endl;

        int choice;
        cin >> choice;
        switch(choice){
        case 1:
            p.enter();
            p.status = "new";
            db.updateProject(p);
            break;
        case 2:
            break;
        default:
            cout << "Invalid choice" << endl;
            updateProject();
        }
    case 2:
        p.enterId();
        p = db.selectProject(p.id);
        db.deleteProject(p);
        break;
    default:
        cout << "Invalid choice" << endl;
        updateProject();
    }
}
void manageProject(){
    Database db;
    Project p;
    cout << "================== Manage project ==================" << endl;
    cout << "1. Show all projects" << endl;
    cout << "2. Add project" << endl;
    int menuChoice;
    cin >> menuChoice;
    switch(menuChoice){
    case 1:
        cout << "================== All projects ==================" << endl;
//        showAllProjects();
        updateProject();
        break;
    case 2:
        p.enter();
        p.status = "new";
        db.insertProject(p);
        break;
    default:
        cout << "Invalid choice" << endl;
        manageProject();
    }
}

void manageProjectMenu(){
    cout << "================== Project menu ==================" << endl;
    cout << "1. Manage project" << endl;
    cout << "2. manage employee" << endl;

    int menuChoice;
    cin >> menuChoice;
    switch(menuChoice){
    case 1:
        manageProject();
        break;
    case 2:
        break;
    default:
        cout << "Invalid choice" << endl;
        manageProjectMenu();
    }
}

//show tasks for a specific project
void showProjectTasks(string project_id){
    Database db;
    Task t;
    Employee e;
    list<Task> tasks;
    //list<Employee> employees;
    tasks = db.selectProjectTasks(project_id);
    for(t:tasks){
        t.show();
        cout << "========== Employee work on this task=============" << endl;
        e = db.selectEmployeeById(t.employee_id);
        e.show();
    }
    db.close();
}



#endif // PROJECTMENU_H_INCLUDED
