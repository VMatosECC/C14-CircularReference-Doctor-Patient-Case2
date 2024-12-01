// C14-CircularReference-Doctor-Patient-Case2.cpp 
// ---------------------------------------------------------------------------------
// Circular Reference between Doctor and Patient
// Doctor and Patient are separate classes
// Doctor class has a list of Patients
// Patient class has a list of Doctors
// Doctor and Patient classes have pointers to each other
// Doctor and Patient classes have forward declarations of each other
// Both classes using the header (.h) file to define and implement the class.
//----------------------------------------------------------------------------------
#include "Doctor.h"
#include "Patient.h"

int main() {

    // Create doctors
    Doctor drHibbert("Julius Hibbert");
    Doctor drHouse("Gregory House");
    Doctor drCasey("Ben Casey");

    // Create patients
    Patient homer("Homer Simpson");
    Patient marge("Marge Simpson");
    Patient bart("Bart Simpson");
    Patient lisa("Lisa Simpson");
    Patient maggie("Maggie Simpson");

    // Assign patients to Dr. Hibbert
    homer.addDoctor(&drHibbert);
    marge.addDoctor(&drHibbert);
    bart.addDoctor(&drHibbert);
    lisa.addDoctor(&drHibbert);
    maggie.addDoctor(&drHibbert);

    // Assign Bart & Lisa additional doctors
    bart.addDoctor(&drHouse);
    bart.addDoctor(&drCasey);
    lisa.addDoctor(&drHouse);


    // Display relationships
    drHibbert.showPatients();
    drHouse.showPatients();
    drCasey.showPatients();

    cout << endl;

    homer.showDoctors();
    bart.showDoctors();
    lisa.showDoctors();

}
