#include <iostream>
#include <windows.h>
#include "System.h"
#include "administrator.h" 
#include "staff.h"
#include "student.h"
#include "restaurant.h"

#include "FileManagement.h"
// Colors
#define BLUE  "\033[34m"
#define WHITE "\033[97m"
#define RESET "\033[0m"

using namespace std ;


int System::run(){
    logoprinter() ;
    MainPage() ;
    
    
    return 0 ;
}



void System::logoprinter(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    
    SetConsoleTextAttribute(hConsole, 9);

    cout << R"(

__          ________ _      _____ ____  __  __ ______
\ \        / /  ____| |    / ____/ __ \|  \/  |  ____|
 \ \  /\  / /| |__  | |   | |   | |  | | \  / | |__
  \ \/  \/ / |  __| | |   | |   | |  | | |\/| |  __|
   \  /\  /  | |____| |___| |___| |__| | |  | | |____
    \/  \/   |______|______\_____\____/|_|  |_|______|

)";

    
    SetConsoleTextAttribute(hConsole, 15);

    cout << R"(

 _______ ____  
|__   __/ __ \
   | | | |  | |
   | | | |  | |
   | | | |__| |
   |_|  \____/

)";

    
    SetConsoleTextAttribute(hConsole, 9);

    cout << R"(

  _____ ____  __  __ ______ ____  _____ _______
 / ____/ __ \|  \/  |  ____/ __ \|  __ \__   __|
| |   | |  | | \  / | |__ | |  | | |__) | | |
| |   | |  | | |\/| |  __|| |  | |  _  /  | |
| |___| |__| | |  | | |   | |__| | | \ \  | |
 \_____\____/|_|  |_|_|    \____/|_|  \_\ |_|

)";

    SetConsoleTextAttribute(hConsole, 15);

    
}

void System::MainPage(){
    
    
    int choice ;


    while(true){
    cout << endl ;
    cout << BLUE;
    cout << "========================================\n";
    cout << "               COMFORT                  \n";
    cout << "========================================\n";

    cout << WHITE;
    cout << "  [1] Register\n";
    cout << "  [2] Login\n";
    cout << "  [3] Exit\n";

    cout << BLUE;
    cout << "========================================\n";
    


    

   

    cout << WHITE ;
    cout << "  Please select an option (1-3): ";
       if (!(cin >> choice))
{
    cout << "  Invalid input. Please enter a number (view the menu).\n";

    cin.clear(); // clear error state
    cin.ignore(10000, '\n'); // discard bad input

    continue;
}
    switch(choice){

    case 1:
    RegisterPage() ;
    break ;
    case 2:
    LoginPage() ;
    break ;
    case 3:
    cout << endl ;
    cout <<WHITE <<"  All your data are saved succefully \n"<<"  Exit ...." ;
    exit(0) ;
    break ;
  
    default:
    cout <<endl ;
    cout << "  Invalide choice (1-3) \n" ;
    break ;

    }
    }

}

void System::RegisterPage(){
       int choice ;


    while(true){
    cout << endl ;
    cout << BLUE;
    cout << "========================================\n";
    cout << "               COMFORT                  \n";
    cout << "========================================\n";

    cout << WHITE;
    cout << "  [1] Administrator\n";
    cout << "  [2] Staff\n";
    cout << "  [3] Student\n";
    cout << "  [4] Back\n" ;

    cout << BLUE;
    cout << "========================================\n";
    


    

   

    cout << WHITE ;
    cout << "  Back or Register as: ";
       if (!(cin >> choice))
{
    cout << "  Invalid input. Please enter a number (view the menu).\n";

    cin.clear(); 
    cin.ignore(10000, '\n'); 

    continue;
}
    switch(choice){

    case 1:
    RegisterAdministrator() ;
    break ;
    case 2:
    RegisterStaff() ;
    break ;
    case 3:
    RegisterStudent() ;
    break ;
  
    case 4:
    return ;
    break ;

    default:
    cout <<endl ;
    cout << "  Invalide choice (1-4) \n" ;
    break ;

    }
    }
}

