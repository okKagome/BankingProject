#include "lookUpAccount.h"
#include "accountDatabase.h"
#include <iostream>

using namespace std;

unique_ptr<bankAccountType> lookUpAccount() {
    int accountNumber;
    cout << "Enter account number to look up: ";
    cin >> accountNumber;

    vector<unique_ptr<bankAccountType>> accounts = loadAccounts();
    for (auto& account : accounts) {
        if (account->getAccountNumber() == accountNumber) {
            cout << "Account found:\n";
            account->print();
            return move(account);
        }
    }

    cout << "Account not found." << endl;
    return nullptr;
}
