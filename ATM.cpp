#include "ATM.h"
#include <iostream>

ATM::ATM(Bank& b) : bank(b) {}
using namespace std;
int ATM::start() {
    char choice;
    do {
        cout << "Please enter your command" << endl;
        cout << "Q – quit/exit" << endl;
        cout << "L – login to account" << endl;
        cin >> choice;
        cout <<"\n"<< endl;
        if (choice == 'Q' || choice == 'q') {
            return 0;
        } else if (choice == 'L' || choice == 'l') {
            string id, pin;
            int attempts = 0;
            while (attempts < 3) {
                cout << "Please enter Account ID" << endl;
                cin >> id;
                cout << "Please enter PIN" << endl;
                cin >> pin;

                Account& acct = bank.findAcct(id, pin);
                if (acct.getID() != "") {
                    cout << "Account found" << "\n" <<endl;
                    transactions(acct);
                    break;
                } else {
                    cout << "Sorry – no match" << "\n" << endl;
                    attempts++;
                }
            }
            if (attempts == 3) {
                return 1;
            }
        }
        else {
            cout << "Unrecognized command " << choice << endl;
        }
    } while (true);
}
void ATM::transactions(Account& acct) {
    char choice;
    do {
       cout << "Please enter your selection or Q to quit.\n" << endl;
       cout << "W - withdraw funds" << endl;
       cout << "D - deposit funds" << endl;
       cout << "B - check balance" << endl;
       cout << "Q - quit/exit" << endl;
       cin >> choice;

        switch (choice) {
            case 'W':
            case 'w': {
                double amount;
                cout << "Please enter amount of withdrawal" << endl;
                cin >> amount;
                acct.Withdraw(amount);
                cout <<"\n"<< endl;
                break;
            }
            case 'D':
            case 'd': {
                cout <<"\n"<< endl;
                double amount;
                cout << "Please enter amount of deposit" << endl;
                cin >> amount;
                acct.Deposit(amount);
                cout <<"\n"<< endl;
                break;
            }
            case 'B':
            case 'b':
                cout <<"\n"<< endl;
                acct.printBalance();
                cout <<"\n"<< endl;
                break;
            case 'Q':
            case 'q':
                cout << "Goodbye.\n" << endl;
                return;
            default:
                cout <<"\n"<< endl;
                cout << "Unrecognized command " << choice << endl;
                cout <<"\n"<< endl;
        }
    } while (true);
}