#include "highInterestSavingsType.h"
#include <iostream>
#include <iomanip>

using namespace std;

const double highInterestSavingsType::MINIMUM_BALANCE = 2500.00;
const double highInterestSavingsType::INTEREST_RATE = 0.005;

highInterestSavingsType::highInterestSavingsType(string n, int acctNumber, double bal)
    : savingsAccountType(n, acctNumber, bal, INTEREST_RATE) {
    minimumBalance = MINIMUM_BALANCE;
}

double highInterestSavingsType::getMinimumBalance() const {
    return minimumBalance;
}

bool highInterestSavingsType::verifyMinimumBalance(double amount) {
    return (getBalance() - amount >= minimumBalance);
}

void highInterestSavingsType::withdraw(double amount) {
    if (verifyMinimumBalance(amount)) {
        bankAccountType::withdraw(amount);
    } else {
        cout << "Withdrawal not allowed. Balance would fall below minimum balance." << endl;
    }
}

void highInterestSavingsType::print() {
    cout << fixed << showpoint << setprecision(2);
    cout << "High Interest Savings: " << getName() << "\t ACCT# " << getAccountNumber() << "\t Balance: $" << getBalance();
}
