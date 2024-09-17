#include "accountDatabase.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
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
            istringstream iss(line);
            string accountNumber, name, type, balance;

            if (getline(iss, accountNumber, ',') &&
                getline(iss, name, ',') &&
                getline(iss, type, ',') &&
                getline(iss, balance, ',')) {
                
                unique_ptr<bankAccountType> account;
                int accNum = stoi(accountNumber);
                double bal = stod(balance);

                if (type == typeid(serviceChargeCheckingType).name()) {
                    account = make_unique<serviceChargeCheckingType>(name, accNum, bal);
                } else if (type == typeid(noServiceChargeCheckingType).name()) {
                    account = make_unique<noServiceChargeCheckingType>(name, accNum, bal);
                } else if (type == typeid(savingsAccountType).name()) {
                    account = make_unique<savingsAccountType>(name, accNum, bal);
                } else if (type == typeid(highInterestCheckingType).name()) {
                    account = make_unique<highInterestCheckingType>(name, accNum, bal);
                } else if (type == typeid(highInterestSavingsType).name()) {
                    account = make_unique<highInterestSavingsType>(name, accNum, bal);
                } else if (type == typeid(certificateOfDepositType).name()) {
                    account = make_unique<certificateOfDepositType>(name, accNum, bal);
                }

                if (account) {
                    accounts.push_back(move(account));
                }
            }
        }
        file.close();
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

bool removeAccountFromDatabase(int accountNumber) {
    vector<unique_ptr<bankAccountType>> accounts = loadAccounts();
    auto it = remove_if(accounts.begin(), accounts.end(),
                        [accountNumber](const unique_ptr<bankAccountType>& account) {
                            return account->getAccountNumber() == accountNumber;
                        });

    if (it != accounts.end()) {
        accounts.erase(it, accounts.end());
        
        ofstream file(FILE_NAME);
        if (file.is_open()) {
            for (const auto& account : accounts) {
                file << account->getAccountNumber() << ","
                     << account->getName() << ","
                     << typeid(*account).name() << ","
                     << account->getBalance() << "\n";
            }
            file.close();
            return true;
        } else {
            cerr << "Unable to open file for writing." << endl;
            return false;
        }
    }
    return false;
}

bool updateAccountInDatabase(const bankAccountType& updatedAccount) {
    vector<unique_ptr<bankAccountType>> accounts = loadAccounts();
    bool found = false;
    
    for (auto& account : accounts) {
        if (account->getAccountNumber() == updatedAccount.getAccountNumber()) {
            account->setName(updatedAccount.getName());
            account->setBalance(updatedAccount.getBalance());
            found = true;
            break;
        }
    }

    if (found) {
        ofstream file(FILE_NAME);
        if (file.is_open()) {
            for (const auto& account : accounts) {
                file << account->getAccountNumber() << ","
                     << account->getName() << ","
                     << typeid(*account).name() << ","
                     << account->getBalance() << "\n";
            }
            file.close();
            return true;
        } else {
            cerr << "Unable to open accounts.txt for writing.\n";
            return false;
        }
    }
    return false;
}
