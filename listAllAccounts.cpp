#include "listAllAccounts.h"
#include "accountDatabase.h"
#include "utilityFunctions.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>

using namespace std;

void listAllAccounts() {
    vector<unique_ptr<bankAccountType>> accounts = loadAccounts();

    if (accounts.empty()) {
        cout << "No accounts found in the system." << endl;
        return;
    }

    clearScreen();
    cout << "=== All Accounts ===" << endl;
    cout << setw(10) << "Account#" << setw(20) << "Name" << setw(20) << "Type" << setw(15) << "Balance" << endl;
    cout << string(65, '-') << endl;

    for (const auto& account : accounts) {
        cout << setw(10) << account->getAccountNumber()
             << setw(20) << account->getName()
             << setw(20) << account->getType()
             << setw(15) << fixed << setprecision(2) << account->getBalance() << endl;
    }

    cout << string(65, '-') << endl;
    cout << "Total Accounts: " << accounts.size() << endl;

    cout << "\nPress Enter to return to the main menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}
