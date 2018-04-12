#include <string>
#include <database.h>
#include <task.h>
using namespace std;

// gab
void SetAdmin(string employeeId){
    Database db;
    db.setAdmin(employeeId);
    db.close();
}
void SetEmployeTask(){
    Database db;
    Task t;
    Employee e;
    db.selectTasks();
    t.enterId();
    db.selectTask(t.id);
    e.enterId();
    db.setEmployeTask(t.id, e.id);
    db.close();
}

bool IsAdmin(string employeeId){
    Database db;
    bool is = db.isAdmin(employeeId);    db.close();
    return is;
}

void GetTask(string taskId) {
    Task t;
    Database db;
    t = db.selectTask(taskId);
    t.show();
}

void createDatabase(){
    Database db;
    db.createDatabase();

}
// end gab

//Ikram
void pauseTask(string id){
    Database db;
    db.pauseTask(id);
}

void endTask(string id){
    Database db;
    db.endTask(id);
}

void startTask(string id){
    Database db;
    db.startTask(id);
}
//end Ikram

