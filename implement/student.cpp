#include "student.h"
#include "staff.h"
int Student::NumOfBreakRes=0 ;
int Student::NumOfLunchRes=0 ;
int Student::NumOfDinnerRes=0 ;
Student::Student(string fn,
                 string ln,
                 string reg)
    : Person(fn,ln,reg)
{
    breakfastReserved = false;
    lunchReserved = false;
    dinnerReserved = false;
}

void Student::reserveBreakfast()
{
    if(breakfastReserved){
    return;
    }else{
        breakfastReserved = true ;
        NumOfBreakRes++ ;
    }

}

void Student::reserveLunch()
{
    if(lunchReserved){
        return;
    }else{
        lunchReserved = true ;
        NumOfLunchRes++ ;
    }

}

void Student::reserveDinner()
{
    if(dinnerReserved){
        return;
    }else{
        dinnerReserved = true ;
        NumOfDinnerRes++ ;
    }

}

void Student::unreserveBreakfast()
{
    if(!breakfastReserved){
        return;
    }else{
        breakfastReserved = false ;
        NumOfBreakRes-- ;
    }

}

void Student::unreserveLunch()
{
    if(!dinnerReserved){
        return;
    }else{
        dinnerReserved = false ;
        NumOfDinnerRes-- ;
    }
}

void Student::unreserveDinner()
{
    if(!dinnerReserved){
        return;
    }else{
        dinnerReserved = false ;
        NumOfDinnerRes-- ;
    }

}

void report(Staff& s,string m){
    s.setMission(m) ;
}

string Student::getRole() const
{
    return "Student";
}
