#ifndef Nurse_h
#define Nurse_h
#include <iostream>
#include "HospitalStaff.h"

using namespace std;

class Nurse: public HospitalStaff{
private:
    int yearsOfExperience;

public:
    Nurse(int ID, string name, string department, int yearsOfExperience=0)
        : HospitalStaff(ID, name, department), yearsOfExperience(yearsOfExperience) {}

    void displayInfo() override {
        cout << "Staff ID: " << getID() << " | Name: " << getName() << " | Department: " << getDepartment() << endl;
        cout << "Years of experience: " << yearsOfExperience << endl;
    }

    void checkPatient(int ID) {
        for (auto patient : patients) {
            if (patient->getID() == ID) {
                cout << "Patient with ID: " << ID << " has been checked." << endl;
                return;
            }
        }
        cout << "There is no patient with ID: " << ID << endl;
    }
};

#endif /* Nurse_h */

