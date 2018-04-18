#include <string>
#include <database.h>
#include <task.h>
#include <show.h>
using namespace std;


void workTimesMenu(string id);

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

void createDatabase(){
    Database db;
    db.createDatabase();

}

//Task updated by ikram
void inbtwShowTask(string taskId)
{
    Task t;
    Database db;
    t = db.selectTask(taskId);
    t.show();
}

void inbtwInsertTask(string projectId)
{
    Task t;
    Database db;
    t.enter();
    t.status = "New";
    t.projectId = projectId;
    db.insertTask(t);
}

void inbtwDeleteTask(string taskId)
{
    Database db;
    db.deleteTask(taskId);
}

void inbtwUpdateTask()
{
    Task t;
    Database db;
    t.enterId();
    t.enterNewTitle();
    db.updateTask(t);
}

void inbtwShowAllTasks(){
    Database db ;
    list<Task> ts =  db.selectTasks();
    Task t;
    for(t:ts){
        t.show();
    }
}

void inbtwSignEmployeeToTask(string taskId, string employeeId){
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
//end updating

void inbtwStartTask(string taskId, string employeeId){
    Database db;
    db.startTask(taskId, employeeId);
}

void inbtwPauseTask(string id){
    Database db;
    db.pauseTask(id);
}

void inbtwEndTask(string id){
    Database db;
    db.endTask(id);
}
//Task End


//Project ONLY
//updated by ikram
void inbtwShowAllProjects(){
    Database db;
    Project p;
    list<Project> projects;
    projects = db.selectProjects();
    for(p:projects){
        p.show();
    }
    db.close();
}

void inbtwInsertProject()
{
    Project p;
    Database db;
    p.enter();
    p.status = "new";
    db.insertProject(p);
}

void inbtwDeleteProject(string id)
{
    Database db;
    db.deleteProject(id);
}

void inbtwUpdateProject()
{
    Project p;
    Database db;
    p.enterId();
    p.enter();
    db.updateProject(p);
}
//Project End
//end updating



// end gab

// mazen
    string longToString(long  number){
        std::stringstream ss;
        ss << number;
        return ss.str();
    }
    long stringToLong(string str){
        return atol(str.c_str());
     }
// end mazen

//start ikram
void inbtwInsertEmployee(){
    Employee e;
    Database db;
    e.enter();
    db.insertEmployee(e);
    e=db.selectEmployeeByEmail(e.email);
    e.show();
}

void inbtwUpdateEmployee(){
    Employee e;
    Show s;
    Database db;
    s.Employee();
    e.enterId();
    e=db.selectEmployeeById(e.id);
    e.show();
    cout <<" ________________________"<<endl;
    cout <<"|    enter new details   |"<<endl;
    cout <<"|________________________|"<<endl;
    e.enter();
    db.updateEmployee(e);
}

void inbtwDeleteEmployee(){
    Employee e;
    Show s;
    Database db;
    s.Employee();
    e=db.selectEmployeeById(e.id);
    e.show();
    e.enterId();
    cout <<" __________________________"<<endl;
    cout <<"|  are you sure press Y/N  |"<<endl;
    cout <<"|__________________________|"<<endl;
    string  choice;
    cin>>choice ;
    if (choice=="y" || choice=="Y"){
        db.deleteEmployee(e.id);
    }
}

void inbtwShowEmployees(){
    Employee e;
    Show s;
    Database db;
    string id;
    s.Employee();
    cout <<" ___________________________________________________________"<<endl;
    cout <<"|    Enter the id you need to show  the work's detail       |"<<endl;
    cout <<"|___________________________________________________________|"<<endl;
    e.enterId();
    workTimesMenu(e.id);
}

void inbtwSignEmployeeAsAdmin(){
    Employee e;
    e.enterId();
    SetAdmin(e.id);
}

void inbtwShowWorkDetails(string id){
    Employee e;
    Database db;
    Day d;
    Show s;
    e=db.selectEmployeeById(id);
    e.show();
    long date1=d.enterPeriod();
    long date2=d.enterPeriod();
    s.Days(date1,date2,id);
}

void inbtwShowTaskForEmployee(string id){
    Show s;
    Employee e;
    s.TaskForEmployee(id);
}

void inbtwShowTimeOff(string id){
    Show s;
    Employee e;
    s.AllTimesOff(id);
}
//end ikram


