#ifndef INBTW_H_INCLUDED
#define INBTW_H_INCLUDED
#include <timoff.h>

// gab
void SetAdmin(std::string employeeId);
bool IsAdmin(std::string employeeId);
void SetEmployeTask();
void createDatabase();

//Task ONLY
void selectTask(std::string taskId);
void insertTask(std::string id);
void deleteTask(std::string id);
void updateTask();
void startTask(std::string TId,std::string EId);
void pauseTask(std::string id);
void endTask(std::string id);
//Task end

//Project ONLY
void insertProject();
void deleteProject(std::string id);
void updateProject();
long stringToLong(std::string str);
long longToString(std::string str);

// end gab

//MOHAMAD
void showDays( long date1,long date2,std::string id);
void showTaskForEmployee(std::string employeeId);
void showTimesOffWithId(std::string id);
void showTimeOff(std::string id);

void showEmployee();
void insertTimeOff(TimeOff timeOf);
void updateTimeOff(TimeOff timeOf);
void deleteTimeOff(std::string id);
TimeOff selectTimeOff(std::string id);
void insertEmployee();
void updateEmployee();
void deleteEmployee();

//end MOHAMAD.

#endif // INBTW_H_INCLUDED
