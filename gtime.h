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

    char *strptime(const char * __restrict, const char * __restrict, struct tm * __restrict);

        const char *time_details = date.c_str();
        struct tm tm;
        strptime(time_details, "%Y:%m:%d", &tm);
        time_t t = mktime(&tm);




    }

    long getTimestampDate(){


        time_t result = time(NULL);
        struct tm nowLocal=*localtime(&result);

        day = nowLocal.tm_mday;
        month = nowLocal.tm_mon+1;
        year = nowLocal.tm_year+1900;
        long result2 = year;

        cout << result2 << endl;
    }
   /* long longTimestamp()
    {


        long mylong = atol(c.getTimestampDate().c_str());
    }*/
};




#endif // GTIME_H_INCLUDED
