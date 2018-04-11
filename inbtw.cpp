#include <string>
#include <database.h>
using namespace std;

// gab
void SetAdmin(string employeeId){
    Database db;
    db.setAdmin(employeeId);
    db.close();
}
bool IsAdmin(string employeeId){
    Database db;
    bool is = db.isAdmin(employeeId);    db.close();
    return is;
}
// end gab

//Ikram
void pauseTask(){
    Task t;
    Database db;
    t.enterId();
    db.pauseTask(t.id);
}

void endTask(){
    Task t;
    Database db;
    t.enterId();
    db.endTask(t.id);
}

void startTask(){
    Task t;
    Database db;
    t.enterId();
    db.startTask(t.id);
}
//end Ikram

