#ifndef GTIME_H_INCLUDED
#define GTIME_H_INCLUDED

#include <iostream>
#include <string>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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


    string  date()
    {
        stringstream sy;    sy << year;     string dateY = sy.str();
        stringstream sm;    sm << month;    string dateM = sm.str();
        stringstream sd;    sd << day;      string dateD = sd.str();

        string date = dateY + "-" + dateM + "-" + dateD;

        return date;
    }

    string Time()
    {
        stringstream sh;    sh << hour;       string shour = sh.str();
        stringstream sm;    sm << minut;      string sminut = sm.str();
        stringstream ss;    ss << second;     string ssecond = ss.str();

        string time = shour + ":" + sminut + ":" + ssecond;

        return time;
    }

    long getTimestampDate(string date){


    //string startTime = "2016/05/18 13:10:00";
    string startTime = date;
    time_t tStart;
    int yy, month, dd, hh, mm, ss;
    struct tm whenStart;
    const char *zStart = startTime.c_str();

    sscanf(zStart, "%d/%d/%d %d:%d:%d", &yy, &month, &dd, &hh, &mm, &ss);
    whenStart.tm_year = yy - 1900;
    whenStart.tm_mon = month - 1;
    whenStart.tm_mday = dd;
    whenStart.tm_hour = hh+1;
    whenStart.tm_min = mm+60;
    whenStart.tm_sec = ss;
    whenStart.tm_isdst = -1;

    tStart = mktime(&whenStart);

    std::cout << tStart << std::endl;

    }

    long getTimestampDate(){

        time_t result = time(NULL);

        cout << result << endl;
    }
   /* long longTimestamp()
    {


        long mylong = atol(c.getTimestampDate().c_str());
    }*/
};




#endif // GTIME_H_INCLUDED
