#ifndef TIMEOFF_H_INCLUDED
#define TIMEOFF_H_INCLUDED

#include <sstream>
#include <string>


using namespace std;

class TimeOff {
public:
    string  id;
    long from ;
    long to ;
    string  employee_id;
public:
    /*void enter(){
        cout <<"Enter your time off by form (y/m/d h:m:s) "<<endl;
        cout <<"from =\t"<<endl;
        cin >>from; cout <<endl;
        cout <<"to  =\t"<<endl;
        cin >>to; cout <<endl;
        */
     enter(string id){
         CustomTime c;
        cout <<"Enter your time off  Date&Time (FROM - TO) "<<endl;

       stringstream dd;
       dd << c.year << "/"<<c.month << "/"<<c.day ;
       string d = dd.str();
       cout <<"from (date) by form y/m/d =\t"<<endl;

       cin >>d ;
       stringstream tt;
       tt << c.hour<<":"<<c.minut<<":"<<c.second;
       string t = tt.str();
       cout <<"from (Time) by form h:m:s =\t"<<endl;
       cin >>t ;
       string fullDate =d +" "+t ;
       from=c.getTimestampDate(fullDate);

       stringstream dd;
       dd << c.year << "/"<<c.month << "/"<<c.day ;
       string d = dd.str();
       cout <<"to (date) by form y/m/d =\t"<<endl;

       cin >>d ;
       stringstream tt;
       tt << c.hour<<":"<<c.minut<<":"<<c.second;
       string t = tt.str();
       cout <<"to (Time) by form h:m:s =\t"<<endl;
       cin >>t ;
       string fullDate =d +" "+t ;
       to=c.getTimestampDate(fullDate);
    }
    void show(){
       cout <<" _____________________________________________________"<<endl;
       cout <<"|              Time Off's details                     |"<<endl;
       cout <<"|_____________________________________________________|"<<endl;
       cout <<"|"<<setw(10)<<"From"<<setw(20)<<"To"<< endl;
       cout <<"|"<<setw(10)<<from<<setw(20)<<to<<"|"<<endl;
       cout <<"|_____________________________________________________|"<<endl;


    }
};


#endif // TIMEOFF_H_INCLUDED