void System::LoginPage(){

       int choice ;


    while(true){
    cout << endl ;
    cout << BLUE;
    cout << "========================================\n";
    cout << "               COMFORT                  \n";
    cout << "========================================\n";

    cout << WHITE;
    cout << "  [1] Administrator\n";
    cout << "  [2] Staff\n";
    cout << "  [3] Student\n";
    cout << "  [4] Back\n" ;

    cout << BLUE;
    cout << "========================================\n";
    


    

   

    cout << WHITE ;
    cout << "  Back or Login as: ";
    if (!(cin >> choice))
{
    cout << "  Invalid input. Please enter a number (view the menu).\n";

    cin.clear(); 
    cin.ignore(10000, '\n'); 

    continue;
}

    switch(choice){

    case 1:
    LoginAdministrator() ;
    break ;
    case 2:
    LoginStaff() ;
    break ;
    case 3:
    LoginStudent() ;
    break ;
  
    case 4:
    return ;
    break ;

    default:
    cout <<endl ;
    cout << "  Invalide choice (1-4) \n" ;
    break ;

    }
    }
}

void System::RegisterAdministrator(){
    
    string enteredpasswd,fn,ln,reg ;
    
    cout << endl ;
    cout << WHITE << "  Enter the Administrator password: "  ;
    cin.ignore() ;
    getline(cin,enteredpasswd) ;
    if(enteredpasswd != Administratorpasswd){
    cout << endl ;
    cout << "  Incorrect Password, Access denied\n " ;
    return ;
    }
    cout << BLUE<<"\n=======" ;
    cout << WHITE << "Regestering As Adminstrator" ;
    cout << BLUE << "======\n" ;
    cout << WHITE ;
    cout << endl ;
    cout << "  Enter your First Name: " ;
    getline(cin,fn) ;
    cout << endl ;
    cout << "  Enter your Last Name: " ;
    getline(cin,ln) ;
    cout << endl ;
    

while(true)
{
    cout << "  Enter a registration ID: ";
    getline(cin, reg);

    bool valid = false;

    for(char c : reg)
    {
        if(!isspace(c))
        {
            valid = true;
            break;
        }
    }

    if(valid)
        break;

    cout << "  registration ID cannot be empty.\n";
}

    if(FileManagement::AdministratorExists(reg))
{
    cout << "  Registration ID already exists.\n";
    return;
}

Administrator A(fn,ln,reg);

FileManagement::SaveAdministrator(A);

 
    
    AdministratorPage(A) ;


}

void System::LoginAdministrator(){
    string enteredpasswd,fn,ln,reg ;
    
    cout << endl ;
    cout << WHITE << "  Enter the Administrator password: "  ;
    cin.ignore() ;
    getline(cin,enteredpasswd) ;
    if(enteredpasswd != Administratorpasswd){
    cout << endl ;
    cout << "  Incorrect Password, Access denied\n " ;
    return ;
    }
    cout << BLUE<<"\n==========" ;
    cout << WHITE << "Login As Adminstrator" ;
    cout << BLUE << "=========\n" ;
    cout << WHITE ;
   cout << endl ;
    cout << "  Enter your registration ID: " ;
    getline(cin,reg) ;
   
        if(!FileManagement::AdministratorExists(reg))
{
    cout << "  Registration ID does not exists.\n";
    return;
}

    Administrator A = FileManagement::GetAdministratorByID(reg) ;

    AdministratorPage(A) ;
}

void System::RegisterStaff(){
    string fn,ln,reg ;  
    
    cout << endl ;
    cout << BLUE<<"\n=======" ;
    cout << WHITE << "Regestering As Staff" ;
    cout << BLUE << "======\n" ;
    cout << WHITE ;
    cin.ignore() ;
    cout << endl ;
    cout << "  Enter your First Name: " ;
    getline(cin,fn) ;
    cout << endl ;
    cout << "  Enter your Last Name: " ;
    getline(cin,ln) ;
    cout << endl ;
    
while(true)
{
    cout << "  Enter a registration ID: ";
    getline(cin, reg);

    bool valid = false;

    for(char c : reg)
    {
        if(!isspace(c))
        {
            valid = true;
            break;
        }
    }

    if(valid)
        break;

    cout << "  registration ID cannot be empty.\n";
}
      if(FileManagement::StaffExists(reg))
{
    cout << "  Registration ID already exists.\n";
    return;
}

Staff S(fn,ln,reg);

FileManagement::SaveStaff(S);

 
    
    StaffPage(S) ;
   
}

