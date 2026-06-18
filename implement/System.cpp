#include <iostream>
#include <windows.h>
#include "System.h"
#include "administrator.h" 
#include "staff.h"
#include "student.h"
#include "restaurant.h"
#include "dorm.h"
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

    cin.clear(); // clear error state
    cin.ignore(10000, '\n'); // discard bad input

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

    cin.clear(); // clear error state
    cin.ignore(10000, '\n'); // discard bad input

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
    cout << WHITE << "  enter the Administrator password: "  ;
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
    cout << "  Enter a registration ID: " ;
    getline(cin,reg) ;
   
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
    cout << WHITE << "  enter the Administrator password: "  ;
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
    cout << "  Enter a registration ID: " ;
    getline(cin,reg) ;

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
    cout << "  Enter a registration ID: " ;
    getline(cin,reg) ;

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

  void System::AdministratorPage(Administrator&){
    exit(0) ;
  } 
    void System::StaffPage(Staff&){
        exit(0) ;
    }

    void System::StudentPage(Student&){
        exit(0) ;
    }