#ifndef INBTW_H_INCLUDED
#define INBTW_H_INCLUDED
#include <timoff.h>

// gab
void SetAdmin(std::string employeeId);
bool IsAdmin(std::string employeeId);
void createDatabase();

//Task
void inbtwShowTask(std::string taskId);
void inbtwInsertTask(std::string projectId);
void inbtwDeleteTask(std::string id);
void inbtwUpdateTask();
void inbtwShowAllTasks();
void inbtwSignEmployeeToTask(std::string taskId, std::string employeeId);
void inbtwStartTask(std::string taskId,std::string employeeId);
void inbtwPauseTask(std::string id);
void inbtwEndTask(std::string id);
//Task end

//Project
void selectProjectById(std::string projectId);
void inbtwShowAllProjects();
void inbtwInsertProject();
void inbtwDeleteProject(std::string id);
void inbtwUpdateProject();
void inbtwShowProjectTasks();
long stringToLong(std::string str);
long longToString(std::string str);
void inbtwShowEmployeeTasksAndProject(std::string employeeId);
//project end
// end gab

//MOHAMAD
void showProjectsWithTasks(string id);
void showProjectsWithTasksForAdmin();
void showAllTasksForProject(string id);
void showDays( long date1,long date2,std::string id);
void showTimeOff(std::string id);
void showTimesOffWithId(std::string id);
void showTaskForEmployee(std::string employeeId);
void insertTimeOff(TimeOff timeOf);
TimeOff selectTimeOff(std::string id);
void updateTimeOff(TimeOff timeOf);
void deleteTimeOff(std::string id);
void showEmployee();
void insertEmployee();
void updateEmployee();
void signEmployeeAsAdmin();
void deleteEmployee();
long employeeLoginRecord(std:: string id);
void employeeLogoutRecord(std::string id,long temp);
void convertTaskStatusIfStatusWasStarted(string id,long temp);
bool cancel(string input);
bool cancelMenu(int &n);


#endif // INBTW_H_INCLUDED
