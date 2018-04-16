#ifndef INBTW_H_INCLUDED
#define INBTW_H_INCLUDED


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



#endif // INBTW_H_INCLUDED
