#include "savingsAccountType.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

savingsAccountType::savingsAccountType(string n, int acctNumber, double bal, double intRate)
    : bankAccountType(n, acctNumber, bal), interestRate(intRate) {
}

double savingsAccountType::getInterestRate() const {
    return interestRate;
}

void savingsAccountType::setInterestRate(double rate) {
    interestRate = rate;
}

void savingsAccountType::postInterest() {
    balance = balance + balance * interestRate;
}

void savingsAccountType::createMonthlyStatement() {
    postInterest();
}

void savingsAccountType::print() {
    cout << fixed << showpoint << setprecision(2);
    cout << "Savings Account: " << getName() << "\t ACCT# " << getAccountNumber() << "\tBalance: $" << getBalance();
}
