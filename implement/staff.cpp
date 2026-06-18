#include "staff.h"

#include <stdexcept>
#include <iostream>

Staff::Staff(string fn,
             string ln,
             string reg)
    : Person(fn,ln,reg)
{
}

void Staff::AddMission(string m)
{
    To_Do.push_back(m);
}

void Staff::printMissions()const
{


        for(int i = 0; i < int(To_Do.size()); i++)
        {
          cout <<"i+1"<<"- " << To_Do[i] <<endl ;   
        }


}

vector<string> Staff::getTo_Do()const{
      return To_Do ;
}

string Staff::getRole() const
{
    return "Staff";
}

void Staff::Done(int i)
{
    if(i >= 1 && i < int(To_Do.size()+1)){
        To_Do.erase(To_Do.begin()+i-1); ;
    }else{
        throw out_of_range("invalid mission number ") ;
    }
}