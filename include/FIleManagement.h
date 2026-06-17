#include "System.h"
#include "administrator.h"
class FileManagement
{
public:
    static bool AdministratorExists(const string& reg);
    static void SaveAdministrator(const Administrator& admin);
};