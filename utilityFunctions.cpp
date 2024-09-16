#include "utilityFunctions.h"
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
