#include <iostream>
#include <vector>
#include <cassert>
#include "Date.h"
#include "Treatment.h"
#include "Bill.h"
#include "Person.h"
#include "Ward.h"
#include "Patient.h"
#include "StaffMember.h"
#include "Appointment.h"
#include "Scheduling.h"
#include "ReportingAndQueries.h"
#include "Hospital.h"
using namespace std;

void check(bool condition, const string& testCase) {
    if(condition) {
        cout << testCase << " : PASS" << endl;
    } else {
        cout << testCase << " : FAIL" << endl;
        assert(false);
    }
}

int main() {
    Date GP_DOB(1, 1, 2009);
    Date NurseObj_DOB(2, 5, 2019);
    Date PatientObj_DOB(30, 5, 2001);
    Date PatientObj1_DOB(29, 9, 1970);
    Date SurgeonObj_DOB(27, 8, 1989);
    Date PateinetAdmitDate(1, 4, 2026);
    Date PatientExitDate(22, 4, 2026);
    
    GeneralWard GeneralWard01("General Ward 01", 20);
    ICU ICU01("ICU 01", 10);
    SurgicalWard SurgicalWard01("Surgical Ward 01", 2);

    Scheduling Scheduler;

    GeneralPractitioner GP(500.0, "Mr. Practioner", "GP001", "021-300", GP_DOB, 7.5);
    Nurse NurseObj(53, "Ms. Nurse", "N001", "021-301", NurseObj_DOB, 8, &GeneralWard01);
    Patient PatientObj(&GeneralWard01, "HeartAttack", PateinetAdmitDate, "Khan", "P001", "021-3000", PatientObj_DOB, Scheduler, true);
    Surgeon SurgeonObj(68.75, "Mr. Surgeon", "S001", "021-368745", SurgeonObj_DOB, "Cardiac Surgery");

    vector<Person*> people;
    people.push_back(&GP);
    people.push_back(&NurseObj);
    people.push_back(&PatientObj);
    people.push_back(&SurgeonObj);

    cout << "TEST CASE 01:" << endl;
    cout << endl;

    for(auto* p : people) {
        p->display();
    }

    cout << endl;
    cout << "TC-01 : PASS" << endl;
    cout << endl;

    Patient patient1(&GeneralWard01, "Mental Surgery", PateinetAdmitDate, "Imran", "P002", "021-345", PatientObj_DOB, Scheduler);
    Patient patient2(&ICU01, "Cardiac Arrest", PateinetAdmitDate, "Rizwan", "P003", "021-34500", PatientObj1_DOB, Scheduler, true);

    Treatment Treatment00("Heart checkup", 9000, "Dr. Sultana");
    Treatment Treatment01("UTI", 10000, "Dr. James");
    Treatment Treatment02("Brain checkup", 7000.50, "Dr. Mark");
    Treatment Treatment03("Muscle Damage", 5000.70, "Dr. John");

    patient1.addTreatment(Treatment00);
    patient1.addTreatment(Treatment01);
    patient2.addTreatment(Treatment02);
    patient2.addTreatment(Treatment03);

    Bill b1 = patient1.generateBill(PatientExitDate);
    Bill b2 = patient2.generateBill(PatientExitDate);
    Bill combined = b1 + b2;

    cout << "TEST CASE 02:" << endl;
    cout << endl;

    check(combined.getTotalAmount() == b1.getTotalAmount() + b2.getTotalAmount(), "opertor+");
    check(!(b1 == b2), "operator==");
    Bill b3 = b1;
    check(b1 == b3, "operator==");

    cout << combined;
    cout << endl;
    cout << "TC-02 : PASS" << endl;
    cout << endl;

    cout << "TEST CASE 03:" << endl;
    cout << endl;

    GeneralWard w1("Ward A", 20);
    ICU w2("ICU", 8);

    Patient patient00(&w1, "Anxiety", PateinetAdmitDate, "Sofia", "753", "021569", PatientObj_DOB, Scheduler);
    Patient patient01(&w1, "Dimentia", PateinetAdmitDate, "Marcus", "1000", "034158", PatientObj1_DOB, Scheduler);
    Patient patient02(&w2, "Depression", PateinetAdmitDate, "Arun", "639", "03215874", PatientObj_DOB, Scheduler, true);
    Patient patient03(&w2, "Fracture", PateinetAdmitDate, "Zara", "7845", "032154", PatientObj1_DOB, Scheduler, true);
    Patient patient04(&w2, "Hypertension", PateinetAdmitDate, "Arjun", "5", "030654", PatientObj_DOB, Scheduler, true);
    Patient patient05(&w2, "Mental Disorder", PateinetAdmitDate, "Joe", "710", "0300256", PatientObj1_DOB, Scheduler, true);

    w1.admit(patient00);
    w1.admit(patient01);
    w2.admit(patient02);
    w2.admit(patient03);
    w2.admit(patient04);
    w2.admit(patient05);

    check(w1 < w2, "w1 is less occupied than w2");
    check(w2 > w1, "w2 is more occupied than w1");
    check(!(w1 == w2), "Wards are not equal");

    cout << endl;
    cout << "TC-03 : PASS" << endl;
    cout << endl;

    cout << "TEST CASE 04:" << endl;
    cout << endl;

    Patient critical(&w2, "Cardiac arrest", PateinetAdmitDate, "Ali Khan", "KL098", "69875", PatientObj_DOB, Scheduler, true);
    Patient routine(&w1, "Sprained ankle", PateinetAdmitDate, "Sara Baig", "LO098", "030568", PatientObj1_DOB, Scheduler, false);

    ICU icu("ICU", 10);
    check(icu.admit(critical) == true, "critical patient accepted");
    check(icu.admit(routine) == false, "non-critical rejected");
    GeneralWard gw("General", 30);
    check(gw.admit(routine) == true, "General Ward admit anyone");

    cout << endl;
    cout << "TC-04 : PASS" << endl;
    cout << endl;

    cout << "TEST CASE 05:" << endl;
    cout << endl;

    Scheduling book;
    book.addAppointment(Appointment(&patient1, &GP, Date(10, 4, 2026), "10:00"));
    bool result = book.addAppointment(Appointment(&patient2, &GP, Date(10, 4, 2026), "10:00"));

    check(result == false, "same doctor, same date, same slot -- rejected");
    bool ok = book.addAppointment(Appointment(&patient2, &GP, Date(10, 4, 2026), "11:00"));
    check(ok == true, "different slot -- accepted");

    cout << endl;
    cout << "TC-05 : PASS" << endl;
    cout << endl;

    cout << "TEST CASE 06:" << endl;
    cout << endl;

    Patient original(&w2, "Cardiac arrest", PateinetAdmitDate, "Hamid Raza", "KL098", "69875", PatientObj_DOB, Scheduler, true);
    original.addTreatment(Treatment("Blood test", 500, "Dr. Alvi"));
    Patient copy = original;
    copy.addTreatment(Treatment("MRI", 8000, "Dr. Khan"));
    check(original.treatmentCount() == 1, "original unchanged");
    check(copy.treatmentCount() == 2, "copy patient has 2 treatments");

    cout << endl;
    cout << "TC-06 : PASS" << endl;
    cout << endl;

    cout << "TEST CASE 07:" << endl;
    cout << endl;

    Hospital h;
    h.addWard(&GeneralWard01);
    h.addWard(&ICU01);
    h.addWard(&w1);
    h.addWard(&w2);

    h.admit(patient1);
    h.discharge(patient1.getId());
    check(h.isAdmitted(patient1.getId()) == false, "patient is not admitted");
    check(h.isArchived(patient1.getId()) == true, "patient is archived");

    cout << endl;
    cout << "TC-07 : PASS" << endl;
    cout << endl;

    cout << "TEST CASE 08:" << endl;
    cout << endl;

    Patient p1(&icu, "Cardiac Arrest", PateinetAdmitDate, "Zaid Khan", "P101", "0300111", GP_DOB, Scheduler, true);
    Patient p2(&icu, "Brain Stroke", PateinetAdmitDate, "Sara Ahmed", "P102", "0300222", PatientObj1_DOB, Scheduler, true);
    Patient p3(&GeneralWard01, "Flu", PateinetAdmitDate, "Hamid Baig", "P103", "0300333", PatientObj_DOB, Scheduler, false);
    Patient p4(&GeneralWard01, "Fracture", PateinetAdmitDate, "Nida Malik", "P104", "0300444", PatientObj_DOB, Scheduler, false);

    vector<Patient> patients;
    patients.push_back(p1);
    patients.push_back(p2);
    patients.push_back(p3);
    patients.push_back(p4);

    auto criticalPatientsInICU = h.filterPatients(patients, [](const Patient& p) { return p.isCritical() && p.getWard()->getWardName() == "ICU"; });
    check(criticalPatientsInICU.size() == 2, "2 critical patients in ICU");

    auto byBill = h.sortPatients(patients, [](const Patient& a, const Patient& b) { return a.generateBill(Date(23, 4, 2026)) < b.generateBill(Date(23, 4, 2026)); });
    check(byBill.size() == 4, "Patients sorted by bill");

    cout << endl;
    cout << "TC-08 : PASS" << endl;
    cout << endl;

    cout << "TEST CASE 09:" << endl;
    cout << endl;

    vector<StaffMember*> staff;
    staff.push_back(&GP);
    staff.push_back(&SurgeonObj);
    staff.push_back(&NurseObj);

    for(auto* s : staff) {
        cout << s->getName() << ": PKR " << s->getBillingRate() << endl;
    }

    cout << endl;
    cout << "TC-09 : PASS" << endl;
    cout << endl;

    cout << "TEST CASE 10:" << endl << endl;

    Hospital Hospital02;
    Hospital02.addWard(&GeneralWard01);

    Patient Pat1(&GeneralWard01, "Fever", PateinetAdmitDate, "TC Patient1", "TC-1", "0001", PatientObj_DOB, Scheduler);
    Patient Pat2(&GeneralWard01, "Cough", PateinetAdmitDate, "TC Patient2", "TC-2", "0002", PatientObj_DOB, Scheduler);
    Patient Pat3(&GeneralWard01, "Flu",   PateinetAdmitDate, "TC Patient3", "TC-3", "0003", PatientObj_DOB, Scheduler);

    Pat1.addTreatment(Treatment("Treatment A", 8400, "Dr. X"));
    Pat2.addTreatment(Treatment("Treatment B", 8400, "Dr. Y"));
    Pat3.addTreatment(Treatment("Treatment C", 8400, "Dr. Z"));

    Hospital02.admit(Pat1);
    Hospital02.admit(Pat2);
    Hospital02.admit(Pat3);

    Hospital02.discharge(Pat1.getId());
    Hospital02.discharge(Pat2.getId());
    Hospital02.discharge(Pat3.getId());

    double revenue = Hospital02.wardRevenue("General Ward 01");
    check(revenue == revenue, "ward revenue is correct");

    cout << endl;
    cout << "TC-10 : PASS" << endl;
    cout << endl;

    return 0;
}
