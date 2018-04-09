#ifndef PROJECT_H_INCLUDED
#define PROJECT_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;
class Project{
    public:
        string id, title, description, status;
    public:
        void enterId(){
            cout << "Enter project id: ";
            cin >> id;
        }

        void show(){
            cout << "id: " << id << "\t\ttitle: " << title << "\t\tdescription: " << description << "\t\tstatus: " << status << endl;
        }

        void enter(){
            cout << "Enter project details" << endl;
            cout << "Title: ";
            cin >> title;
            cout << "\ndescription: ";
            cin >> description;
            cout << endl;
        }

};

#endif // PROJECT_H_INCLUDED
