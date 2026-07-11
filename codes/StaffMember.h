#pragma once
#include <string>
#include <iostream>
#include "Person.h"
using namespace std;

class Ward;

class StaffMember : public Person {
protected:
    double salary;
    string department;
    double hoursWorked;

public:
    StaffMember();
    StaffMember(string dept, string n, string i, string contact, Date birth, double hours = 0.0);

    virtual double getBillingRate() const = 0;

    double generateSalary() const override;
    void display() const override;

    virtual ~StaffMember() {}
};

class GeneralPractitioner : public StaffMember {
private:
    double consultationFee;

public:
    GeneralPractitioner();
    GeneralPractitioner(double fee, string n, string i, string contact, Date birth, double hours = 0.0);

    double getBillingRate() const override;
    double generateSalary() const override;
    void display() const override;
};

class Surgeon : public StaffMember {
private:
    string specialization;
    double perOperationFee;

public:
    Surgeon();
    Surgeon(double fee, string n, string i, string contact, Date birth, string spec);

    double getBillingRate() const override;
    void display() const override;
};

class Nurse : public StaffMember {
private:
    Ward* assignedWard;
    double hourlyCareFee;

public:
    Nurse();
    Nurse(double fee, string n, string i, string contact, Date birth, double hours = 0.0, Ward* ward = nullptr);

    double getBillingRate() const override;
    double generateSalary() const override;
    void display() const override;
};
