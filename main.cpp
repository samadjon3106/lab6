#include <iostream>
#include <vector>
#include "Doctor.h"
#include "Nurse.h"
#include "Patient.h"
#include "HospitalStaff.h"

using namespace std;

int main() {
    // Create staff members (doctors and nurses)
    Doctor* doctor1 = new Doctor(1, "Dr. Smith", "Cardiology", "Heart Surgery", 5);
    Doctor* doctor2 = new Doctor(2, "Dr. Adams", "Neurology", "Brain Surgery", 3);
    Nurse* nurse1 = new Nurse(3, "Nurse Jane", "Cardiology", 10);
    Nurse* nurse2 = new Nurse(4, "Nurse Bob", "Neurology", 7);
    Doctor* doctor3 = new Doctor(5, "Dr. Williams", "Orthopedics", "Joint Surgery", 4);
    Doctor* doctor4 = new Doctor(6, "Dr. Brown", "Dermatology", "Skin Disorders", 6);
    Nurse* nurse3 = new Nurse(7, "Nurse Emily", "Orthopedics", 8);
    Nurse* nurse4 = new Nurse(8, "Nurse Daniel", "Dermatology", 5);

    // Add all staff to a vector
    vector<HospitalStaff*> staffList = {doctor1, doctor2, nurse1, nurse2, doctor3, doctor4, nurse3, nurse4};

    // Create patients
    Patient* patient1 = new Patient(101, "John Doe", 45, "Arrhythmia");
    Patient* patient2 = new Patient(102, "Alice Green", 30, "Fractured Leg");

    // Add patients to the staff members
    doctor1->addPatient(patient1);
    doctor2->addPatient(patient1);
    nurse1->addPatient(patient1);
    nurse1->addPatient(patient2);
    doctor3->addPatient(patient1);
    doctor3->addPatient(patient2);
    doctor4->addPatient(patient2);
    nurse3->addPatient(patient2);

    // Assign treatment to patient 301 (though no such patient exists in the initial list, it could be a test case)
    doctor1->treatPatient(301, "Antibiotics");

    // Print lists of patients for each doctor and nurse
    cout << "Doctor 1's Patients: " << endl;
    doctor1->showPatients();
    cout << "Doctor 2's Patients: " << endl;
    doctor2->showPatients();
    cout << "Nurse 1's Patients: " << endl;
    nurse1->showPatients();
    cout << "Nurse 2's Patients: " << endl;
    nurse2->showPatients();

    // Nurse 1 checks patient with ID 302
    nurse1->checkPatient(302);

    // Add 3 night shifts to Doctor 1
    doctor1->addNightShifts(3);

    // Print all staff information
    for (auto staff : staffList) {
        staff->displayInfo();
    }

    // Remove patient with ID 101 from all staff members
    for (auto staff : staffList) {
        staff->removePatient(101);  // Removes patient 101 from the staff's list
    }

    // Print updated patient lists
    cout << "Updated Patients List for Doctor 1: " << endl;
    doctor1->showPatients();
    cout << "Updated Patients List for Nurse 1: " << endl;
    nurse1->showPatients();

    // Clean up allocated memory (important in C++ to avoid memory leaks)
    delete doctor1;
    delete doctor2;
    delete nurse1;
    delete nurse2;
    delete doctor3;
    delete doctor4;
    delete nurse3;
    delete nurse4;
    delete patient1;
    delete patient2;

    return 0;
}


