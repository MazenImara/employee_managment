#ifndef DAY_H_INCLUDED
#define DAY_H_INCLUDED
#include <sstream>
#include <iostream>
#include <string>
using namespace std;



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
