#include "administrator.h"
#include "FileManagement.h"
#include <iostream>
#include <stdexcept>
using namespace std ;


Administrator::Administrator(string fn,
                             string ln,
                             string reg)
    : Person(fn,ln,reg)
{

}



bool Administrator::addStudentToDorm(const string& ID,int RoomNum){
   bool success =
        FileManagement::AssignStudentToRoom(ID, RoomNum);


    return success;
}




bool Administrator::RemStudent(const string& ID)
{
    bool success =
        FileManagement::RemoveStudent(ID) ;

   

    return success;
}


bool Administrator::RemStaff(const string& ID)
{
    bool success =
        FileManagement::RemoveStaff(ID) ;

   

    return success;

    
}


bool Administrator::RemStudentFromDorm(const string& ID)
{
    bool success =
        FileManagement::RemoveStudentFromRoom(ID) ;

   

    return success;
}




string Administrator::getRole() const
{
    return "Administrator";
}
