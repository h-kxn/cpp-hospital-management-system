#pragma once
#include <string>
#include "Date.h"
using namespace std;

class Patient;
class StaffMember;

class Appointment {
private:
    Patient* patient;
    StaffMember* staff;
    Date date;
    string timeSlot;

public:
    Appointment(Patient* p, StaffMember* s, Date d, string t);

    bool operator==(const Appointment& other) const;

    string getPatientName();
    string getStaffName();
    string getDate();
    string getPatientID();
    string getStaffID();
};
