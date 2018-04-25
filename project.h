#ifndef PROJECT_H_INCLUDED
#define PROJECT_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;
class Project{
    public:
        string id, title, description, status,timeSpend;

        bool check=true;
    public:
        void enterId(){
            cout << "Enter project id: ";
            cin >> id;
            if (cancel(id)==false){
                check=false;
            }
        }

        /*void show(){
            cout << "id: " << id << "\t\ttitle: " << title << "\t\tdescription: " << description << "\t\tstatus: " << status << endl;
        }*/
        void header()
        {
            cout <<" _______________________________________________________________________________________________________________"<<endl;
            cout <<"|                                                                                                               |"<<endl;
            cout <<"|                                               Project's details                                               |"<<endl;
            cout <<"|_______________________________________________________________________________________________________________|"<<endl;
            cout <<"|"<<setw(10)<<"id"<<setw(20)<<"Title"<<setw(30)<<"Description"<<setw(20)<<"Status"<<setw(20)<<"TimeSpend"<<setw(12)<<"|"<<endl;
        }
        void show(){

            cout <<"|"<<setw(10)<<id<<setw(20)<<title<<setw(30)<<description<<setw(20)<<status<<setw(20)<<timeSpend<<setw(12)<<"|"<<endl;
            cout <<"|_______________________________________________________________________________________________________________|"<<endl;
        }

        void enter(){
            cout << "Enter project details" << endl;
            cout << "Title: ";
            cin >> title;
            if (cancel(title)==false){
               check=false;
            }
            else{
            cout << "\nDescription: ";
            cin >> description;
            cout << endl;
            if (cancel(description)==false){
                check=false;
            }
            }
        }

        void Add()
        {
            inbtwInsertProject();
        }

        void Delete(string id)
        {
            inbtwDeleteProject(id);
        }

        void Update()
        {
            inbtwUpdateProject();
        }
};

#endif // PROJECT_H_INCLUDED
