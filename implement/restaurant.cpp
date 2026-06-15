#include "restaurant.h"

// Constructor implementation
Restaurant::Restaurant(string b, string l, string d)
    : breakfast(b), Lunch(l), Dinner(d)
{

}

// Getter for breakfast
string Restaurant::getbreakfast() const {
    return breakfast;
}

// Getter for lunch
string Restaurant::getLunch() const {
    return Lunch;
}

// Getter for dinner
string Restaurant::getDinner() const {
    return Dinner;
}
