#include "lookUpAccount.h"
#include "accountDatabase.h"
#include "utilityFunctions.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unique_ptr<bankAccountType> lookUpAccount() {
    vector<unique_ptr<bankAccountType>> accounts = loadAccounts();
    vector<unique_ptr<bankAccountType>*> matchedAccounts;
    string searchTerm;

    while (true) {
        matchedAccounts.clear();
        cout << "Enter account holder's name to search (or '0' to exit): ";
        getline(cin, searchTerm);

        if (searchTerm == "0") {
            return nullptr;
        }

        string lowerSearchTerm = toLowerCase(searchTerm);

        for (auto& account : accounts) {
            if (toLowerCase(account->getName()).find(lowerSearchTerm) != string::npos) {
                matchedAccounts.push_back(&account);
            }
        }

        if (matchedAccounts.empty()) {
            cout << "No matches found. Please try again." << endl;
        } else {
            cout << "Matches found:" << endl;
            for (size_t i = 0; i < matchedAccounts.size(); ++i) {
                const auto& account = matchedAccounts[i];
                cout << i + 1 << ". " 
                     << (*account)->getName() << " (Acc# " 
                     << (*account)->getAccountNumber() << ") - "
                     << (*account)->getType() << endl;
            }

            int choice;
            while (true) {
                cout << "Enter the number of the account you want to select (or 0 to search again): ";
                cin >> choice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (choice == 0) {
                    break;
                }

                if (choice > 0 && static_cast<size_t>(choice) <= matchedAccounts.size()) {
                    return move(*matchedAccounts[choice - 1]);
                } else {
                    cout << "Invalid selection. Please try again." << endl;
                }
            }

            if (choice != 0) {
                break;
            }
        }
    }

    return nullptr;
}
