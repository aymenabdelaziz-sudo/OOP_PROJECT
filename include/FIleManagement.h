#include "System.h"
#include "administrator.h"
#include "restaurant.h"
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

    static void DisplayAllStaff() ;
    static bool AddMissionToStaff(const string& ID , const string& mission) ;
    static void DisplayAllStudents() ;
    static bool SaveRestaurant(const Restaurant& ) ;
    static void DisplayMealsByDate(const string& date) ;
    static bool SortAndRemoveDuplicateMenus() ;
    static void DisplayDormInformation() ;
    static void DisplayLatestRestaurantMenu() ;
    static void DisplayStudentRoom(const string& studentID) ;
    static bool AssignMissionToLeastBusyStaff(const string& mission) ;
    static bool ResetStudentMealsIfNewDate(const string& date) ;
};