#include "Person.h"

Person::Person() {
    name = "";
    id = "";
    contactNumber = "";
    dob = Date();
}

Person::Person(string n, string i, string contact, Date birth) {
    name = n;
    id = i;
    contactNumber = contact;
    dob = birth;
}

string Person::getName() const {
    return name;
}

string Person::getId() const {
    return id;
}

double Person::generateSalary() const {
    return 0.0;
}
