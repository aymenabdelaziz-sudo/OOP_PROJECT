#include "System.h"
#include "administrator.h"
class FileManagement
{
public:
    static bool AdministratorExists(const string& reg);
    static void SaveAdministrator(const Administrator& admin);

    static bool StaffExists(const string& regID);
    static void SaveStaff(const Staff& S);

    static bool StudentExists(const string& regID);
    static void SaveStudent(const Student& S);

    
};