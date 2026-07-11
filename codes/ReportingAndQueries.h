#pragma once
#include <vector>
#include <string>
#include "Patient.h"
#include "StaffMember.h"
#include "Bill.h"
using namespace std;

class ReportingAndQueries {
public:
    vector<Patient> filterPatients(const vector<Patient>& patients, bool (*predicate)(const Patient&)) const;
    vector<Patient> sortPatients(vector<Patient> patients, bool (*compare)(const Patient&, const Patient&)) const;
    vector<StaffMember*> filterStaff(const vector<StaffMember*>& staff, bool (*predicate)(const StaffMember&)) const;
    vector<Patient*> patientsTreatedBy(const vector<Patient*>& patients, const string& staffName) const;
    double wardRevenue(const vector<Patient>& archivedPatients, const string& wardName) const;
};
