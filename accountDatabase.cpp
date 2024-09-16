#include "accountDatabase.h"
#include <fstream>
#include <iostream>
#include "serviceChargeCheckingType.h"
#include "noServiceChargeCheckingType.h"
#include "savingsAccountType.h"
#include "highInterestCheckingType.h"
#include "highInterestSavingsType.h"
#include "certificateOfDepositType.h"

using namespace std;

const string FILE_NAME = "accounts.txt";

void saveAccount(const unique_ptr<bankAccountType>& account) {
    ofstream file(FILE_NAME, ios::app);
    if (file.is_open()) {
        file << account->getAccountNumber() << ","
             << account->getName() << ","
             << typeid(*account).name() << ","
             << account->getBalance() << "\n";
        file.close();
        cout << "Account saved to accounts.txt\n";
    } else {
        cerr << "Unable to open accounts.txt for writing.\n";
    }
}

vector<unique_ptr<bankAccountType>> loadAccounts() {
    vector<unique_ptr<bankAccountType>> accounts;
    ifstream file(FILE_NAME);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            // Implement loading logic here
        }
        file.close();
        cout << "Accounts loaded from accounts.txt\n";
    } else {
        cerr << "Unable to open accounts.txt for reading.\n";
    }

    return accounts;
}

int getNextAccountNumber() {
    vector<unique_ptr<bankAccountType>> accounts = loadAccounts();
    if (accounts.empty()) {
        return 1000; // Start with account number 1000 if no accounts exist
    }
    return accounts.back()->getAccountNumber() + 1;
}
