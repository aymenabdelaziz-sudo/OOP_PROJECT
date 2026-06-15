#include "person.h"



Person::Person(string fn,string ln,string reg):firstName(fn),lastName(ln),registrationNumber(reg){}



string Person::getFirstName() const
{
    return firstName;
}

string Person::getLastName() const
{
    return lastName;
}

string Person::getRegistrationNumber() const
{
    return registrationNumber;
}
