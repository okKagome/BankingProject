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
        }#include "utilityFunctions.h"
#include <iostream>
#include <limits>

using namespace std;

void clearScreen() {
    cout << "\033[H\033[2J" << endl;
}

double getValidAmount(const char* prompt) {
    double amount;
    while (true) {
        cout << prompt;
        if (cin >> amount && amount >= 0) {
            return amount;
        }
        cout << "Invalid input. Please enter a non-negative number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int getValidInteger(const char* prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= 0) {
            return value;
        }
        cout << "Invalid input. Please enter a non-negative integer.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
