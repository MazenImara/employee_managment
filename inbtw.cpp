#include <string>
#include <database.h>
using namespace std;

// gab
void SetAdmin(string employeeId){
    Database db;
    db.setAdmin(employeeId);
    db.close();
}
bool IsAdmin(string employeeId){
    Database db;
    bool is = db.isAdmin(employeeId);
    return is;
}
// end gab
