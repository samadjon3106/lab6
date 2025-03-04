#ifndef Patient_h
#define Patient_h
#include <string>
#include <iostream>

using namespace std;

class Patient{
private:
    int ID;
    string name;
    int age;
    string treatment;
    string diagnosis;

public:
    Patient(int ID, string name, int age, string diagnosis ){
        this->ID = ID;
        this->name = name;
        this->age = age;
        this->diagnosis = diagnosis;
    }

    int getID(){
        return ID;
    }
    string getName(){
        return name;
    }
     void setName(string name){
        this->name = name;
    }
    void setTreatment(string treatment){
        this->treatment = treatment;
    }

    void displayInfo(){
        cout << "ID: " << ID << " | Name: " << name << " | Age: " << age << endl;
        cout << "Diagnosis: " << diagnosis << " | Treatment: " << treatment << endl;
    }
};
#endif /* Patient_h */
