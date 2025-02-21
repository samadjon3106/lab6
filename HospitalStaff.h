#ifndef HospitalStaff_h
#define HospitalStaff_h
#include <string>
#include <iostream>
#include <vector>
#include "Patient.h"

using namespace std;

class HospitalStaff{
private:
    string name;
    int ID;
    string department;
    vector<Patient*> patients;

public:
    HospitalStaff(int ID, string name, string department): ID(ID), name(name), department(department) {}

    virtual void displayInfo() = 0;

    string getName(){
        return name;
    }

    int getID(){
        return ID;
    }

    string getDepartment() {
        return department;
    }

    void setName(string name){
        this->name = name;
    }

    void setDepartment(string department){
        this->department = department;
    }

    void addPatient(Patient* p) {
        patients.push_back(p);
    }

    Patient* findPatient(int ID) {
        for (auto patient : patients) {
            if (patient->getID() == ID) {
                return patient;
            }
        }
        cout << "There is no patient with ID: " << ID << endl;
        return nullptr;
    }

    void showPatients() {
        cout << name << "'s Patients:" << endl;
        for (auto patient : patients) {
            cout << "Patient ID: " << patient->getID()
                 << " | Name: " << patient->getName()

                 << endl;
            cout << "Diagnosis: " << patient->getDiagnosis()
                 << " | Treatment: " << patient->getTreatment()
                 << endl;
        }
    }


    void removePatient(int ID) {
        for (auto it = patients.begin(); it != patients.end(); ++it) {
            if ((*it)->getID() == ID) {
                patients.erase(it);
                break;
            }
        }
    }
};

#endif /* HospitalStaff_h */
