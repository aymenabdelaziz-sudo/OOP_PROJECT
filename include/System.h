#ifndef SYSTEM_H
#define SYSTEM_H
#include <string>
#include "administrator.h"
#include "staff.h"
#include "student.h"
using namespace std ;

class System{

    private :
    string Administratorpasswd = "ENSIA 2026" ;
    public :
    System() = default ;
    int run() ;
    void logoprinter() ;
    void MainPage() ;
    void RegisterPage() ;
    void LoginPage() ;
    
    void RegisterAdministrator() ;
    void RegisterStaff() ;
    void RegisterStudent() ;

    void LoginAdministrator() ;
    void LoginStaff() ;
    void LoginStudent() ;
    
    void AdministratorPage(Administrator&) ;
    void StaffPage(Staff&) ;
    void StudentPage(Student&) ;


};








#endif