#include "checkBalance.h"
#include "lookUpAccount.h"
#include "utilityFunctions.h"
#include <iostream>
#include <iomanip>
#include <memory>

using namespace std;

void checkBalance() {
    while (true) {
        unique_ptr<bankAccountType> account = lookUpAccount();
        if (!account) {
            cout << "Returning to previous menu." << endl;
            return;
        }

        try {
            clearScreen();
            cout << "=== Account Balance ===" << endl;
            cout << "Account Number: " << account->getAccountNumber() << endl;
            cout << "Account Holder: " << account->getName() << endl;
            cout << "Account Type: " << account->getType() << endl;
            cout << "Current Balance: $" << fixed << setprecision(2) << account->getBalance() << endl;
            cout << "As of: " << getCurrentDate() << endl;
            cout << "=======================" << endl;
        } catch (const exception& e) {
            cerr << "An error occurred while displaying account information: " << e.what() << endl;
        }

        cout << "\nWould you like to check another account balance? (Y/N): ";
        char choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (toupper(choice) != 'Y') {
            cout << "Returning to main menu." << endl;
            return;
        }
    }
}
