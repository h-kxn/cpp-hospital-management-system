#include "Date.h"
#include <ctime>

Date::Date() {
    day = 0;
    month = 0;
    year = 0;
}

Date::Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

string Date::getCombinedDate() const {
    return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}

bool Date::operator==(const Date& other) const {
    if(this->day == other.day && this->month == other.month && this->year == other.year) return true;
    else return false;
}

int Date::daysInBetween(const Date& other) const {
    auto isLeapYear = [](int y) {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    };

    auto totalDays = [&](const Date& d) {
        int days = 0;
        days += 365 * (d.year - 1);
        days += (d.year - 1) / 4;
        days -= (d.year - 1) / 100;
        days += (d.year - 1) / 400;
        int monthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        for (int i = 0; i < d.month - 1; i++) {
            days += monthDays[i];
        }
        if (d.month > 2 && isLeapYear(d.year)) {
            days += 1;
        }
        days += d.day;
        return days;
    };

    int thisTotal = totalDays(*this);
    int otherTotal = totalDays(other);
    return (thisTotal > otherTotal) ? (thisTotal - otherTotal) : (otherTotal - thisTotal);
}

ostream& operator<<(ostream& os, const Date& d) {
    os << d.getCombinedDate();
    return os;
}

Date getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int day = ltm->tm_mday;
    int month = 1 + ltm->tm_mon;
    int year = 1900 + ltm->tm_year;
    return Date(day, month, year);
}
