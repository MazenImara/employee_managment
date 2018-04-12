#ifndef INBTW_H_INCLUDED
#define INBTW_H_INCLUDED


// gab
void SetAdmin(std::string employeeId);
bool IsAdmin(std::string employeeId);
void GetTask(std::string taskId);
void SetEmployeTask();
void createDatabase();
// end gab

//Ikram
void pauseTask(std::string id);
void endTask(std::string id);
void startTask(std::string id);
//end Ikram


#endif // INBTW_H_INCLUDED
