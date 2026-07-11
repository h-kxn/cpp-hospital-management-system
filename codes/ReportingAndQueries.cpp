#include "ReportingAndQueries.h"
#include "Ward.h"

vector<Patient> ReportingAndQueries::filterPatients(const vector<Patient>& patients, bool (*predicate)(const Patient&)) const {
    vector<Patient> result;
    for(const Patient& p : patients) {
        if(predicate(p)) {
            result.push_back(p);
        }
    }
    return result;
}

vector<Patient> ReportingAndQueries::sortPatients(vector<Patient> patients, bool (*compare)(const Patient&, const Patient&)) const {
    int n = patients.size();
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(compare(patients[j + 1], patients[j])) {
                Patient temp = patients[j];
                patients[j] = patients[j + 1];
                patients[j + 1] = temp;
            }
        }
    }
    return patients;
}

vector<StaffMember*> ReportingAndQueries::filterStaff(const vector<StaffMember*>& staff, bool (*predicate)(const StaffMember&)) const {
    vector<StaffMember*> result;
    for(StaffMember* s : staff) {
        if(predicate(*s)) {
            result.push_back(s);
        }
    }
    return result;
}

vector<Patient*> ReportingAndQueries::patientsTreatedBy(const vector<Patient*>& patients, const string& staffName) const {
    vector<Patient*> result;
    for(Patient* p : patients) {
        for(int i = 0; i < p->treatmentCount(); i++) {
            if(p->getTreatmentList()[i]->getStaffName() == staffName) {
                result.push_back(p);
                break;
            }
        }
    }
    return result;
}

double ReportingAndQueries::wardRevenue(const vector<Patient>& archivedPatients, const string& wardName) const {
    double total = 0.0;
    for(const Patient& p : archivedPatients) {
        Ward* w = p.getWard();
        if(w != nullptr && w->getWardName() == wardName) {
            Bill b = p.generateBill(p.getDischargeDate());
            total += b.getTotalAmount();
        }
    }
    return total;
}
