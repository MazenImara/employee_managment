#ifndef TIMOFF_H_INCLUDED
#define TIMOFF_H_INCLUDED
#include <sstream>
#include<string>
#include <list>
using namespace std;

class TimeOff {
public:
    string  id;
    long from ;
    long to ;
    string  employee_id;
public:
    TimeOff enter(string id){
           TimeOff timeOf;
           CustomTime c;
           timeOf.employee_id=id;

           cout <<" _______________________________________________________"<<endl;
           cout <<"|       Enter your time off  Date&Time (FROM - TO)      |"<<endl;
           cout <<"|_______________________________________________________|"<<endl;

           stringstream dd;
           dd << c.year << "/"<<c.month << "/"<<c.day ;
           string d = dd.str();

           cout <<"|     1- from (date) by form y/m/d =\t                |"<<endl;
           cout <<"|_______________________________________________________|"<<endl;
           cout <<"            "; cin >>d ;

           stringstream tt;
           tt << c.hour<<":"<<c.minut<<":"<<c.second;
           string t = tt.str();
           cout <<"|_______________________________________________________|"<<endl;
           cout <<"|      2- from (Time) by form h:m:s =\t                |"<<endl;
           cout <<"|_______________________________________________________|"<<endl;
           cout <<"            ";cin >>t ;

           string fullDateFrom =d +" "+t ;
           timeOf.from=c.getTimestampDate(fullDateFrom);

           stringstream bb;
           bb << c.year << "/"<<c.month << "/"<<c.day ;
           string b = bb.str();
           cout <<"|_______________________________________________________| "<<endl;
           cout <<"|        1- to (date) by form y/m/d =\t                |"<<endl;
           cout <<"|_______________________________________________________|"<<endl;
           cout <<"            ";cin >>b ;

           stringstream hh;
           hh << c.hour<<":"<<c.minut<<":"<<c.second;
           string h = hh.str();
           cout <<"|_______________________________________________________| "<<endl;
           cout <<"|         2- to (Time) by form h:m:s =\t                |"<<endl;
           cout <<"|_______________________________________________________|"<<endl;
           cout <<"            ";cin >>h ;
           cout <<"|_______________________________________________________|"<<endl;

           string fullDateTo =b +" "+h ;
           timeOf.to=c.getTimestampDate(fullDateTo);

           return timeOf;
    }

    void show(){

       cout <<"+-------------------------------------------------------------------------+"<<endl;
       cout <<"|              Time Off's details                                         |"<<endl;
       cout <<"+-------------------------------------------------------------------------+"<<endl;
          CustomTime c1 =CustomTime(from),c2=CustomTime(to);
       cout <<"|"<<setw(12)<<"From"<<setw(40)<<"To"<<"                     |"<< endl;
       cout <<"|_________________________________________________________________________|"<<endl;
       cout <<"|"<<setw(10)<<c1.date()<<"  "<<c1.Time()<<setw(30)<<c2.date()<<"  "<<c2.Time()<<"              |"<<endl;
       cout <<"|_________________________________________________________________________|"<<endl;


    }

};


#endif // TIMOFF_H_INCLUDED