void System::LoginStaff(){
      
       string reg ;  
    
    cout << endl ;
    cout << BLUE<<"\n==========" ;
    cout << WHITE << "Login As Staff" ;
    cout << BLUE << "=========\n" ;
    cout << WHITE ;
    cin.ignore() ;
    cout << endl ;
    cout << "  Enter your registration ID: " ;
    getline(cin,reg) ;

      if(!FileManagement::StaffExists(reg))
{
    cout << "  Registration ID does not exists.\n";
    return;
}



    Staff S = FileManagement::GetStaffByID(reg) ;

 
    
    StaffPage(S) ;
   
     



}


void System::RegisterStudent(){
 string fn,ln,reg ;  
    
    cout << endl ;
    cout << BLUE<<"\n=======" ;
    cout << WHITE << "Regestering As Staff" ;
    cout << BLUE << "======\n" ;
    cout << WHITE ;
    cin.ignore() ;
    cout << endl ;
     cout << "  Enter your First Name: " ;
    getline(cin,fn) ;
    cout << endl ;
    cout << "  Enter your Last Name: " ;
    getline(cin,ln) ;
    cout << endl ;

while(true)
{
    cout << "  Enter a registration ID: ";
    getline(cin, reg);

    bool valid = false;

    for(char c : reg)
    {
        if(!isspace(c))
        {
            valid = true;
            break;
        }
    }

    if(valid)
        break;

    cout << "  registration ID cannot be empty.\n";
}

      if(FileManagement::StudentExists(reg))
{
    cout << "  Registration ID already exists.\n";
    return;
}

Student S(fn,ln,reg);

FileManagement::SaveStudent(S);

 
    
    StudentPage(S) ;

}

