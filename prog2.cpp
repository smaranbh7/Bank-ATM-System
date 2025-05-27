#include <iostream>
#include <fstream>
#include "Bank.h"
#include "ATM.h"
using namespace std;

int main() {
    ifstream inf;
    Bank bk;
    string filename;
    cout << "Enter path for account information : ";
    cin >> filename;
    inf.open(filename);
    if (!inf) {
        cerr << "Error opening file. Exiting." << endl;
        return 1;
    }
    cout << "Loading Data..." << endl;
    bk.loadAccounts(inf);
    inf.close();
    ATM atm(bk);
    int result = atm.start();
    switch (result) {
        case 0:
            cout << "Normal Exit." << endl;
            break;
        case 1:
            cout << "Account not found – system shutting down" << endl;
            break;
    }
    return 0;
}
