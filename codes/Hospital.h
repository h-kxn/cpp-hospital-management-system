#pragma once
#include <vector>
#include <string>
#include "Patient.h"
#include "Ward.h"
#include "Scheduling.h"
#include "ReportingAndQueries.h"
using namespace std;

class Hospital {
private:
    vector<Patient> activePatients;
    vector<Patient> archivedPatients;
    vector<Ward*> wards;

    Scheduling scheduler;
    ReportingAndQueries reporter;

public:
    void addWard(Ward* w);
    void admit(Patient& p);
    void discharge(const string& patientId);

    bool isAdmitted(const string& patientId) const;
    bool isArchived(const string& patientId) const;

    double wardRevenue(const string& wardName) const;

    vector<Patient> filterPatients(const vector<Patient>& patients, bool (*predicate)(const Patient&));
    vector<Patient> sortPatients(vector<Patient> patients, bool (*compare)(const Patient&, const Patient&));

    vector<Patient>& getActivePatients();

    ~Hospital();
};
