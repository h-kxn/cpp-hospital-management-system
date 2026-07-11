#pragma once
#include <iostream>
using namespace std;

class Bill {
private:
    double totalAmount;

public:
    Bill();
    Bill(const Bill& other);

    double getTotalAmount() const;
    void addCharge(double amount);

    Bill operator+(const Bill& other) const;
    bool operator<(const Bill& other) const;
    bool operator>(const Bill& other) const;
    bool operator==(const Bill& other) const;

    friend ostream& operator<<(ostream& out, const Bill& b);
};
