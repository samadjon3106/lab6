
#define Doctor_h
#include <iostream>
#include "HospitalStaff.h"

using namespace std;

class Doctor: public HospitalStaff{
private:
    string specialization;
    int nightShift;

public:
    Doctor(int ID, string name, string department, string specialization, int n=0)
        : HospitalStaff(ID, name, department), specialization(specialization), nightShift(n) {}

    void addNightShifts(int n){
        nightShift += n;
    }

    int getNightShifts(){
        return nightShift;
    }

    void displayInfo() override {
        cout << "Staff ID: " << getID() << " | Name: " << getName() << " | Department: " << getDepartment() << endl;
        cout << "Specialization: " << specialization << " | Night Shifts: " << nightShift << endl;
    }

    void treatPatient(int ID, string treatment) {
        Patient* patient = findPatient(ID);
        if (patient != nullptr) {
            patient->setTreatment(treatment);
        }
    }
};

#endif /* Doctor_h */
