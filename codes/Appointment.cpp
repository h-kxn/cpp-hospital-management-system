#include "Appointment.h"
#include "Patient.h"
#include "StaffMember.h"

Appointment::Appointment(Patient* p, StaffMember* s, Date d, string t) {
    patient = p;
    staff = s;
    date = d;
    timeSlot = t;
}

bool Appointment::operator==(const Appointment& other) const {
    if(other.date == this->date && other.staff->getName() == this->staff->getName() && other.timeSlot == this->timeSlot) return true;
    else return false;
}

string Appointment::getPatientName() {
    return patient->getName();
}

string Appointment::getStaffName() {
    return staff->getName();
}

string Appointment::getDate() {
    return date.getCombinedDate();
}

string Appointment::getPatientID() {
    return patient->getId();
}

string Appointment::getStaffID() {
    return staff->getId();
}
