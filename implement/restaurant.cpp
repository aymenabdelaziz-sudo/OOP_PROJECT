#include "restaurant.h"

// Constructor implementation
Restaurant::Restaurant(vector<string> b, vector<string> l, vector<string> d , string date)
    : BreakFast(b), Lunch(l), Dinner(d) ,Date(date)
{

}

// Getter for breakfast
void Restaurant::SetMeals()
{
    BreakFast.clear();
    Lunch.clear();
    Dinner.clear();
    
    cout << "  Enter date (YYYY-MM-DD): ";
    cin >> Date;

    int n;
    string item;

    // Breakfast
    cout << endl ;
    cout << "  Number of breakfast items: ";
    cin >> n;

    cin.ignore();

    for(int i = 0; i < n; i++)
    {
        cout << "  Breakfast item " << i + 1 << ": ";
        getline(cin, item);

        BreakFast.push_back(item);
    }

    // Lunch
    cout << endl ;
    cout << "  Number of lunch items: ";
    cin >> n;

    cin.ignore();

    for(int i = 0; i < n; i++)
    {
        cout << "  Lunch item " << i + 1 << ": ";
        getline(cin, item);

        Lunch.push_back(item);
    }

    // Dinner
    cout << endl ;
    cout << "  Number of dinner items: ";
    cin >> n;

    cin.ignore();

    for(int i = 0; i < n; i++)
    {
        cout << "  Dinner item " << i + 1 << ": ";
        getline(cin, item);

        Dinner.push_back(item);
    }
}