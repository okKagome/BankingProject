#include "editAccount.h"
#include "lookUpAccount.h"
#include "utilityFunctions.h"
#include "accountDatabase.h"
#include <iostream>
#include <iomanip>
#include <memory>
#include <limits>

using namespace std;

void editAccount() {
    unique_ptr<bankAccountType> account = lookUpAccount();
    if (!account) {
        cout << "No account selected. Returning to main menu." << endl;
        return;
    }

    while (true) {
        clearScreen();
        cout << "Edit Account Menu for Account #" << account->getAccountNumber() << endl;
        cout << "1. Edit Account Holder's Name" << endl;
        cout << "2. Edit Balance" << endl;
        cout << "3. Save Changes and Exit" << endl;
        cout << "4. Cancel and Exit" << endl;
        cout << "Enter your choice: ";

        int choice = getValidInteger();

        switch (choice) {
            case 1: {
                string newName;
                cout << "Current Name: " << account->getName() << endl;
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, newName);
                account->setName(newName);
                cout << "Name updated successfully." << endl;
                break;
            }
            case 2: {
               double newBalance;
                cout << "Current Balance: $" << fixed << setprecision(2) << account->getBalance() << endl;
                newBalance = getValidAmount("Enter new balance: $");
					double currentBalance = account->getBalance();
						if (newBalance > currentBalance) {
							account->deposit(newBalance - currentBalance);
						} else if (newBalance < currentBalance) {
               	   account->withdraw(currentBalance - newBalance);
                }
                cout << "Balance updated successfully." << endl;
                break;
            }
            case 3: {
                cout << "Are you sure you want to save the following changes?" << endl;
                cout << "Name: " << account->getName() << endl;
                cout << "Balance: $" << fixed << setprecision(2) << account->getBalance() << endl;
                cout << "Enter 'Y' to confirm or any other key to continue editing: ";
                char confirm;
                cin >> confirm;
                if (toupper(confirm) == 'Y') {
                    if (updateAccountInDatabase(*account)) {
                    cout << "Changes saved successfully." << endl;
                    return;
                } else {
							cout << "Failed to save changes." << endl;
                    }
                }
                break;
            }
            case 4:
                cout << "Changes discarded. Returning to main menu." << endl;
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << "Press Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }
}
