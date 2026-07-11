#include "StaffMember.h"
#include "Ward.h"

StaffMember::StaffMember() : Person() {
    salary = 0.0;
    department = "";
    hoursWorked = 0.0;
}

StaffMember::StaffMember(string dept, string n, string i, string contact, Date birth, double hours) : Person(n, i, contact, birth) {
    salary = 0.0;
    department = dept;
    hoursWorked = hours;
}

double StaffMember::generateSalary() const {
    return salary;
}

void StaffMember::display() const {}

GeneralPractitioner::GeneralPractitioner() : StaffMember() {
    consultationFee = 0.0;
}

GeneralPractitioner::GeneralPractitioner(double fee, string n, string i, string contact, Date birth, double hours) : StaffMember("General Medicine", n, i, contact, birth, hours) {
    consultationFee = fee;
}

double GeneralPractitioner::getBillingRate() const {
    return consultationFee;
}

double GeneralPractitioner::generateSalary() const {
    return salary + (hoursWorked * consultationFee);
}

void GeneralPractitioner::display() const {
    cout << "General Practitioner: " << name << ", Consultation Fee: " << consultationFee << endl;
}

Surgeon::Surgeon() : StaffMember() {
    specialization = "";
    perOperationFee = 0.0;
}

Surgeon::Surgeon(double fee, string n, string i, string contact, Date birth, string spec) : StaffMember("Surgery", n, i, contact, birth) {
    perOperationFee = fee;
    specialization = spec;
}

double Surgeon::getBillingRate() const {
    return perOperationFee;
}

void Surgeon::display() const {
    cout << "Surgeon: " << name << ", Specialization: " << specialization << ", Operation Fee: PKR " << perOperationFee << endl;
}

Nurse::Nurse() : StaffMember() {
    assignedWard = nullptr;
    hourlyCareFee = 0.0;
}

Nurse::Nurse(double fee, string n, string i, string contact, Date birth, double hours, Ward* ward) : StaffMember("Nursing", n, i, contact, birth, hours) {
    assignedWard = ward;
    hourlyCareFee = fee;
}

double Nurse::getBillingRate() const {
    return hourlyCareFee;
}

double Nurse::generateSalary() const {
    return salary + (hoursWorked * hourlyCareFee);
}

void Nurse::display() const {
    if(assignedWard) {
        cout << "Nurse: " << name << ", Assigned Ward: " << (assignedWard->getWardName()) << endl;
    } else {
        cout << "Nurse: " << name << ", Assigned Ward: None" << endl;
    }
}
