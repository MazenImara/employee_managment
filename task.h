#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED

class Task{
public:
    string id;
    string title;
    string status;
    string timespend;
    string datecreated;
    string start;
    string project_id;
    string employee_id;
public:
    void enterId(){
        cout<<" Enter id: "<<endl;cin>>id;
        }
    void enter(){
        cout<<" Enter Title: "<<endl;cin>>title;
    }
    void show(){
        cout<<" Enter id: "<<endl;cin>>id;
        cout<<" Enter Title: "<<endl;cin>>title;
        cout<<" Enter Status: "<<endl;cin>>status;
        cout<<" Enter Time spend: "<<endl;cin>>timespend;
        cout<<" Enter Date created: "<<endl;cin>>datecreated;
        cout<<" Enter Start: "<<endl;cin>>start;
        cout<<" Enter Project id: "<<endl;cin>>project_id;
        cout<<" Enter Employee id: "<<endl;cin>>employee_id;
    }
};

#endif // TASK_H_INCLUDED
