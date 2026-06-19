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

    static Administrator GetAdministratorByID(const string& ID) ;
    static Staff GetStaffByID(const string& ID) ;
    static Student GetStudentByID(const string& ID) ;

    static bool AssignStudentToRoom(const string& ID , int RoomNum) ;
    static bool RemoveStudentFromRoom(const string& ID) ;
    static bool RemoveStudent(const string& ID) ;
    static bool RemoveStaff(const string& regID) ;

    static bool SaveStudentData(const Student& S) ;
    static bool SaveStaffData(const Staff& S) ;
};