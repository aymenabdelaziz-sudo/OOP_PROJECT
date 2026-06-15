#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"
#include "staff.h"
class Student : public Person
{
private:
    bool breakfastReserved;
    bool lunchReserved;
    bool dinnerReserved;


public :
    static int NumOfBreakRes ;
    static int NumOfLunchRes ;
    static int NumOfDinnerRes ;


    Student(string fn,
            string ln,
            string reg);

    void reserveBreakfast();
    void reserveLunch();
    void reserveDinner();

    void unreserveBreakfast();
    void unreserveLunch();
    void unreserveDinner();

    void Report(Staff&,string)const ;

    string getRole() const override;
};

#endif 
