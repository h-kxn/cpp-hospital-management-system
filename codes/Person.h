#pragma once
#include <string>
#include "Date.h"
using namespace std;

class Person {
protected:
    string name;
    string id;
    string contactNumber;
    Date dob;

public:
    Person();
    Person(string n, string i, string contact, Date birth);

    virtual void display() const = 0;

    string getName() const;
    string getId() const;

    virtual double generateSalary() const;

    virtual ~Person() {}
};
