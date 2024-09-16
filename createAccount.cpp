#include "createAccount.h"
#include "accountDatabase.h"
#include "utilityFunctions.h"
#include "serviceChargeCheckingType.h"
#include "noServiceChargeCheckingType.h"
#include "savingsAccountType.h"
#include "highInterestCheckingType.h"
#include "highInterestSavingsType.h"
#include "certificateOfDepositType.h"
#include <iostream>
#include <memory>

using namespace std;

void createAccount() {
    string name;
    int accountNumber = getNextAccountNumber();
    double initialBalance;
    int accountType;

    while (true) {
        cout << "Enter account holder's name (or '0' to cancel): ";
        getline(cin, name);
        if (name == "0") return;

        cout << "Enter initial balance: $";
        initialBalance = getValidAmount();

        cout << "\nSelect account type:\n"
             << "1. Service Charge Checking\n"
             << "2. No Service Charge Checking\n"
             << "3. Savings\n"
             << "4. High Interest Checking\n"
             << "5. High Interest Savings\n"
             << "6. Certificate of Deposit\n"
             << "0. Go back to previous menu\n"
             << "Enter choice: ";
        accountType = getValidInteger();

        if (accountType == 0) {
            cout << "Returning to previous menu...\n";
            continue;
        }

        if (accountType < 1 || accountType > 6) {
            cout << "Invalid account type. Please try again.\n";
            continue;
        }

        unique_ptr<bankAccountType> newAccount;

        switch(accountType) {
            case 1: {
                double monthlyFee = getValidAmount("Enter monthly fee: $");
                newAccount = make_unique<serviceChargeCheckingType>(name, accountNumber, initialBalance);
                break;
            }
            case 2:
                newAccount = make_unique<noServiceChargeCheckingType>(name, accountNumber, initialBalance);
                break;
            case 3: {
                double interestRate = getValidAmount("Enter interest rate (as decimal): ");
                newAccount = make_unique<savingsAccountType>(name, accountNumber, initialBalance, interestRate);
                break;
            }
            case 4:
                newAccount = make_unique<highInterestCheckingType>(name, accountNumber, initialBalance);
                break;
            case 5:
                newAccount = make_unique<highInterestSavingsType>(name, accountNumber, initialBalance);
                break;
            case 6: {
                double interestRate = getValidAmount("Enter interest rate (as decimal): ");
                int maturityMonths = getValidInteger("Enter maturity period (in months): ");
                newAccount = make_unique<certificateOfDepositType>(name, accountNumber, initialBalance, interestRate, maturityMonths);
                break;
            }
        }

        saveAccount(newAccount);
        cout << "Account created successfully.\n";
        return;
    }
}