void System::LoginStudent(){

string reg ;  
    
    cout << endl ;
    cout << BLUE<<"\n==========" ;
    cout << WHITE << "Login As Student" ;
    cout << BLUE << "=========\n" ;
    cout << WHITE ;
    cin.ignore() ;
    cout << endl ;
    cout << "  Enter your registration ID: " ;
    getline(cin,reg) ;

      if(!FileManagement::StudentExists(reg))
{
    cout << "  Registration ID does not exists.\n";
    return;
}



    Student S = FileManagement::GetStudentByID(reg) ;

 
    
    StudentPage(S) ;
   
     





}

  void System::AdministratorPage(Administrator& A){
       int choice ;
       while(true){
       cout << endl ;
    cout << BLUE;
    cout << "========================================\n";
    cout << "               COMFORT                  \n";
    cout << "========================================\n";

    cout << WHITE;
    cout << "  [1] View my information \n" ;
    cout << "  [2] Staff Management\n";
    cout << "  [3] Studnet Management\n";
    cout << "  [4] Restaurant Management\n";
    cout << "  [5] Dorm Management\n" ;
    cout << "  [6] Logout\n" ;
    cout << "  [7] Exit\n" ;

    cout << BLUE;
    cout << "========================================\n";
    
    cout << WHITE ;
    cout << "  Enter your choice (1-7): " ;
       if (!(cin >> choice))
{
    cout << "  Invalid input. Please enter a number (view the menu).\n";

    cin.clear(); 
    cin.ignore(10000, '\n'); 

    continue;
}

    switch(choice){
    case 1:
    
    cout << BLUE;
    cout << "========================================\n";
    cout << WHITE ; 
    cout << "  You are an " << A.getRole() <<endl ;
    cout << "  First Name       : " << A.getFirstName() <<endl ;
    cout << "  Last Name        : " << A.getLastName() <<endl;
    cout << "  Registeration ID : " << A.getRegistrationID() << endl ;
    cout << BLUE;
    cout << "========================================\n";
    break ;

    case 2:
    StaffManagement(A) ;
    break ;
    case 3:
    StudentManagement(A) ;
    break ;
    case 4:
    RestaurantManagemnt(A) ;
    break ;
    case 5:
    DormMAnagement(A) ;
    break ;
    case 6:
    MainPage() ;
    break ;
  
    case 7:
    cout << WHITE ;
    cout <<"  All your data are saved successfully \n" ;
    cout <<"  Exit ...." ;
    exit(0) ;
    break ;

    default:
    cout <<endl ;
    cout << "  Invalide choice (1-7) \n" ;
    break ;

    }

       }

       

  } 

    void System::StaffManagement(Administrator A){
    int choice ;
    string ID , mission ;
    while(true){
              cout << endl ;
    cout << BLUE;
    cout << "========================================\n";
    cout << "               COMFORT                  \n";
    cout << "========================================\n";

    cout << WHITE;
    cout << "  [1] Display Staff Information \n" ;
    cout << "  [2] Remove Staff\n";
    cout << "  [3] Assign mission to a Staff\n";
    cout << "  [4] Back\n";
   

    cout << BLUE;
    cout << "========================================\n";
    
    cout << WHITE ;
    cout << "  Enter your choice (1-4): " ;
       if (!(cin >> choice))
{
    cout << "  Invalid input. Please enter a number (view the menu).\n";

    cin.clear(); 
    cin.ignore(10000, '\n'); 

    continue;
}

    switch(choice){
        case 1:
        FileManagement::DisplayAllStaff() ;
        break ;
        case 2:
       
        cout << WHITE ;
        cout << "  Entet the registeration ID of the staff you want to remove: " ;
        cin.ignore() ;
        getline(cin,ID) ;
        if(A.RemStaff(ID)){
            cout << "  Staff removed succefully. \n" ;
        } 
        break ;
        case 3:
        cout << WHITE ;
        cout << "  Enter the registration ID of the staff you want to assign mission to: " ;
        cin.ignore() ;
        getline(cin,ID) ;
        cout << "  Enter the mission: " ;
        getline(cin,mission) ;
        if(FileManagement::AddMissionToStaff(ID,mission)){
            cout << "  Mission assigned to staff successfully\n" ;
        } 
        break ;
        case 4:
        AdministratorPage(A) ;
        break ;
         default:
         cout <<endl ;
         cout << "  Invalide choice (1-4) \n" ;
         break ;
    }
    }
    }

    void System::StudentManagement(Administrator A){

        int choice ;
        string ID ;
          while(true){
              cout << endl ;
    cout << BLUE;
    cout << "========================================\n";
    cout << "               COMFORT                  \n";
    cout << "========================================\n";

    cout << WHITE;
    cout << "  [1] Display Student Information \n" ;
    cout << "  [2] Remove Student\n";
    cout << "  [3] Back\n";
  
   

    cout << BLUE;
    cout << "========================================\n";
    
    cout << WHITE ;
    cout << "  Enter your choice (1-3): " ;
       if (!(cin >> choice))
{
    cout << "  Invalid input. Please enter a number (view the menu).\n";

    cin.clear(); 
    cin.ignore(10000, '\n'); 

    continue;
}
    switch(choice){
        case 1:
        FileManagement::DisplayAllStudents() ;
        break ;
        case 2:
        cout << WHITE ;
        cout << "  Entet the registeration ID of the student you want to remove: " ;
        cin.ignore() ;
        getline(cin,ID) ;
        if(A.RemStudent(ID)){
            cout << "  Student removed succefully. \n" ;
        } 
        break ;
        case 3:
        AdministratorPage(A) ;
        break ;
        default:
        cout <<endl ;
        cout << "  Invalide choice (1-3) \n" ;
        break ;
    }
    
    }
}


    void System::RestaurantManagemnt(Administrator A){
        int choice ;
        string date ;
        Restaurant R ;
           while(true){
              cout << endl ;
    cout << BLUE;
    cout << "========================================\n";
    cout << "               COMFORT                  \n";
    cout << "========================================\n";

    cout << WHITE;
    cout << "  [1] Set Restaurant Menu \n" ;
    cout << "  [2] View Restaurant Menu\n";
    cout << "  [3] Back\n";
    

    cout << BLUE;
    cout << "========================================\n";
    
    cout << WHITE ;
    cout << "  Enter your choice (1-3): " ;
       if (!(cin >> choice))
{
    cout << "  Invalid input. Please enter a number (view the menu).\n";

    cin.clear(); 
    cin.ignore(10000, '\n'); 

    continue;
}
    switch(choice){
    case 1:
    
    R.SetMeals() ;
    FileManagement::SaveRestaurant(R) ;
    FileManagement::SortAndRemoveDuplicateMenus() ;
    break ;
    case 2:
    cout << endl ;
    cout << WHITE ;
    cout << "  Enter the date of restaurant menu (YYYY-MM-DD): " ;
    cin.ignore() ;
    getline(cin,date) ;
    FileManagement::DisplayMealsByDate(date) ;
    break ;
    case 3:
    AdministratorPage(A) ;
    break ;
    default :
    cout <<endl ;
    cout << "  Invalide choice (1-4) \n" ;
    break ;


    }
}
    }

    void System::DormMAnagement(Administrator A){
        string ID ;
        int choice,roomNum ;
          while(true){
              cout << endl ;
    cout << BLUE;
    cout << "========================================\n";
    cout << "               COMFORT                  \n";
    cout << "========================================\n";

    cout << WHITE;
    cout << "  [1] View rooms informaton \n" ;
    cout << "  [2] Remove student from dorm\n";
    cout << "  [3] Add student to dorm\n";
    cout << "  [4] Back \n" ;
    

    cout << BLUE;
    cout << "========================================\n";
    
    cout << WHITE ;
    cout << "  Enter your choice (1-4): " ;
       if (!(cin >> choice))
{
    cout << "  Invalid input. Please enter a number (view the menu).\n";

    cin.clear(); 
    cin.ignore(10000, '\n'); 

    continue;
}

    switch(choice){
        case 1:
        FileManagement::DisplayDormInformation() ;
        break ;
        case 2:
        cout << "  Enter the registration ID of the student you want to remove from the dorm: " ;
        cin.ignore() ;
        getline(cin,ID) ;
        A.RemStudentFromDorm(ID) ;
        break ;
        case 3:
        cin.ignore() ;
        cout << "  Enter the registration of the student you want to add dorm: " ;
        getline(cin,ID) ;
        

while(true)
{
    cout << "  Enter the room number you want to add student to: " ;


    if(cin >> roomNum)
        break;

    cout << "  Invalid input. Please enter an integer.\n";

    cin.clear();
    cin.ignore(10000, '\n'); 
}
        A.addStudentToDorm(ID,roomNum) ;
        break ;
        case 4:
        AdministratorPage(A) ;
        break ;
        default :
        cout <<endl ;
        cout << "  Invalide choice (1-4) \n" ;
        break ;
    }
    }
}


    void System::StaffPage(Staff& S){
          int choice,missionNum;
          while(true){
              cout << endl ;
    cout << BLUE;
    cout << "========================================\n";
    cout << "               COMFORT                  \n";
    cout << "========================================\n";

    cout << WHITE;
    cout << "  [1] View my informaton \n" ;
    cout << "  [2] View my missions\n";
    cout << "  [3] Check mission\n";
    cout << "  [4] Logout \n" ;
    cout << "  [5] Exit \n" ;

    

    cout << BLUE;
    cout << "========================================\n";
    
    cout << WHITE ;
    cout << "  Enter your choice (1-4): " ;
       if (!(cin >> choice))
{
    cout << "  Invalid input. Please enter a number (view the menu).\n";

    cin.clear(); 
    cin.ignore(10000, '\n'); 

    continue;
}

    switch(choice){
        case 1:
        
    cout << BLUE;
    cout << "========================================\n";
    cout << WHITE ; 
    cout << "  You are a " << S.getRole() <<endl ;
    cout << "  First Name       : " << S.getFirstName() <<endl ;
    cout << "  Last Name        : " << S.getLastName() <<endl;
    cout << "  Registeration ID : " << S.getRegistrationID() << endl ;
    cout << BLUE;
    cout << "========================================\n";
    
        break ;
        case 2:
        cout << WHITE ;
        S.printMissions() ;
        break ;
        case 3:
        cout << WHITE ;
        cout << "  Enter a mission to be done: " ;
           if (!(cin >> missionNum))
{
    cout << "  Invalid input. Enter the number of finished mission. \n ";
    
    cin.clear(); 
    cin.ignore(10000, '\n'); 
    
    continue ;
}
        S.Done(missionNum) ;
        break ;
        case 4:
        FileManagement::SaveStaffData(S) ;
        MainPage() ;
        break ;
        case 5:
        FileManagement::SaveStaffData(S) ;
        cout << "  All your data are saved successfully \n" ;
        cout << "  Exit ...." ;
        exit(0) ;
        break ;
        default :
        cout <<endl ;
        cout << "  Invalide choice (1-4) \n" ;
        break ;
    }
}

    }

    void System::StudentPage(Student& S){
             int choice;
             string report ;
          while(true){
              cout << endl ;
    cout << BLUE;
    cout << "========================================\n";
    cout << "               COMFORT                  \n";
    cout << "========================================\n";

    cout << WHITE;
    cout << "  [1] View my informaton \n" ;
    cout << "  [2] View restaurant menu\n";
    cout << "  [3] View my room number\n" ;
    cout << "  [4] Reserve break fast\n";
    cout << "  [5] Reserve lunch \n" ;
    cout << "  [6] Reserve dinner \n" ;
    cout << "  [7] Unreserve break fast\n";
    cout << "  [8] Unreserve lunch \n" ;
    cout << "  [9] Unreserve dinner \n" ;
    cout << "  [10] Report a problem\n" ;
    cout << "  [11] Logout\n" ;
    cout << "  [12] Exit\n" ;
    

    cout << BLUE;
    cout << "========================================\n";
    
    cout << WHITE ;
    cout << "  Enter your choice (1-12): " ;
       if (!(cin >> choice))
{
    cout << "  Invalid input. Please enter a number (view the menu).\n";

    cin.clear(); 
    cin.ignore(10000, '\n'); 

    continue;
}

    switch(choice){
        case 1:
        
    cout << BLUE;
    cout << "========================================\n";
    cout << WHITE ; 
    cout << "  You are a " << S.getRole() <<endl ;
    cout << "  First Name       : " << S.getFirstName() <<endl ;
    cout << "  Last Name        : " << S.getLastName() <<endl;
    cout << "  Registeration ID : " << S.getRegistrationID() << endl ;
    cout << "  Breakfast        : " << (S.getBreakfast() ? "Reserved" : "Not Reserved")<<endl ;
    cout << "  Lunch            : " << (S.getLunch() ? "Reserved" : "Not Reserved")<<endl ;
    cout << "  Dinner           : " << (S.getDinner() ? "Reserved" : "Not Reserved") <<endl ;
    cout << BLUE;
    cout << "========================================\n";
    
        break ;
        case 2:
        FileManagement::DisplayLatestRestaurantMenu() ;
        break ;
        case 3:
        FileManagement::DisplayStudentRoom(S.getRegistrationID()) ;
        break ;
        case 4:
        S.reserveBreakfast() ;
        break ;
        case 5:
        S.reserveLunch() ;
        break ;
        case 6:
        S.reserveDinner() ;
        break ;
        case 7:
        S.unreserveBreakfast() ;
        break ;
        case 8:
        S.unreserveLunch() ;
        break ;
        case 9:
        S.unreserveDinner() ;
        break ;
        case 10:
        cout << WHITE ;
        cout << "  Enter your report: " ;
        cin.ignore() ;
        getline(cin,report) ;
        FileManagement::AssignMissionToLeastBusyStaff(report) ;
        break ;
        case 11:
        FileManagement::SaveStudentData(S) ;
        MainPage() ;
        break ;
        case 12:
        FileManagement::SaveStudentData(S) ;
        cout << "  All your data are saved successfully \n" ;
        cout << "  Exit ...." ;
        exit(0) ;
        break ;
        default :
        cout <<endl ;
        cout << "  Invalide choice (1-12) \n" ;
        break ;
    }
}
    }