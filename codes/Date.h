#pragma once
#include <string>
using namespace std;

class Date {
public:
    int day;
    int month;
    int year;

    Date();
    Date(int d, int m, int y);

    string getCombinedDate() const;
    bool operator==(const Date& other) const;
    int daysInBetween(const Date& other) const;
    friend ostream& operator<<(ostream& os, const Date& d);
};

Date getCurrentDate();
