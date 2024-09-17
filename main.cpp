#include <iostream>
#include <limits>
#include "createAccount.h"
#include "editAccount.h"
#include "deposit.h"
#include "withdraw.h"
#include "checkBalance.h"
#include "listAllAccounts.h"
#include "deleteAccount.h"
#include "utilityFunctions.h"

using namespace std;

int main() {
    char choice;

    do {
        clearScreen();
        cout << "\nBank System Menu:\n"
             << "1. Create Account\n"
             << "2. Edit Account\n"
             << "3. Deposit\n"
             << "4. Withdraw\n"
             << "5. Check Balance\n"
             << "6. List All Accounts\n"
             << "7. Delete Account\n"
             << "8. Quit\n"
             << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case '1':
                createAccount();
                break;
            case '2':
                editAccount();
                break;
            case '3':
                deposit();
                break;
            case '4':
                withdraw();
                break;
            case '5':
                checkBalance();
                break;
            case '6':
                listAllAccounts();
                break;
            case '7':
                deleteAccount();
                break;
            case '8':
                cout << "Thank you for using the Bank System. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

        if (choice != '8') {
            cout << "Press Enter to continue...";
            cin.get();
        }
    } while (choice != '8');

    return 0;
}
