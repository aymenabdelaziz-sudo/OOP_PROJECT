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

    bool getBreakfast()const ;
    bool getLunch()const ;
    bool getDinner()const ;

    void Report(Staff&,string)const ;

    string getRole() const override;
};

#endif 
