#include <iostream>
#include <fstream>
#include <sstream>
#include "System.h"
#include "administrator.h" 
#include "staff.h"
#include "student.h"
#include "restaurant.h"
#include "dorm.h"
#include "FileManagement.h"

using namespace std ;



bool FileManagement::AdministratorExists(const string& reg)
{
    ifstream file("data/administrator.csv");

    if (!file.is_open())
        return false;

    string line;

    getline(file, line); // skip header

    while (getline(file, line))
    {
        stringstream ss(line);

        string fn, ln, id;

        getline(ss, fn, ',');
        getline(ss, ln, ',');
        getline(ss, id, ',');

        if (id == reg)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

void FileManagement::SaveAdministrator(const Administrator& admin){
         ofstream file("data/administrator.csv", ios::app); // ios::app is used to append data

    file << admin.getFirstName() << ","
         << admin.getLastName() << ","
         << admin.getRegistrationID() << "\n";

    file.close();

}