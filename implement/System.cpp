#include <iostream>
#include <windows.h>
#include "System.h"
#include "administrator.h" 
#include "staff.h"
#include "student.h"
#include "restaurant.h"
#include "dorm.h"

using namespace std ;

void system::logoprinter(){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // WELCOME (Blue)
    SetConsoleTextAttribute(hConsole, 9);

    cout << R"(

__          ________ _      _____ ____  __  __ ______
\ \        / /  ____| |    / ____/ __ \|  \/  |  ____|
 \ \  /\  / /| |__  | |   | |   | |  | | \  / | |__
  \ \/  \/ / |  __| | |   | |   | |  | | |\/| |  __|
   \  /\  /  | |____| |___| |___| |__| | |  | | |____
    \/  \/   |______|______\_____\____/|_|  |_|______|

)";

    // TO (White)
    SetConsoleTextAttribute(hConsole, 15);

    cout << R"(

 _______ ____  
|__   __/ __ \
   | | | |  | |
   | | | |  | |
   | | | |__| |
   |_|  \____/

)";

    // COMFORT (Blue)
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

