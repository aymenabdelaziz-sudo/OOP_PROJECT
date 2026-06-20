#include "student.h"
#include "staff.h"

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
       breakfastReserved = true ;
     

}

void Student::reserveLunch()
{
        lunchReserved = true ;


}

void Student::reserveDinner()
{
   
        dinnerReserved = true ;


}

void Student::unreserveBreakfast()
{
   
        breakfastReserved = false ;
       

}

void Student::unreserveLunch()
{
  
        dinnerReserved = false ;
        
}

void Student::unreserveDinner()
{
 
        dinnerReserved = false ;
        
    

}



string Student::getRole() const
{
    return "Student";
}


string Student::getDinner()const{
    if(dinnerReserved){
    return "Reserved" ;
    }else{
        return "Unreserved" ;
    }
}

string Student::getLunch()const{
    if(lunchReserved){
        return "Reserved" ;
    }else{
        return "Unreserved" ;
    }
}

string Student::getBreakfast()const{
       if(dinnerReserved){
        return "Reserved" ;
    }else{
        return "Unreserved" ;
    }
}