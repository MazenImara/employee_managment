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


//Task ONLY
void GetTask(string taskId)
{
    Task t;
    Database db;
    t = db.selectTask(taskId);
    t.show();
}

void GetInsertTask(string ProjectId)
{
    Task t;
    Database db;
    t.enter();
    t.status = "New";
    t.project_id = ProjectId;
    db.insertTask(t);
}
void GetDeleteTask(string taskId)
{
    Database db;
    db.deleteTask(taskId);
}
void GetUpdateTask()
{
    Task t;
    Database db;
    t.enterId();
    t.enter();
    db.updateTask(t);
}

void startTask(string id){
    Database db;
    db.startTask(id);
}

void pauseTask(string id){
    Database db;
    db.pauseTask(id);
}

void endTask(string id){
    Database db;
    db.endTask(id);
}


//Task End

//Project ONLY
void GetInsertProject()
{
    Project p;
    Database db;
    p.enter();
    p.status = "new";
    db.insertProject(p);
}

void GetDeleteProject(string id)
{
    Database db;
    db.deleteProject(id);
}

void GetUpdateProject()
{
    Project p;
    Database db;
    p.enterId();
    p.enter();
    db.updateProject(p);
}
//Project End

void createDatabase(){
    Database db;
    db.createDatabase();

}


// end gab


