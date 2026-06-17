#ifndef STAFF_H
#define STAFF_H

#include "person.h"
#include <Vector>
using namespace std ;
class Staff : public Person
{
private:
    vector<string> To_Do;


public:
    Staff(string fn,
          string ln,
          string reg);

    void setMission(string m);

    void printMissions()const  ;

    string getRole() const override;

    vector<string> getTo_Do()const ;

    void Done(int i) ;
};



#endif 
