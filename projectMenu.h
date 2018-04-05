#ifndef PROJECTMENU_H_INCLUDED
#define PROJECTMENU_H_INCLUDED

#include <iostream>
#include <string>
#include <iomanip>
#include <project.h>
#include <list>

#include <database.h>

using namespace std;

void manageProject();
void manageProjectMenu();


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

void updateProject(){
    Database db;
    Project p;
    cout << "1. Update project" << endl;
    cout << "2. Delete project" << endl;
    cout << "0. Back" << endl;

    int menuChoice;
    cin >> menuChoice;
    switch(menuChoice){
    case 1:
        p.enterId();
        p = db.selectProject(p.id);
        cout << "1. Update project details" << endl;
        cout << "2. Manage task" << endl;
        cout << "0. Back" << endl;

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
        case 0:
            updateProject();
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
    case 0:
        manageProject();
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
    cout << "0. Back" << endl;
    int menuChoice;
    cin >> menuChoice;
    switch(menuChoice){
    case 1:
        cout << "================== All projects ==================" << endl;
        showAllProjects();
        updateProject();
        break;
    case 2:
        p.enter();
        p.status = "new";
        db.insertProject(p);
        break;
    case 0:
        manageProjectMenu();
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



#endif // PROJECTMENU_H_INCLUDED
