#include "Hospital.h"

void Hospital::addWard(Ward* w) {
    wards.push_back(w);
}

void Hospital::admit(Patient& p) {
    for(int i = 0; i < wards.size(); i++) {
        if(wards[i]->admit(p)) {
            activePatients.push_back(p);
            break;
        }
    }
}

void Hospital::discharge(const string& patientId) {
    for(int i = 0; i < activePatients.size(); i++) {
        if(activePatients[i].getId() == patientId) {
            activePatients[i].setDischargeDate(getCurrentDate());
            archivedPatients.push_back(activePatients[i]);
            activePatients.erase(activePatients.begin() + i);
        }
    }
}

bool Hospital::isAdmitted(const string& patientId) const {
    for(int i = 0; i < activePatients.size(); i++) {
        if(activePatients[i].getId() == patientId) return true;
    }
    return false;
}

bool Hospital::isArchived(const string& patientId) const {
    for(int i = 0; i < archivedPatients.size(); i++) {
        if(archivedPatients[i].getId() == patientId) return true;
    }
    return false;
}

double Hospital::wardRevenue(const string& wardName) const {
    return reporter.wardRevenue(archivedPatients, wardName);
}

vector<Patient> Hospital::filterPatients(const vector<Patient>& patients, bool (*predicate)(const Patient&)) {
    return reporter.filterPatients(patients, predicate);
}

vector<Patient> Hospital::sortPatients(vector<Patient> patients, bool (*compare)(const Patient&, const Patient&)) {
    return reporter.sortPatients(patients, compare);
}

vector<Patient>& Hospital::getActivePatients() {
    return activePatients;
}

Hospital::~Hospital() {}
