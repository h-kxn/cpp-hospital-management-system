#pragma once
#include <vector>
#include "Appointment.h"
using namespace std;

class Patient;
class StaffMember;

class Scheduling {
private:
    vector<Appointment> appointments;

public:
    bool addAppointment(const Appointment& a);
    void cancelAppointment(const Appointment& a);

    vector<Appointment> RetrieveStaffAppointmentsOnDay(const StaffMember& s, Date dateToSearch);
    vector<Appointment> RetrieveStaffAppointments(const StaffMember& s);
    vector<Appointment> RetrievePatientAppointments(const Patient& p);
};
