#include "deleteAccount.h"
#include "lookUpAccount.h"
#include "accountDatabase.h"
#include "utilityFunctions.h"
#include <iostream>
#include <iomanip>
#include <memory>
#include <limits>

using namespace std;

void deleteAccount() {
    while (true) {
        unique_ptr<bankAccountType> account = lookUpAccount();
        if (!account) {
            cout << "Returning to previous menu." << endl;
            return;
        }

        cout << "\nAccount Details:" << endl;
        cout << "Account Number: " << account->getAccountNumber() << endl;
        cout << "Account Holder: " << account->getName() << endl;
        cout << "Account Type: " << account->getType() << endl;
        cout << "Current Balance: $" << fixed << setprecision(2) << account->getBalance() << endl;

        cout << "\nAre you sure you want to delete this account? This action cannot be undone. (Y/N): ";
        char confirm;
        cin >> confirm;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (toupper(confirm) == 'Y') {
            if (removeAccountFromDatabase(account->getAccountNumber())) {
                cout << "Account successfully deleted." << endl;
            } else {
                cout << "Error: Failed to delete the account." << endl;
            }
        } else {
            cout << "Account deletion cancelled." << endl;
        }

        cout << "\nWould you like to delete another account? (Y/N): ";
        cin >> confirm;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (toupper(confirm) != 'Y') {
            cout << "Returning to main menu." << endl;
            return;
        }
    }
}
