#ifndef ATM_H
#define ATM_H
#include "Bank.h"

class ATM {
    Bank& bank;
public:
    ATM(Bank& b);
    int start();
    void transactions(Account& acct);
};

#endif // ATM_H