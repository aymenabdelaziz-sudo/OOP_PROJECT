#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"
#include "staff.h"
class Student : public Person
{
private:
    bool breakfastReserved=false;
    bool lunchReserved=false;
    bool dinnerReserved=false;


public :
 


    Student(string fn="",
            string ln="",
            string reg="");

    void reserveBreakfast();
    void reserveLunch();
    void reserveDinner();

    void unreserveBreakfast();
    void unreserveLunch();
    void unreserveDinner();

    bool getBreakfast()const ;
    bool getLunch()const ;
    bool getDinner()const ;

 

    string getRole() const override;
};

#endif 
