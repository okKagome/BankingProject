#include "deposit.h"
#include "lookUpAccount.h"
#include "utilityFunctions.h"
#include "accountDatabase.h"
#include <iostream>
#include <iomanip>
#include <memory>

using namespace std;

void deposit() {
    while (true) {
        unique_ptr<bankAccountType> account = lookUpAccount();
        if (!account) {
            cout << "Returning to previous menu." << endl;
            return;
        }

        cout << "Selected Account:" << endl;
        cout << "Name: " << account->getName() << endl;
        cout << "Account Number: " << account->getAccountNumber() << endl;
        cout << "Current Balance: $" << fixed << setprecision(2) << account->getBalance() << endl;

        double depositAmount;
        while (true) {
            depositAmount = getValidAmount("Enter deposit amount (or 0 to cancel): $");
            if (depositAmount == 0) {
                cout << "Deposit cancelled. Returning to previous menu." << endl;
                return;
            }
            if (depositAmount > 0) {
                break;
            }
            cout << "Invalid amount. Please enter a positive number." << endl;
        }

        double newBalance = account->getBalance() + depositAmount;
        
        // Confirm deposit
        cout << "\nDeposit Summary:" << endl;
        cout << "Amount to deposit: $" << fixed << setprecision(2) << depositAmount << endl;
        cout << "New balance will be: $" << fixed << setprecision(2) << newBalance << endl;
        cout << "Confirm deposit? (Y/N): ";
        char confirm;
        cin >> confirm;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (toupper(confirm) == 'Y') {
            account->setBalance(newBalance);
            updateAccountInDatabase(*account);

            // Print receipt
            cout << "\n--- Deposit Receipt ---" << endl;
            cout << "Account Number: " << account->getAccountNumber() << endl;
            cout << "Account Holder: " << account->getName() << endl;
            cout << "Deposit Amount: $" << fixed << setprecision(2) << depositAmount << endl;
            cout << "New Balance: $" << fixed << setprecision(2) << newBalance << endl;
            cout << "Transaction Date: " << getCurrentDate() << endl;
            cout << "----------------------" << endl;

            cout << "Deposit successful. Returning to main menu." << endl;
            return;
        } else {
            cout << "Deposit cancelled. Would you like to try another deposit? (Y/N): ";
            cin >> confirm;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (toupper(confirm) != 'Y') {
                cout << "Returning to main menu." << endl;
                return;
            }
        }
    }
}
