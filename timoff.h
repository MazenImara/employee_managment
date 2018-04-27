#ifndef TIMOFF_H_INCLUDED
#define TIMOFF_H_INCLUDED
#include <sstream>
#include<string>
#include <list>
#include <gtime.h>

using namespace std;

//MOHAMAD CODE

class TimeOff {
public:
    string  id;
    long from ;
    long to ;
    string  employeeId;
    bool check;
public:
    TimeOff enter(string id){

        TimeOff timeOf;
        CustomTime c;
        string f="*";
        timeOf.employeeId=id;
        bool returnToBegin=false;
        timeOf.check=false;
        do {
            cout <<"+-----------------------------------------------------------+"<<endl;
            cout <<"|       |- Enter your time off  Date&Time (FROM - TO)       |"<<endl;
            cout <<"|  OBS  |- Press (oneDay/D/d) for input date of this day    |"<<endl;
            cout <<"|       |- Press (full/F/f) for input full time Of          |"<<endl;
            cout <<"|       |- Press (N/n)  for new input                       |"<<endl;
            cout <<"|       |- Press *   for back to Menu                       |"<<endl;
            cout <<"|___________________________________________________________|"<<endl;
            stringstream dd;
            dd << c.year << "/"<<c.month << "/"<<c.day ;
            string d = dd.str();
            cout <<"|     1- from (date) by form y/m/d =\t                    |"<<endl;
            cout <<"|___________________________________________________________|"<<endl;
            cout <<"            "; cin >>d ;
            if (d=="*"){
                goto backToMenu;
            }
            else{
                 if (d=="oneDay" || d=="D" || d=="d") {
                      cout <<" ___________________________________________________________"<<endl;
                      cout <<"|     Enter the (date) by form y/m/d =                      |"<<endl;
                      cout <<"|___________________________________________________________|"<<endl;
                      cout <<"            "; cin >>d ;
                      stringstream tt;
                      tt << 8<<":"<<0<<":"<<0;
                      string t = tt.str();
                      string fullDateFrom =d +" "+t ;
                      timeOf.from=c.getTimestampDate(fullDateFrom);

                      stringstream hh;
                      hh << 17<<":"<<0<<":"<<0;
                      string h = hh.str();
                      string fullDateTo =d +" "+h ;
                      timeOf.to=c.getTimestampDate(fullDateTo);
                      goto continuePro;
                 }
                 else{
                     if (d=="N" || d=="n"){
                        goto backToEnter;
                     }
                     else{
                         stringstream tt;
                         tt << c.hour<<":"<<c.minut<<":"<<c.second;
                         string t = tt.str();
                         cout <<"|___________________________________________________________|"<<endl;
                         cout <<"|      2- from (Time) by form h:m:s =\t                    |"<<endl;
                         cout <<"|___________________________________________________________|"<<endl;
                         cout <<"            ";cin >>t ;
                         if (t=="*"){
                            goto backToMenu;
                         }
                         else{
                             if (t=="N" || t=="n"){
                                goto backToEnter;
                             }
                             if (t=="full" || t=="F" || t=="f"){
                                stringstream tt;
                                tt << 8<<":"<<0<<":"<<0;
                                t = tt.str();
                             }
                             string fullDateFrom =d +" "+t ;
                             timeOf.from=c.getTimestampDate(fullDateFrom);
                             stringstream bb;
                             bb << c.year << "/"<<c.month << "/"<<c.day ;
                             string b = bb.str();
                             cout <<"|___________________________________________________________|"<<endl;
                             cout <<"|       1- to (date) by form y/m/d =\t                    |"<<endl;
                             cout <<"|___________________________________________________________|"<<endl;
                             cout <<"            ";cin >>b ;
                             if (b=="*"){
                                goto backToMenu;
                             }
                             else{
                                if (b=="N" || b=="n"){
                                    goto backToEnter;
                                }
                                stringstream hh;
                                hh << c.hour<<":"<<c.minut<<":"<<c.second;
                                string h = hh.str();
                                cout <<"|___________________________________________________________|"<<endl;
                                cout <<"|       2- to (Time) by form h:m:s =\t                    |"<<endl;
                                cout <<"|___________________________________________________________|"<<endl;
                                cout <<"            ";cin >>h ;
                                cout <<"|___________________________________________________________|"<<endl;
                                if (h=="*"){
                                    goto backToMenu;
                                }
                                else{
                                    if (h=="N" || h=="n"){
                                        goto backToEnter;
                                    }
                                    if (h=="full" || h=="F" || h=="f"){
                                        stringstream hh;
                                        hh << 17<<":"<<0<<":"<<0;
                                        h = hh.str();
                                    }
                                    string fullDateTo =b +" "+h ;
                                    timeOf.to=c.getTimestampDate(fullDateTo);
                                    timeOf.check=true;
                                    goto continuePro;
                               }
                             }
                            }
                       }

                    }
            }


                backToEnter: {
                    returnToBegin=true;
                    cout <<"+-----------------------------------------------------------+"<<endl;
                    cout <<"|       try to enter again correct (Date and Time)          |"<<endl;
                    cout <<"+-----------------------------------------------------------+"<<endl;
               }
        } while(returnToBegin==true);

        continuePro:{
            if (timeOf.from==-1 || timeOf.to==-1){
                cout <<"+----------------------------+"<<endl;
                cout <<"|   Wrong input tray again   |"<<endl;
                cout <<"+----------------------------+"<<endl;
                system("pause");
                timeOf.check=false;
            }
            else{
              timeOf.check=true;
              return timeOf;
            }
        }
            backToMenu:{
              timeOf.check=false;
        }


    }
    void showHeaderWithId(){
    cout <<" ___________________________________________________________________________"<<endl;
    cout <<"|                                   Your TimesOff                           |"<<endl;
    cout <<"|___________________________________________________________________________|"<<endl;
    cout <<"|"<<setw(5)<<"ID"<<setw(18)<<"From"<<setw(32)<<"To"<<setw(21)<<"|"<< endl;
    cout <<"|___________________________________________________________________________|"<<endl;
    }
    void showHeaderWithout(){
    cout <<" ___________________________________________________________"<<endl;
    cout <<"|                       Your TimesOff                       |"<<endl;
    cout <<"|___________________________________________________________|"<<endl;
    cout <<"|"<<setw(15)<<"From"<<setw(30)<<"To"<<setw(15)<<"|"<< endl;
    cout <<"|___________________________________________________________|"<<endl;
    }
    void show(){
        // TimeOff timeOf;
         cout <<"+-----------------------------------------------------------+"<<endl;
         cout <<"|                   Time Off's details                      |"<<endl;
         cout <<"|___________________________________________________________|"<<endl;
         cout <<"|"<<setw(15)<<"From"<<setw(30)<<"To"<<setw(15)<<"|"<< endl;
         CustomTime c1 =CustomTime(from),c2=CustomTime(to);
         cout <<"|___________________________________________________________|"<<endl;
         cout <<"|"<<setw(10)<<c1.date()<<"  "<<setw(10)<<c1.Time()<<setw(20)<<c2.date()<<"  "<<setw(10)<<c2.Time()<<setw(6)<<"|"<<endl;
         cout <<"|___________________________________________________________|"<<endl;
}
};


#endif // TIMOFF_H_INCLUDED
