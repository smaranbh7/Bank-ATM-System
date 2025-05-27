#include "Account.h"
#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;
Account::Account() : accountID(""), accountPIN(""), accountBalance(0.0) {}
Account::Account(const string& id, const string& pin, double balance) {
    setID(id);
    setPIN(pin);
    setAccountBalance(balance);
}
void Account::setID(const string& id) {
    if (id.length() == 8) {
        accountID = id;
    } else {
        cout << "Invalid ID. Must be exactly 8 characters long." << endl;
    }
}
string Account::getID() const {
    return accountID;
}
void Account::setPIN(const string& pin) {
    if (pin.length() == 4 && all_of(pin.begin(), pin.end(), ::isdigit)) {
        accountPIN = pin;
    } else {
        cout << "Invalid PIN. Must be exactly 4 digits." << endl;
    }
}
string Account::getPIN() const {
    return accountPIN;
}
void Account::setAccountBalance(double balance) {
    if (balance >= 0.0) {
        accountBalance = balance;
    } else {
        cout << "Invalid balance. Must be non-negative." << endl;
    }
}
double Account::getAccountBalance() const {
    return accountBalance;
}
void Account::printBalance() const {
    cout << "Balance: $" << fixed << setprecision(2) << accountBalance << endl;
}
void Account::Deposit(double amt) {
    if (amt >= 0.0) {
        setAccountBalance(getAccountBalance() + amt);
    } else {
        cout << "Invalid deposit amount. Must be non-negative." << endl;
    }
}
void Account::Withdraw(double amt) {
    if (amt > 0.0 && amt <= accountBalance) {
        setAccountBalance(getAccountBalance() - amt);
    } else {
        cout << "Invalid withdrawal amount or insufficient funds." << endl;
    }
}