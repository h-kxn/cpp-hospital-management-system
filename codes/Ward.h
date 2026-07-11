#pragma once
#include <string>
#include <vector>
using namespace std;

class Patient;

class Ward {
protected:
    string name;
    int capacity;
    double dailyRate;
    vector<Patient*> patients;

public:
    Ward(string n, int c, double rate);

    virtual bool canAdmit(const Patient& p) const = 0;

    bool admit(Patient& p);

    string getWardName() const;
    double getDailyRate() const;
    double getOccupancy() const;

    bool operator<(const Ward& other) const;
    bool operator>(const Ward& other) const;
    bool operator==(const Ward& other) const;

    virtual ~Ward() {}
};

class GeneralWard : public Ward {
public:
    GeneralWard(string n, int c);
    bool canAdmit(const Patient& p) const override;
};

class ICU : public Ward {
public:
    ICU(string n, int c);
    bool canAdmit(const Patient& p) const override;
};

class SurgicalWard : public Ward {
public:
    SurgicalWard(string n, int c);
    bool canAdmit(const Patient& p) const override;
};
