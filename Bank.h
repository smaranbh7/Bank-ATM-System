#ifndef BANK_H
#define BANK_H
#include <vector>
#include <fstream>
#include "Account.h"
using namespace std;

class Bank {
protected:
    vector<Account> allAccounts;
    Account dummyAccount;
public:
    Account& findAcct(const string& id, const string& pin);
    void addAcct(const Account& acct);
    void loadAccounts(ifstream& inf);
};

#endif 