//PATIENT CLASS
//Patient class has a name and a vector of pointers to Doctor objects.

#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// Forward declaration of Doctor class
class Doctor;

class Patient {
private:
    string name;
    vector<Doctor*> doctors; // Holds pointers to Doctor objects

public:
    Patient(const string& name);
    void addDoctor(Doctor* doctor);
    void showDoctors() const;
    string getName() const;
};

//IMPLEMENTATION ------------------------------------------------------
#include "Patient.h"
#include "Doctor.h" // Include Doctor definition for implementation

Patient::Patient(const string& name) : name(name) {}

void Patient::addDoctor(Doctor* doctor) {
    // Avoid duplicate entries
    for (const auto& doc : doctors) {
        if (doc == doctor) return;
    }
    doctors.push_back(doctor);
    doctor->addPatient(this); // Also add this patient to the doctor's list
}

void Patient::showDoctors() const {
    cout << endl << name << "'s Doctors:" << endl;
    for (const auto& doctor : doctors) {
        cout << "- Dr. " << doctor->getName() << endl;
    }
}

string Patient::getName() const {
    return name;
}

