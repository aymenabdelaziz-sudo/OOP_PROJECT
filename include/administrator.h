#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "person.h"
#include "student.h"
#include "staff.h"
#include "dorm.h"

class Administrator : public Person
{
private:
    
    static int studentCount;
    static int staffCount;
    static int studentInDormCount ;

public:
    Administrator(string fn="",
                  string ln="",
                  string reg="");

    ~Administrator() ;              

    

    bool addStudentToDorm(const string& ID , int RoomNum) ;

    bool RemStudent(const string& ID) ;

    bool RemStaff(const string& ID ) ;

    bool RemStudentFromDorm(const string& ID) ;


    void assignmission(Staff&,string) ;

    string getRole() const override;
};


#endif 
