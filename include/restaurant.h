#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <string>
#include "administrator.h"
#include <string>
using namespace std ;
class Restaurant
{
    friend class Administrator ;
private :
    string breakfast ;
    string Lunch ;
    string Dinner ;
public:
    Restaurant(string,string,string);
    string getbreakfast()const ;
     string getLunch()const ;
    string getDinner()const ;

};

#endif // RESTAURANT_H
