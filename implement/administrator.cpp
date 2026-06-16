#include "administrator.h"
#include <iostream>
#include <stdexcept>
using namespace std ;
Student* Administrator::students[1000] = { nullptr };
Staff* Administrator::staffs[100] = { nullptr };
Dorm* Administrator::Rooms[1000] = { nullptr };
int Administrator::studentCount=0 ;
int Administrator::staffCount=0 ;
int Administrator::studentInDormCount=0 ;
Administrator::Administrator(string fn,
                             string ln,
                             string reg)
    : Person(fn,ln,reg)
{

}

Administrator::~Administrator(){
         for(int i=0;i<studentCount;i++){
            delete students[i] ;
         } 
        
         for(int i=0;i<staffCount;i++){
            delete staffs[i] ;
         }

         for(int i=0;i<studentInDormCount;i++){
            delete Rooms[i] ;
         }
}
void Administrator::addStudent(string fn,string ln,string ID)
{
    if(studentCount<1000){
        students[studentCount++] = new Student(fn,ln,ID);
    }else{
        throw out_of_range("student list is full. ") ;
    }
}

void Administrator::addStaff(string fn,string ln,string ID)
{
    if(staffCount<1000){
        staffs[staffCount++] = new Staff( fn, ln, ID);
    }else{
        throw out_of_range("staff list is full. ") ;
    }
}

void Administrator::addStudentToDorm(string ID){
    if(studentInDormCount<1000){
        bool found=false ;
       
        for(int i=0;i<studentCount;i++){
           if(students[i]->getRegistrationID()==ID){
                found=true ;
                Student* tmp = students[i] ;
                 Rooms[studentInDormCount++] = new Dorm(ID,tmp);
                break ;
           }
        }
        if(!found){
            throw invalid_argument("Student not found") ;
        }
       
       
    }else{
        throw out_of_range("Dorm list is full. ") ;
    }
}




void Administrator::RemStudent(string ID)
{
    int pos = -1;

    for(int i = 0; i < studentCount; i++)
    {
        if(students[i]->getRegistrationID()
            == ID)
        {
            pos = i;
            break;
        }
    }

    if(pos == -1)
    {
        throw std::invalid_argument("Student not found.");
    }

    for(int i = pos; i < studentCount - 1; i++)
    {
        students[i] = students[i + 1];
    }
    delete students[studentCount - 1] ;
    students[studentCount - 1] = nullptr;
    studentCount--;
}


void Administrator::RemStaff(string ID)
{
    int pos = -1;

    for(int i = 0; i < staffCount; i++)
    {
        if(staffs[i]->getRegistrationID()
            == ID)
        {
            pos = i;
            break;
        }
    }

    if(pos == -1)
    {
        throw std::invalid_argument("Staff member not found.");
    }

    for(int i = pos; i < staffCount - 1; i++)
    {
        staffs[i] = staffs[i + 1];
    }
    delete staffs[staffCount - 1] ;
    staffs[staffCount - 1] = nullptr;
    staffCount--;
}


void Administrator::RemStudentFromDorm(string ID)
{
    int pos = -1;

    for(int i = 0; i < studentInDormCount; i++)
    {
        if(Rooms[i]->getStudent().getRegistrationID()
            == ID)
        {
            pos = i;
            break;
        }
    }

    if(pos == -1)
    {
        throw std::invalid_argument(
            "Student is not assigned to a dorm."
            );
    }

    delete Rooms[pos];

    for(int i = pos; i < studentInDormCount - 1; i++)
    {
        Rooms[i] = Rooms[i + 1];
    }
    delete Rooms[studentInDormCount - 1] ;
    Rooms[studentInDormCount - 1] = nullptr;
    studentInDormCount--;
}


void assignmission(Staff& s,string m){
    s.setMission(m) ;
}

string Administrator::getRole() const
{
    return "Administrator";
}
