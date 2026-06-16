#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "person.h"
#include "student.h"
#include "staff.h"
#include "dorm.h"

class Administrator : public Person
{
private:
    static Student* students[1000];
    static Staff* staffs[100];
    static Dorm* Rooms[1000] ;
    static int studentCount;
    static int staffCount;
    static int studentInDormCount ;

public:
    Administrator(string fn,
                  string ln,
                  string reg);

    ~Administrator() ;              

    void addStudent(string fn,string ln,string ID);

    void addStaff(string fn,string ln,string ID);

    void addStudentToDorm(string ID) ;

    void RemStudent(string ID) ;

    void RemStaff(string ID ) ;

    void RemStudentFromDorm(string ID) ;


    void assignmission(Staff&,string) ;

    string getRole() const override;
};


#endif 
