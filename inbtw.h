#ifndef INBTW_H_INCLUDED
#define INBTW_H_INCLUDED

//all updated by ikram
// gab
void SetAdmin(std::string employeeId);
bool IsAdmin(std::string employeeId);
void createDatabase();

//Task ONLY
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

//Project ONLY
void inbtwShowAllProjects();
void inbtwInsertProject();
void inbtwDeleteProject(std::string id);
void inbtwUpdateProject();
long stringToLong(std::string str);
long longToString(std::string str);
//project end
// end gab



#endif // INBTW_H_INCLUDED
