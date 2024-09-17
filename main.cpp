#include <iostream>
#include "bankAccountType.h"
#include "savingsAccountType.h"
#include "highInterestSavingsType.h"
#include "noServiceChargeCheckingType.h"
#include "serviceChargeCheckingType.h"
#include "highInterestCheckingType.h"
#include "certificateOfDepositType.h"
#include "checkingAccountType.h"
#include "createAccount.h"
#include "editAccount.h"
#include "lookUpAccount.h"
#include "deposit.h"
#include "withdraw.h"
#include "checkBalance.h"
#include "listAllAccounts.h"
#include "deleteAccount.h"
#include "accountDatabase.h"
#include "utilityFunctions.h"

using namespace std;

int main() {
    char choice;

    do {
        clearScreen();
        cout << "\nBank System Menu:\n"
             << "1. Create Account\n"
             << "2. Edit Account\n"
             << "3. Look Up Account\n"
             << "4. Deposit\n"
             << "5. Withdraw\n"
             << "6. Check Balance\n"
             << "7. List All Accounts\n"
             << "8. Delete Account\n"
             << "9. Quit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
               createAccount();
                break;
            case '2':
               editAccount();
                break;
            case '3':
               lookUpAccount();
                break;
            case '4':
					deposit();
                break;
            case '5':
					withdraw();
                break;
            case '6':
					checkBalance();
                break;
            case '7':
					listAllAccounts();
                break;
            case '8':
					deleteAccount();
                break;
            case '9':
					cout << "Thank you for using the Bank System. Goodbye!\n";
                break;
            default:
               cout << "Invalid choice. Please try again.\n";
        }
        if (choice != '9') {
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
        }
    } while (choice != '9');

    return 0;
}
