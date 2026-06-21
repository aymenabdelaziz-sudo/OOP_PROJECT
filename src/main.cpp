#include "system.h"
#include <exception>
#include <iostream>

int main(){
    try{
    System sys ;
    sys.run() ;
    }

    catch(const exception& e){
        std::cout <<"  "<< e.what() ;
    }
}