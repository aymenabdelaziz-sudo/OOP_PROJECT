#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include "System.h"
#include "administrator.h" 
#include "staff.h"
#include "student.h"
#include "restaurant.h"
#include "dorm.h"
#include "FileManagement.h"

using namespace std ;
#define BLUE  "\033[34m"
#define WHITE "\033[97m"
#define RESET "\033[0m"



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

void FileManagement::DisplayAllStaff()
{
    ifstream file("data/staff.csv");

    if (!file.is_open())
    {
        cout << "Unable to open staff.csv\n";
        return;
    }

    string line;

    // Skip header
    getline(file, line);
    cout << BLUE ;
    cout << "\n============== " ;
    cout<<WHITE<<"STAFF LIST"<< BLUE<<"==============\n\n";

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

        cout << "First Name      : " << fn << '\n';
        cout << "Last Name       : " << ln << '\n';
        cout << "Registration ID : " << reg << '\n';

        cout << "Missions        : ";

        stringstream missionStream(missions);
        string mission;

        bool first = true;

        while (getline(missionStream, mission, '|'))
        {
            if (!first)
                cout << ", ";

            cout << mission;
            first = false;
        }

        cout << "\n\n";
    }

    file.close();
}

bool FileManagement::AddMissionToStaff(const string& regID,
                                       const string& newMission)
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

        string fn, ln, reg, missions;

        getline(ss, fn, ',');
        getline(ss, ln, ',');
        getline(ss, reg, ',');
        getline(ss, missions);

        if (reg == regID)
        {
            found = true;

            if (missions.empty())
                missions = newMission;
            else
                missions += "|" + newMission;

            line = fn + "," +
                   ln + "," +
                   reg + "," +
                   missions;
        }

        lines.push_back(line);
    }

    in.close();

    if (!found)
    {
        cout << "Staff member not found.\n";
        return false;
    }

    ofstream out("data/staff.csv");

    if (!out.is_open())
        return false;

    for (const string& l : lines)
        out << l << '\n';

    out.close();

    return true;
}

void FileManagement::DisplayAllStudents()
{
    ifstream file("data/students.csv");

    if (!file.is_open())
    {
        cout << "Unable to open students.csv\n";
        return;
    }

    string line;

    // Skip header
    getline(file, line);

    cout << "\n========== STUDENTS LIST ==========\n\n";

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

        cout << "  First Name      : " << fn << '\n';
        cout << "  Last Name       : " << ln << '\n';
        cout << "  Registration ID : " << reg << '\n';
        cout << "  Breakfast       : " << breakfast << '\n';
        cout << "  Lunch           : " << lunch << '\n';
        cout << "  Dinner          : " << dinner << '\n';

        cout << "\n\n";
    }

    file.close();
}

bool FileManagement::SaveRestaurant(const Restaurant& R)
{
    ofstream file("data/restaurant.csv", ios::app);

    if(!file.is_open())
        return false;

    file << R.Date << ",";

    for(size_t i=0;i<R.BreakFast.size();i++)
    {
        file << R.BreakFast[i];

        if(i != R.BreakFast.size()-1)
            file << "|";
    }

    file << ",";

    for(size_t i=0;i<R.Lunch.size();i++)
    {
        file << R.Lunch[i];

        if(i != R.Lunch.size()-1)
            file << "|";
    }

    file << ",";

    for(size_t i=0;i<R.Dinner.size();i++)
    {
        file << R.Dinner[i];

        if(i != R.Dinner.size()-1)
            file << "|";
    }

    file << '\n';

    file.close();

    return true;
}

void FileManagement::DisplayMealsByDate(const string& date)
{
    ifstream file("data/restaurant.csv");

    if(!file.is_open())
        return;

    string line;

    getline(file,line); // header

    while(getline(file,line))
    {
        stringstream ss(line);

        string fileDate;
        string breakfast;
        string lunch;
        string dinner;

        getline(ss,fileDate,',');
        getline(ss,breakfast,',');
        getline(ss,lunch,',');
        getline(ss,dinner);

        if(fileDate == date)
        {
            cout << "\nDate: " << fileDate << "\n";

            cout << "\nBreakfast:\n";
            string item;
            stringstream bss(breakfast);

            while(getline(bss,item,'|'))
                cout << "- " << item << '\n';

            cout << "\nLunch:\n";
            stringstream lss(lunch);

            while(getline(lss,item,'|'))
                cout << "- " << item << '\n';

            cout << "\nDinner:\n";
            stringstream dss(dinner);

            while(getline(dss,item,'|'))
                cout << "- " << item << '\n';

            file.close();
            return;
        }
    }

    cout << "  No menu found for this date.\n";

    file.close();
}



bool FileManagement::SortAndRemoveDuplicateMenus()
{
    ifstream in("data/restaurant.csv");

    if(!in.is_open())
        return false;

    string header;
    getline(in, header);

    vector<string> lines;
    string line;

    while(getline(in, line))
        lines.push_back(line);

    in.close();

    vector<string> uniqueLines;

    for(size_t i = 0; i < lines.size(); i++)
    {
        stringstream ss1(lines[i]);

        string date1;
        getline(ss1, date1, ',');

        bool duplicateFoundLater = false;

        for(size_t j = i + 1; j < lines.size(); j++)
        {
            stringstream ss2(lines[j]);

            string date2;
            getline(ss2, date2, ',');

            if(date1 == date2)
            {
                duplicateFoundLater = true;
                break;
            }
        }

        if(!duplicateFoundLater)
            uniqueLines.push_back(lines[i]);
    }

    sort(uniqueLines.begin(),
         uniqueLines.end(),
         [](const string& a, const string& b)
         {
             stringstream sa(a);
             stringstream sb(b);

             string dateA;
             string dateB;

             getline(sa, dateA, ',');
             getline(sb, dateB, ',');

             return dateA < dateB;
         });

    ofstream out("data/restaurant.csv");

    if(!out.is_open())
        return false;

    out << header << '\n';

    for(const string& l : uniqueLines)
        out << l << '\n';

    out.close();

    return true;
}