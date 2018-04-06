#include <sstream>
#include <iostream>


using namespace std;

 string longToString(long  number){
     std::stringstream ss;
     ss << number;
     return ss.str();
}
 long stringToLong(string str){
    // return atol(str.c_str());
}
