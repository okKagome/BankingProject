#include "utilityFunctions.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void clearScreen() {
    cout << "\033[H\033[2J" << endl;
    return;
}

void updateAccountInDatabase(const Account& updatedAccount) {
    vector<Account> accounts = loadAccounts();
    bool found = false;
    
    for (auto& account : accounts) {
        if (account.accountNumber == updatedAccount.accountNumber) {
            account = updatedAccount;
            found = true;
            break;
        }
    }

    if (found) {
        ofstream file("accounts.txt");
        if (file.is_open()) {
            for (const auto& account : accounts) {
                file << account.accountNumber << ","
                     << account.name << ","
                     << account.type << ","
                     << account.balance << ","
                     << account.additionalInfo << "\n";
            }
            file.close();
            cout << "Account updated successfully.\n";
        } else {
            cerr << "Unable to open accounts.txt for writing.\n";
        }
    } else {
        cout << "Account not found in the database.\n";
    }
}
