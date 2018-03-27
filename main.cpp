
#include <iostream>
#include <string>
#include <database.h>
#include <employee.h>

using namespace std;


int main()
{
    Employee e;
    e.enterLogin();
   Database db;
   e=db.getLoginEmployee(e);
   e.show();
    return 0;
}
