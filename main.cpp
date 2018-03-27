
#include <iostream>
#include <string>
#include <database.h>
#include <gtime.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int main()
{
    CustomTime t(10000);

    cout<< t.timeStamp + 1000 << endl;
    cout<< t.showDate()<< endl;
    cout<< t.showTime()<< endl;


    return 0;
}

int main1(){
/*
  time_t base = 1142085600;
    struct tm* tm = localtime(&base);
    tm->tm_mday += i;
    time_t next = mktime(tm);
    std::cout << ctime(&next);

 */
return 0;
}

