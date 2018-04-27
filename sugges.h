#ifndef SUGGES_H_INCLUDED
#define SUGGES_H_INCLUDED
class Sugges{

public:
    string id;
    Task     t;
    Employee e;
    Project  p;
void showHeader(){
        cout <<" ______________________________________________________________"<<endl;
        cout <<"|              Suggestions for selected project                |"<<endl;
        cout <<"|______________________________________________________________|"<<endl;
        cout <<"|"<<setw(18)<<"ProjectName"<<setw(23)<<"employeeName"<<setw(18)<<"TaskName"<<setw(4)<<"  |"<< endl;
        cout <<"|______________________________________________________________|"<<endl;
    }
    void showData(){

        cout <<"|"<<setw(18)<<p.id<<setw(23)<<e.id<<setw(18)<<t.id<<setw(4)<<"  |"<< endl;
        cout <<"|______________________________________________________________|"<<endl;
    }
    void showHeaderWithId(){
        cout <<" ________________________________________________________________________"<<endl;
        cout <<"|                                Suggestions                             |"<<endl;
        cout <<"|________________________________________________________________________|"<<endl;
        cout <<"|"<<setw(10)<<"SuggesId"<<setw(18)<<"ProjectName"<<setw(23)<<"employeeName"<<setw(18)<<"TaskName"<<setw(4)<<"  |"<< endl;
        cout <<"|________________________________________________________________________|"<<endl;
    }
    void showDataWithId(){

        cout <<"|"<<setw(10)<<id<<setw(18)<<p.id<<setw(23)<<e.id<<setw(18)<<t.id<<setw(4)<<"  |"<< endl;
        cout <<"|________________________________________________________________________|"<<endl;
    }






};


#endif // SUGGES_H_INCLUDED
