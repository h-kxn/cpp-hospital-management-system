#include "Scheduling.h"
#include "Patient.h"
#include "StaffMember.h"

bool Scheduling::addAppointment(const Appointment& a) {
    for(auto& p : appointments) {
        if(p == a) return false;
    }
    appointments.push_back(a);
    return true;
}

void Scheduling::cancelAppointment(const Appointment& a) {
    for(int i = 0; i < appointments.size(); i++) {
        if(appointments[i] == a) {
            appointments.erase(appointments.begin() + i);
        }
    }
}

vector<Appointment> Scheduling::RetrieveStaffAppointmentsOnDay(const StaffMember& s, Date dateToSearch) {
    vector<Appointment> StaffAppointments;
    for(int i = 0; i < appointments.size(); i++) {
        if(appointments[i].getStaffName() == s.getName() && appointments[i].getDate() == dateToSearch.getCombinedDate() && appointments[i].getStaffID() == s.getId()) {
            StaffAppointments.push_back(appointments[i]);
        }
    }
    return StaffAppointments;
}

vector<Appointment> Scheduling::RetrieveStaffAppointments(const StaffMember& s) {
    vector<Appointment> StaffAppointments;
    for(int i = 0; i < appointments.size(); i++) {
        if(appointments[i].getStaffName() == s.getName() && appointments[i].getStaffID() == s.getId()) {
            StaffAppointments.push_back(appointments[i]);
        }
    }
    return StaffAppointments;
}

vector<Appointment> Scheduling::RetrievePatientAppointments(const Patient& p) {
    vector<Appointment> PatientAppointments;
    for(int i = 0; i < appointments.size(); i++) {
        if(appointments[i].getPatientName() == p.getName() && appointments[i].getPatientID() == p.getId()) {
            PatientAppointments.push_back(appointments[i]);
        }
    }
    return PatientAppointments;
}
