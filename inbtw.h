#ifndef INBTW_H_INCLUDED
#define INBTW_H_INCLUDED
#include <timoff.h>
#include <employee.h>

// gab
void SetAdmin(std::string employeeId);
bool IsAdmin(std::string employeeId);
void SetEmployeTask();
void createDatabase();

//Task ONLY
void GetTask(std::string taskId);
void GetInsertTask(std::string id);
void GetDeleteTask(std::string id);
void GetUpdateTask();
void startTask(std::string TId,std::string EId);
void pauseTask(std::string id);
void endTask(std::string id);
//Task end

//Project ONLY
void GetInsertProject();
void GetDeleteProject(std::string id);
void GetUpdateProject();
long stringToLong(std::string str);
long longToString(std::string str);

// end gab

//MOHAMAD
void showTaskForEmployee(std::string employeeId);
void showTimesOffWithId(std::string id);
void showTimeOff(std::string id);
void showDays( long date1,long date2,std::string id);
void showEmployee();
void getInsertTimeOff(TimeOff timeOf);
void getUpdateTimeOff(TimeOff timeOf);
void getDeleteTimeOff(std::string id);
TimeOff getSelectTimeOff(std::string id);

//end MOHAMAD.

#endif // INBTW_H_INCLUDED
