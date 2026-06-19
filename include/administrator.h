#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "person.h"
#include "student.h"
#include "staff.h"
#include "dorm.h"

class Administrator : public Person
{

    


public:
    
    Administrator(string fn="",
                  string ln="",
                  string reg="");

              

    

    bool addStudentToDorm(const string& ID , int RoomNum) ;

    bool RemStudent(const string& ID) ;

    bool RemStaff(const string& ID ) ;

    bool RemStudentFromDorm(const string& ID) ;


   

    string getRole() const override;
};


#endif 
