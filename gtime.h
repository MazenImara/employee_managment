#ifndef GTIME_H_INCLUDED
#define GTIME_H_INCLUDED

#include <iostream>
#include <string>
#include <time.h>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

class CustomTime
{
public:

    int day, month ,year, hour ,minut , second ;
    time_t timeStamp;



public:
   CustomTime(time_t st)
   {
       timeStamp = st;
        struct tm nowLocal=*localtime(&timeStamp);
        //setAtt(nowLocal);
        day = nowLocal.tm_mday;
        month = nowLocal.tm_mon+1;
        year = nowLocal.tm_year+1900;
        hour = nowLocal.tm_hour;
        minut = nowLocal.tm_min;
        second = nowLocal.tm_sec;
   }

    CustomTime(){
        timeStamp=time(NULL);
        struct tm nowLocal=*localtime(&timeStamp);
        //setAtt(nowLocal);
        day = nowLocal.tm_mday;
        month = nowLocal.tm_mon+1;
        year = nowLocal.tm_year+1900;
        hour = nowLocal.tm_hour;
        minut = nowLocal.tm_min;
        second = nowLocal.tm_sec;
    }


    string  showDate()
    {
        stringstream sy;    sy << year;     string dateY = sy.str();
        stringstream sm;    sm << month;    string dateM = sm.str();
        stringstream sd;    sd << day;      string dateD = sd.str();

        string date = dateY + "-" + dateM + "-" + dateD;

        return date;
    }

    string showTime()
    {
        stringstream sh;    sh << hour;       string shour = sh.str();
        stringstream sm;    sm << minut;      string sminut = sm.str();
        stringstream ss;    ss << second;     string ssecond = ss.str();

        string time = shour + ":" + sminut + ":" + ssecond;

        return time;
    }

};




#endif // GTIME_H_INCLUDED
