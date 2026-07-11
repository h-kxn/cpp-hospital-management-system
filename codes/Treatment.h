#pragma once
#include <string>
using namespace std;

class Treatment {
private:
    string treatmentName;
    string staffName;
    double cost;

public:
    Treatment();
    Treatment(string name, double c, string staff);

    double getCost() const;
    string getStaffName() const;
};
