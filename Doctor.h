//DOCTOR CLASS
//Doctor class has a name and a vector of pointers to Patient objects.

#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// Forward declaration of Patient class
class Patient;

class Doctor {
private:
    string name;
    vector<Patient*> patients; // Holds pointers to Patient objects

public:
    Doctor(const string& name);
    void addPatient(Patient* patient);
    void showPatients() const;
    string getName() const;
};

//IMPLEMENTATION ------------------------------------------------------
#include "Doctor.h"
#include "Patient.h" // Include Patient definition for implementation

Doctor::Doctor(const string& name) : name(name) {}

void Doctor::addPatient(Patient* patient) {
    // Avoid duplicate entries
    for (const auto& pat : patients) {
        if (pat == patient) return;
    }
    patients.push_back(patient);
}

void Doctor::showPatients() const {
    cout << "\nDr. " << name << "'s Patients:" << endl;
    for (const auto& patient : patients) {
        cout << "- " << patient->getName() << endl;
    }
}

string Doctor::getName() const {
    return name;

}
