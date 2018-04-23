#ifndef DAY_H_INCLUDED
#define DAY_H_INCLUDED
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

//MOHAMAD CODE

class Day{
public:
    string id,employeeId;
    long  date ,start,endTime,temp;
    int timeSpend;
    bool check;
    long period1,period2;

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
    void showHeader(){
    cout <<" ________________________________________________________________________________"<<endl;
    cout <<"|                       Days's details for Employee                              |"<<endl;
    cout <<"|________________________________________________________________________________|"<<endl;
    cout <<"|"<<setw(18)<<"Date"<<setw(23)<<"startTime"<<setw(18)<<"endTime"<<setw(18)<<"timeSpend"<<setw(4)<<"  |"<< endl;
    cout <<"|________________________________________________________________________________|"<<endl;
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
    Day enterPeriod(){
           CustomTime c;
           Day day;
           bool returnToBegin=false;
           day.check=false;
           do{
           cout <<"+----------------------------------------------------------------+"<<endl;
           cout <<"|   Enter the date period that you need to show work details     |"<<endl;
           cout <<"|                    by form year/month/day                      |"<<endl;
           cout <<"|  OBS  |2- Press (thisMonth) for this month                     |"<<endl;
           cout <<"|       |3- Press (N/n)  for new input                           |"<<endl;
           cout <<"|       |4- Press *   for back to Menu                           |"<<endl;
           cout <<"+----------------------------------------------------------------+"<<endl;
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
                if (d=="N" || d=="n"){
                    goto backToEnter;
                }

                    if (d=="thisMonth"){
                        stringstream mm;
                        mm << c.beginThisMonth();
                        string m = mm.str();

                        stringstream nn;
                        nn << c.firstNextMonth();
                        string n = nn.str();

                        string date =m+" "+ "00"+ ":" + "00" + ":" + "00";
                        day.period1=c.getTimestampDate(date);


                        string date2 =n+" "+ "00"+ ":" + "00" + ":" + "00";
                        day.period2=c.getTimestampDate(date2);
                        goto continuePro;
                    }
                    else{
                        string date =d+" "+ "00"+ ":" + "00" + ":" + "00";
                        day.period1=c.getTimestampDate(date);
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

                            string date3 =b+" "+ "00"+ ":" + "00" + ":" + "00";
                            day.period2=c.getTimestampDate(date3);
                            goto continuePro;
                           }
                       }
                  }

                backToEnter: {
                    returnToBegin=true;
                    /*
                    cout <<"+-----------------------------------------------------------+"<<endl;
                    cout <<"|       try to enter  again                                 |"<<endl;
                    cout <<"+-----------------------------------------------------------+"<<endl;
                    system("pause");
                    system("cls");
                    */
                }
        } while(returnToBegin==true);

        continuePro:{
            if (day.period1==-1 || day.period2==-1){
                cout <<"+----------------------------+"<<endl;
                cout <<"|   Wrong input tray again   |"<<endl;
                cout <<"+----------------------------+"<<endl;
                system("pause");
                day.check=false;
            }
            else{
              day.check=true;
              return day;
            }
        }
        backToMenu:{
              day.check=false;
        }/*
        cout<<day.period1<<endl;
       cout<<day.period2<<endl;
           cout<<day.check<<endl;
           system("pause");
           */
   }
/*
           stringstream dd;
           dd << c.year << "/"<<c.month << "/"<<c.day ;
           string d = dd.str();
           cout <<"            "; cin >>d ;
           string date =d+" "+ "00"+ ":" + "00" + ":" + "00";
           long date1=c.getTimestampDate(date);
           return date1;
           */

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
