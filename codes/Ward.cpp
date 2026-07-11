#include "Ward.h"
#include "Patient.h"

Ward::Ward(string n, int c, double rate) {
    name = n;
    capacity = c;
    dailyRate = rate;
}

bool Ward::admit(Patient& p) {
    if(patients.size() < capacity && canAdmit(p)) {
        patients.push_back(&p);
        return true;
    }
    return false;
}

string Ward::getWardName() const {
    return name;
}

double Ward::getDailyRate() const {
    return dailyRate;
}

double Ward::getOccupancy() const {
    if(capacity == 0) return 0.0;
    else return ((patients.size() / (double)capacity) * 100.0);
}

bool Ward::operator<(const Ward& other) const {
    return getOccupancy() < other.getOccupancy();
}

bool Ward::operator>(const Ward& other) const {
    return getOccupancy() > other.getOccupancy();
}

bool Ward::operator==(const Ward& other) const {
    return getOccupancy() == other.getOccupancy();
}

GeneralWard::GeneralWard(string n, int c) : Ward(n, c, 100.0) {}

bool GeneralWard::canAdmit(const Patient& p) const {
    return true;
}

ICU::ICU(string n, int c) : Ward(n, c, 200.0) {}

bool ICU::canAdmit(const Patient& p) const {
    if(p.isCritical()) return true;
    else return false;
}

SurgicalWard::SurgicalWard(string n, int c) : Ward(n, c, 150.0) {}

bool SurgicalWard::canAdmit(const Patient& p) const {
    if(p.hasScheduledSurgery()) return true;
    else return false;
}
