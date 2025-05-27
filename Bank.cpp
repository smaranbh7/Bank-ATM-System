#include "Bank.h"
#include <iostream>
using namespace std;
Account& Bank::findAcct(const string& id, const string& pin) {
    for (auto& acct : allAccounts) {
        if (acct.getID() == id && acct.getPIN() == pin) {
            return acct;
        }
    }
    return dummyAccount;
}
void Bank::addAcct(const Account& acct) {
    allAccounts.push_back(acct);
}
void Bank::loadAccounts(ifstream& inf) {
    string id, pin;
    double balance;
    while (inf >> id >> pin >> balance) {
        Account newAcct(id, pin, balance);
        addAcct(newAcct);
    }
    cout << allAccounts.size() << " Accounts loaded.\n" << endl;
}