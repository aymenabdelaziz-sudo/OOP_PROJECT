#include "person.h"



Person::Person(string fn,string ln,string reg):firstName(fn),lastName(ln),registrationID(reg){}



string Person::getFirstName() const
{
    return firstName;
}

string Person::getLastName() const
{
    return lastName;
}

string Person::getRegistrationID() const
{
    return registrationID;
}
