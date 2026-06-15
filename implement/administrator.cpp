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
         delete [] students ;
         delete [] staffs ;
         delete [] Rooms ;
}
void Administrator::addStudent(Student *s)
{
    if(studentCount<1000){
        students[studentCount++] = s;
    }else{
        throw out_of_range("student list is full. ") ;
    }
}

void Administrator::addStaff(Staff *s)
{
    if(staffCount<1000){
        staffs[staffCount++] = s;
    }else{
        throw out_of_range("staff list is full. ") ;
    }
}

void Administrator::addStudentToDorm(Student* s){
    if(studentInDormCount<1000){
        string stdID;
        cout << "enter the id room number of student with registration number (" << s->getRegistrationNumber() << ") : ";
        getline(cin, stdID);
        Rooms[studentInDormCount++] = new Dorm(stdID,s);
    }else{
        throw out_of_range("Dorm list is full. ") ;
    }
}




void Administrator::RemStudent(Student *s)
{
    int pos = -1;

    for(int i = 0; i < studentCount; i++)
    {
        if(students[i]->getRegistrationNumber()
            == s->getRegistrationNumber())
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

    students[studentCount - 1] = nullptr;
    studentCount--;
}


void Administrator::RemStaff(Staff *s)
{
    int pos = -1;

    for(int i = 0; i < staffCount; i++)
    {
        if(staffs[i]->getRegistrationNumber()
            == s->getRegistrationNumber())
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

    staffs[staffCount - 1] = nullptr;
    staffCount--;
}


void Administrator::RemStudentFromDorm(Student *s)
{
    int pos = -1;

    for(int i = 0; i < studentInDormCount; i++)
    {
        if(Rooms[i]->getStudent().getRegistrationNumber()
            == s->getRegistrationNumber())
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
