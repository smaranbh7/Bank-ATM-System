#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
using namespace std;

class Account {
protected:
    string accountID;
    string accountPIN;
    double accountBalance;
public:
    Account();
    Account(const string& id, const string& pin, double balance);
    void setID(const string& id);
    string getID() const;
    void setPIN(const string& pin);
    string getPIN() const;
    void setAccountBalance(double balance);
    double getAccountBalance() const;
    void printBalance() const;
    void Deposit(double amt);
    void Withdraw(double amt);
};

#endif