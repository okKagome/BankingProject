#include "withdraw.h"
#include "lookUpAccount.h"
#include "utilityFunctions.h"
#include "accountDatabase.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <memory>

using namespace std;

void withdraw() {
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

        double withdrawalAmount;
        while (true) {
            withdrawalAmount = getValidAmount("Enter withdrawal amount (or 0 to cancel): $");
            if (withdrawalAmount == 0) {
                cout << "Withdrawal cancelled. Returning to previous menu." << endl;
                return;
            }
            if (withdrawalAmount > 0) {
                if (withdrawalAmount > account->getBalance()) {
                    cout << "Error: Withdrawal amount exceeds current balance." << endl;
                    cout << "Please enter a smaller amount." << endl;
                } else {
                    break;
                }
            } else {
                cout << "Invalid amount. Please enter a positive number." << endl;
            }
        }

        double newBalance = account->getBalance() - withdrawalAmount;

        // Confirm withdrawal
        cout << "\nWithdrawal Summary:" << endl;
        cout << "Amount to withdraw: $" << fixed << setprecision(2) << withdrawalAmount << endl;
        cout << "New balance will be: $" << fixed << setprecision(2) << newBalance << endl;
        cout << "Confirm withdrawal? (Y/N): ";
        char confirm;
        cin >> confirm;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (toupper(confirm) == 'Y') {
            account->setBalance(newBalance);
            updateAccountInDatabase(*account);

            // Print receipt
            cout << "\n--- Withdrawal Receipt ---" << endl;
            cout << "Account Number: " << account->getAccountNumber() << endl;
            cout << "Account Holder: " << account->getName() << endl;
            cout << "Withdrawal Amount: $" << fixed << setprecision(2) << withdrawalAmount << endl;
            cout << "New Balance: $" << fixed << setprecision(2) << newBalance << endl;
            cout << "Transaction Date: " << getCurrentDate() << endl;
            cout << "-------------------------" << endl;

            cout << "Withdrawal successful. Returning to main menu." << endl;
            return;
        } else {
            cout << "Withdrawal cancelled. Would you like to try another withdrawal? (Y/N): ";
            cin >> confirm;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (toupper(confirm) != 'Y') {
                cout << "Returning to main menu." << endl;
                return;
            }
        }
    }
}
