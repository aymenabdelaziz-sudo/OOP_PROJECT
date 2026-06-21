#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <string>
#include "administrator.h"
#include <string>
#include <iostream>
using namespace std ;
class Restaurant
{
    
public :
    vector<string> BreakFast ;
    vector<string> Lunch ;
    vector<string> Dinner ;
    string Date ;

    Restaurant(vector<string>,vector<string>,vector<string>,string);
    Restaurant(){} ;
    void SetMeals() ; 
   
};

#endif 
