#include "dorm.h"

Dorm::Dorm(string id,Student* s):Roomid(id),student(s) {

}

string Dorm::getRoomId()const{
    return Roomid ;
}

Student Dorm::getStudent()const{
    return *student ;
}