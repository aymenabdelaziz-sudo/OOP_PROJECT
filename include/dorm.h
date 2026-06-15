#ifndef DORM_H
#define DORM_H


#include "student.h"


class Dorm
{
private:
    string Roomid ;
    Student* student ;
public:
    Dorm(string,Student*);
    string getRoomId()const ;
    Student getStudent()const ;
};

#endif 
