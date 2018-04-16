#ifndef DAY_H_INCLUDED
#define DAY_H_INCLUDED
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

//MOHAMAD CODE

class Day{
public:
    string id,employee_id;
    long  date ,start,endTime,temp;
    int timeSpend;
public:
    void enterDate(){
        cout<<"Enter date=\t";cin >>date;
    }
    void enterStart(){
        cout <<"Enter start=\t";cin >>start;
    }
    void enterEnd(){
        cout <<"Enter end=\t";cin >>endTime;
    }
    long enterPeriodStepByStep(){
       cout <<"+---------------------------------------------------------+"<<endl;
       cout <<"|Enter the date period that you need to show work details |"<<endl;
       cout <<"+---------------------------------------------------------+"<<endl;
       CustomTime c;Employee e;
       string date=e.getDate();
       date =date+" "+ "00"+ ":" + "00" + ":" + "00";
       long date1=c.getTimestampDate(date);
       return date1;
    }
    long enterPeriod(){
           CustomTime c;
           cout <<"+----------------------------------------------------------------+"<<endl;
           cout <<"|   Enter the date period that you need to show work details     |"<<endl;
           cout <<"|                    by form year/month/day                      |"<<endl;
           cout <<"+----------------------------------------------------------------+"<<endl;

           stringstream dd;
           dd << c.year << "/"<<c.month << "/"<<c.day ;
           string d = dd.str();
           cout <<"            "; cin >>d ;
           string date =d+" "+ "00"+ ":" + "00" + ":" + "00";
           long date1=c.getTimestampDate(date);
           return date1;
    }
    string longToString(long  number){
    std::stringstream ss;
    ss << number;
    return ss.str();
    }
    long stringToLong(string str){
        return atol(str.c_str());
    }
};

#endif // DAY_H_INCLUDED
