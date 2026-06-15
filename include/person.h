#ifndef PERSON_H
#define PERSON_H
#include <String>
using namespace std ;
class Person
{
protected:
    string firstName;
    string lastName;
    string registrationNumber;

public:
    Person(string fn,
           string ln,
           string reg);

    string getFirstName() const;
    string getLastName() const;
    string getRegistrationNumber() const;

    virtual string getRole() const = 0;

};

#endif // PERSON_H
