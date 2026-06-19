#include "administrator.h"
#include "FileManagement.h"
#include <iostream>
#include <stdexcept>
using namespace std ;

int Administrator::studentCount=0 ;
int Administrator::staffCount=0 ;
int Administrator::studentInDormCount=0 ;
Administrator::Administrator(string fn,
                             string ln,
                             string reg)
    : Person(fn,ln,reg)
{

}



bool Administrator::addStudentToDorm(const string& ID,int RoomNum){
   bool success =
        FileManagement::AssignStudentToRoom(ID, RoomNum);

    if(success)
        studentInDormCount++;

    return success;
}




bool Administrator::RemStudent(const string& ID)
{
    bool success =
        FileManagement::RemoveStudent(ID) ;

    if(success)
        studentCount--;

    return success;
}


bool Administrator::RemStaff(const string& ID)
{
    bool success =
        FileManagement::RemoveStaff(ID) ;

    if(success)
        studentInDormCount--;

    return success;

    
}


bool Administrator::RemStudentFromDorm(const string& ID)
{
    bool success =
        FileManagement::RemoveStudentFromRoom(ID) ;

    if(success)
        studentInDormCount--;

    return success;
}


void assignmission(Staff& s,string m){
    s.AddMission(m) ;
}

string Administrator::getRole() const
{
    return "Administrator";
}
