#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdio>
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

bool FileManagement::StaffExists(const string& regID){
    

    ifstream file("data/staff.csv");

    if (!file.is_open())
        return false;

    string line;

    // Skip header
    getline(file, line);

    while (getline(file, line))
    {
        stringstream ss(line);

        string fn;
        string ln;
        string reg;
        string missions;

        getline(ss, fn, ',');
        getline(ss, ln, ',');
        getline(ss, reg, ',');
        getline(ss, missions);

        if (reg == regID)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;


}

void FileManagement::SaveStaff(const Staff& S){




    ofstream file("data/staff.csv", ios::app);

    

    file << S.getFirstName() << ","
         << S.getLastName() << ","
         << S.getRegistrationID() << ",";

    vector<string> missions = S.getTo_Do();

    for (size_t i = 0; i < missions.size(); i++)
    {
        file << missions[i];

        if (i != missions.size() - 1)
            file << "|";
    }

    file << '\n';

    file.close();




}

bool FileManagement::StudentExists(const string& regID)
{
    ifstream file("data/students.csv");

    if (!file.is_open())
        return false;

    string line;

    getline(file, line); 

    while (getline(file, line))
    {
        stringstream ss(line);

        string fn;
        string ln;
        string reg;
        string breakfast;
        string lunch;
        string dinner;

        getline(ss, fn, ',');
        getline(ss, ln, ',');
        getline(ss, reg, ',');
        getline(ss, breakfast, ',');
        getline(ss, lunch, ',');
        getline(ss, dinner);

        if (reg == regID)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

void FileManagement::SaveStudent(const Student& S)
{
    ofstream file("data/students.csv", ios::app);


    file << S.getFirstName() << ","
         << S.getLastName() << ","
         << S.getRegistrationID() << ","
         << (S.getBreakfast() ? "Reserved" : "Not Reserved") << ","
         << (S.getLunch() ? "Reserved" : "Not Reserved") << ","
         << (S.getDinner() ? "Reserved" : "Not Reserved")
         << '\n';

    file.close();
}


#include <fstream>
#include <sstream>

Administrator FileManagement::GetAdministratorByID(const string& regID)
{
    ifstream file("data/administrator.csv");

    string line;

    getline(file, line); 

    while (getline(file, line))
    {
        stringstream ss(line);

        string fn;
        string ln;
        string reg;

        getline(ss, fn, ',');
        getline(ss, ln, ',');
        getline(ss, reg);

        if (reg == regID)
        {
            file.close();
            return Administrator(fn, ln, reg);
        }
    }

    

    return Administrator();  //this case will never be reached since the Administrator with the ID in the argument exist in administrator.csv so it is just to avoid the warning from the compiler


}

Staff FileManagement::GetStaffByID(const string& regID)
{
    ifstream file("data/staff.csv");

    string line;
    getline(file, line); 

    while(getline(file, line))
    {
        stringstream ss(line);

        string fn;
        string ln;
        string reg;
        string missionsField;

        getline(ss, fn, ',');
        getline(ss, ln, ',');
        getline(ss, reg, ',');
        getline(ss, missionsField);

        if(reg == regID)
        {
            Staff S(fn, ln, reg);

            stringstream missionStream(missionsField);
            string mission;

            while(getline(missionStream, mission, '|'))
            {
                S.AddMission(mission);
            }

            return S;
        }
    }

    return Staff();
}

Student FileManagement::GetStudentByID(const string& regID)
{
    ifstream file("data/student.csv");

    string line;
    getline(file, line); 

    while(getline(file, line))
    {
        stringstream ss(line);

        string fn;
        string ln;
        string reg;
        string breakfast;
        string lunch;
        string dinner;

        getline(ss, fn, ',');
        getline(ss, ln, ',');
        getline(ss, reg, ',');
        getline(ss, breakfast, ',');
        getline(ss, lunch, ',');
        getline(ss, dinner);

        if(reg == regID)
        {
            Student S(fn, ln, reg);

           if(breakfast=="Reserved"){
            S.reserveBreakfast() ;
           }

           if(lunch == "Reserved"){
            S.reserveLunch() ;
           }

           if(dinner == "Reserved"){
            S.reserveDinner() ;
           }
            return S;
        }
    }

    return Student();
}



bool FileManagement::AssignStudentToRoom(const string& studentID,
                                         int roomNumber)
{
    if (!FileManagement::StudentExists(studentID))
{
    cout << "  Student does not exist.\n";
    return false;
}

    ifstream in("data/dorm.csv");

    if (!in.is_open())
        return false;

    vector<string> lines;
    string line;

    // Copy header
    getline(in, line);
    lines.push_back(line);

    bool studentAlreadyAssigned = false;
    bool roomFound = false;
    bool roomEmpty = false;

    while (getline(in, line))
    {
        stringstream ss(line);

        string id;
        string room;

        getline(ss, id, ',');
        getline(ss, room);

        // Check if student already has a room
        if (id == studentID)
            studentAlreadyAssigned = true;

        // Check target room
        if (stoi(room) == roomNumber) //stoi used to convert from string to int
        {
            roomFound = true;

            if (id.empty())
            {
                roomEmpty = true;
                line = studentID + "," + room;
            }
        }

        lines.push_back(line);
    }

    in.close();

    if (studentAlreadyAssigned)
    {
        cout << "  Student already has a room.\n";
        return false;
    }

    if (!roomFound)
    {
        cout << "  Room does not exist.\n";
        return false;
    }

    if (!roomEmpty)
    {
        cout << "  Room is already occupied.\n";
        return false;
    }

    ofstream out("data/dorm.csv");

    for (const string& l : lines)
        out << l << '\n';

    out.close();

    return true;
}

bool FileManagement::RemoveStudentFromRoom(const string& studentID)
{
    ifstream in("data/dorm.csv");

    if (!in.is_open())
        return false;

    vector<string> lines;
    string line;

    // Save header
    getline(in, line);
    lines.push_back(line);

    bool found = false;

    while (getline(in, line))
    {
        stringstream ss(line);

        string id;
        string room;

        getline(ss, id, ',');
        getline(ss, room);

        if (id == studentID)
        {
            found = true;

            // Empty the StudentID field
            line = "," + room;
        }

        lines.push_back(line);
    }

    in.close();

    if (!found)
    {
        cout << "  Student does not have a room.\n";
        return false;
    }

    ofstream out("data/dorm.csv");

    if (!out.is_open())
        return false;

    for (const string& l : lines)
    {
        out << l << '\n';
    }

    out.close();

    return true;
}

bool FileManagement::RemoveStudent(const string& regID)
{
    ifstream in("data/student.csv");

    if (!in.is_open())
        return false;

    vector<string> lines;
    string line;

    // Save header
    getline(in, line);
    lines.push_back(line);

    bool found = false;

    while (getline(in, line))
    {
        stringstream ss(line);

        string fn;
        string ln;
        string reg;
        string breakfast;
        string lunch;
        string dinner;

        getline(ss, fn, ',');
        getline(ss, ln, ',');
        getline(ss, reg, ',');
        getline(ss, breakfast, ',');
        getline(ss, lunch, ',');
        getline(ss, dinner);

        if (reg == regID)
        {
            found = true;
            continue; // Skip this line
        }

        lines.push_back(line);
    }

    in.close();

    if (!found)
    {
        cout << "  Student not found.\n";
        return false;
    }

    ofstream out("data/student.csv");

    if (!out.is_open()) // this optional because some rare cases like full disk or the data folder does mot exist
        return false;

    for (const string& l : lines)
    {
        out << l << '\n';
    }

    out.close();

    return true;
}

bool FileManagement::RemoveStaff(const string& regID)
{
    ifstream in("data/staff.csv");

    if (!in.is_open())
        return false;

    vector<string> lines;
    string line;

    // Save header
    getline(in, line);
    lines.push_back(line);

    bool found = false;

    while (getline(in, line))
    {
        stringstream ss(line);

        string fn;
        string ln;
        string reg;
        string missions;

        getline(ss, fn, ',');
        getline(ss, ln, ',');
        getline(ss, reg, ',');
        getline(ss, missions);

        if (reg == regID)
        {
            found = true;
            continue; 
        }

        lines.push_back(line);
    }

    in.close();

    if (!found)
    {
        cout << "  Staff member not found.\n";
        return false;
    }

    ofstream out("data/staff.csv");

    if (!out.is_open())
        return false;

    for (const string& l : lines)
    {
        out << l << '\n';
    }

    out.close();

    return true;
}


    bool FileManagement::SaveStudentData(const Student& S)
{
    ifstream in("data/student.csv");

    if (!in.is_open())
        return false;

    vector<string> lines;
    string line;

    getline(in, line);
    lines.push_back(line);

    bool found = false;

    while (getline(in, line))
    {
        stringstream ss(line);

        string fn, ln, reg;

        getline(ss, fn, ',');
        getline(ss, ln, ',');
        getline(ss, reg, ',');

        if (reg == S.getRegistrationID())
        {
            found = true;

            line =
                S.getFirstName() + "," +
                S.getLastName() + "," +
                S.getRegistrationID() + "," +
                (S.getBreakfast() ? "Reserved" : "Not Reserved") + "," +
                (S.getLunch() ? "Reserved" : "Not Reserved") + "," +
                (S.getDinner() ? "Reserved" : "Not Reserved");
        }

        lines.push_back(line);
    }

    in.close();

    if (!found)
        return false;

    ofstream out("data/student.csv");

    for (const string& l : lines)
        out << l << '\n';

    out.close();

    return true;
}


bool FileManagement::SaveStaffData(const Staff& S)
{
    ifstream in("data/staff.csv");

    if (!in.is_open())
        return false;

    vector<string> lines;
    string line;

    getline(in, line);
    lines.push_back(line);

    bool found = false;

    while (getline(in, line))
    {
        stringstream ss(line);

        string fn, ln, reg, missions;

        getline(ss, fn, ',');
        getline(ss, ln, ',');
        getline(ss, reg, ',');
        getline(ss, missions);

        if (reg == S.getRegistrationID())
        {
            found = true;

            string newLine =
                S.getFirstName() + "," +
                S.getLastName() + "," +
                S.getRegistrationID() + ",";

            vector<string> todo = S.getTo_Do();

            for (size_t i = 0; i < todo.size(); i++)
            {
                newLine += todo[i];

                if (i != todo.size() - 1)
                    newLine += "|";
            }

            line = newLine;
        }

        lines.push_back(line);
    }

    in.close();

    if (!found)
        return false;

    ofstream out("data/staff.csv");

    for (const string& l : lines)
        out << l << '\n';

    out.close();

    return true;
}