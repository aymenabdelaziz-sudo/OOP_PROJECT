#ifndef PERSON_H
#define PERSON_H
#include <String>
using namespace std ;
class Person
{
protected:
    string firstName;
    string lastName;
    string registrationID;

public:
    Person(string fn,
           string ln,
           string reg);
    virtual ~Person() = default ;
    string getFirstName() const;
    string getLastName() const;
    string getRegistrationID() const;

    virtual string getRole() const = 0;

};

#endif 
