#ifndef INBTW_H_INCLUDED
#define INBTW_H_INCLUDED


// gab
void SetAdmin(std::string employeeId);
bool IsAdmin(std::string employeeId);
void SetEmployeTask();
void createDatabase();

//Task ONLY
void getTask(std::string taskId);
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



#endif // INBTW_H_INCLUDED
