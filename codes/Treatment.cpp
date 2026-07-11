#include "Treatment.h"

Treatment::Treatment() {
    treatmentName = "";
    staffName = "";
    cost = 0.0;
}

Treatment::Treatment(string name, double c, string staff) {
    treatmentName = name;
    cost = c;
    staffName = staff;
}

double Treatment::getCost() const {
    return cost;
}

string Treatment::getStaffName() const {
    return staffName;
}
