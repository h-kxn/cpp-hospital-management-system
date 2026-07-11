#pragma once
#include <vector>
#include <string>
#include "Person.h"
#include "Treatment.h"
#include "Bill.h"
#include "Appointment.h"
using namespace std;

class Ward;
class Scheduling;

class Patient : public Person {
private:
    string diagnosis;
    bool critical;
    Date admissionDate;
    Date dischargeDate;
    Ward* assignedWard;
    vector<Treatment*> treatments;
    vector<Appointment> scheduledAppointments;

public:
    Patient();
    Patient(Ward* w, string d, Date a, string n, string i, string c, Date b, Scheduling&, bool crit = false);

    Patient(const Patient& other);
    Patient& operator=(const Patient& other);

    Patient(Patient&& other) noexcept;
    Patient& operator=(Patient&& other);

    ~Patient();

    void display() const override;

    void addTreatment(const Treatment& t);
    int treatmentCount() const;
    bool isCritical() const;
    Ward* getWard() const;
    void setDischargeDate(const Date& d);
    Date getDischargeDate() const;

    Bill generateBill(const Date& exit) const;

    bool hasScheduledSurgery() const;

    vector<Treatment*> getTreatmentList() const;
};
