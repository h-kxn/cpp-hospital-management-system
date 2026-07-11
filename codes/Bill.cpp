#include "Bill.h"

Bill::Bill() {
    totalAmount = 0.0;
}

Bill::Bill(const Bill& other) {
    totalAmount = other.totalAmount;
}

double Bill::getTotalAmount() const {
    return totalAmount;
}

void Bill::addCharge(double amount) {
    totalAmount += amount;
}

Bill Bill::operator+(const Bill& other) const {
    Bill combinedBill;
    combinedBill.totalAmount = this->totalAmount + other.totalAmount;
    return combinedBill;
}

bool Bill::operator<(const Bill& other) const {
    return this->totalAmount < other.totalAmount;
}

bool Bill::operator>(const Bill& other) const {
    return this->totalAmount > other.totalAmount;
}

bool Bill::operator==(const Bill& other) const {
    if(this->totalAmount == other.totalAmount) return true;
    else return false;
}

ostream& operator<<(ostream& out, const Bill& b) {
    out << "Total Amount: PKR " << b.getTotalAmount() << endl;
    return out;
}
