#include "Patient.h"
#include "Ward.h"
#include "Scheduling.h"
#include <iostream>

Patient::Patient() : critical(false), assignedWard(nullptr) {}

Patient::Patient(Ward* w, string d, Date a, string n, string i, string c, Date b, Scheduling&, bool crit)
    : Person(n, i, c, b), diagnosis(d), critical(crit), admissionDate(a), assignedWard(w) {}

Patient::Patient(const Patient& other) : Person(other) {
    diagnosis = other.diagnosis;
    critical = other.critical;
    admissionDate = other.admissionDate;
    dischargeDate = other.dischargeDate;
    assignedWard = other.assignedWard;
    for(auto t : other.treatments) {
        treatments.push_back(new Treatment(*t));
    }
}

Patient& Patient::operator=(const Patient& other) {
    if(this != &other) {
        name = other.name;
        id = other.id;
        contactNumber = other.contactNumber;
        dob = other.dob;
        diagnosis = other.diagnosis;
        critical = other.critical;
        admissionDate = other.admissionDate;
        dischargeDate = other.dischargeDate;
        assignedWard = other.assignedWard;
        for(auto t : treatments) delete t;
        treatments.clear();
        for(auto t : other.treatments) {
            treatments.push_back(new Treatment(*t));
        }
    }
    return *this;
}

Patient::Patient(Patient&& other) noexcept {
    name = other.name;
    id = other.id;
    contactNumber = other.contactNumber;
    dob = other.dob;
    diagnosis = other.diagnosis;
    critical = other.critical;
    admissionDate = other.admissionDate;
    dischargeDate = other.dischargeDate;
    assignedWard = other.assignedWard;
    treatments = other.treatments;
    other.assignedWard = nullptr;
    other.treatments = vector<Treatment*>();
}

Patient& Patient::operator=(Patient&& other) {
    if(this != &other) {
        name = other.name;
        id = other.id;
        contactNumber = other.contactNumber;
        dob = other.dob;
        diagnosis = other.diagnosis;
        critical = other.critical;
        admissionDate = other.admissionDate;
        dischargeDate = other.dischargeDate;
        assignedWard = other.assignedWard;
        treatments = other.treatments;
        other.assignedWard = nullptr;
        other.treatments = vector<Treatment*>();
    }
    return *this;
}

Patient::~Patient() {
    for(auto t : treatments) delete t;
}

void Patient::display() const {
    cout << "Patient: " << name << ", Diagnosis: " << diagnosis << ", Admission Date: " << admissionDate << endl;
}

void Patient::addTreatment(const Treatment& t) {
    treatments.push_back(new Treatment(t));
}

int Patient::treatmentCount() const {
    return treatments.size();
}

bool Patient::isCritical() const {
    return critical;
}

Ward* Patient::getWard() const {
    return assignedWard;
}

void Patient::setDischargeDate(const Date& d) {
    dischargeDate = d;
}

Date Patient::getDischargeDate() const {
    return dischargeDate;
}

Bill Patient::generateBill(const Date& exit) const {
    Bill b;
    double sum = 500;
    sum += assignedWard->getDailyRate() * exit.daysInBetween(admissionDate);
    for(auto t : treatments) sum += t->getCost();
    b.addCharge(sum);
    return b;
}

bool Patient::hasScheduledSurgery() const {
    return !scheduledAppointments.empty();
}

vector<Treatment*> Patient::getTreatmentList() const {
    return treatments;
}
