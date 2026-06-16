#include <iostream>
#include <windows.h>
#include "System.h"
#include "administrator.h" 
#include "staff.h"
#include "student.h"
#include "restaurant.h"
#include "dorm.h"

// Colors
#define BLUE  "\033[34m"
#define WHITE "\033[97m"
#define RESET "\033[0m"

using namespace std ;

int system::run(){
    logoprinter() ;
    MainPage() ;
    
    
    return 0 ;
}



void system::logoprinter(){
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

void system::MainPage(){
    
    
    int choice ;


    while(true){
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
    cin >> choice ;
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

void system::RegisterPage(){
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
    cin >> choice ;
    switch(choice){

    case 1:
 
    break ;
    case 2:
   
    break ;
    case 3:
    
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

void system::LoginPage(){

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
    cin >> choice ;
    switch(choice){

    case 1:
 
    break ;
    case 2:
   
    break ;
    case 3:
    
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